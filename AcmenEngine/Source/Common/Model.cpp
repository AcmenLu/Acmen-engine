#include "Acmen.h"

#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>

#pragma comment( lib, "assimpd" )
#pragma comment( lib, "zlibstaticd" )

Model::Model( const string& filename ): mResName( filename )
{
	LoadModel( filename );
}

_void Model::Render( _float elapse )
{
	if ( mMeshs.size( ) <= 0 )
		return;

	for ( _dword i = 0; i < mMeshs.size( ); i ++ )
		mMeshs[i]->Render( elapse );
}

_void Model::LoadModel( const string& filename )
{
	if ( filename.size( ) <= 0 )
		return;
	mResName = filename;
	Assimp::Importer importer;
	const aiScene* scene = importer.ReadFile( filename, aiProcess_Triangulate | aiProcess_FlipUVs | aiProcess_CalcTangentSpace );

	if( !scene || scene->mFlags & AI_SCENE_FLAGS_INCOMPLETE || !scene->mRootNode )
	{
		cout << "ERROR::ASSIMP:: " << importer.GetErrorString() << endl;
		return;
	}
	processNode( (_void*)(scene->mRootNode), (_void*)scene );
}

_void Model::processNode( _void* node, _void* scene )
{
	aiNode* mnode = (aiNode*)node;
	aiScene* mscene = (aiScene*)scene;
	if ( mnode == _null || mscene == _null )
		return;

	for( _dword i = 0; i < mnode->mNumMeshes; i++ )
	{
		aiMesh* mesh = mscene->mMeshes[mnode->mMeshes[i]];
		Mesh* mmesh = processMesh( mesh, scene );
		if ( mmesh != _null )
			mMeshs.push_back( mmesh );
	}
	
	for( _dword i = 0; i < mnode->mNumChildren; i++ )
		processNode( (_void*)mnode->mChildren[i], scene );
}

Mesh* Model::processMesh( _void* mesh, _void* scene )
{
	aiMesh* mmesh = (aiMesh*)mesh;
	aiScene* mscene = (aiScene*)scene;
	if ( mmesh == _null || mscene == _null )
		return _null;
	
	if ( mmesh->mNumFaces <= 0 )
		return _null;

	vector< Vertex > vertices;
	for( _dword i = 0; i < mmesh->mNumVertices; i++ )
	{
		Vertex vec;
		vec.Position = Vector3( mmesh->mVertices[i].x, mmesh->mVertices[i].y, mmesh->mVertices[i].z );
		vec.Normal = Vector3( mmesh->mNormals[i].x, mmesh->mNormals[i].y, mmesh->mNormals[i].z );
		if ( mmesh->mTextureCoords[0] != _null )
			vec.TexCoord = Vector2( mmesh->mTextureCoords[0][i].x, mmesh->mTextureCoords[0][i].y );
		else
			vec.TexCoord = Vector2( 0.0f, 0.0f );
		vertices.push_back( vec );
	}

	vector< _dword > indices;
	for ( _dword i = 0; i < mmesh->mNumFaces; i++ )
	{
		aiFace face = mmesh->mFaces[i];
		for ( _dword j = 0; j < face.mNumIndices; j++ )
			indices.push_back( face.mIndices[j] );
	}
	aiMaterial* material = mscene->mMaterials[mmesh->mMaterialIndex];
	vector<Texture*> normals = loadMaterialTextures( material, aiTextureType_AMBIENT );
	vector<Texture*> diffuses = loadMaterialTextures( material, aiTextureType_DIFFUSE );
	vector<Texture*> speculars = loadMaterialTextures( material, aiTextureType_SPECULAR );
	vector<Texture*> height = loadMaterialTextures( material, aiTextureType_HEIGHT );
	Material* mats = new Material( normals, diffuses, speculars, height );
	return new Mesh( vertices, indices, mats );
}

vector<Texture*> Model::loadMaterialTextures( _void *mat, _dword type )
{
	aiMaterial* material = (aiMaterial*) mat;
	vector<Texture*> textures;
	for ( _dword i = 0; i < material->GetTextureCount( (aiTextureType)type ); i++ )
	{
		aiString str;
		material->GetTexture( (aiTextureType)type, i, &str );
		string path = mResName.substr( 0, mResName.find_last_of( '/' ) );
		Texture* tex = new Texture( path + str.C_Str( ) );
		textures.push_back( tex );
	}
	return textures;
}