#include "Acmen.h"

Matrix4 Matrix4::CreateOrthoLH( _float width, _float height, _float znear, _float zfar )
{
	_float xs = 2.0f / width;
	_float ys = 2.0f / height;
	_float zf = 1.0f / ( zfar - znear );
	_float zn = - znear * zf;

	return Matrix4(
		xs, 0.0f, 0.0f, 0.0f,
		0.0f,   ys, 0.0f, 0.0f,
		0.0f, 0.0f,   zf, 0.0f,
		0.0f, 0.0f,   zn, 1.0f );
}

Matrix4 Matrix4::CreateOrthoRH( _float width, _float height, _float znear, _float zfar )
{
	_float xs = 2.0f / width;
	_float ys = -2.0f / height;
	_float zf = 2.0f / ( znear - zfar );
	_float zn = -( zfar + znear ) / ( zfar - znear );

	return Matrix4(
		xs, 0.0f, 0.0f, 0.0f,
		0.0f,   ys, 0.0f, 0.0f,
		0.0f, 0.0f,   zf, 0.0f,
		-1.0f, 1.0f,   zn, 1.0f );
}

Matrix4 Matrix4::CreatePerspectiveFovLH( _float fovy, _float aspect, _float znear, _float zfar )
{
	_float ys = 1.0f / ::tanf( fovy / 2.0f );
	_float xs = ys / aspect;
	_float zf = zfar / ( zfar - znear );
	_float zn = - znear * zf;

	return Matrix4(
		xs, 0.0f, 0.0f, 0.0f,
		0.0f,   ys, 0.0f, 0.0f,
		0.0f, 0.0f,   zf, 1.0f,
		0.0f, 0.0f,   zn, 0.0f );
}

Matrix4 Matrix4::CreatePerspectiveFovRH( _float fovy, _float aspect, _float znear, _float zfar )
{
	_float ys = 1.0f / ::tanf( fovy / 2.0f );
	_float xs = ys / aspect;
	_float zf = zfar / ( znear - zfar );
	_float zn = znear * zf;

	return Matrix4(
		xs, 0.0f, 0.0f,  0.0f,
		0.0f,   ys, 0.0f,  0.0f,
		0.0f, 0.0f,   zf, -1.0f,
		0.0f, 0.0f,   zn,  0.0f );
}

Matrix4 Matrix4::CreateLookAtLH( const Vector3& eye, const Vector3& lookat, const Vector3& upaxis )
{
	Vector3 zaxis = ( lookat - eye ).Normalize( );
	Vector3 xaxis = Vector3::Cross( upaxis, zaxis ).Normalize( );
	Vector3 yaxis = Vector3::Cross( zaxis, xaxis );

	_float xeye = - Vector3::Dot( xaxis, eye );
	_float yeye = - Vector3::Dot( yaxis, eye );
	_float zeye = - Vector3::Dot( zaxis, eye );

	return Matrix4(
		xaxis.x, yaxis.x, zaxis.x, 0.0f,
		xaxis.y, yaxis.y, zaxis.y, 0.0f,
		xaxis.z, yaxis.z, zaxis.z, 0.0f,
		xeye,    yeye,    zeye, 1.0f );
}

Matrix4 Matrix4::CreateLookAtRH( const Vector3& eye, const Vector3& lookat, const Vector3& upaxis )
{
	Vector3 zaxis = ( eye - lookat ).Normalize( );
	Vector3 xaxis = Vector3::Cross( upaxis, zaxis ).Normalize( );
	Vector3 yaxis = Vector3::Cross( zaxis, xaxis );

	_float xeye = - Vector3::Dot( xaxis, eye );
	_float yeye = - Vector3::Dot( yaxis, eye );
	_float zeye = - Vector3::Dot( zaxis, eye );

	return Matrix4(
		xaxis.x, yaxis.x, zaxis.x, 0.0f,
		xaxis.y, yaxis.y, zaxis.y, 0.0f,
		xaxis.z, yaxis.z, zaxis.z, 0.0f,
		xeye,    yeye,    zeye, 1.0f );
}

Matrix4& Matrix4::operator += ( const Matrix4& mat )
{
	m[0][0] += mat.m[0][0]; m[0][1] += mat.m[0][1]; m[0][2] += mat.m[0][2]; m[0][3] += mat.m[0][3];
	m[1][0] += mat.m[1][0]; m[1][1] += mat.m[1][1]; m[1][2] += mat.m[1][2]; m[1][3] += mat.m[1][3];
	m[2][0] += mat.m[2][0]; m[2][1] += mat.m[2][1]; m[2][2] += mat.m[2][2]; m[2][3] += mat.m[2][3];
	m[3][0] += mat.m[3][0]; m[3][1] += mat.m[3][1]; m[3][2] += mat.m[3][2]; m[3][3] += mat.m[3][3];

	return *this;
}

