#pragma once

namespace Acmen
{
class Spriter : public RenderObject
{

private:
	vector< Vertex >		mVertices;
	vector< _dword >		mIndices;
	vector< _dword >		mTextures;
	Shader*					mShader;
	_dword					mVAO;
	glm::vec2				mSize;
	glm::mat4				mTransform;

public:
	Spriter( const string& filename );
	~Spriter( );

	inline glm::vec2 GetSize( )
		{ return mSize; }
	inline glm::mat4 GetTransform( )
		{ return mTransform; }

	_void InitData( const string& filename );
	virtual _void InitVAO( );
	_void InitShader( );
	_void BindShaderData( );
	virtual _void Render( );
};

}