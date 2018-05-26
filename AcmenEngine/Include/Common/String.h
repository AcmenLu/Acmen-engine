#pragma once

namespace Acmen
{

class String
{
public:
	static _bool StartWith( const String& srcstr, const String& desstr );

private:
	_char*			mString;
	_long			mSize;
	_long			mLength;

public:
	inline String( )
		:mString( _null ), mSize( 0 ){ }
	String( const _char* str );
	inline String( String* str )
		: mString( (_char*)str ), mSize( str->Size( ) ), mLength( str->Length( ) ){ }

	inline ~String( )
		{ if ( mString != _null ) delete mString; mSize = 0; }

	inline operator const _char* ( ) const
		{ return mString; }
	inline _char operator [] ( _long index ) const
		{ return mString[ index ]; }

	inline _long Size( )
		{ return mSize; }
	inline _long Length( )
		{ return mLength; }

	_void	Grow( _dword length );
	String&	operator = ( const _char* chrs );
	String&	operator += ( _char ch );
	String&	operator += ( const _char* str );

private:

};
}