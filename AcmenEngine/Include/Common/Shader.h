#pragma once

namespace Acmen
{

class Shader
{
public:
	_dword mShaderProgram;

	Shader( const string& vertexPath, const string& fragmentPath, _bool isFile );
	inline ~Shader( )
		{ }

	_void Use( );
	_void SetBool( const string &name, _bool value );
	_void SetInt( const string &name, _long value );
	_void SetFloat( const string &name, _float value );
	_void SetVector3( const string &name, _float x, _float y, _float z );
	_void SetVector3( const string &name, Vector3 vec );
	_void SetMatrix4( const string &name, _float* value, _bool transpose = false );
};

};