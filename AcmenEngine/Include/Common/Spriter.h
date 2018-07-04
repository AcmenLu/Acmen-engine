#pragma once

namespace Acmen
{
class Spriter : public RenderObject
{

public:
	Texture*			mTexture;

public:
	Spriter( );
	Spriter::Spriter( Texture* texture );
	~Spriter( );

	_bool CreateShader( );
	_bool SetUniform( );
	_void Render( _float elapse );

private:
	_void createVertices( );
};

}