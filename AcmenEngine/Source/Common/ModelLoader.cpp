#include "Acmen.h"


// ------------------------------------------------------------------------------
// -------------------------	ModelLoader	-------------------------------------
// ------------------------------------------------------------------------------
ModelLoader::~ModelLoader( )
{
}

_void ModelLoader::LoadMeshsFromFile( const string& filename, vector< Mesh* >& meshs )
{
	File file = File( );
	file.Open( filename, "rb" );
	string str = file.Read( );
	file.Close( );
	vector<string> objs = String::Split( str, "\no " );

	vector<string> linis = String::Split( objs[0], "\r\n" );
	for ( _dword j = 0; j < linis.size( ); j ++ )
	{
		if ( String::StartWith( linis[j], "mtllib" ) )
		{
			vector<string> name = String::Split( linis[j], " " );
			LoadMaterialsFromFile(name[1]);
		}
	}

	for ( _dword i = 0; i < objs.size( ); i ++ )
	{
		if ( String::StartWith( objs[i], "o " ) )
		{
			meshs.push_back( LoadMeshFromString( objs[i] ) );
		}
	}
}


Mesh* ModelLoader::LoadMeshFromString( const string& str )
{
	vector<string> linis = String::Split( str, "\r\n" );
	vector < Vector3 >		positions;
	vector < Vector3 >		normals;
	vector < Vector2 >		texcoords;
	vector < Vector3 >		faces;
	string					mtlname = "";

	Mesh* mesh = new Mesh( );
	for ( _dword i = 0; i < linis.size( ); i++ )
	{
		vector<string> tmps = String::Split( linis[i], " " );
		if ( String::StartWith( linis[i], "o" ) )
		{
			mesh->SetResName( String::TrimWith( tmps[1], " " ) );
		}
		else if ( String::StartWith( linis[i], "v" ) )
		{
			if ( String::StartWith( linis[i], "vn" ) )
				normals.push_back( Vector3( String::StrToFloat( tmps[1] ), String::StrToFloat( tmps[2] ), String::StrToFloat( tmps[3] ) ) );
			else if ( String::StartWith( str, "vt" ) )
				texcoords.push_back( Vector2( String::StrToFloat( tmps[1] ), String::StrToFloat( tmps[2] ) ) );
			else if (  String::StartWith( str, "v " ) )
				positions.push_back( Vector3( String::StrToFloat( tmps[1] ), String::StrToFloat( tmps[2] ), String::StrToFloat( tmps[3] ) ) );
		}
		else if ( String::StartWith( str, "f" ) )
		{
			faces.push_back( Vector3( String::StrToDword( tmps[1] ), String::StrToDword( tmps[2] ), String::StrToDword( tmps[3] ) ) );
		}
		else if ( String::StartWith( str, "usemtl" ) )
		{
			mtlname = tmps[1];
		}
	}

	for ( _dword i = 0; i < faces.size( ); i ++ )
	{
		Vertex vertex;
		_dword posIndex = ( faces[i].x - 1 ) > ( positions.size( ) - 1 ) ? ( positions.size( ) - 1 ) : ( faces[i].x - 1 );
		vertex.Position = positions[posIndex];
		_dword nIndex = ( faces[i].y - 1 ) > ( normals.size( ) - 1 ) ? ( normals.size( ) - 1 ) : ( faces[i].y - 1 );
		vertex.Normal = normals[nIndex];
		_dword tIndex = ( faces[i].z - 1 ) > ( texcoords.size( ) - 1 ) ? ( texcoords.size( ) - 1 ) : ( faces[i].z - 1 );
		vertex.TexCoord = texcoords[tIndex];
		mesh->GetVertexs( ).push_back( vertex );
	}
	return mesh;
}

_void ModelLoader::LoadMaterialsFromFile( const string& filename )
{
	File file = File( );
	file.Open( filename, "r" );
	string str;
	while ( ( str = file.ReadLine( ) ) != "" )
	{
		if ( String::StartWith( str, "mtllib" ) )
		{

		}
	}
	file.Close( );
}

_void ModelLoader::CreateSubMesh(  vector< Mesh* >& meshs, string name )
{
	if ( mFaces.size( ) > 0 )
	{
		Mesh* mesh = new Mesh( );
		for ( _dword i = 0; i < mFaces.size( ); i ++ )
		{
			Vertex vertex;
			_dword posIndex = ( mFaces[i].mVIndex - 1 ) > ( mPositions.size( ) - 1 ) ? ( mPositions.size( ) - 1 ) : ( mFaces[i].mVIndex - 1 );
			vertex.Position = mPositions[posIndex];
			_dword nIndex = ( mFaces[i].mNIndex - 1 ) > ( mNormals.size( ) - 1 ) ? ( mNormals.size( ) - 1 ) : ( mFaces[i].mNIndex - 1 );
			vertex.Normal = mNormals[nIndex];
			_dword tIndex = ( mFaces[i].mTIndex - 1 ) > ( mTexcoords.size( ) - 1 ) ? ( mTexcoords.size( ) - 1 ) : ( mFaces[i].mTIndex - 1 );
			vertex.TexCoord = mTexcoords[tIndex];
			mesh->GetVertexs( ).push_back( vertex );
		}
		meshs.push_back( mesh );
	}
	mMeshName = name;
	mPositions.clear( );
	mNormals.clear( );
	mTexcoords.clear( );
}

_void ModelLoader::ReadValueFromStr( const string& strs, ObjType types )
{
	vector< string> list = String::Split( strs, " " );
	if ( types == MATERIALFILE && list.size( ) == 2 )
	{
		//_long index = mResName.LastIndexOf( '/');
		//string str = "";
		//if ( index > 0 )
		//{
		//	string* str = mResName.SubString( 0, index + 1 );
		//	*str += (*list[1]);
		//}
		//else
		//{
		//	str = (*list[1]);
		//}
		//LoadMaterialsFromFile( str );
	}
	else if ( ( types == POSITION || types == NORMAL ) && list.size( ) == 4 )
	{
		Vector3 vec = Vector3( String::StrToFloat( list[1] ), String::StrToFloat( list[2] ), String::StrToFloat( list[3] ) );
		if ( types == POSITION )
			mPositions.push_back( vec );
		else
			mNormals.push_back( vec );
	}
	else if ( types == TEXCOORD && list.size( ) == 3 )
	{
		mTexcoords.push_back( Vector2( String::StrToFloat( list[1] ), String::StrToFloat( list[2] ) ) );
	}
	else if ( types == FACE && list.size( ) > 1 )
	{
		for ( _dword i = 1; i < list.size( ); i ++ )
		{
			vector< string > tmp = String::Split( list[i], "/" );
			if ( tmp.size( ) == 3 )
			{
				FaceVertex face;
				face.mVIndex = String::StrToDword( tmp[0] );
				face.mTIndex = String::StrToDword( tmp[1] );
				face.mNIndex = String::StrToDword( tmp[2] );
				mFaces.push_back( face );
			}
		}
	}
}
