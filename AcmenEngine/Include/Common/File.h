#pragma once

namespace Acmen
{

class File
{

public:
	FILE*		mFile;

public:
	inline File( )
		{ }

	_bool	Open( const string& name, const string& model );
	string	ReadLine( );
	string	Read( );
	_bool	Write( string& str );
	_bool Close( );
};
}