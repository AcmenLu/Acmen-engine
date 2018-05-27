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
	OBJECT = 0,
	MATERIAL = 1,
	POSITION = 2,
	NORMAL = 3,
	TEXCOORD = 4,
	FACE = 5,
};

class Model : public RenderObject
{
public:
	vector< Mesh* > mMeshs;

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
	_void StartMesh( String& loginname );
	_void EndMesh( );
	_void ReadValueFromStr( String& strs, ObjType types );
};
};