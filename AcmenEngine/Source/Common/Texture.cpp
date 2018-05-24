#include "Acmen.h"

#define STB_IMAGE_IMPLEMENTATION
#include "Common/stb_image.h"

Texture::Texture( const string& filename, _bool reversal )
	: mWidth( 0 ), mHeight( 0 ), mChannel( 0 ), mData( _null ), mResName( filename )
{
	LoadTexture( filename, reversal );
}

_dword Texture::CreateGLTexture( Texture* texture ,_dword wrap_s, _dword wrap_t, _dword min_filter, _dword mag_filter )
{
	if ( texture->mData == _null )
		return -1;

	_dword tex;
	glGenTextures( 1, &tex );
	glBindTexture( GL_TEXTURE_2D, tex );
	glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, wrap_s );
	glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, wrap_t );
	glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, min_filter );
	glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, mag_filter );

	if ( texture->GetChannel( ) == 3 )
		glTexImage2D( GL_TEXTURE_2D, 0, GL_RGB, texture->GetWidth( ), texture->GetHeight( ), 0, GL_RGB, GL_UNSIGNED_BYTE, texture->GetData( ) );
	else if ( texture->GetChannel( ) == 4 )
		glTexImage2D( GL_TEXTURE_2D, 0, GL_RGBA, texture->GetWidth( ), texture->GetHeight( ), 0, GL_RGBA, GL_UNSIGNED_BYTE, texture->GetData( ) );

	glGenerateMipmap( GL_TEXTURE_2D );
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
}