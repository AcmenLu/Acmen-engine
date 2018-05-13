#include "Mesh.h"

Mesh::Mesh( std::vector<Vertex> vertexs, std::vector<unsigned int> indices, std::vector<Texture> textures )
{
	mVertexs = vertexs;
	mIndices = indices;
	mTextures = textures;
	setUpMesh( );
}

void LoadMesh( const char* filename )
{

}

void Mesh::Draw( Shader* shader )
{
	unsigned int diffuseNr = 1;
	unsigned int specularNr = 1;
	unsigned int normalNr   = 1;
	unsigned int heightNr   = 1;
	for ( unsigned int index = 0; index < mTextures.size( ); index++ )
	{
		glActiveTexture( GL_TEXTURE0 + index );
		std::string number;
		std::string name = mTextures[index].Type;
		if ( mTextures[index].Type == "texture_diffuse" )
			number = std::to_string( diffuseNr++ );
		else if( name == "texture_specular" )
			number = std::to_string( specularNr++ );
		else if( name == "texture_normal" )
			number = std::to_string( normalNr++ );
		else if( name == "texture_height" )
			number = std::to_string( heightNr++ );

		shader->SetInt( ( name + number ).c_str( ), index );
		glBindTexture( GL_TEXTURE_2D, mTextures[index].Identity );
	}
	
	glBindVertexArray( mVAO );
	glDrawElements( GL_TRIANGLES, mIndices.size( ), GL_UNSIGNED_INT, 0 );
	glBindVertexArray( 0 );
}

void Mesh::setUpMesh( )
{
	glGenVertexArrays( 1, &mVAO );
	glGenBuffers( 1, &mVBO );
	glGenBuffers( 1, &mEBO );

	glBindVertexArray( mVAO );
	glBindBuffer( GL_ARRAY_BUFFER, mVBO );
	glBufferData( GL_ARRAY_BUFFER, sizeof( Vertex ) * mVertexs.size( ), &mVertexs[0], GL_STATIC_DRAW );
	glBindBuffer( GL_ELEMENT_ARRAY_BUFFER, mEBO );
	glBufferData( GL_ELEMENT_ARRAY_BUFFER, sizeof( unsigned int ) * mIndices.size( ), &mIndices[0], GL_STATIC_DRAW );

	glEnableVertexAttribArray( 0 );
	glVertexAttribPointer( 0, 3, GL_FLOAT, GL_FALSE, sizeof( Vertex ), (void*)0 );
	glEnableVertexAttribArray( 1 );
	glVertexAttribPointer( 1, 3, GL_FLOAT, GL_FALSE, sizeof( Vertex ), (void*)offsetof( Vertex, Normal ) );
	glEnableVertexAttribArray( 2 );
	glVertexAttribPointer( 2, 2, GL_FLOAT, GL_FALSE, sizeof( Vertex ), (void*)offsetof( Vertex, TexCoord ) );

	glBindVertexArray( 0 );
}