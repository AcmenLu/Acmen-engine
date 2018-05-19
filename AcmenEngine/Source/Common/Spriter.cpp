#include "Acmen.h"

Spriter::Spriter( const string& filename ): mTransform( glm::mat4( ) )
{
	InitData( filename );
	InitVAO( );
	InitShader( );
	BindShaderData( );
}

Spriter::~Spriter( )
{
	if ( mShader != _null )
	{
		mShader->~Shader( );
		delete mShader;
	}
}

_void Spriter::InitData( const string& filename )
{
	mVertices.push_back( Vertex( 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f ) );
	mVertices.push_back( Vertex( 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f ) );
	mVertices.push_back( Vertex( 1.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 1.0f ) );
	mVertices.push_back( Vertex( 1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f ) );

	mIndices.push_back( 0 );
	mIndices.push_back( 1 );
	mIndices.push_back( 3 );
	mIndices.push_back( 1 );
	mIndices.push_back( 2 );
	mIndices.push_back( 3 );

	Texture texture = Texture( filename );
	_long width, height, channel;
	_dword tex = Texture::CreateGLTexture( &texture );
	mTextures.push_back( tex );
}

_void Spriter::InitVAO( )
{
	_dword VBO;
	glGenBuffers( 1, &VBO );
	glGenVertexArrays( 1, &mVAO );
	glBindVertexArray( mVAO );

	glBindBuffer( GL_ARRAY_BUFFER, VBO );
	glBufferData( GL_ARRAY_BUFFER, mVertices.size( ) * sizeof( Vertex ), &mVertices[0], GL_STATIC_DRAW );

	_dword EBO;
	glGenBuffers( 1, &EBO );
	glBindBuffer( GL_ELEMENT_ARRAY_BUFFER, EBO );
	glBufferData( GL_ELEMENT_ARRAY_BUFFER, mIndices.size( ) * sizeof( _dword ), &mIndices[0], GL_STATIC_DRAW );

	// Position
	glEnableVertexAttribArray( 0 );
	glVertexAttribPointer( 0, 3, GL_FLOAT, GL_FALSE, sizeof( Vertex ), (_void*)0 );

	// Normal
	glEnableVertexAttribArray( 1 );
	glVertexAttribPointer( 1, 3, GL_FLOAT, GL_FALSE, sizeof( Vertex ), (_void*)offsetof( Vertex, Normal ) );

	// Texcoord
	glEnableVertexAttribArray( 2 );
	glVertexAttribPointer( 2, 2, GL_FLOAT, GL_FALSE, sizeof( Vertex ), (_void*)offsetof( Vertex, TexCoord ) );
}

_void Spriter::InitShader( )
{
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
					"gl_Position = vec4(position, 1.0);\n" \
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

_void Spriter::BindShaderData( )
{
	if ( mShader == _null )
		return;

	mTransform = glm::scale( mTransform, glm::vec3( mSize, 1.0f ) );
	glm::mat4 pro = Windows::GetInstance( )->mRenderer->GetProjection2D( );
	glm::mat4 view = glm::mat4( );
	mShader->Use( );
	mShader->SetMatrix4( "projection", glm::value_ptr( pro ), _false );
	mShader->SetMatrix4( "view", glm::value_ptr( pro ), _false );
	mShader->SetMatrix4( "model", glm::value_ptr( mTransform ), _false );
	mShader->SetInt( "texture0", 0 );
}

_void Spriter::Render( )
{
	mShader->Use( );
	for ( _dword i = 0; i < mTextures.size( ); i ++ )
	{
		glActiveTexture( GL_TEXTURE0 + i );
		glBindTexture( GL_TEXTURE_2D, mTextures[i] );
	}

	glBindVertexArray( mVAO );
	glDrawElements( GL_TRIANGLES, mIndices.size( ), GL_UNSIGNED_INT, 0 );
	glBindVertexArray( 0 );
}