#include "Acmen.h"

RenderObject::RenderObject( vector< Vertex > vertices, vector< _dword > indices )
	:mVertices( vector< Vertex >( ) ), mIndices( vector< _dword >( ) ),
	mShader( _null ), mTransform( Matrix4( ) ), mVAO( 0 ), mVBO( 0 ), mEBO( 0 )
{
	if ( vertices.size( ) > 0 )
		mVertices.assign( vertices.begin( ), vertices.end( ) );

	if ( indices.size( ) > 0 )
		mIndices.assign( indices.begin( ), indices.end( ) );
}

RenderObject::~RenderObject( )
{
	if ( mVBO > 0 )
		glDeleteBuffers( 1, &mVBO );

	if ( mEBO > 0 )
		glDeleteBuffers( 1, &mEBO );

	if ( mVAO > 0 )
		glDeleteVertexArrays( 1, &mVAO );

	mVertices.clear( );
	mIndices.clear( );
	mVBO = 0;
	mEBO = 0;
	mVAO = 0;

	if ( mShader != _null )
		SAFE_RELESE( mShader )
}

_bool RenderObject::InitRenderData( )
{
	if ( CreateGeometry( ) == _false )
		return _false;

	if ( CreateShader( ) == _false )
		return _false;

	return _true;
}

_bool RenderObject::CreateGeometry( )
{
	if ( mVertices.size( ) <= 0 )
		return _false;

	glGenVertexArrays( 1, &mVAO );
	glBindVertexArray( mVAO );

	glGenBuffers( 1, &mVBO );
	glBindBuffer( GL_ARRAY_BUFFER, mVBO );
	glBufferData( GL_ARRAY_BUFFER, mVertices.size( ) * sizeof( Vertex ), &mVertices[0], GL_STATIC_DRAW );

	if ( mIndices.size( ) > 0 )
	{
		glGenBuffers( 1, &mEBO );
		glBindBuffer( GL_ELEMENT_ARRAY_BUFFER, mEBO );
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
	return _true;
}

_void RenderObject::Render( _float elapse )
{
	if ( mShader == _null )
		return;

	mShader->Use( );
	SetUniform( );
	SetRenderData( );
	glBindVertexArray( mVAO );

	if ( mIndices.size( ) > 0 )
		glDrawElements( GL_TRIANGLES, mIndices.size( ), GL_UNSIGNED_INT, 0 );
	else
		glDrawArrays( GL_TRIANGLES, 0, mVertices.size( ) );

	glBindVertexArray( 0 );
}