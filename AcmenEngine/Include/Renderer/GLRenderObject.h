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

class GLRenderObject : public RenderObject
{

protected:
	vector< Vertex >		mVertices;
	vector< _dword >		mIndices;
	Shader*					mShader;
	Matrix4					mTransform;
	_dword					mVAO;
	_dword					mVBO;
	_dword					mEBO;

public:
	inline GLRenderObject( ) 
		: mVertices( vector< Vertex >( ) ), mIndices( vector< _dword >( ) ), mShader( _null ), mTransform( Matrix4( ) ), mVAO( 0 ), mVBO( 0 ), mEBO( 0 ){ }
	GLRenderObject( vector< Vertex > vertices, vector< _dword > indices );
	~GLRenderObject( );

	virtual vector< Vertex >& GetVertices( )
	{ return mVertices; }
	virtual _void SetVertices( vector< Vertex > vertices )
	{ mVertices.assign( vertices.begin( ), vertices.end( ) ); }

	virtual vector< _dword >& GetIndices( )
	{ return mIndices; }
	virtual _void SetIndices( vector< _dword > indices )
	{ mIndices.assign( indices.begin( ), indices.end( ) ); }

	virtual Shader* GetShader( )
	{ return mShader; }
	virtual _void SetShader( Shader* shader )
	{ mShader = shader; }

	virtual Matrix4& GetTransform( )
	{ return mTransform; }
	virtual _void SetTransform( Matrix4& mat4 )
	{ mTransform = mat4; }

	virtual _dword GetVAO( )
	{ return mVAO; }
	virtual _dword GetVBO( )
	{ return mVBO; }
	virtual _dword GetEBO( )
	{ return mEBO; }
};

}