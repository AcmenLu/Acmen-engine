#pragma once

namespace Acmen
{

class String
{
public:
	static _bool StartWith( const String& srcstr, const String& desstr );
	static _dword StrToDword( const String& srcstr );
	static _float StrToFloat( const String& srcstr );

private:
	_char*			mString;
	_long			mLength;
	_long			mSize;

public:
	inline String( )
		:mString( _null ), mLength( 0 ), mSize( 0 ){ }
	inline String( String* str )
		: mString( (_char*)str ), mLength( str->Length( ) ), mSize( str->Size( ) ){ }

	String( const _char* str );
	~String( );

	inline operator const _char* ( ) const
		{ return mString; }
	inline _char operator [] ( _long index ) const
		{ return mString[ index ]; }
	inline _char* GetData( )
		{ return mString; }

	inline _long Size( ) const
		{ return mSize; }
	inline _long Length( ) const
		{ return mLength; }

	_void	Grow( _dword length );
	String&	operator = ( const _char* chrs );
	String&	operator += ( _char ch );
	String&	operator += ( const _char* str );
	String*	SubString( _long start, _long end = -1 );
	String& TrimStart( const _char ch = ' ' );
	String& TrimEnd( const _char ch = ' ' );
	String& Trim( const _char ch = ' ' );
	vector<String*>& Split( const _char str, vector<String*> &list );
	_long	LastIndexOf( _char ch );
};
}