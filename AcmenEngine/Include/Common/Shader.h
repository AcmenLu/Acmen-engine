#pragma once

namespace Acmen
{

class Shader
{
public:
	_dword mShaderProgram;

	Shader( const char* vertexPath, const char* fragmentPath );
	inline ~Shader( )
		{ }

	_void Use( );
	_void SetBool( const string &name, _bool value );
	_void SetInt( const string &name, _long value );
	_void SetFloat( const string &name, _float value );
	_void Shader::SetVector3( const string &name, _float x, _float y, _float z );
	_void Shader::SetVector3( const string &name, Vector3 vec );
	_void SetMatrix4( const string &name, _float* value, _bool transpose = false );
};

};