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
	glm::mat4				mTransform;

public:
	Spriter( const string& filename );
	~Spriter( );

	inline glm::vec2 GetSize( )
		{ return glm::vec2( mTransform[0][0], mTransform[1][1] ); }
	_void SetSize( _float x, _float y );

	inline glm::vec2 GetPosition( )
		{ return glm::vec2( mTransform[3][0], mTransform[3][1] ); }
	_void SetPosition( _float x, _float y );


	inline glm::mat4 GetTransform( )
		{ return mTransform; }

	_void InitData( const string& filename );
	virtual _void InitVAO( );
	_void InitShader( );
	_void BindShaderData( );
	virtual _void Render( );
};

}