Matrix4& Matrix4::operator *= ( const Matrix4& mat )
{
	Matrix4 tmp = Matrix4( *this );

	for ( _dword i = 0; i < 4; i ++ )
	{
		for ( _dword j = 0; j < 4; j ++ )
		{
			m[i][j] = 0.0f;
			for( _dword k = 0; k < 4; k ++ )
			{
				m[i][j] += tmp( i, k ) * mat( k, j );
			}
		}
	}
	return *this;
}

Matrix4& Matrix4::operator *= ( _float s )
{
	m[0][0] *= s; m[0][1] *= s; m[0][2] *= s; m[0][3] *= s;
	m[1][0] *= s; m[1][1] *= s; m[1][2] *= s; m[1][3] *= s;
	m[2][0] *= s; m[2][1] *= s; m[2][2] *= s; m[2][3] *= s;
	m[3][0] *= s; m[3][1] *= s; m[3][2] *= s; m[3][3] *= s;

	return *this;
}

Matrix4& Matrix4::operator = ( const Matrix4& mat )
{
	m[0][0] = mat( 0, 0 ); m[0][1] = mat( 0, 1 ); m[0][2] = mat( 0, 2 ); m[0][3] = mat( 0, 3 );
	m[1][0] = mat( 1, 0 ); m[1][1] = mat( 1, 1 ); m[1][2] = mat( 1, 2 ); m[1][3] = mat( 1, 3 );
	m[2][0] = mat( 2, 0 ); m[2][1] = mat( 2, 1 ); m[2][2] = mat( 2, 2 ); m[2][3] = mat( 2, 3 );
	m[3][0] = mat( 3, 0 ); m[3][1] = mat( 3, 1 ); m[3][2] = mat( 3, 2 ); m[3][3] = mat( 3, 3 );
	return *this;
}

Vector4 Matrix4::operator * ( const Vector4& vec )
{
	return Vector4( m[0][0] * vec.x +  m[0][1] * vec.y +  m[0][2] * vec.w +  m[0][3] * vec.w,
					m[1][0] * vec.x +  m[1][1] * vec.y +  m[1][2] * vec.w +  m[1][3] * vec.w,
					m[2][0] * vec.x +  m[2][1] * vec.y +  m[2][2] * vec.w +  m[2][3] * vec.w,
					m[3][0] * vec.x +  m[3][1] * vec.y +  m[3][2] * vec.w +  m[3][3] * vec.w );
}

_bool Matrix4::operator == ( const Matrix4& mat ) const
{
	return	m[0][0] == mat.m[0][0] && m[0][1] == mat.m[0][1] && m[0][2] == mat.m[0][2] && m[0][3] == mat.m[0][3] &&
		m[1][0] == mat.m[1][0] && m[1][1] == mat.m[1][1] && m[1][2] == mat.m[1][2] && m[1][3] == mat.m[1][3] &&
		m[2][0] == mat.m[2][0] && m[2][1] == mat.m[2][1] && m[2][2] == mat.m[2][2] && m[2][3] == mat.m[2][3] &&
		m[3][0] == mat.m[3][0] && m[3][1] == mat.m[3][1] && m[3][2] == mat.m[3][2] && m[3][3] == mat.m[3][3];
}

Matrix4& Matrix4::Identity( )
{
	m[0][0]	= 1.0f; m[0][1] = 0.0f; m[0][2] = 0.0f; m[0][3] = 0.0f;
	m[1][0] = 0.0f; m[1][1] = 1.0f; m[1][2] = 0.0f; m[1][3] = 0.0f;
	m[2][0] = 0.0f; m[2][1] = 0.0f; m[2][2] = 1.0f; m[2][3] = 0.0f;
	m[3][0] = 0.0f; m[3][1] = 0.0f; m[3][2] = 0.0f; m[3][3] = 1.0f;

	return *this;
}

