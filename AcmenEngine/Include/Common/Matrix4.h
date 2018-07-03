#pragma once

namespace Acmen
{

class  Matrix4
{

public:
	static Matrix4 CreateOrthoLH( _float width, _float height, _float znear, _float zfar );
	static Matrix4 CreateOrthoRH( _float width, _float height, _float znear, _float zfar );
	static Matrix4 CreatePerspectiveFovLH( _float fovy, _float aspect, _float znear, _float zfar );
	static Matrix4 CreatePerspectiveFovRH( _float fovy, _float aspect, _float znear, _float zfar );

	static Matrix4 CreateLookAtLH( const Vector3& eye, const Vector3& lookat, const Vector3& upaxis );
	static Matrix4 CreateLookAtRH( const Vector3& eye, const Vector3& lookat, const Vector3& upaxis );
public:
	_float		m[4][4];

public:
	inline Matrix4( )
	{
		m[0][0]	= 1.0f; m[0][1] = 0.0f; m[0][2] = 0.0f; m[0][3] = 0.0f;
		m[1][0] = 0.0f; m[1][1] = 1.0f; m[1][2] = 0.0f; m[1][3] = 0.0f;
		m[2][0] = 0.0f; m[2][1] = 0.0f; m[2][2] = 1.0f; m[2][3] = 0.0f;
		m[3][0] = 0.0f; m[3][1] = 0.0f; m[3][2] = 0.0f; m[3][3] = 1.0f;
	}

	inline Matrix4( _float m00, _float m01, _float m02, _float m03, _float m10, _float m11, _float m12, _float m13,
		_float m20, _float m21, _float m22, _float m23, _float m30, _float m31, _float m32, _float m33 )
	{
		m[0][0] = m00; m[0][1] = m01; m[0][2] = m02; m[0][3] = m03;
		m[1][0] = m10; m[1][1] = m11; m[1][2] = m12; m[1][3] = m13;
		m[2][0] = m20; m[2][1] = m21; m[2][2] = m22; m[2][3] = m23;
		m[3][0] = m30; m[3][1] = m31; m[3][2] = m32; m[3][3] = m33;
	}

	inline Matrix4( const Matrix4& mat )
	{
		m[0][0] = mat( 0, 0 ); m[0][1] = mat( 0, 1 ); m[0][2] = mat( 0, 2 ); m[0][3] = mat( 0, 3 );
		m[1][0] = mat( 1, 0 ); m[1][1] = mat( 1, 1 ); m[1][2] = mat( 1, 2 ); m[1][3] = mat( 1, 3 );
		m[2][0] = mat( 2, 0 ); m[2][1] = mat( 2, 1 ); m[2][2] = mat( 2, 2 ); m[2][3] = mat( 2, 3 );
		m[3][0] = mat( 3, 0 ); m[3][1] = mat( 3, 1 ); m[3][2] = mat( 3, 2 ); m[3][3] = mat( 3, 3 );
	}

	inline _float* operator [] ( _long r )
		{ return m[r]; }

	inline _float operator ( ) ( _long r, _long c ) const
		{ return m[r][c]; }
	inline _float& operator ( ) ( _long r, _long c )
		{ return m[r][c]; }

	inline Matrix4 operator + ( ) const
		{ return Matrix4( m[0][0], m[0][1], m[0][2], m[0][3], m[1][0], m[1][1], m[1][2], m[1][3], m[2][0], m[2][1], m[2][2], m[2][3], m[3][0], m[3][1], m[3][2], m[3][3] ); }
	inline Matrix4 operator - ( ) const
		{ return Matrix4( -m[0][0], -m[0][1], -m[0][2], -m[0][3], -m[1][0], -m[1][1], -m[1][2], -m[1][3], -m[2][0], -m[2][1], -m[2][2], -m[2][3], -m[3][0], -m[3][1], -m[3][2], -m[3][3] ); }

	inline Matrix4 operator + ( const Matrix4& mat ) const
		{ Matrix4 ret( *this ); return ret += mat; }
	inline Matrix4 operator - ( const Matrix4& mat ) const
		{ Matrix4 ret( *this ); return ret -= mat; }

	inline Matrix4 operator * ( _float s ) const
		{ Matrix4 ret( *this ); return ret *= s; }
	inline Matrix4 operator / ( _float s ) const
		{ Matrix4 ret( *this ); return ret /= s; }

	inline Matrix4 operator * ( const Matrix4& mat ) const
		{ Matrix4 ret( *this ); return ret *= mat; }

	inline Matrix4& operator -= ( const Matrix4& mat )
		{ return operator += ( - mat ); }
	inline Matrix4& operator /= ( _float s )
		{ return operator *= ( 1.0f / s ); }
	inline _bool operator != ( const Matrix4& mat ) const
		{ return ! operator == ( mat ); }

	inline 	Matrix4& Scaling( const Vector3& v )
		{  return Scaling( v.x, v.y, v.z ); }

	Vector4		operator * ( const Vector4& vec );
	Matrix4&	operator += ( const Matrix4& mat );
	Matrix4&	operator *= ( const Matrix4& mat );
	Matrix4&	operator *= ( _float s );
	Matrix4&	operator = ( const Matrix4& mat );
	_bool		operator == ( const Matrix4& mat ) const;

	Matrix4&	Identity( );
	Matrix4&	Transpose( );

	inline Matrix4& Translate( const Vector3& vec )
		{ return Translate( vec.x, vec.y, vec.z ); }
	Matrix4&	Translate( _float x, _float y, _float z );

	Matrix4&	RotationX( _float r );
	Matrix4&	RotationY( _float r );
	Matrix4&	RotationZ( _float r );
	Matrix4&	Rotation( const Vector3& a, _float r );

	Matrix4&	Scaling( _float x, _float y, _float z );

};

}