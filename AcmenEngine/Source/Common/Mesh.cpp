#include "Acmen.h"

#pragma comment( lib, "assimp" )

Mesh::Mesh( const string& filename ) : mMaterial( _null ), mShader( _null )
{
	InitData( filename );
}

Mesh::Mesh( vector< Vertex > vertices, vector< _dword > indices, Material* material )
	: mVertices( vertices ), mIndices( indices ), mMaterial( material )
{
	InitVAO( );
	InitShader( );
	BindShaderData( );
}

Mesh::~Mesh( )
{
	if ( mShader != _null )
		delete mShader;

	if ( mMaterial != _null )
		delete mMaterial;

	for ( _dword i = 0; i < mMeshs.size( ); i ++ )
		delete mMeshs[i];
}

_void Mesh::InitData( const string& filename )
{
	mResName = filename;
	Assimp::Importer import;
	const aiScene *scene = import.ReadFile( filename, aiProcess_Triangulate | aiProcess_FlipUVs );
	if( !scene || scene->mFlags & AI_SCENE_FLAGS_INCOMPLETE || !scene->mRootNode ) 
	{
		cout << "ERROR::ASSIMP::" << import.GetErrorString() << endl;
		return;
	}

	ProcessNode( scene->mRootNode, scene );
}

_void Mesh::InitVAO( )
{
	if ( mVertices.size( ) <= 0 )
		return;

	glGenVertexArrays( 1, &mVAO );
	glBindVertexArray( mVAO );

	_dword VBO;
	glGenBuffers( 1, &VBO );
	glBindBuffer( GL_ARRAY_BUFFER, VBO );
	glBufferData( GL_ARRAY_BUFFER, mVertices.size( ) * sizeof( Vertex ), &mVertices[0], GL_STATIC_DRAW );

	_dword EBO;
	glGenBuffers( 1, &EBO );
	glBindBuffer( GL_ELEMENT_ARRAY_BUFFER, EBO );
	glBufferData( GL_ELEMENT_ARRAY_BUFFER, mIndices.size( ) * sizeof( _dword ), &mIndices[0], GL_STATIC_DRAW );

	// Position
	glVertexAttribPointer( 0, 3, GL_FLOAT, GL_FALSE, sizeof( Vertex ), (_void*)0 );
	glEnableVertexAttribArray( 0 );
	// Normal
	glVertexAttribPointer( 1, 3, GL_FLOAT, GL_FALSE, sizeof( Vertex ), (_void*)offsetof( Vertex, Normal ) );
	glEnableVertexAttribArray( 1 );
	// Texcoord
	glVertexAttribPointer( 2, 2, GL_FLOAT, GL_FALSE, sizeof( Vertex ), (_void*)offsetof( Vertex, TexCoord ) );
	glEnableVertexAttribArray( 2 );

	glBindBuffer( GL_ARRAY_BUFFER, 0 );
	glBindVertexArray( 0 );
}

_void Mesh::InitShader( )
{
	if ( mVertices.size( ) <= 0 )
		return;

	string vsstr = "#version 330 core\n" \
		"layout (location = 0) in vec3 position;\n" \
		"layout (location = 1) in vec3 normal;\n" \
		"layout (location = 2) in vec2 texcoord;\n" \
		"out vec2 TexCoord;\n" \
		"uniform mat4 model;\n" \
		"uniform mat4 view;\n" \
		"uniform mat4 projection;\n" \
		"void main()\n" \
		"{\n" \
		"TexCoord = texcoord;\n" \
		"gl_Position = projection * view * model * vec4(position, 1.0);\n" \
		"}";

	string psstr = "#version 330 core\n" \
		"out vec4 FragColor;\n" \
		"in vec2 TexCoord;\n" \
		"uniform sampler2D texture0;\n" \
		"void main()\n" \
		"{\n" \
		"FragColor = texture(texture0, TexCoord);\n" \
		"}\n";
	mShader = new Shader( vsstr, psstr, _false );
}

