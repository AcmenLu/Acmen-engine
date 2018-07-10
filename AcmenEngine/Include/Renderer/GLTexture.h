#pragma once
namespace Acmen
{
class GLTexture : public Texture
{

private:
	_dword mGLId;

public:
	inline GLTexture( ):mGLId( 0 ){ }
	GLTexture( const string& filename );
	GLTexture( Texture* texture );
	~GLTexture( );
	
	inline _dword GetGLId( )
		{ return mGLId; }
	_dword LoadGLTexture( Texture* texture );
};
}