#include "Acmen.h"

Application* Application::sApplication = _null;

Application* Application::GetInstance( )
{
	if ( sApplication == _null )
		sApplication = new Application( );

	return sApplication;
}

_void Application::FinishLaunched( )
{
	if ( mLaunchedFunc != _null )
		mLaunchedFunc( );
}

_void Application::KeyDown( const _dword keycode )
{
	if ( mKeyDownFunc != _null )
		mKeyDownFunc( keycode );
}

_void Application::KeyUp( const _dword keycode )
{
	if ( mKeyUpFunc != _null )
		mKeyUpFunc( keycode );
}

_void Application::MouseDown( const _dword keycode, const Vector2& vec2 )
{
	mMouseState |= (_dword)Math::Pow( 2, keycode );
	if ( mMouseDownFunc != _null )
		mMouseDownFunc( keycode, vec2 );
}

_void Application::MouseMove( const Vector2& vec2 )
{
	if ( mMouseDownFunc != _null && mMouseState > 0 )
		mMouseMoveFunc( vec2 );
}

_void Application::MouseUp( const _dword keycode, const Vector2& vec2 )
{
	mMouseState &= ~(_dword)Math::Pow( 2, keycode );
	if ( mMouseUpFunc != _null )
		mMouseUpFunc( keycode, vec2 );
}

_void Application::EnterBack( )
{
	if ( mEnterBackFunc != _null )
		mEnterBackFunc( );
}

_void Application::EnterFore( )
{
	if ( mEnterForeFunc != _null )
		mEnterForeFunc( );
}

_void Application::InitGLContextAttrs( )
{

}

_void Application::Run( )
{
	mTimer->Run( );
	_double elapse = mTimer->GetElapse( );

	UIDirector::GetInstance( )->MainLoop( elapse );
	if ( mIdleFunc!= _null )
		mIdleFunc( elapse );
}