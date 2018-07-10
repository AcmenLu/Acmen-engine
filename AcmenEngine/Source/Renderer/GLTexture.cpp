#include "Acmen.h"

GLTexture::GLTexture( const string& filename )
	:mGLId( 0 )
{
	LoadTexture( filename );
	LoadGLTexture( this );
	ReleaseData( );
}

GLTexture::GLTexture( Texture* texture )
{
	LoadGLTexture( texture );
}

GLTexture::~GLTexture( )
{
	if ( mGLId > 0 )
		glDeleteTextures( 1, &mGLId );
}

_dword GLTexture::LoadGLTexture( Texture* texture )
{
	if ( texture == _null )
		return;

	if ( mGLId > 0 )
		glDeleteTextures( 1, &mGLId );

	glGenTextures( 1, &mGLId );
	glBindTexture( GL_TEXTURE_2D, mGLId );
	glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT );
	glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT );
	glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR );
	glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR );

	if ( texture->GetChannel( ) == 3 )
		glTexImage2D( GL_TEXTURE_2D, 0, GL_RGB, texture->GetWidth( ), texture->GetHeight( ), 0, GL_RGB, GL_UNSIGNED_BYTE, texture->GetData( ) );
	else if ( texture->GetChannel( ) == 4 )
		glTexImage2D( GL_TEXTURE_2D, 0, GL_RGBA, texture->GetWidth( ), texture->GetHeight( ), 0, GL_RGBA, GL_UNSIGNED_BYTE, texture->GetData( ) );

	glGenerateMipmap( GL_TEXTURE_2D );
	return mGLId;
}