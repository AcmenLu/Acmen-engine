#pragma once
namespace Acmen
{
class Rect
{
public:
	Vector2		mPosition;
	Vector2		mSize;

public:
	inline Rect( )
		: mPosition( Vector2( ) ), mSize( Vector2( ) ) { }
	inline Rect( Vector2 position, Vector2 size )
		:mPosition( position ), mSize( size ) { }
	inline Rect( _float x, _float y, _float w, _float h )
		:mPosition( Vector2( x, y ) ), mSize( Vector2( w, h ) ) { }

	inline Vector2 GetPosition( )
		{ return mPosition; }
	inline _void SetPosition( Vector2 pos )
		{ mPosition = pos; }
	inline _void SetPosition( _float x, _float y )
		{ mPosition.x = x; mPosition.y = y;}

	inline Vector2 GetSize( )
		{ return mSize; }
	inline _void SetSize( Vector2 size )
		{ mSize = size; }
	inline _void SetSize( _float x, _float y )
		{ mSize.x = x; mSize.y = y; }

	inline _float GetX( )
		{ return mPosition.x; }
	inline _float GetY( )
		{ return mPosition.x; }
	inline _float GetW( )
		{ return mSize.x; }
	inline _float GetH( )
		{ return mSize.x; }
	inline _float GetX1( )
		{ return mPosition.x + mSize.x; }
	inline _float GetY1( )
		{ return mPosition.x + mSize.y; }

	inline ~Rect( ){ }
};

}