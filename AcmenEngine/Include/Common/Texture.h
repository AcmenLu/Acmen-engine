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
	_char*			mData;

public:
	static _dword CreateGLTexture( Texture* texture, _dword wrap_s = GL_REPEAT, _dword wrap_t = GL_REPEAT, _dword min_filter = GL_LINEAR, _dword mag_filter = GL_LINEAR );
public:
	inline Texture( )
		: mWidth( 0 ), mHeight( 0 ), mChannel( 0 ), mData( _null ), mResName( "" ){ }
	inline Texture( const string& filename )
		: mWidth( 0 ), mHeight( 0 ), mChannel( 0 ), mData( _null ), mResName( filename ){ }
	~Texture( );

	inline _long GetWidth( )
		{ return mWidth; }
	inline _long GetHeight( )
		{ return mHeight; }
	inline _long GetChannel( )
		{ return mChannel; }
	inline string GetmResName( )
		{ return mResName; }
	inline _char* GetData( )
		{ return mData; }

	_void LoadTexture( _bool reversal = _false );
	_void LoadTexture( const string& filename, _bool reversal = _false );
};

};