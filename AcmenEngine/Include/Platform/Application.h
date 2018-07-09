#pragma once
namespace Acmen
{

class Application
{
public:
	typedef _void (*OnIdle)( const _dword elapse );
	typedef _void (*OnKeyDown)( const _dword keyCode );
	typedef _void (*OnKeyUp)( const _dword keyCode );
	typedef _void (*OnMouseDown)( const _dword keyCode, const Vector2& vec2 );
	typedef _void (*OnMouseMove)( const Vector2& vec2 );
	typedef _void (*OnMouseUp)( const _dword keyCode, const Vector2& vec2 );

	typedef _void (*OnLaunched)( );
	typedef _void (*OnEnterBack)( );
	typedef _void (*OnEnterFore)( );

	static Application* sApplication;
	static Application* GetInstance( );

private:
	OnIdle				mIdleFunc;
	OnKeyDown			mKeyDownFunc;
	OnKeyUp				mKeyUpFunc;
	OnMouseDown			mMouseDownFunc;
	OnMouseMove			mMouseMoveFunc;
	OnMouseUp			mMouseUpFunc;
	OnLaunched			mLaunchedFunc;
	OnEnterBack			mEnterBackFunc;
	OnEnterFore			mEnterForeFunc;
	_char				mMouseState;
	Timer*				mTimer;

public:
	Application( )
		: mMouseState( 0 ), mTimer( new Timer( ) ){ }
	inline ~Application( ){ }

	inline _float GetElapse( )
		{ return mTimer->GetElapse( ); }

	inline _void SetIdleCallback( OnIdle funcptr )
		{ mIdleFunc = funcptr; }
	inline _void SetKeyDownCallback( OnKeyDown funcptr )
		{ mKeyDownFunc = funcptr; }
	inline _void SetKeyUpCallback( OnKeyUp funcptr )
		{ mKeyUpFunc = funcptr; }
	inline _void SetMouseDownCallback( OnMouseDown funcptr )
		{ mMouseDownFunc = funcptr; }
	inline _void SetMouseMoveCallback( OnMouseMove funcptr )
		{ mMouseMoveFunc = funcptr; }
	inline _void SetMouseUpCallback( OnMouseUp funcptr )
		{ mMouseUpFunc = funcptr; }
	inline _void SetLaunchedCallback( OnLaunched funcptr )
		{ mLaunchedFunc = funcptr; }
	inline _void SetEnterBackCallback( OnEnterBack funcptr )
		{ mEnterBackFunc = funcptr; }
	inline _void SetEnterForeCallback( OnEnterFore funcptr )
		{ mEnterForeFunc = funcptr; }

	virtual _void FinishLaunched( );
	virtual _void KeyDown( _dword keycode );
	virtual _void KeyUp( const _dword keycode );
	virtual _void MouseDown( const _dword keycode, const Vector2& vec2 );
	virtual _void MouseMove( const Vector2& vec2 );
	virtual _void MouseUp( const _dword keycode, const Vector2& vec2 );
	virtual _void EnterBack( );
	virtual _void EnterFore( );

	virtual _void InitGLContextAttrs( );
	virtual _void Run( );

};

}