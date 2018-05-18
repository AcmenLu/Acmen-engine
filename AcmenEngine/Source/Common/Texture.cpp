#include "Acmen.h"

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

Texture::~Texture( )
{
	if ( mData != _null )
		stbi_image_free( mData );

	if ( mData != _null )
		delete mData;

	mData = _null;
}

_void Texture::LoadTexture( _bool reversal )
{
	if ( mResName == "" )
		return;

	LoadTexture( mResName, reversal );
}

_void Texture::LoadTexture( const string& filename, _bool reversal )
{
	mResName = filename;
	if ( reversal )
		stbi_set_flip_vertically_on_load( _true );

	mData = stbi_load( filename.c_str( ), &mWidth, &mHeight, &mChannel, 0 );
}

_dword Texture::CreateGLTexture( _dword wrap_s, _dword wrap_t, _dword min_filter, _dword mag_filter )
{
	_dword texture;
	glGenTextures( 1, &texture );
	glBindTexture( GL_TEXTURE_2D, texture );

	glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, wrap_s );
	glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, wrap_t );
	glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, min_filter );
	glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, mag_filter );

	if ( mChannel == 3 )
		glTexImage2D( GL_TEXTURE_2D, 0, GL_RGB, mWidth, mHeight, 0, GL_RGB, GL_UNSIGNED_BYTE, mData );
	else if ( mChannel == 4 )
		glTexImage2D( GL_TEXTURE_2D, 0, GL_RGB, mWidth, mHeight, 0, GL_RGBA, GL_UNSIGNED_BYTE, mData );

	glGenerateMipmap( GL_TEXTURE_2D );
}