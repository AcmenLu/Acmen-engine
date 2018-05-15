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

	static Windows*		sInstance;

	OnIdle				mIdleFunc;
	OnKeyDown			mKeyDownFunc;
	OnKeyUp				mKeyUpFunc;

	_dword			mWidth;
	_dword			mHeight;
	Renderer*		mRenderer;
	Camera*			mCamera;
	glm::mat4		mProjection;
	GLFWwindow*		mWindow;


public:
	static Windows* GetInstance( );

	Windows( );
	Windows( _dword w, _dword h );
	~Windows( );

	inline _void SetIdleCallback( OnIdle funcptr )
		{ mIdleFunc = funcptr; }
	inline _void SetKeyDownCallback( OnKeyDown funcptr )
		{ mKeyDownFunc = funcptr; }
	inline _void SetKeyUpFunc( OnKeyUp funcptr )
		{ mKeyUpFunc = funcptr; }

	_void ReSize( _dword w, _dword h );
	_void Run( );
	_void Close( );

	inline Renderer* GetRenderer( )
		{ return mRenderer; }
	inline Camera* GetCamera( )
		{ return mCamera; }
	inline glm::mat4 GetProjection( )
		{ return mProjection; }

private:
	_void initWindows( );

};

};