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

	_bool Open( const string &name, const string &model );
	
};
}