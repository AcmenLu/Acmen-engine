#include "Acmen.h"

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

Texture::Texture( const string& filename )
{
	mTransform = glm::mat4( );
	InitData( );
	InitShader( );
	LoadImage( filename );
	BindShaderData( );
}

Texture::~Texture( )
{
	if ( mShader != _null )
	{
		mShader->~Shader( );
		delete mShader;
	}
}

_void Texture::InitData( )
{
	_float vertices[] = {
		0.5f,  0.5f, 1.0f, 1.0f,
		0.5f, -0.5f, 1.0f, 0.0f,
		-0.5f, -0.5f, 0.0f, 0.0f,
		-0.5f, 0.5f, 0.0f, 1.0f
	};

	_dword indices[] = {
		0, 1, 3,
		1, 2, 3
	};
	_dword VBO;
	glGenBuffers( 1, &VBO );
	glGenVertexArrays( 1, &mVAO );
	glBindVertexArray( mVAO );

	glBindBuffer( GL_ARRAY_BUFFER, VBO );
	glBufferData( GL_ARRAY_BUFFER, sizeof( vertices ), vertices, GL_STATIC_DRAW );

	_dword EBO;
	glGenBuffers( 1, &EBO );
	glBindBuffer( GL_ELEMENT_ARRAY_BUFFER, EBO );
	glBufferData( GL_ELEMENT_ARRAY_BUFFER, sizeof( indices ), indices, GL_STATIC_DRAW );

	glEnableVertexAttribArray( 0 );
	glVertexAttribPointer( 0, 4, GL_FLOAT, GL_FALSE, 4 * sizeof( _float ), (_void*)0 );
}

_void Texture::InitShader( )
{
	string vsstr = "#version 330 core\n" \
					"layout (location = 0) in vec4 vertex;\n" \
					"out vec2 TexCoords;\n" \
					"void main()\n" \
					"{\n" \
					"TexCoords = vertex.zw;\n" \
					"gl_Position = vec4(vertex.xy, 0.0, 1.0);\n" \
					"}";

	string psstr = "#version 330 core\n" \
					"out vec4 FragColor;\n" \
					"in vec2 TexCoords;\n" \
					"uniform sampler2D image;\n" \
					"void main()\n" \
					"{\n" \
					"FragColor = texture(image, TexCoords);\n" \
					"}\n";
	mShader = new Shader( vsstr, psstr, _false );
}

_void Texture::BindShaderData( )
{
	if ( mShader == _null )
		return;

	mShader->Use( );
	mShader->SetInt( "image", 0 );

}
_void Texture::LoadImage( const string& filename )
{
	glGenTextures( 1, &mTexture );
	glBindTexture( GL_TEXTURE_2D, mTexture );

	glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT );
	glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT );
	glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR );
	glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR );

	int width, height, nrChannels;
	stbi_set_flip_vertically_on_load( true );
	unsigned char* data = stbi_load( filename.c_str( ), &width, &height, &nrChannels, 0 );
	if ( data )
	{
		if ( nrChannels == 3 )
			glTexImage2D( GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data );
		else if (nrChannels == 4 )
			glTexImage2D( GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data );

		glGenerateMipmap( GL_TEXTURE_2D );
	}
	stbi_image_free( data );
}

_void Texture::Render( )
{
	mShader->Use( );
	glActiveTexture( GL_TEXTURE0 );
	glBindTexture( GL_TEXTURE_2D, mTexture );

	glBindVertexArray( mVAO );
	glDrawElements( GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0 );
	glBindVertexArray( 0 );
}