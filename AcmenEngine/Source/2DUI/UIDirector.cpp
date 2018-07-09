#include "Acmen.h"

UIDirector* UIDirector::sDirector = _null;

UIDirector*  UIDirector::GetInstance( )
{
	if ( sDirector == _null )
		sDirector = new UIDirector( );

	return sDirector;
}

_void UIDirector::KeyDown( const _dword keycode )
{

}

_void UIDirector::KeyUp( const _dword keycode )
{

}

_void UIDirector::MouseDown( const _dword keycode, const Vector2& vec2 )
{

}

_void UIDirector::MouseMove( const Vector2& vec2 )
{

}

_void UIDirector::MouseUp( const _dword keycode, const Vector2& vec2 )
{
	
}

_void UIDirector::DispatchEvent( InputType event, InputParams params )
{
	for( UIScene* node : mScenes )
	{
		
	}
}

_void UIDirector::Vsit( )
{
	for( UIScene* scene : mScenes )
	{
		if ( scene->IsVisible( ) == _true )
			scene->Visit( Renderer::GetInstance( ), Matrix4( ) );
	}
}

_void UIDirector::MainLoop( _float elapse )
{
	Vsit( );
	Renderer::GetInstance( )->OnRender( elapse );
}