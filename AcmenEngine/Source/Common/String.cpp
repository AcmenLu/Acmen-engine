#include "Acmen.h"

String::String( const _wchar* str )
{
	if ( str != _null )
	{
		
	}
}
String::~String( )
{
	if ( mString != _null )
	{
		delete mString;
		mString = _null;
	}
}
