#pragma once

namespace Acmen
{
class Spriter : public RenderObject
{
public:
	Shader*		mShader;
	_dword		mVAO;
	_dword		mTexture;
	glm::vec2	mSize;
	glm::mat4	mTransform;

public:
	Spriter( const string& filename );
	~Spriter( );
	_void InitData( );
	_void InitShader( );
	_void LoadImage( const string& filename );
	_void BindShaderData( );
	virtual _void Render( );

};

}