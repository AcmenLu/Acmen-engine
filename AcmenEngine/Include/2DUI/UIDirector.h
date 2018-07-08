#pragma once
namespace Acmen
{
struct InputParams
{
	_dword		mKeyCode;
	Vector2		mPosition;
	InputParams( _dword key, _float posx, _float posy )
		:mKeyCode( key ), mPosition( Vector2( posx, posy ) ){ }

};
enum InputEvent
{
	KEYDOWN,
	KEYUP,
	MOUSEDOWN,
	MOUSEMOVE,
	MOUSEUP,
	TOUCHBEGIN,
	TOUCHMOVE,
	TOUCHEND
};


typedef _void (*OnKeyDown)( const _dword keyCode );
typedef _void (*OnKeyUp)( const _dword keyCode );
typedef _void (*OnMouseDown)( const _dword keyCode, const Vector2& vec2 );
typedef _void (*OnMouseMove)( const Vector2& vec2 );
typedef _void (*OnMouseUp)( const _dword keyCode, const Vector2& vec2 );

class UIDirector
{

public:
	static UIDirector* sDirector;
	static UIDirector* GetInstance( );

public:
	vector<UIScene*> mScenes;

public:
	inline UIDirector( ){ }
	inline ~UIDirector( ){ }

	_void KeyDown( const _dword keycode );
	_void KeyUp( const _dword keycode );
	_void MouseDown( const _dword keycode, const Vector2& vec2 );
	_void MouseMove( const Vector2& vec2 );
	_void MouseUp( const _dword keycode, const Vector2& vec2 );
	_void DispatchEvent( InputEvent event, InputParams params );

};

}