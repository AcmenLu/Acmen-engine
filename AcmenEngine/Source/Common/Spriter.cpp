#include "Acmen.h"

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

Spriter::Spriter( const string& filename )
{
	mTransform = glm::mat4( );
	InitData( );
	InitShader( );
	LoadImage( filename );
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

_void Spriter::InitData( )
{
	mVertices.push_back( Vertex( 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f ) );
	mVertices.push_back( Vertex( 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f ) );
	mVertices.push_back( Vertex( 1.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 1.0f ) );
	mVertices.push_back( Vertex( 1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f ) );

	mIndices.push_back( 0 );
	mIndices.push_back( 1 );
	mIndices.push_back( 3 );
	mIndices.push_back( 1 );
	mIndices.push_back( 1 );
	mIndices.push_back( 3 );
}

_void Spriter::InitShader( )
{
	string vsstr = "#version 330 core\n" \
					"layout (location = 0) in vec4 vertex;\n" \
					"out vec2 TexCoords;\n" \
					"uniform mat4 model;\n" \
					"uniform mat4 projection;\n" \
					"void main()\n" \
					"{\n" \
					"TexCoords = vertex.zw;\n" \
					"gl_Position = projection * model * vec4(vertex.xy, 0.0, 1.0);\n" \
					"}";

	string psstr = "#version 330 core\n" \
					"out vec4 FragColor;\n" \
					"in vec2 TexCoords;\n" \
					"uniform sampler2D image;\n" \
					"void main()\n" \
					"{\n" \
					"FragColor = Spriter(image, TexCoords);\n" \
					"}\n";
	mShader = new Shader( vsstr, psstr, _false );
}

_void Spriter::BindShaderData( )
{
	if ( mShader == _null )
		return;

	mTransform = glm::scale( mTransform, glm::vec3( mSize, 1.0f ) );
	glm::mat4 pro = Windows::GetInstance( )->mRenderer->GetProjection2D( );
	mShader->Use( );
	mShader->SetMatrix4( "projection", glm::value_ptr( pro ), _false );
	mShader->SetMatrix4( "model", glm::value_ptr( mTransform ), _false );
	mShader->SetInt( "image", 0 );
}

_void Spriter::Render( )
{
	mShader->Use( );
	glActiveTexture( GL_TEXTURE0 );
	glBindTexture( GL_TEXTURE_2D, mTexture );

	glBindVertexArray( mVAO );
	glDrawElements( GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0 );
	glBindVertexArray( 0 );
}