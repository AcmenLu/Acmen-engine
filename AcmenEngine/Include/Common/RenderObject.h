#pragma once

namespace Acmen
{

struct Vertex
{
	Vector3 Position;
	Vector3 Normal;
	Vector2 TexCoord;

	inline Vertex( )
		: Position( Vector3( ) ), Normal( Vector3( ) ), TexCoord( Vector2( ) ){ }
	inline Vertex( _float px, _float py, _float pz, _float nx, _float ny, _float nz, _float tx, _float ty )
	{
		Position = Vector3( px, py, pz );
		Normal = Vector3( nx, ny, nz );
		TexCoord = Vector2( tx, ty );
	}

	inline Vertex( Vector3 vecP, Vector3 vecN, Vector2 vecT )
		: Position( vecP ), Normal( vecN ), TexCoord( vecT ){ }
};

class RenderObject
{
protected:
	vector< Vertex >		mVertices;
	vector< _dword >		mIndices;
	Shader*					mShader;
	_dword					mVAO;
	_dword					mVBO;
	_dword					mEBO;

public:
	inline RenderObject( ) 
		: mShader( _null ), mVAO( 0 ), mVBO( 0 ), mEBO( 0 ){ }
	~RenderObject( );

	_bool CreatGeometry( );
	virtual _void Render( ) = 0;
};

};