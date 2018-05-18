#include "Acmen.h"

_void RenderObject::InitVAO( )
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
	glVertexAttribPointer( 0, 3, GL_FLOAT, GL_FALSE, 4 * sizeof( Vertex ), (_void*)0 );

	// Normal
	glEnableVertexAttribArray( 1 );
	glVertexAttribPointer( 0, 3, GL_FLOAT, GL_FALSE, 4 * sizeof( Vertex ), (_void*)offsetof( Vertex, Normal ) );

	// Texcoord
	glEnableVertexAttribArray( 2 );
	glVertexAttribPointer( 0, 3, GL_FLOAT, GL_FALSE, 4 * sizeof( Vertex ), (_void*)offsetof( Vertex, TexCoord ) );
}