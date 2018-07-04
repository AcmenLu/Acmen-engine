#include "Acmen.h"

Spriter::Spriter( ): mTexture( _null )
{
	createVertices( );
}

Spriter::Spriter( Texture* texture ): mTexture( texture )
{
	createVertices( );
}

Spriter::~Spriter( )
{
	SAFE_RELESE( mTexture );
}

_bool Spriter::CreateShader( )
{
	string vsstr = "#version 330 core\n" \
					"layout (location = 0) in vec3 position;\n" \
					"layout (location = 1) in vec3 normal;\n" \
					"layout (location = 2) in vec2 texcoord;\n" \
					"out vec2 TexCoord;\n" \
					"uniform mat4 model;\n" \
					"uniform mat4 projection;\n" \
					"void main()\n" \
					"{\n" \
					"TexCoord = texcoord;\n" \
					"gl_Position = projection * model * vec4(position, 1.0);\n" \
					"}";

	string psstr = "#version 330 core\n" \
					"out vec4 FragColor;\n" \
					"in vec2 TexCoord;\n" \
					"uniform sampler2D texture0;\n" \
					"void main()\n" \
					"{\n" \
					"vec4 texColor = texture(texture0, TexCoord);\n" \
					"if (texColor.a < 0.3)\n" \
					"discard;\n" \
					"FragColor = texColor;\n" \
					"}\n";
	mShader = new Shader( vsstr, psstr, _false );
	return _true;
}

_bool Spriter::SetUniform( )
{
	if ( mShader == _null )
		return _false;

	Matrix4 pro = Renderer::GetProjection2D(  );
	mShader->SetMatrix4( "projection", &pro[0][0], _false );
	mShader->SetMatrix4( "model", &mTransform[0][0], _false );
	mShader->SetInt( "texture0", 0 );
	return _true;
}

_void Spriter::Render( _float elapse )
{
	if ( mIsInited == _false )
		Init( );
	RenderObject::Render( elapse );
}

_void Spriter::createVertices( )
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
}