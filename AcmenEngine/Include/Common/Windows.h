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
	typedef _bool (*OnIdle)( _dword elapse );

	_dword			mWidth;
	_dword			mHeight;
	Renderer*		mRenderer;
	GLFWwindow*		mWindow;


public:
	Windows( _dword w, _dword h );
	~Windows( );
	inline _void SetIdleCallback( OnIdle funcptr )
		{ mIdleFunc = funcptr; }

	_void Run( );

protected:
	OnIdle				mIdleFunc;
};

};