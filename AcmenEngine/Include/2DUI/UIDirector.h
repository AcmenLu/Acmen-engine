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
enum InputType
{
	KEYDOWN,
	KEYUP,
	CLICK,
	DBCLICK,
	DRAGBEGIN,
	BRAGEND
};


typedef _void (*OnKeyDown)( const _dword keyCode );
typedef _void (*OnKeyUp)( const _dword keyCode );
typedef _void (*OnClick)( const Vector2& vec2 );
typedef _void (*OnDBClick)( const Vector2& vec2 );
typedef _void (*OnDragBegin)( const Vector2& vec2 );
typedef _void (*OnDragEnd)( const Vector2& vec2 );

class UIDirector
{

public:
	static UIDirector* sDirector;
	static UIDirector* GetInstance( );

public:
	vector<UIScene*> mScenes;
	Renderer*		mRenderer;

public:
	inline UIDirector( ){ }
	inline ~UIDirector( ){ }

	_void KeyDown( const _dword keycode );
	_void KeyUp( const _dword keycode );
	_void MouseDown( const _dword keycode, const Vector2& vec2 );
	_void MouseMove( const Vector2& vec2 );
	_void MouseUp( const _dword keycode, const Vector2& vec2 );
	_void DispatchEvent( InputType event, InputParams params );

	_void Vsit( );
	_void MainLoop( _float elapse );

};

}