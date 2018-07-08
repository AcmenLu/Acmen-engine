#include "Acmen.h"

Shader::Shader( const string& vertexstr, const string& fragmentstr )
	: mShaderProgram( 0 ), mVertex( 0 ), mFragment( 0 )
{
	if ( CompileShader( vertexstr, ShaderType::SHADERTYPE_VERTEX ) == _false )
		return;

	if ( CompileShader( vertexstr, ShaderType::SHADERTYPE_FRAGMENT ) == _false )
		return;

	LinkProgrma( );
}

Shader::~Shader( )
{
	glUseProgram( 0 );
	if ( mShaderProgram > 0 )
		glDeleteProgram( mShaderProgram );

	if ( mFragment > 0 )
		glDeleteShader( mFragment );

	if ( mVertex > 0 )
		glDeleteShader( mVertex );

	mShaderProgram = 0;
	mFragment = 0;
	mVertex = 0;
}

_bool Shader::CompileShader( const string& shaderstr, ShaderType shadertype )
{
	if ( shaderstr.empty( ) == _false )
		return _false;

	const _char* shadercode = shaderstr.c_str( );
	_long success;
	_char infoLog[512];

	_dword shader = 0;

	if ( shadertype == ShaderType::SHADERTYPE_VERTEX )
	{
		shader = glCreateShader( GL_VERTEX_SHADER );
		mVertex = shader;
	}
	else if ( shadertype == ShaderType::SHADERTYPE_FRAGMENT )
	{
		shader = glCreateShader( GL_FRAGMENT_SHADER );
		mFragment = shader;
	}

	glShaderSource( shader, 1, &shadercode, NULL );
	glCompileShader( shader );
	glGetShaderiv( mFragment, GL_COMPILE_STATUS, &success );
	if ( !success )
	{
		glGetShaderInfoLog( shader, 512, NULL, infoLog );
		cout << "[ERROR]: Compile shader failed:\n" << infoLog << endl;
		return _false;
	}

	return _true;
}

_bool Shader::LinkProgrma( )
{
	if ( mVertex <= 0 || mFragment <= 0 )
		return _false;

	mShaderProgram = glCreateProgram( );
	glAttachShader( mShaderProgram, mVertex );
	glAttachShader( mShaderProgram, mFragment );
	glLinkProgram( mShaderProgram );

	_long success;
	_char infoLog[512];
	glGetProgramiv( mShaderProgram, GL_LINK_STATUS, &success );
	if ( !success )
	{
		glGetProgramInfoLog( mShaderProgram, 512, NULL, infoLog );
		cout << "[ERROR]:Link progrma failed!\n" << infoLog << endl;
		return _false;
	}
	return _true;
}

_void Shader::Use( )
{
	if ( mShaderProgram > 0 )
		glUseProgram( mShaderProgram );
}

_void Shader::SetBool( const string &name, _bool value )
{
	if ( mShaderProgram <= 0 )
		return;

	_long location = glGetUniformLocation( mShaderProgram, name.c_str( ) );
	if ( location > 0 )
		glUniform1i( location, int( value ) );
}

_void Shader::SetInt( const string &name, _long value )
{
	if ( mShaderProgram <= 0 )
		return;

	_long location = glGetUniformLocation( mShaderProgram, name.c_str( ) );
	if ( location > 0 )
		glUniform1i( location, value );
}

_void Shader::SetFloat( const string &name, _float value )
{
	if ( mShaderProgram <= 0 )
		return;

	_long location = glGetUniformLocation( mShaderProgram, name.c_str( ) );
	if ( location > 0 )
		glUniform1f( location, value );
}

_void Shader::SetVector3( const string &name, _float x, _float y, _float z )
{
	if ( mShaderProgram <= 0 )
		return;

	_long location = glGetUniformLocation( mShaderProgram, name.c_str( ) );
	if ( location >= 0 )
		glUniform3f( location, x, y, z );
}

_void Shader::SetVector3( const string &name, Vector3 vec )
{
	if ( mShaderProgram <= 0 )
		return;

	_long location = glGetUniformLocation( mShaderProgram, name.c_str( ) );
	if ( location >= 0 )
		glUniform3f( location, vec.x, vec.y, vec.z );
}

_void Shader::SetMatrix4( const string &name, _float* value, _bool transpose )
{
	if ( mShaderProgram <= 0 )
		return;

	_long location = glGetUniformLocation( mShaderProgram, name.c_str( ) );
	if ( location >= 0 )
		glUniformMatrix4fv( location, 1, transpose, value );
}