#pragma once

#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>

namespace Acmen
{

class Mesh : public RenderObject
{

private:
	vector< Vertex >		mVertices;
	vector< _dword >		mIndices;
	vector< Mesh* >			mMeshs;
	Material*				mMaterial;
	Shader*					mShader;
	_dword					mVAO;
	string					mResName;

public:
	Matrix4					mTransform;

public:
	Mesh( const string& filename );
	Mesh( vector< Vertex > vertices, vector< _dword > indices, Material* material );
	~Mesh( );

	inline string GetResName( )
		{ return mResName; }
	inline Matrix4 GetTransform( )
		{ return mTransform; }

	_void InitData( const string& filename );
	virtual _void InitVAO( );
	_void InitShader( );
	_void BindShaderData( );
	virtual _void Render( );

private:
	_void ProcessNode( aiNode *node, const aiScene *scene );
	Mesh* ProcessMesh( aiMesh *mesh, const aiScene *scene );
	Texture* LoadMaterialTexture( aiMaterial *mat, aiTextureType type );
};

};