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
	Texture( const string& filename );
	~Texture( );
	_void InitData( );
	_void InitShader( );
	_void LoadImage( const string& filename );
	_void BindShaderData( );
	virtual _void Render( );

};

}