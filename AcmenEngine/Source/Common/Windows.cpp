#include "Acmen.h"

void OnKeyCallback( GLFWwindow* window, int key, int scancode, int action, int mode )
{
	if ( key == GLFW_KEY_ESCAPE && action == GLFW_PRESS )
		glfwSetWindowShouldClose( window, true );
}

Windows::Windows( ) : mWidth( 800 ), mHeight( 600 )
{
	initWindows( );
}

Windows::Windows( _dword w, _dword h ) : mWidth( w ), mHeight( h )
{
	initWindows( );
}

Windows::~Windows( )
{
	if ( mRenderer != _null )
		mRenderer->~Renderer( );
}

_bool Windows::ReSize( _dword w, _dword h )
{
	mWidth =  w;
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

	if ( glewInit( ) != GLEW_OK )
	{
		Trace::TraceString( "[WM] Initialize windows failed!" );
		return;
	}

	glfwSetFramebufferSizeCallback( mWindow, &(this->onReSize) );
	glfwMakeContextCurrent( mWindow );
	glfwSetKeyCallback( mWindow, this->processInput );
	glEnable( GL_DEPTH_TEST );
	mRenderer = new Renderer( );
}

_void Windows::processInput( GLFWwindow* window, int key, int scancode, int action, int mode )
{
}

_void Windows::onReSize( GLFWwindow* window, _long width, _long height )
{
	glViewport( 0, 0, width, height );
}