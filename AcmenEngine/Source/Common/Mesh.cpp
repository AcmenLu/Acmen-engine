#include "Acmen.h"

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
}

_void Mesh::InitMesh( )
{
	if ( mIsInited == _true )
		return;

	InitVAO( );
	InitShader( );
	mIsInited = true;
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

	if ( mIndices.size( ) > 0 )
	{
		_dword EBO;
		glGenBuffers( 1, &EBO );
		glBindBuffer( GL_ELEMENT_ARRAY_BUFFER, EBO );
		glBufferData( GL_ELEMENT_ARRAY_BUFFER, mIndices.size( ) * sizeof( _dword ), &mIndices[0], GL_STATIC_DRAW );
	}
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
	mShader->SetMatrix4( "projection", pro[0], _false );
	mShader->SetMatrix4( "view", view[0], _false );
	mShader->SetMatrix4( "model", mTransform[0], _false );
	mShader->SetInt( "texture0", 0 );
}

_void Mesh::Render( _float elapse )
{
	if ( mIsInited == _false )
		InitMesh( );

	if ( mShader == _null )
		return;

	mShader->Use( );
	BindShaderData( );

	if ( mMaterial->mDiffuseMaps.size( ) > 0 )
	{
		glActiveTexture( GL_TEXTURE0 );
		glBindTexture( GL_TEXTURE_2D, mMaterial->mDiffuseMaps[0]->mGLId );
	}

	glBindVertexArray( mVAO );

	if ( mIndices.size( ) > 0 )
		glDrawElements( GL_TRIANGLES, mIndices.size( ), GL_UNSIGNED_INT, 0 );
	else
		glDrawArrays( GL_TRIANGLES, 0, mVertices.size( ) );

	glBindVertexArray( 0 );
}
