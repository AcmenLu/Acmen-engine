#pragma once

namespace Acmen
{

template<class T>
SAFE_RELESE( T* t )
{
	if ( t != _null )
		delete t;

	t = _null;
}


};