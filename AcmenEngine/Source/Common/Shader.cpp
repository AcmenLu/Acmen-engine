#include "Acmen.h"

Shader::Shader( const char* vertexPath, const char* fragmentPath )
{
	string vertexCode;
	string fragmentCode;
	ifstream vShaderFile;
	ifstream fShaderFile;
	vShaderFile.exceptions( ifstream::failbit | ifstream::badbit );
	fShaderFile.exceptions( ifstream::failbit | ifstream::badbit );

	try
	{
		vShaderFile.open( vertexPath );
		fShaderFile.open( fragmentPath );
		stringstream vShaderStream, fShaderStream;
		vShaderStream << vShaderFile.rdbuf( );
		fShaderStream << fShaderFile.rdbuf( );

		vShaderFile.close( );
		fShaderFile.close( );

		vertexCode = vShaderStream.str( );
		fragmentCode = fShaderStream.str( );
	}
	catch( ifstream::failure e )
	{
		 cout << "[ERROR]: Read file failed!" << endl;
	}

	const char* vShaderCode = vertexCode.c_str( );
	const char* fShaderCode = fragmentCode.c_str( );

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

void Shader::Use( )
{
	glUseProgram( mShaderProgram );
}

void Shader::SetBool( const string &name, bool value )
{
	int location = glGetUniformLocation( mShaderProgram, name.c_str( ) );
	if ( location > 0 )
		glUniform1i( location, int( value ) );
}

void Shader::SetInt( const string &name, int value )
{
	int location = glGetUniformLocation( mShaderProgram, name.c_str( ) );
	if ( location > 0 )
		glUniform1i( location, value );
}

void Shader::SetFloat( const string &name, float value )
{
	int location = glGetUniformLocation( mShaderProgram, name.c_str( ) );
	if ( location > 0 )
		glUniform1f( location, value );
}

void Shader::SetVector3( const string &name, float x, float y, float z )
{
	int location = glGetUniformLocation( mShaderProgram, name.c_str( ) );
	if ( location >= 0 )
		glUniform3f( location, x, y, z );
}

void Shader::SetVector3( const string &name,Vector3 vec )
{
	int location = glGetUniformLocation( mShaderProgram, name.c_str( ) );
	if ( location >= 0 )
		glUniform3f( location, vec.x, vec.y, vec.z );
}

void Shader::SetMatrix4( const string &name, float* value, bool transpose )
{
	int location = glGetUniformLocation( mShaderProgram, name.c_str( ) );
	if ( location >= 0 )
		glUniformMatrix4fv( location, 1, transpose, value );
}