#pragma once

namespace Acmen
{

struct Vertex
{
	glm::vec3 Position;
	glm::vec3 Normal;
	glm::vec2 TexCoord;
};

class RenderObject
{

public:
	vector< Vertex >		mVertices;
	vector< _dword >		mIndices;
	vector< Texture >		mTextures;
	Shader*					mShader;
	glm::mat4				mTransform;
	_dword					mVAO;

public:
	inline RenderObject( ){}
	inline ~RenderObject( ){}
	virtual _void InitData( ) = 0;
	virtual _void InitVAO( );
	virtual _void InitShader( ) = 0;
	virtual _void Render( ) = 0;
};

};