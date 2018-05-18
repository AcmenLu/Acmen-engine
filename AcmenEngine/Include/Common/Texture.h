#pragma once

namespace Acmen
{

class Texture
{

public:
	_dword			mWidth;
	_dword			mHeight;
	_dword			mChannel;
	string			mResName;
	_char*			mData;

public:
	inline Texture( ){ }
	Texture( const string& filename );
	_void LoadTexture( const string& filename, _bool reversal = _false );
	~Texture( );

};

};