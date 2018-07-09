#include "Acmen.h"

_void OnKeyCallback( GLFWwindow* window, _long key, _long scancode, _long action, _long mode )
{
	if ( action == GLFW_PRESS )
		Application::GetInstance( )->KeyDown( key );
	else if ( action == GLFW_RELEASE )
		Application::GetInstance( )->KeyUp( key );
}

_void OnReSize( GLFWwindow* window, _long width, _long height )
{
	glViewport( 0, 0, width, height );
}

_void OnMouseCallBack( GLFWwindow* window, _long button, _long action, _long modify )
{
	_double posx, posy;
	glfwGetCursorPos( window, &posx, &posy );
	if ( action == GLFW_PRESS )
		Application::GetInstance( )->MouseDown( button, Vector2( posx, posy ) );
	else if ( action == GLFW_RELEASE )
		Application::GetInstance( )->MouseUp( button, Vector2( posx, posy ) );
}


_void OncursorMove( GLFWwindow* window, _double x, _double y)
{
	Application::GetInstance( )->MouseMove( Vector2( x, y ) );
}

Windows::Windows( )
{
	initWindows( 800.0f, 600.0f );
}

Windows::Windows( _float w, _float h )
{
	initWindows( w, h );
}

Windows::~Windows( )
{
	Close( );
	mGLFWWindow = _null;
}

_float Windows::GetWidth( )
{
	_long w, h;
	glfwGetWindowSize( mGLFWWindow, &w, &h );
	return w;
}

_float Windows::GetHeight( )
{
	_long w, h;
	glfwGetWindowSize( mGLFWWindow, &w, &h );
	return h;
}

_void Windows::ReSize( _float width, _float height )
{
	if ( mGLFWWindow == _null )
		return;

	glfwSetWindowSize( mGLFWWindow, (_long)width, (_long)height );
	_long w, h;
	glfwGetFramebufferSize( mGLFWWindow, &w, &h );
	OnReSize( mGLFWWindow, w, h );
}

_void Windows::Run( )
{
	if ( mGLFWWindow == _null )
		return;

	while ( !glfwWindowShouldClose( mGLFWWindow ) )
	{
		glfwPollEvents( );
		Application::GetInstance( )->Run( );
		glfwSwapBuffers( mGLFWWindow );
	}
	glfwTerminate( );
}

_void Windows::Close( )
{
	if ( mGLFWWindow != _null )
		glfwSetWindowShouldClose( mGLFWWindow, _true );
}

_void Windows::initWindows( _float width, _float height )
{
	glfwInit( );
	glfwWindowHint( GLFW_CONTEXT_VERSION_MAJOR, 3 );
	glfwWindowHint( GLFW_CONTEXT_VERSION_MINOR, 3 );
	glfwWindowHint( GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE );

	mGLFWWindow = glfwCreateWindow( width, height, "Acmen", NULL, NULL );
	if ( mGLFWWindow == _null )
	{
		Trace::TraceString( "[WM] Create windows failed!" );
		return;
	}

	glfwMakeContextCurrent( mGLFWWindow );
	glfwSetFramebufferSizeCallback( mGLFWWindow, OnReSize );
	glfwSetKeyCallback( mGLFWWindow, OnKeyCallback );
	glfwSetMouseButtonCallback( mGLFWWindow, OnMouseCallBack );
	glfwSetCursorPosCallback( mGLFWWindow, OncursorMove );

	if ( glewInit( ) != GLEW_OK )
	{
		Trace::TraceString( "[WM] Initialize windows failed!" );
		return;
	}

	ReSize( width, height );
	Application::GetInstance( )->FinishLaunched( );
}