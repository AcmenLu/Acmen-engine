#include "Acmen.h"
#pragma comment( lib, "AcmenCommon" )

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

	Mesh* mesh = new Mesh( "resources/objects/nanosuit/nanosuit.obj" );
	renderer->AddRenderObject( mesh );
	if ( window != _null )
		window->Run( );

	delete renderer;
	delete window;
}