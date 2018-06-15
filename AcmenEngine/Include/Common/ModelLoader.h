#pragma once
namespace Acmen
{

class ModelLoader
{
	struct FaceVertex
	{
		_dword mVIndex;
		_dword mTIndex;
		_dword mNIndex;
	};
	enum ObjType
	{
		MATERIALFILE = 0,
		MATERIAL = 1,
		OBJECT = 2,
		POSITION = 3,
		NORMAL = 4,
		TEXCOORD = 5,
		FACE = 6,
	};

public:
	vector < Vector3 >		mPositions;
	vector < Vector3 >		mNormals;
	vector < Vector2 >		mTexcoords;
	vector < FaceVertex >	mFaces;
	vector< Material >		mMaterials;
	string					mMeshName;

public:
	inline ModelLoader( ): mMeshName( "" )
	{ }
	~ModelLoader( );
	_void LoadMeshsFromFile( const string& filename, vector< Mesh* >& meshs );
	Mesh* LoadMeshFromString( const string& str );
	_void LoadMaterialsFromFile( const string& filename );
	_void CreateSubMesh(  vector< Mesh* >& meshs, string name = "" );
	//_void EndMaterial( );
	_void ReadValueFromStr( const string& strs, ObjType types );

};
};