#include "Acmen.h"
#pragma comment( lib, "AcmenCommon" )

int main( )
{
	Windows* window = new Windows( 800, 600 );
	if ( window != _null )
		window->run( );

	delete window;
}