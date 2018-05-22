#pragma once

namespace Acmen
{

class Vector4
{

public:
	inline static _float Dot( const Vector4& v1, const Vector4& v2 )
		{ return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z + v1.w * v2.w; };

public:
	_float x;
	_float y;
	_float z;
	_float w;

public:
	inline Vector4( )
		: x( 0.0f ), y( 0.0f ), z( 0.0f ), w( 0.0f ){ }
	inline Vector4( _float nx, _float ny, _float nz, _float nw )
		: x( nx ), y( ny ), z( nz ), w( nw ){ }
	inline Vector4( const Vector4& v )
		: x( v.x ), y( v.y ), z( v.z ), w( v.w ) { }
	inline Vector4( const Vector3& v, _float ww )
		: x( v.x ), y( v.y ), z( v.z ), w( ww ) { }

	inline Vector4& operator = ( const Vector3 &v )
		{ x = v.x; y = v.y; z = v.z, w = 0.0f; return *this; }
	inline Vector4& operator = ( const Vector4 &v )
		{ x = v.x; y = v.y; z = v.z, w = v.w; return *this; }

	inline Vector4 operator + ( ) const
		{ return Vector4( x, y, z, w ); }
	inline Vector4 operator - ( ) const
		{ return Vector4( -x, -y, -z, -w ); }

	inline Vector4 operator + ( const Vector4& v ) const
		{ return Vector4( x + v.x, y + v.y, z + v.z, w + v.w ); }
	inline Vector4 operator - ( const Vector4& v ) const
		{ return Vector4( x - v.x, y - v.y, z - v.z, w - v.w ); }

	inline Vector4& operator += ( const Vector4& v )
		{ x += v.x; y += v.y; z += v.z; w += v.w; return *this; }
	inline Vector4& operator -= ( const Vector4& v )
		{ x -= v.x; y -= v.y; z -= v.z; w -= v.w; return *this; }

	inline Vector4 operator * ( _float s ) const
		{ return Vector4( x * s, y * s, z * s, w * s ); }
	inline Vector4 operator / ( _float s ) const
		{ return Vector4( x / s, y / s, z / s, w / s ); }

	inline Vector4& operator *= ( _float s )
		{ x *= s; y *= s; z *= s; w *= s; return *this; }
	inline Vector4& operator /= ( _float s )
		{ x /= s; y /= s; z /= s; w /= s; return *this; }

	inline Vector4 operator * ( const Vector4& v ) const
		{ return Vector4( x * v.x, y * v.y, z * v.z, w * v.w ); }
	inline Vector4 operator / ( const Vector4& v ) const
		{ return Vector4( x / v.x, y / v.y, z / v.z, w / v.w ); }

	inline Vector4& operator *= ( const Vector4& v )
		{ x *= v.x; y *= v.y; z *= v.z; w *= v.w; return *this; }
	inline Vector4& operator /= ( const Vector4& v )
		{ x /= v.x; y /= v.y; z /= v.z; w /= v.w; return *this; }

	inline _bool operator == ( const Vector4& v ) const
		{ return x == v.x && y == v.y && z == v.z && w == v.w; }
	inline _bool operator != ( const Vector4& v ) const
		{ return x != v.x || y != v.y || z != v.z || w != v.w; }

	inline _float Magnitude( ) const
		{ return sqrt( x * x + y * y + z * z + w * w ); }
	inline _float MagnitudeSquared( ) const
		{ return x * x + y * y + z * z + w * w; }

	inline Vector4& Normalize( )
		{ _float m = Magnitude( ); if ( m > 0.0f ) { x /= m; y /= m; z /= m; w /= m; } return *this; }
};

};