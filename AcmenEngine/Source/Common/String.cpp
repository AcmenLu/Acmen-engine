#include "Acmen.h"

_bool String::StartWith( const String& srcstr, const String& desstr )
{
	if ( srcstr.Length( ) <= 0 || desstr.Length( ) <= 0 )
		return _false;

	if ( srcstr.Length( ) < desstr.Length( ) )
		return _false;

	for( _dword i = 0; i < desstr.Length( ); i ++ )
	{
		if ( desstr[i] != srcstr[i] )
			return _false;
	}
	return _true;
}

_dword String::StrToDword( const String& srcstr )
{
	_char* tmp = new _char[srcstr.Length( )];
	for ( _dword i = 0; i < srcstr.Length( ); i ++ )
		tmp[i] = srcstr[i];
	return ::atoi( tmp );
}

_float String::StrToFloat( const String& srcstr )
{
	_char* tmp = new _char[srcstr.Length( )];
	for ( _dword i = 0; i < srcstr.Length( ); i ++ )
		tmp[i] = srcstr[i];
	return ::atof( tmp );
}

String::String( const _char* str )
	: mString( _null ), mLength( 0 ), mSize( 0 )
{
	_dword len = ::strlen( str );
	if ( len <= 0 )
		return;

	Grow( len );
	::memcpy( mString, str, len );
	mString[len] = '\0';
	mLength = len;
}

String::~String( )
{
	mLength = 0;
	mSize = 0;
	SAFE_RELESE( mString );
}

_void String::Grow( _dword length )
{
	if ( length <= 0 || mLength + length <= mSize )
		return;

	if ( mSize == 0 )
		mSize = 32;

	while ( mLength + length + 1 > mSize )
		mSize *= 2;

	_char* tmp = new _char[mSize];
	::memset( tmp, 0, mSize );
	if ( mString != _null )
	{
		::memcpy( mString, tmp, mLength );
		SAFE_RELESE( mString );
	}
	mString = tmp;
}

String&	String::operator = ( const _char* chrs )
{
	SAFE_RELESE( mString );
	mLength = 0;
	mSize = 0;

	_dword len = ::strlen( chrs );
	if ( len > 0 )
	{
		Grow( len );
		::memcpy( mString, chrs, len );
		mString[len] = '\0';
		mLength = len;
	}
	return *this;
}

String&	String::operator += ( _char ch )
{
	Grow( 1 );
	mString[mLength++] = ch;
	mString[mLength] = '\0';
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
	mString[mLength] = '\0';
	return *this;
}

String String::SubString( _long start, _long end )
{
	if ( start < 0 )
		return String( );

	if ( end == -1 || end > mLength )
		end = mLength;

	if ( end < start )
		return String( );

	_dword len = end - start;
	_char* cha = new _char[len];
	for ( _dword i = start; i < end; i ++ )
		cha[i] = mString[i - start];
	return String( cha );
}

String& String::TrimStart( const _char ch )
{
	_long index = -1;
	for ( _dword i = 0; i < mLength; i ++ )
	{
		if ( mString[i] != ch )
			break;

		index = i;
	}
	if ( index >= 0 )
	{
		for ( _dword i = index; i < mLength; i ++ )
			mString[i - index] = mString[i];
		
		mLength -= ( index + 1 );
		mString[mLength] = '\0';
	}
	return *this;
}

String& String::TrimEnd( const _char ch )
{
	if ( mString != _null )
	{
		for ( _dword i = mLength - 1; i >= 0; i -- )
		{
			if ( mString[i] != ch )
				break;
			mString[--mLength] = '\0';
		}
	}
	return *this;
}

String& String::Trim( const _char ch )
{
	TrimStart( ch );
	TrimEnd( ch );
	return *this;
}

vector<String*> & String::Split( const _char str, vector<String*> &list )
{
	if ( str == _null )
		return list;

	_dword head = 0, tail = 0;
	while( mString[tail] != '\0')
	{
		if ( mString[tail] == str )
		{
			String* s = new String( );
			while( head < tail )
			{
				(*s) += mString[head];
				head ++;
			}
			list.push_back( s );
			head = tail + 1;
		}
		tail ++;
	}

	list.push_back( new String( mString + head ) );
	return list;
}