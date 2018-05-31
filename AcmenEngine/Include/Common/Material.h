#pragma once

namespace Acmen
{

class Material
{

private:
	Texture*		mNormalMap;
	Texture*		mDiffuseMap;
	Texture*		mSpecularMap;
	Texture*		mHeightMap;
	String			mResName;

	_dword			mNormalMapId;
	_dword			mDiffuseMapId;
	_dword			mSpecularMapId;
	_dword			mHeightMapId;

public:
	inline Material( )
		: mNormalMap( _null ), mDiffuseMap( _null ), mSpecularMap( _null ), mHeightMap( _null ),
		mNormalMapId( 0 ), mDiffuseMapId( 0 ), mSpecularMapId( 0 ),mHeightMapId( 0 ){ }
	~Material( );

	inline Texture* GetNormalMap( )
		{ return mNormalMap; }
	_void SetNormalMap( Texture* texture );

	inline Texture* GetDiffuseMap( )
		{ return mDiffuseMap; }
	_void SetDiffuseMap( Texture* texture );

	inline Texture* GetSpecularMap( )
		{ return mSpecularMap; }
	_void SetSpecularMap( Texture* texture );

	inline Texture* GetHeightMap( )
		{ return mHeightMap; }
	_void SetHeightMap( Texture* texture );

	inline _dword GetNormalMapId( )
		{ return mNormalMapId; }

	inline _dword GetDiffuseMapId( )
	{ return mDiffuseMapId; }

	inline _dword GetSpecularMapId( )
		{ return mSpecularMapId; }

	inline _dword GetHeightMapId( )
		{ return mHeightMapId; }
};

};