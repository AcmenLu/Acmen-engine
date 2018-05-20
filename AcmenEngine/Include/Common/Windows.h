#pragma once

namespace Acmen
{

class Renderer;

class Windows
{

public:
	static Windows*		sInstance;
	typedef _void (*OnIdle)( _dword elapse );
	typedef _void (*OnKeyDown)( _dword keyCode );
	typedef _void (*OnKeyUp)( _dword keyCode );

private:
	OnIdle				mIdleFunc;
	OnKeyDown			mKeyDownFunc;
	OnKeyUp				mKeyUpFunc;

	Renderer*			mRenderer;
	_dword				mWidth;
	_dword				mHeight;
	GLFWwindow*			mWindow;

public:
	static Windows* GetInstance( );

	Windows( );
	Windows( _dword w, _dword h );
	~Windows( );

	inline OnIdle GetOnIdleCallBack( )
		{ return mIdleFunc; }
	inline _void SetIdleCallback( OnIdle funcptr )
		{ mIdleFunc = funcptr; }

	inline OnIdle GetKeyDownCallback( )
		{ return mKeyDownFunc; }
	inline _void SetKeyDownCallback( OnKeyDown funcptr )
		{ mKeyDownFunc = funcptr; }

	inline OnIdle GetKeyUpCallback( )
		{ return mKeyUpFunc; }
	inline _void SetKeyUpFunc( OnKeyUp funcptr )
		{ mKeyUpFunc = funcptr; }

	inline Renderer* GetRenderer( )
		{ return mRenderer; }
	inline _void BindRenderer( Renderer* renderer )
		{ mRenderer = renderer; }

	inline _dword GetWidth( )
		{ return mWidth; }
	inline _dword GetHeight( )
		{ return mHeight; }

	_void ReSize( _dword w, _dword h );
	_void Run( );
	_void Close( );

private:
	_void initWindows( );

};

};