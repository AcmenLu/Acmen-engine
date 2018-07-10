#pragma once

namespace Acmen
{

class Texture
{

public:
	_long			mWidth;
	_long			mHeight;
	_long			mChannel;
	string			mResName;
	_chara*			mData;

public:
	inline Texture( )
		: mWidth( 0 ), mHeight( 0 ), mChannel( 0 ), mData( _null ), mResName( "" ){ }
	Texture( const string& filename , _bool reversal = _false );
	~Texture( );

	virtual _long GetWidth( )
		{ return mWidth; }
	virtual _long GetHeight( )
		{ return mHeight; }
	virtual _long GetChannel( )
		{ return mChannel; }
	virtual string GetmResName( )
		{ return mResName; }
	virtual _chara* GetData( )
		{ return mData; }

	virtual _void LoadTexture( const string& filename, _bool reversal = _false );
	virtual _void ReleaseData( );
};

};