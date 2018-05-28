#pragma once
namespace Acmen
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

class Model : public RenderObject
{
public:
	vector< Mesh* > mMeshs;
	String			mResName;

	vector < Vector3 > mPositions;
	vector < Vector3 > mNormals;
	vector < Vector2 > mTexcoords;
	vector <FaceVertex > mFaces;

public:
	Model( const String& filename );
	inline ~Model( )
		{ }

public:
	_void Render( );
	_void LoadMeshsFromFile( const String& filename );
	_void LoadMaterialsFromFile( const String& filename );
	_void StartMesh( String& loginname );
	_void EndMesh( );
	_void EndMaterial( );
	_void ReadValueFromStr( String& strs, ObjType types );
};
};