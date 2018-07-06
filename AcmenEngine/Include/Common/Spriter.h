#pragma once

namespace Acmen
{
class Spriter : public RenderObject
{

public:
	Texture*			mTexture;
	Rect				mRect;
	_bool				mIsReady;
public:
	inline Spriter( ) :mTexture( _null ), mIsReady( _false ), mRect( Rect( ) ){ }
	Spriter( const string filename );
	inline Spriter( Texture* texture ): mTexture( texture ), mIsReady( _false ), mRect( Rect( ) ){ }
	~Spriter( );

	_bool CreateShader( );
	_bool SetUniform( );
	_void SetRenderData( );
	_void Update( _float elapse );

private:
	_void createVertices( );
};

}