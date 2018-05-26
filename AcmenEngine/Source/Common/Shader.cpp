#include "Acmen.h"

Shader::Shader( const string& vertexPath, const string& fragmentPath, _bool isFile )
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
	unsigned int vertex, fragment;
	int success;
	char infoLog[512];

	vertex = glCreateShader( GL_VERTEX_SHADER );
	glShaderSource( vertex, 1, &vShaderCode, NULL );
	glCompileShader( vertex );

	glGetShaderiv( vertex, GL_COMPILE_STATUS, &success );
	if ( !success )
	{
		glGetShaderInfoLog( vertex, 512, NULL, infoLog );
		cout << "[ERROR]: Compile vertex shader failed:\n" << infoLog << endl;
	}

	fragment = glCreateShader( GL_FRAGMENT_SHADER );
	glShaderSource( fragment, 1, &fShaderCode, NULL );
	glCompileShader( fragment );
	glGetShaderiv( fragment, GL_COMPILE_STATUS, &success );
	if ( !success )
	{
		glGetShaderInfoLog( fragment, 512, NULL, infoLog );
		cout << "[ERROR]: Compile fragment shader failed!\n" << infoLog << endl;
	}

	mShaderProgram = glCreateProgram( );
	glAttachShader( mShaderProgram, vertex );
	glAttachShader( mShaderProgram, fragment );
	glLinkProgram( mShaderProgram );

	glGetProgramiv( mShaderProgram, GL_LINK_STATUS, &success );
	if ( !success )
	{
		glGetProgramInfoLog( mShaderProgram, 512, NULL, infoLog );
		cout << "[ERROR]:Link progrma failed!\n" << infoLog << endl;
	}

	glDeleteShader( vertex );
	glDeleteShader( fragment );
}

_void Shader::Use( )
{
	glUseProgram( mShaderProgram );
}

_void Shader::SetBool( const string &name, _bool value )
{
	int location = glGetUniformLocation( mShaderProgram, name.c_str( ) );
	if ( location > 0 )
		glUniform1i( location, int( value ) );
}

_void Shader::SetInt( const string &name, _long value )
{
	int location = glGetUniformLocation( mShaderProgram, name.c_str( ) );
	if ( location > 0 )
		glUniform1i( location, value );
}

_void Shader::SetFloat( const string &name, _float value )
{
	int location = glGetUniformLocation( mShaderProgram, name.c_str( ) );
	if ( location > 0 )
		glUniform1f( location, value );
}

_void Shader::SetVector3( const string &name, _float x, _float y, _float z )
{
	int location = glGetUniformLocation( mShaderProgram, name.c_str( ) );
	if ( location >= 0 )
		glUniform3f( location, x, y, z );
}

_void Shader::SetVector3( const string &name, Vector3 vec )
{
	int location = glGetUniformLocation( mShaderProgram, name.c_str( ) );
	if ( location >= 0 )
		glUniform3f( location, vec.x, vec.y, vec.z );
}

_void Shader::SetMatrix4( const string &name, _float* value, _bool transpose )
{
	int location = glGetUniformLocation( mShaderProgram, name.c_str( ) );
	if ( location >= 0 )
		glUniformMatrix4fv( location, 1, transpose, value );
}