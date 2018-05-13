#include "Acmen.h"

void OnKeyCallback( GLFWwindow* window, int key, int scancode, int action, int mode )
{
	if ( key == GLFW_KEY_ESCAPE && action == GLFW_PRESS )
		glfwSetWindowShouldClose( window, true );
}

Windows::Windows( _dword w, _dword h )
{
	mWidth = w;
	mHeight = h;
	glfwInit( );
	glfwWindowHint( GLFW_CONTEXT_VERSION_MAJOR, 3 );
	glfwWindowHint( GLFW_CONTEXT_VERSION_MINOR, 3 );
	glfwWindowHint( GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE );

	mWindow = glfwCreateWindow( mWidth, mHeight, "Acmen", NULL, NULL );
	if ( mWindow == _null )
	{
		Trace::TraceString( "[WM] Create windows failed!" );
		return;
	}

	glfwMakeContextCurrent( mWindow );
	glfwSetKeyCallback( mWindow, OnKeyCallback );

	glewExperimental = GL_TRUE;
	if ( glewInit( ) != GLEW_OK )
	{
		Trace::TraceString( "[WM] Failed to initialize GLEW" );
		return;
	}

	int width, height;
	glfwGetFramebufferSize( mWindow, &width, &height );
	glViewport( 0, 0, width, height );
	glEnable( GL_DEPTH_TEST );
	mRenderer = new Renderer( );
}

Windows::~Windows( )
{
	if ( mRenderer != _null )
		mRenderer->~Renderer( );
}

void Windows::Run( )
{
	if ( mWindow == _null )
		return;

	while (!glfwWindowShouldClose( mWindow ) )
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