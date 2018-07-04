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

	Texture* texture = new Texture( "resources/textures/toy_box_diffuse.png" );
	Spriter* sprite = new Spriter( texture );
	renderer->AddRenderObject( sprite );

	if ( window != _null )
		window->Run( );

	SAFE_RELESE( sprite )
	SAFE_RELESE( renderer )
	SAFE_RELESE( window )
}