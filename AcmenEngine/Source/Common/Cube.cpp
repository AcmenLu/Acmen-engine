#include "Acmen.h"

Cube::Cube( )
{
	mTransform = glm::mat4( );
	InitData( );
	InitShader( );
	BindShaderData( );
}

Cube::~Cube( )
{
	if ( mShader != _null )
	{
		mShader->~Shader( );
		delete mShader;
	}
}

_void Cube::InitData( )
{

}
