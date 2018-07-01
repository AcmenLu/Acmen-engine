#include "Acmen.h"
#pragma comment( lib, "Common" )

Windows* window = _null;
Renderer* renderer = _null;

_void onKeyDown( _dword keycode )
{
	if ( keycode == 32 )
		window->Close( );
}

int main( )
{
	window = new Windows( 800, 600 );
	window->SetKeyDownCallback( onKeyDown );
	renderer = new Renderer( );
	window->BindRenderer( renderer );

	if ( window != _null )
		window->Run( );

	delete renderer;
	delete window;
}