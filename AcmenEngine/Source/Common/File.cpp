#include "Acmen.h"

_bool File::Open( const string &name, const string &model )
{
	mFile = fopen( name.c_str( ), model.c_str( ) );
	if ( mFile != _null )
		return _true;

	return _false;
}