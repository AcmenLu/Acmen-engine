#include "Acmen.h"

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

Texture::Texture( )
{
	mTransform = glm::mat4( );
	InitData( );
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
	_dword VBO;
	_float vertices[] = {
		0.0f, 1.0f, 0.0f, 1.0f,
		1.0f, 0.0f, 1.0f, 0.0f,
		0.0f, 0.0f, 0.0f, 0.0f, 

		0.0f, 1.0f, 0.0f, 1.0f,
		1.0f, 1.0f, 1.0f, 1.0f,
		1.0f, 0.0f, 1.0f, 0.0f
	};

	glGenVertexArrays( 1, &mVAO );
	glGenBuffers( 1, &VBO );

	glBindBuffer( GL_ARRAY_BUFFER, VBO );
	glBufferData( GL_ARRAY_BUFFER, sizeof( vertices ), vertices, GL_STATIC_DRAW );

	glBindVertexArray( mVAO );
	glEnableVertexAttribArray( 0 );
	glVertexAttribPointer( 0, 4, GL_FLOAT, GL_FALSE, 4 * sizeof( _float ), (_void*)0 );

	glBindBuffer( GL_ARRAY_BUFFER, 0 );
	glBindVertexArray( 0 );
}

_void Texture::InitShader( )
{
	string vsstr = "#version 330 core" \
					"layout (location = 0) in vec4 vertex;" \
					"out vec2 TexCoords;" \
					"uniform mat4 transform;" \
					"void main()" \
					"{" \
					"TexCoords = vertex.zw;" \
					"gl_Position = transform * vec4(vertex.xy, 0.0, 1.0);" \
					"}";

	string psstr = "#version 330 core" \
					"in vec2 TexCoords;" \
					"out vec4 color;" \
					"uniform sampler2D image;" \
					"uniform vec3 spriteColor;" \
					"void main()" \
					"{" \
					"color = vec4(spriteColor, 1.0) * texture(image, TexCoords);" \
					"}";
	mShader = new Shader( vsstr, psstr, _false );
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
	mShader->Use();
	glm::mat4 transform = Windows::GetInstance( )->GetProjection( ) * mTransform;
	mShader->SetMatrix4( "transform", glm::value_ptr( transform ) );

	glActiveTexture( GL_TEXTURE0 );
	glBindTexture( GL_TEXTURE_2D, mTexture );

	glBindVertexArray( mVAO );
	glDrawArrays( GL_TRIANGLES, 0, 6 );
	glBindVertexArray( 0 );
}