#include "Acmen.h"

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

Texture::Texture( const string& filename )
{

	mResName = filename;
}

_void Texture::LoadTexture( _bool reversal )
{
	_long width, height, nrChannels;
	//stbi_set_flip_vertically_on_load( _true );
	unsigned char* data = stbi_load( filename.c_str( ), &width, &height, &nrChannels, 0 );
	if ( data )
	{
		if ( nrChannels == 3 )
			glTexImage2D( GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data );
		else if (nrChannels == 4 )
			glTexImage2D( GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data );

		glGenerateMipmap( GL_TEXTURE_2D );
	}
	mSize = glm::vec2( width, height );
}