_void Mesh::BindShaderData( )
{
	if ( mShader == _null )
		return;

	Matrix4 pro = Renderer::GetProjection3D( );
	Matrix4 view = Windows::GetInstance( )->GetRenderer( )->GetCamera( )->GetMatrix( );
	mShader->Use( );
	mShader->SetMatrix4( "projection", pro[0], _false );
	mShader->SetMatrix4( "view", view[0], _false );
	mShader->SetMatrix4( "model", mTransform[0], _false );
	mShader->SetInt( "texture0", 0 );
}

_void Mesh::Render( )
{
	for ( _dword i = 0; i < mMeshs.size( ); i ++ )
		mMeshs[i]->Render( );

	if ( mShader == _null )
		return;

	mShader->Use( );
	//for ( _dword i = 0; i < mTextures.size( ); i ++ )
	//{
		glActiveTexture( GL_TEXTURE0 );
		glBindTexture( GL_TEXTURE_2D, mMaterial->GetDiffuseMapId( ) );
	//}

	glBindVertexArray( mVAO );
	glDrawElements( GL_TRIANGLES, mIndices.size( ), GL_UNSIGNED_INT, 0 );
	glBindVertexArray( 0 );
}

_void Mesh::ProcessNode( aiNode *node, const aiScene *scene )
{
	for( _dword i = 0; i < node->mNumMeshes; i++ )
	{
		aiMesh* mesh = scene->mMeshes[node->mMeshes[i]];
		mMeshs.push_back( ProcessMesh( mesh, scene ) );
	}

	for( _dword i = 0; i < node->mNumChildren; i++ )
	{
		ProcessNode( node->mChildren[i], scene );
	}
}

Mesh* Mesh::ProcessMesh( aiMesh *mesh, const aiScene *scene )
{
	vector< Vertex >	vertices;
	vector< _dword >	indices;
	Material*			material = new Material( );
	// Init vertices.
	for ( _dword i = 0; i < mesh->mNumVertices; i ++ )
	{
		Vertex vertex;
		vertex.Position = Vector3( mesh->mVertices[i].x, mesh->mVertices[i].y, mesh->mVertices[i].z );
		vertex.Normal = Vector3( mesh->mNormals[i].x, mesh->mNormals[i].y, mesh->mNormals[i].z );
		if ( mesh->mTextureCoords[0])
			vertex.TexCoord = Vector2( mesh->mTextureCoords[0][i].x, mesh->mTextureCoords[0][i].y );
		else
			vertex.TexCoord = Vector2( 0.0f, 0.0f );

		vertices.push_back( vertex );
	}

	// Init Indices.
	for ( _dword i = 0; i < mesh->mNumFaces; i ++ )
	{
		aiFace face = mesh->mFaces[i];
		for ( _dword j = 0; j < face.mNumIndices; j ++ )
			indices.push_back( face.mIndices[j] );
	}
	// Texture
	aiMaterial* aimaterial = scene->mMaterials[mesh->mMaterialIndex];
	if ( aimaterial != _null )
	{
		material->SetNormalMap( LoadMaterialTexture( aimaterial, aiTextureType_AMBIENT ) );
		material->SetDiffuseMap( LoadMaterialTexture( aimaterial, aiTextureType_DIFFUSE ) );
		material->SetSpecularMap( LoadMaterialTexture( aimaterial, aiTextureType_SPECULAR ) );
		material->SetHeightMap( LoadMaterialTexture( aimaterial, aiTextureType_HEIGHT ) );
	}
	return new Mesh( vertices, indices, material );
}

Texture* Mesh::LoadMaterialTexture( aiMaterial *mat, aiTextureType type )
{
	string directory = mResName.substr( 0, mResName.find_last_of( '/' ) );
	Texture* texture = _null;
	for( _dword i = 0; i < mat->GetTextureCount( type ); i++ )
	{
		aiString str;
		mat->GetTexture( type, i, &str );
		if( std::strcmp( "" , str.C_Str( ) ) != 0 )
		{
			texture = new Texture( directory + "/" + str.C_Str( ) );
			return texture;
		}
	}
}