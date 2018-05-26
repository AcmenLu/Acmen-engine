#include "Acmen.h"

_bool String::StartWith( const String& srcstr, const String& desstr )
{
	_dword slen = ::strlen( srcstr );
	_dword dlen = ::strlen( desstr );
	if ( slen < dlen )
		return _false;

	for( _dword i = 0; i < dlen; i ++ )
	{
		if ( desstr[i] != srcstr[i] )
			return _false;
	}
	return _true;
}

String::String( const _char* str ): mLength( 0 ), mSize( 0 )
{
	_dword len = ::strlen( str );
	Grow( len );
	::memcpy( mString, str, len );
}

_void String::Grow( _dword length )
{
	if ( length <= 0 || mLength + length <= mSize )
		return;

	if ( mSize == 0 )
	{
		mSize = 32;
		while ( length > mSize )
			mSize *= 2;

		mString = new _char[mSize];
		::memset( mString, 0, mSize );
	}
	else
	{
		_long len = mSize * 2;
		while( mLength + length > len )
			len *= 2;

		_char* tmp = new _char[len];
		::memset( tmp, 0, len );
		::memcpy( mString, tmp, mLength );
		delete mString;
		mString = tmp;
		mSize = len;
	}
}

String&	String::operator = ( const _char* chrs )
{
	if ( mString != _null )
		delete mString;

	_dword len = ::strlen( chrs );
	mString = new _char[len + 1];
	::memcpy( mString, chrs, len );
	mString[len] = '\0';
	mLength = mSize = len + 1;
	return *this;
}

String&	String::operator += ( _char ch )
{
	Grow( 1 );
	mString[mLength++] = ch;
	return *this;
}

String&	String::operator += ( const _char* str )
{
	_dword len = ::strlen( str );
	Grow( len );
	for ( _dword i = 0; i < len; i ++ )
	{
		if ( str[i] == '\0' )
			break;

		mString[mLength++] = str[i];
	}
	return *this;
}