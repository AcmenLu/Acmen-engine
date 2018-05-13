#pragma once

#include "Sample.h"

class Model
{
public:
	inline Model( )
		{ }
	Model( char* filename );

	inline ~Model( )
		{ }

	void LoadModel( char* filename );
	void Draw( Shader* shader );

private:
	std::vector<Mesh> mMeshs;
};