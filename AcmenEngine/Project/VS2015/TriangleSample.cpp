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

	vector<Vertex> vertices;
	vertices.push_back( Vertex( -0.5f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f ) );
	vertices.push_back( Vertex( 0.5f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f ) );
	vertices.push_back( Vertex( 0.0f, 0.5f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f ) );
	Shapes* shape = new Shapes( );
	shape->mVertices = vertices;
	renderer->AddRenderObject( shape );

	if ( window != _null )
		window->Run( );

	SAFE_RELESE( shape )
	SAFE_RELESE( renderer )
	SAFE_RELESE( window )
}