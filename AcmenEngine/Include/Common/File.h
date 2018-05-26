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

	_bool Open( const String &name, const String &model );
	String* ReadLine( String* str );
	String* Read( String* str );
	_bool Close( );
};
}