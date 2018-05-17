#pragma once

namespace Acmen
{


	
	{
	public:
		

	public:
		Texture( const string& filename );
		~Texture( );
		_void InitData( );
		_void InitShader( );
		_void LoadImage( const string& filename );
		_void BindShaderData( );
		virtual _void Render( );

	};

class Cube : public RenderObject
{

public:
	Shader*		mShader;
	_dword		mVAO;
	_dword		mTexture;
	glm::vec2	mSize;
	glm::mat4	mTransform;

public:
	Cube( );
	~Cube( );
	virtual _void InitData( );
	virtual _void InitShader( );
	virtual _void BindShaderData( );
	virtual _void Render( );
};
}