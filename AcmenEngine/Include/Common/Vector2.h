#pragma once
namespace Acmen
{

class Vector2
{

public:
	inline static _float Dot( const Vector2& v1, const Vector2& v2 )
		{ return v1.x * v2.x + v1.y * v2.y; }

	inline static _float Cross( const Vector2& v1, const Vector2& v2 )
		{ return v1.x * v2.y - v1.y * v2.x; }
public:
	_float x;
	_float y;

public:
	inline Vector2( )
		: x( 0.0f ), y( 0.0f ){ }
	inline Vector2( _float nx, _float ny )
		: x( nx ), y( ny ){ }
	inline Vector2( const Vector2& v )
		: x( v.x ), y( v.y ){ }

	inline Vector2 operator + ( ) const
		{ return Vector2( x, y ); }
	inline Vector2 operator - ( ) const
		{ return Vector2( -x, -y ); }

	inline Vector2 operator + ( const Vector2& v ) const
		{ return Vector2( x + v.x, y + v.y ); }
	inline Vector2 operator - ( const Vector2& v ) const
		{ return Vector2( x - v.x, y - v.y ); }

	inline Vector2& operator += ( const Vector2& v )
		{ x += v.x; y += v.y; return *this; }
	inline Vector2& operator -= ( const Vector2& v )
		{ x -= v.x; y -= v.y; return *this; }

	inline Vector2 operator * ( _float s ) const
		{ return Vector2( x * s, y * s ); }
	inline Vector2 operator / ( _float s ) const
		{ return Vector2( x / s, y / s ); }

	inline Vector2& operator *= ( _float s )
		{ x *= s; y *= s; return *this; }
	inline Vector2& operator /= ( _float s )
		{ x /= s; y /= s; return *this; }

	inline Vector2 operator * ( const Vector2& v ) const
		{ return Vector2( x * v.x, y * v.y ); }
	inline Vector2 operator / ( const Vector2& v ) const
		{ return Vector2( x / v.x, y / v.y ); }

	inline Vector2& operator *= ( const Vector2& v )
		{ x *= v.x; y *= v.y; return *this; }
	inline Vector2& operator /= ( const Vector2& v )
		{ x /= v.x; y /= v.y; return *this; }

	inline Vector2& Normalize( )
		{ _float m = Magnitude( ); if ( m > 0.0f ) { x /= m; y /= m; } return *this; }

	inline _float Magnitude( ) const
		{ return sqrt( x * x + y * y ); }
	inline _float MagnitudeSquared( ) const
		{ return x * x + y * y; }
};

};