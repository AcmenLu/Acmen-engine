#include "Acmen.h"

UISprite::~UISprite( )
{
	SAFE_RELESE( mTexture )
}