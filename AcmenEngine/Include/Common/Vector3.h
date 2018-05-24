#pragma once

namespace Acmen
{

class Vector3
{
public:
	inline static _float Dot( const Vector3& v1, const Vector3& v2 )
		{ return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z; }

	inline static Vector3 Cross( const Vector3& v1, const Vector3& v2 )
		{ return Vector3( v1.y * v2.z - v1.z * v2.y, v1.z * v2.x - v1.x * v2.z, v1.x * v2.y - v1.y * v2.x ); }

	inline static _float Distance( const Vector3& v1, const Vector3& v2 )
	{
		_float dx = v1.x - v2.x;
		_float dy = v1.y - v2.y;
		_float dz = v1.z - v2.z;
		return sqrt( dx * dx + dy * dy + dz * dz );
	}

public:
	_float x;
	_float y;
	_float z;

public:
	inline Vector3( )
		: x( 0.0f ), y( 0.0f ), z( 0.0f ){ }
	inline Vector3( _float nx, _float ny, _float nz )
		: x( nx ), y( ny ), z( nz ){ }
	inline Vector3( const Vector2& v, _float zz )
		: x( v.x ), y( v.y ), z( zz ){ }
	inline Vector3( const Vector3& v )
		: x( v.x ), y( v.y ), z( v.z ){ }

	inline Vector3 operator + ( ) const
		{ return Vector3( x, y, z ); }
	inline Vector3 operator - ( ) const
		{ return Vector3( -x, -y, -z ); }

	inline Vector3 operator + ( const Vector3& v ) const
		{ return Vector3( x + v.x, y + v.y, z + v.z ); }
	inline Vector3 operator - ( const Vector3& v ) const
		{ return Vector3( x - v.x, y - v.y, z - v.z ); }

	inline Vector3& operator += ( const Vector3& v )
		{ x += v.x; y += v.y; z += v.z; return *this; }
	inline Vector3& operator -= ( const Vector3& v )
		{ x -= v.x; y -= v.y; z -= v.z; return *this; }

	inline Vector3 operator * ( _float s )
		{ return Vector3( x * s, y * s, z * s ); }
	inline Vector3 operator / ( _float s )
		{ return Vector3( x / s, y / s, z / s ); }

	inline Vector3 operator *= ( _float s )
		{ return Vector3( x *= s, y *= s, z *= s ); }
	inline Vector3 operator /= ( _float s )
		{ return Vector3( x /= s, y /= s, z /= s ); }

	inline Vector3 operator * ( const Vector3& v ) const
		{ return Vector3( x * v.x, y * v.y, z * v.z ); }
	inline Vector3 operator / ( const Vector3& v ) const
		{ return Vector3( x / v.x, y / v.y, z / v.z ); }

	inline Vector3& operator *= ( const Vector3& v )
		{ x *= v.x; y *= v.y; z *= v.z; return *this; }
	inline Vector3& operator /= ( const Vector3& v )
		{ x /= v.x; y /= v.y; z /= v.z; return *this; }

	inline Vector3& operator = ( const Vector3& v )
		{ x = v.x; y = v.y; z = v.z; return *this; }

	inline _bool operator == ( const Vector3& v ) const
		{ return x == v.x && y == v.y && z == v.z; }
	inline _bool operator != ( const Vector3& v ) const
		{ return x != v.x || y != v.y || z != v.z; }

	inline _float Magnitude( ) const
		{ return sqrt( x * x + y * y + z * z ); }
	inline _float MagnitudeSquared( ) const
		{ return x * x + y * y + z * z; }

	inline Vector3& Normalize( )
	{
		_float m = Magnitude( );
		if ( m > 0.0f )
			{ x /= m; y /= m; z /= m; }

		return * this;
	}
};

};