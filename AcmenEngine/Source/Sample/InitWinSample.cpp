#include "Acmen.h"
#pragma comment( lib, "Platform" )

Windows* win;

_void onKeyDown( _dword keycode )
{
	if ( keycode == 32 )
	{
		win->Close( );
	}
}

int main( )
{
	Application::GetInstance( )->SetKeyDownCallback( onKeyDown );
	win = new Windows( 1000.0f, 700.0f );
	win->Run( );
}