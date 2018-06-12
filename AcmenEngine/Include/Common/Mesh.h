#pragma once

namespace Acmen
{

class Mesh : public RenderObject
{

private:
	vector< Vertex >		mVertices;
	vector< _dword >		mIndices;
	Material*				mMaterial;
	Shader*					mShader;
	_dword					mVAO;
	string					mResName;
	_bool					mIsInited;

public:
	Matrix4					mTransform;

public:
	inline Mesh( )
		: mTransform( Matrix4( ) ),mShader( _null ), mVAO( 0 ), mResName( "" ), mIsInited( _false ){ }
	Mesh( const String& filename )
		: mMaterial( _null ), mShader( _null ), mVAO( 0 ), mResName( "" ), mIsInited( _false ){ }
	Mesh( vector< Vertex > vertices, vector< _dword > indices, Material* material );
	~Mesh( );

	inline string GetResName( )
		{ return mResName; }
	inline Matrix4 GetTransform( )
		{ return mTransform; }

	inline _void SetVertexs( vector< Vertex > vertices )
		{ mVertices = vertices; }
	inline vector<Vertex>& GetVertexs( )
		{ return mVertices; }

	inline _void SetIndices( vector< _dword > indices )
		{ mIndices = indices; }
	inline vector< _dword >& GetIndices( )
		{ return mIndices; }

	_void InitMesh( );
	_void InitVAO( );
	_void InitShader( );
	_void BindShaderData( );
	_void Render( );
};

};