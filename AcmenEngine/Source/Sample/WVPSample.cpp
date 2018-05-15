#include "Acmen.h"
#pragma comment( lib, "AcmenCommon" )

Windows* window = _null;

_void onKeyDown( _dword keycode )
{
	if ( keycode == 32 )
		window->Close( );
}

int main( )
{
	window = new Windows( 800, 600 );
	window->SetKeyDownCallback( onKeyDown );
	window->ReSize( 900, 800 );
	if ( window != _null )
		window->Run( );

	delete window;
}