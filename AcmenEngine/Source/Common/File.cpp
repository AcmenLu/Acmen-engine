#include "Acmen.h"

_bool File::Open( const String &name, const String &model )
{
	Close( );
	mFile = fopen( name, model );
	if ( mFile != _null )
		return _true;

	return _false;
}

String* File::ReadLine( String* str )
{
	if ( mFile == _null )
		return str;

	_char line[1024];
	memset( line, 0, 1024 );
	if ( !feof( mFile ) )
		fgets( line, 1024, mFile );
	else
		return _null;

	if ( str == _null )
		str = new String( );

	(*str) = line;
	
	return str;
}

String* File::Read( String* str )
{
	if ( mFile == _null )
		return str;

	if ( str == _null )
		str = new String( );

	_dword length = 1024;
	_dword index = 0;
	
	_char ch;
	while( EOF!=( ch = fgetc( mFile ) ) )
		(*str) += ch;

	return str;
}

_bool File::Close( )
{
	if ( mFile == _null )
		return _false;

	return fclose( mFile ) == 0;
}