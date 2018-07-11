#pragma once
namespace Acmen
{
class UISprite : public GLRenderObject
{

public:
	GLTexture*	mTexture;
	Vector4		mBgColor;

public:
	inline UISprite( ){}
	~UISprite( );

	inline Vector4& GetBgColor( )
		{ return mBgColor; }
	inline _void SetBgColor( Vector4& vect4 )
		{ mBgColor = vect4; }
};
}