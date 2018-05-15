#pragma once

#define GLEW_STATIC
#include "glew.h"
#include "glfw3.h"

#pragma comment( lib, "glfw3" )
#pragma comment( lib, "glew32s" )
#pragma comment( lib, "opengl32" )

namespace Acmen
{
class Renderer;

class Windows
{
public:
	typedef _void (*OnIdle)( _dword elapse );
	typedef _void (*OnKeyDown)( _dword keyCode );
	typedef _void (*OnKeyUp)( _dword keyCode );

	_dword			mWidth;
	_dword			mHeight;
	Renderer*		mRenderer;
	GLFWwindow*		mWindow;


public:
	Windows( );
	Windows( _dword w, _dword h );
	~Windows( );

	inline _void SetIdleCallback( OnIdle funcptr )
		{ mIdleFunc = funcptr; }
	inline _void SetKeyDownCallback( OnKeyDown funcptr )
		{ mKeyDownFunc = funcptr; }
	inline _void SetKeyUpFunc( OnKeyUp funcptr )
		{ mKeyUpFunc = funcptr; }

	_bool ReSize( _dword w, _dword h );
	_void Run( );

private:
	_void initWindows( );
	_void processInput( GLFWwindow* window, int key, int scancode, int action, int mode );
	_void onReSize( GLFWwindow* window, _long width, _long height );
	

protected:
	OnIdle				mIdleFunc;
	OnKeyDown			mKeyDownFunc;
	OnKeyUp				mKeyUpFunc;

};

};