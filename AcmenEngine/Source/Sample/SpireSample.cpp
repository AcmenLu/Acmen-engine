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

	Spriter* sprite = new Spriter( "resources/textures/toy_box_diffuse.png" );
	sprite->GetTransform( ).Translate( Vector3( 100, 200, 0 ) );
	renderer->AddRenderObject( sprite );

	if ( window != _null )
		window->Run( );

	SAFE_RELESE( sprite )
	SAFE_RELESE( renderer )
	SAFE_RELESE( window )
}