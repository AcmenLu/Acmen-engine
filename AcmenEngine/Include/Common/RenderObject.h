#pragma once

namespace Acmen
{

struct Vertex
{
	glm::vec3 Position;
	glm::vec3 Normal;
	glm::vec2 TexCoord;

	inline Vertex( _float px, _float py, _float pz, _float nx, _float ny, _float nz, _float tx, _float ty )
	{
		Position = glm::vec3( px, py, pz );
		Normal = glm::vec3( nx, ny, nz );
		TexCoord = glm::vec2( tx, ty );
	}

	inline Vertex( glm::vec3 vecP, glm::vec3 vecN, glm::vec2 vecT )
		: Position( vecP ), Normal( vecN ), TexCoord( vecT ){ }
};

class RenderObject
{

public:
	vector< Vertex >		mVertices;
	vector< _dword >		mIndices;
	vector< _dword >		mTextures;
	Shader*					mShader;
	glm::mat4				mTransform;
	_dword					mVAO;

public:
	inline RenderObject( ){ }
	inline ~RenderObject( ){ }

	virtual _void InitVAO( ) = 0;

	_void InitData( ){ };
	_void InitShader( ){};
	virtual _void Render( ) = 0;
};

};