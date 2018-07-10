#include "Acmen.h"

#define STB_IMAGE_IMPLEMENTATION
#include "Common/stb_image.h"

Texture::Texture( const string& filename, _bool reversal )
	: mWidth( 0 ), mHeight( 0 ), mChannel( 0 ), mData( _null ), mResName( filename )
{
	LoadTexture( filename, reversal );
}

Texture::~Texture( )
{
	mWidth = 0;
	mHeight = 0;
	mChannel = 0;
	ReleaseData( );
}

_void Texture::LoadTexture( const string& filename, _bool reversal )
{
	mResName = filename;
	if ( reversal )
		stbi_set_flip_vertically_on_load( _true );

	mData = stbi_load( filename.c_str( ), &mWidth, &mHeight, &mChannel, 0 );
}

_void Texture::ReleaseData( )
{
	if ( mData != _null )
		stbi_image_free( mData );

	mData = _null;
}