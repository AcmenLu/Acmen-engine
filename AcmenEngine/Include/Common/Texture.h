#pragma once

namespace Acmen
{
class Texture : public RenderObject
{
public:
	Shader*		mShader;
	_dword		mVAO;
	_dword		mTexture;
	glm::mat4	mTransform;

public:
	Texture( );
	~Texture( );
	_void InitData( );
	_void InitShader( );
	_void Render( );
	_void LoadImage( const string& filename );

};

}