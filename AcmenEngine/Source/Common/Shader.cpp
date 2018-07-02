#include "Acmen.h"

Shader::Shader( const string& vertexPath, const string& fragmentPath, _bool isFile )
	: mShaderProgram( 0 ),
	mVertex( 0 ),
	mFragment( 0 )
{
	const char* vShaderCode;
	const char* fShaderCode;
	if ( isFile )
	{
		string vertexCode;
		string fragmentCode;
		ifstream vShaderFile;
		ifstream fShaderFile;
		vShaderFile.exceptions( ifstream::failbit | ifstream::badbit );
		fShaderFile.exceptions( ifstream::failbit | ifstream::badbit );

		try
		{
			//vShaderFile.open( vertexPath );
			//fShaderFile.open( fragmentPath );
			//stringstream vShaderStream, fShaderStream;
			//vShaderStream << vShaderFile.rdbuf( );
			//fShaderStream << fShaderFile.rdbuf( );

			//vShaderFile.close( );
			//fShaderFile.close( );

			//vertexCode = vShaderStream.str( );
			//fragmentCode = fShaderStream.str( );
		}
		catch( ifstream::failure e )
		{
			 cout << "[ERROR]: Read file failed!" << endl;
		}

		vShaderCode = vertexCode.c_str( );
		fShaderCode = fragmentCode.c_str( );
	}
	else
	{
		vShaderCode = vertexPath.c_str( );
		fShaderCode = fragmentPath.c_str( );
	}

	int success;
	char infoLog[512];

	mVertex = glCreateShader( GL_VERTEX_SHADER );
	glShaderSource( mVertex, 1, &vShaderCode, NULL );
	glCompileShader( mVertex );

	glGetShaderiv( mVertex, GL_COMPILE_STATUS, &success );
	if ( !success )
	{
		glGetShaderInfoLog( mVertex, 512, NULL, infoLog );
		cout << "[ERROR]: Compile vertex shader failed:\n" << infoLog << endl;
	}

	mFragment = glCreateShader( GL_FRAGMENT_SHADER );
	glShaderSource( mFragment, 1, &fShaderCode, NULL );
	glCompileShader( mFragment );
	glGetShaderiv( mFragment, GL_COMPILE_STATUS, &success );
	if ( !success )
	{
		glGetShaderInfoLog( mFragment, 512, NULL, infoLog );
		cout << "[ERROR]: Compile fragment shader failed!\n" << infoLog << endl;
	}

	mShaderProgram = glCreateProgram( );
	glAttachShader( mShaderProgram, mVertex );
	glAttachShader( mShaderProgram, mFragment );
	glLinkProgram( mShaderProgram );

	glGetProgramiv( mShaderProgram, GL_LINK_STATUS, &success );
	if ( !success )
	{
		glGetProgramInfoLog( mShaderProgram, 512, NULL, infoLog );
		cout << "[ERROR]:Link progrma failed!\n" << infoLog << endl;
	}
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