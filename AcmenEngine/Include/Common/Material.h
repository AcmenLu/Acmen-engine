#pragma once

namespace Acmen
{

class Material
{
public:
	vector<Texture*>		mNormalMaps;
	vector<Texture*>		mDiffuseMaps;
	vector<Texture*>		mSpecularMaps;
	vector<Texture*>		mHeightMaps;

public:
	inline Material( ){ }
	inline Material( vector<Texture*> normals, vector<Texture*> diffuses, vector<Texture*> speculars, vector<Texture*> heights )
		:mNormalMaps( normals ), mDiffuseMaps( diffuses ), mSpecularMaps( speculars ), mHeightMaps( heights ) { }
	~Material( );

	inline vector<Texture*> GetNormalMaps( )
		{ return mNormalMaps; }
	inline _void SetNormalMaps( vector<Texture*> testures )
		{ mNormalMaps = testures; }

	inline vector<Texture*> GetDiffuseMaps( )
		{ return mDiffuseMaps; }
	inline _void SetDiffuseMaps( vector<Texture*> testures )
		{ mDiffuseMaps = testures; }

	inline vector<Texture*> GetSpecularMaps( )
		{ return mSpecularMaps; }
	inline _void SetSpecularMaps( vector<Texture*> testures )
		{ mSpecularMaps = testures; }

	inline vector<Texture*> GetHeightMaps( )
		{ return mHeightMaps; }
	inline _void SetHeightMaps( vector<Texture*> testures )
		{ mHeightMaps = testures; }
};

};