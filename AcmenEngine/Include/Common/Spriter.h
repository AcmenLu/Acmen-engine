#pragma once

namespace Acmen
{
class Spriter : public RenderObject
{
public:
	Shader*		mShader;
	_dword		mVAO;
	glm::vec2	mSize;
	glm::mat4	mTransform;

public:
	Spriter( const string& filename );
	~Spriter( );
	_void InitData( const string& filename );
	_void InitShader( );
	_void BindShaderData( );
	virtual _void Render( );

};

}