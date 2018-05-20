#include "Acmen.h"

Material::~Material( )
{
	if ( mNormalMap != _null )
		delete mNormalMap;

	if ( mDiffuseMap != _null )
		delete mDiffuseMap;

	if ( mSpecularMap != _null )
		delete mSpecularMap;

	if ( mHeightMap != _null )
		delete mHeightMap;
}

_void Material::SetNormalMap( Texture* texture )
{
	if ( mNormalMap != _null )
		delete mNormalMap;

	mNormalMap = texture;
	if ( texture != _null )
		mNormalMapId = Texture::CreateGLTexture( mNormalMap );
}

_void Material::SetDiffuseMap( Texture* texture )
{
	if ( mDiffuseMap != _null )
		delete mDiffuseMap;

	mDiffuseMap = texture;
	if ( texture != _null )
		mDiffuseMapId = Texture::CreateGLTexture( mDiffuseMap );
}

_void Material::SetSpecularMap( Texture* texture )
{
	if ( mSpecularMap != _null )
		delete mSpecularMap;

	mSpecularMap = texture;
	if ( texture != _null )
		mSpecularMapId = Texture::CreateGLTexture( mSpecularMap );
}

_void Material::SetHeightMap( Texture* texture )
{
	if ( mHeightMap != _null )
		delete mHeightMap;

	mHeightMap = texture;
	if ( texture != _null )
		mHeightMapId = Texture::CreateGLTexture( mHeightMap );
}