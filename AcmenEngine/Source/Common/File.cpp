#include "Acmen.h"

_bool File::Open( const string &name, const string &model )
{
	Close( );
	errno_t err = ::fopen_s( &mFile, name.c_str( ), model.c_str( ) );
	if ( err != 0 || mFile == _null )
		return _false;

	return _true;
}

string File::ReadLine( )
{
	string tmp = "";
	_char ch;
	while( EOF!=( ch = fgetc( mFile ) ) )
	{
		if ( ch == '\n' )
			break;

		tmp += ch;
	}

	return tmp;
}

string File::Read( )
{
	::fseek( mFile, 0L, SEEK_END );
	long len = ::ftell( mFile );
	_char* chs = new _char[len + 1];
	::memset( chs, 0, len + 1 );
	::fseek( mFile, 0L, SEEK_SET );
	::fread( chs, sizeof(_char), len, mFile );
	return chs;
}

_bool File::Write( string& str )
{
	return ::fputs( str.c_str( ), mFile ) >= 0;
}

_bool File::Close( )
{
	if ( mFile == _null )
		return _false;

	return ::fclose( mFile ) == 0;
}