Matrix4& Matrix4::Transpose( )
{
	_float m01 = m[0][1], m02 = m[0][2], m03 = m[0][3], m10 = m[1][0], m12 = m[1][2], m13 = m[1][3],
		m20 = m[2][0], m21 = m[2][1], m23 = m[2][3], m30 = m[3][0], m31 = m[3][1], m32 = m[3][2];

	m[0][1] = m10; m[0][2] = m20; m[0][3] = m30;
	m[1][0] = m01; m[1][2] = m21; m[1][3] = m31;
	m[2][0] = m02; m[2][1] = m12; m[2][3] = m32;
	m[3][0] = m03; m[3][1] = m13; m[3][2] = m23;

	return *this;
}

Matrix4& Matrix4::Translate( _float x, _float y, _float z )
{
	m[3][0] += x;m[3][1] += y; m[3][2] += z;
	return *this;
}

Matrix4& Matrix4::RotationX( _float r )
{
	_float sinvalue = sin( r ), cosvalue = cos( r );

	m[0][0]	= 1.0f; m[0][1] =       0.0f; m[0][2] =     0.0f; m[0][3] = 0.0f;
	m[1][0] = 0.0f; m[1][1] =   cosvalue; m[1][2] = sinvalue; m[1][3] = 0.0f;
	m[2][0] = 0.0f; m[2][1] = - sinvalue; m[2][2] = cosvalue; m[2][3] = 0.0f;
	m[3][0] = 0.0f; m[3][1] =       0.0f; m[3][2] =     0.0f; m[3][3] = 1.0f;

	return *this;
}

Matrix4& Matrix4::RotationY( _float r )
{
	_float sinvalue = sin( r ), cosvalue = cos( r );

	m[0][0]	= cosvalue; m[0][1] = 0.0f; m[0][2] = - sinvalue; m[0][3] = 0.0f;
	m[1][0] =     0.0f; m[1][1] = 1.0f; m[1][2] =       0.0f; m[1][3] = 0.0f;
	m[2][0] = sinvalue; m[2][1] = 0.0f; m[2][2] =   cosvalue; m[2][3] = 0.0f;
	m[3][0] =     0.0f; m[3][1] = 0.0f; m[3][2] =       0.0f; m[3][3] = 1.0f;

	return *this;
}

Matrix4& Matrix4::RotationZ( _float r )
{
	_float sinvalue = ::sin( r ), cosvalue = ::cos( r );

	m[0][0]	=   cosvalue; m[0][1] = sinvalue; m[0][2] = 0.0f; m[0][3] = 0.0f;
	m[1][0] = - sinvalue; m[1][1] = cosvalue; m[1][2] = 0.0f; m[1][3] = 0.0f;
	m[2][0] =       0.0f; m[2][1] =     0.0f; m[2][2] = 1.0f; m[2][3] = 0.0f;
	m[3][0] =       0.0f; m[3][1] =     0.0f; m[3][2] = 0.0f; m[3][3] = 1.0f;

	return *this;
}

Matrix4& Matrix4::Rotation( const Vector3& a, _float r )
{
	_float sinvalue = ::sin( r ), cosvalue = ::cos( r ), cosreverse = 1.0f - cosvalue;

	Vector3 n( a );
	n.Normalize( );

	m[0][0] = cosreverse * n.x * n.x + cosvalue;
	m[0][1] = cosreverse * n.x * n.y + sinvalue * n.z;
	m[0][2] = cosreverse * n.x * n.z - sinvalue * n.y;
	m[0][3] = 0.0f;

	m[1][0] = cosreverse * n.x * n.y - sinvalue * n.z;
	m[1][1] = cosreverse * n.y * n.y + cosvalue;
	m[1][2] = cosreverse * n.y * n.z + sinvalue * n.x;
	m[1][3] = 0.0f;

	m[2][0] = cosreverse * n.x * n.z + sinvalue * n.y;
	m[2][1] = cosreverse * n.y * n.z - sinvalue * n.x;
	m[2][2] = cosreverse * n.z * n.z + cosvalue;
	m[2][3] = 0.0f;

	m[3][0] = 0.0f;
	m[3][1] = 0.0f;
	m[3][2] = 0.0f;
	m[3][3] = 1.0f;

	return *this;
}

Matrix4& Matrix4::Scaling( _float x, _float y, _float z )
{
	m[0][0]	=    x; m[0][1] = 0.0f; m[0][2] = 0.0f; m[0][3] = 0.0f;
	m[1][0] = 0.0f; m[1][1] =    y; m[1][2] = 0.0f; m[1][3] = 0.0f;
	m[2][0] = 0.0f; m[2][1] = 0.0f; m[2][2] =    z; m[2][3] = 0.0f;
	m[3][0] = 0.0f; m[3][1] = 0.0f; m[3][2] = 0.0f; m[3][3] = 1.0f;

	return *this;
}