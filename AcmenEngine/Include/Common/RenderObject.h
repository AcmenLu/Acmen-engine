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
	_bool					mIsInited;
	_dword					mVAO;
	_dword					mVBO;
	_dword					mEBO;

public:
	inline RenderObject( ) 
		: mVertices( vector< Vertex >( ) ), mIndices( vector< _dword >( ) ), mShader( _null ),mIsInited( _false ), mVAO( 0 ), mVBO( 0 ), mEBO( 0 ){ }
	RenderObject( vector< Vertex > vertices, vector< _dword > indices );
	~RenderObject( );

	inline vector< Vertex >& GetVertices( )
		{ return mVertices; }
	inline _void SetVertices( vector< Vertex > vertices )
		{ mVertices.assign( vertices.begin( ), vertices.end( ) ); }

	inline vector< _dword >& GetIndices( )
		{ return mIndices; }
	inline _void SetIndices( vector< _dword > indices )
		{ mIndices.assign( indices.begin( ), indices.end( ) ); }

	inline Shader* GetShader( )
		{ return mShader; }
	inline _void SetShader( Shader* shader )
		{ mShader = shader; }

	inline _dword GetVAO( )
		{ return mVAO; }
	inline _dword GetVBO( )
		{ return mVBO; }
	inline _dword GetEBO( )
		{ return mEBO; }

	_bool Init( );
	_bool CreateGeometry( );
	virtual _bool CreateShader( ){ return _true; };
	virtual _bool SetUniform( ){ return _true; };
	virtual _void Update( _float elapse ) = 0;
	virtual _void Render( _float elapse ) = 0;
};

};