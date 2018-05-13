#pragma once

#include "Sample.h"

struct Vertex
{
	glm::vec3 Position;
	glm::vec3 Normal;
	glm::vec2 TexCoord;
};

struct Texture {
	unsigned int Identity;
	std::string Type;
};

class Mesh
{
public:
	std::vector<Vertex> mVertexs;
	std::vector<unsigned int> mIndices;
	std::vector<Texture> mTextures;

	inline Mesh( )
		{ }
	inline ~Mesh( )
		{ }
	Mesh( std::vector<Vertex> vertexs, std::vector<unsigned int> indices, std::vector<Texture> textures );
	
	void LoadMesh( const char* filename );
	void Draw( Shader* shader );

private:
	unsigned int mVAO;
	unsigned int mVBO;
	unsigned int mEBO;
	void setUpMesh( );
};
