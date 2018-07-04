#include "Acmen.h"

#define STB_IMAGE_IMPLEMENTATION
#include "Common/stb_image.h"

Texture::Texture( const string& filename, _bool reversal )
	: mWidth( 0 ), mHeight( 0 ), mChannel( 0 ), mData( _null ), mResName( filename ),mGLId( 0 )
{
	LoadTexture( filename, reversal );
}

_dword Texture::CreateGLTexture( const string& filename, _dword wrap_s, _dword wrap_t, _dword min_filter, _dword mag_filter )
{
	_long width, height, channel;
	_chara* data = stbi_load( filename.c_str( ), &width, &height, &channel, 0 );
	if ( data == _null )
		return 0;

	_dword tex;
	glGenTextures( 1, &tex );
	glBindTexture( GL_TEXTURE_2D, tex );
	glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, wrap_s );
	glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, wrap_t );
	glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, min_filter );
	glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, mag_filter );

	if ( channel == 3 )
		glTexImage2D( GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data );
	else if ( channel == 4 )
		glTexImage2D( GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data );

	glGenerateMipmap( GL_TEXTURE_2D );
	stbi_image_free( data );
	return tex;
}

Texture::~Texture( )
{
	if ( mData != _null )
		stbi_image_free( mData );

	mData = _null;
}

_void Texture::LoadTexture( const string& filename, _bool reversal )
{
	mResName = filename;
	if ( reversal )
		stbi_set_flip_vertically_on_load( _true );

	mData = stbi_load( filename.c_str( ), &mWidth, &mHeight, &mChannel, 0 );

	glGenTextures( 1, &mGLId );
	glBindTexture( GL_TEXTURE_2D, mGLId );
	glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT );
	glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT );
	glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR );
	glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR );

	if ( mChannel == 3 )
		glTexImage2D( GL_TEXTURE_2D, 0, GL_RGB, mWidth, mHeight, 0, GL_RGB, GL_UNSIGNED_BYTE, mData );
	else if ( mChannel == 4 )
		glTexImage2D( GL_TEXTURE_2D, 0, GL_RGBA, mWidth, mHeight, 0, GL_RGBA, GL_UNSIGNED_BYTE, mData );

	glGenerateMipmap( GL_TEXTURE_2D );
}