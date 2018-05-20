#include "Acmen.h"

#pragma comment( lib, "glfw3" )
#pragma comment( lib, "glew32s" )
#pragma comment( lib, "opengl32" )

_void OnKeyCallback( GLFWwindow* window, _long key, _long scancode, _long action, _long mode )
{
	if ( Windows::GetInstance( ) == _null )
		return;

	if ( action == GLFW_PRESS )
	{
		if ( Windows::GetInstance( )->GetKeyDownCallback( ) != _null )
			Windows::GetInstance( )->GetKeyDownCallback( )( key );
	}
	else if ( action == GLFW_RELEASE )
	{
		if ( Windows::GetInstance( )->GetKeyUpCallback( ) != _null )
			Windows::GetInstance( )->GetKeyUpCallback( )( key );
	}
}

_void OnReSize( GLFWwindow* window, _long width, _long height )
{
	glViewport( 0, 0, width, height );
	//if ( Windows::GetInstance( )->mRenderer != _null )
	//	Windows::GetInstance( )->mRenderer->ResetProjection( (_float)width, (_float)height );
}

Windows* Windows::sInstance = _null;
Windows* Windows::GetInstance( )
{
	if ( sInstance == _null )
		sInstance = new Windows( );

	return sInstance;
}

Windows::Windows( ) : mWidth( 800 ), mHeight( 600 )
{
	initWindows( );
	sInstance = this;
}

Windows::Windows( _dword w, _dword h ) : mWidth( w ), mHeight( h )
{
	initWindows( );
	sInstance = this;
}

Windows::~Windows( )
{
}

_void Windows::ReSize( _dword w, _dword h )
{
	mWidth = w;
	mHeight = h;
	initWindows( );
}

_void Windows::Run( )
{
	if ( mWindow == _null )
		return;

	while ( !glfwWindowShouldClose( mWindow ) )
	{
		glfwPollEvents( );
		if ( mRenderer != _null )
			mRenderer->OnRender( 0.0f );

		if ( mIdleFunc != _null )
			mIdleFunc( 0 );

		glfwSwapBuffers( mWindow );
	}

	glfwTerminate( );
}

_void Windows::Close( )
{
	glfwSetWindowShouldClose( mWindow, _true );
}

_void Windows::initWindows( )
{
	glfwInit( );
	glfwWindowHint( GLFW_CONTEXT_VERSION_MAJOR, 3 );
	glfwWindowHint( GLFW_CONTEXT_VERSION_MINOR, 3 );
	glfwWindowHint( GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE );
	glewExperimental = GL_TRUE;

	mWindow = glfwCreateWindow( mWidth, mHeight, "Acmen", NULL, NULL );
	if ( mWindow == _null )
	{
		Trace::TraceString( "[WM] Create windows failed!" );
		return;
	}
	glfwMakeContextCurrent( mWindow );
	if ( glewInit( ) != GLEW_OK )
	{
		Trace::TraceString( "[WM] Initialize windows failed!" );
		return;
	}

	glfwSetFramebufferSizeCallback( mWindow, OnReSize );
	glfwSetKeyCallback( mWindow, OnKeyCallback );
	glEnable( GL_DEPTH_TEST );


	_long width, height;
	glfwGetFramebufferSize( mWindow, &width, &height );
	OnReSize( mWindow, width, height );
}