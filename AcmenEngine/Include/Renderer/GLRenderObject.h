#pragma once

namespace Acmen
{

struct Vertex
{
	Vector3 Position;
	Vector3 Normal;
	Vector2 TexCoord;
	Vector4 Color;

	inline Vertex( )
		: Position( Vector3( ) ), Normal( Vector3( ) ), TexCoord( Vector2( ) ), Color( Vector4( ) ) { }
	inline Vertex( _float px, _float py, _float pz, _float nx, _float ny, _float nz, _float tx, _float ty, _float cx, _float cy, _float cz, _float cw )
	{
		Position = Vector3( px, py, pz );
		Normal = Vector3( nx, ny, nz );
		TexCoord = Vector2( tx, ty );
		Color = Vector4( cx, cy, cz, cw );
	}

	inline Vertex( Vector3 vecP, Vector3 vecN, Vector2 vecT, Vector4 vecC )
		: Position( vecP ), Normal( vecN ), TexCoord( vecT ), Color( vecC ){ }
};

struct ShaderParms
{
	_bool UseNormal;
	_bool UseTexCoord;
	_bool UseColor;
	inline ShaderParms( )
		:UseNormal( _false ), UseTexCoord( _false ), UseColor( _true ){ }
};

class GLRenderObject : public RenderObject
{

protected:
	vector< Vertex >		mVertices;
	vector< _dword >		mIndices;
	Shader*					mShader;
	_dword					mVAO;
	_dword					mVBO;
	_dword					mEBO;
	ShaderParms				mShaderParms;

public:
	inline GLRenderObject( ) 
		: mVertices( vector< Vertex >( ) ), mIndices( vector< _dword >( ) ), mShader( _null ), mVAO( 0 ), mVBO( 0 ), mEBO( 0 ), mShaderParms( ShaderParms( ) ){ }
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

	virtual _dword GetVAO( )
		{ return mVAO; }
	virtual _dword GetVBO( )
		{ return mVBO; }
	virtual _dword GetEBO( )
		{ return mEBO; }

	virtual _void OnRender( _float elapse ) = 0;
	virtual _bool CreateGeometry( );
	virtual _bool CreateShader( );
	virtual _bool SetUniform( ){ return _true; }
};

}