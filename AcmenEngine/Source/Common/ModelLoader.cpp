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
	for ( _dword i = 0; i < objs.size( ); i ++ )
	{
		if ( String::StartWith( objs[i], "o " ) )
		{
			
		}
		else
		{

		}
	}
	//Trace::TraceString( str );
	//while ( ( str = file.ReadLine( ) ) != "" )
	//{
		//strs.push_back( str );
		/*if ( String::StartWith( str, "mtllib" ) )
		{
			ReadValueFromStr( str, MATERIALFILE );
		}
		else if ( String::StartWith( str, "o" ) )
		{
			vector< string> list = String::Split( str, " " );
			CreateSubMesh( meshs, list[1] );
		}
		else if ( String::StartWith( str, "vt" ) )
		{
			ReadValueFromStr( str, TEXCOORD );
		}
		else if ( String::StartWith( str, "vn" ) )
		{
			ReadValueFromStr( str, NORMAL );
		}
		else if ( String::StartWith( str, "v" ) )
		{
			ReadValueFromStr( str, POSITION );
		}
		else if ( String::StartWith( str, "usemtl" ) )
		{
			Trace::TraceString( "Strat with usemtl" );
		}
		else if ( String::StartWith( str, "f" ) )
		{
			ReadValueFromStr( str, FACE );
		}*/
	//}

	CreateSubMesh( meshs );
	//file.Close( );
}


Mesh* ModelLoader::LoadMeshFromString( const string& str )
{
	vector<string> linis = String::Split( str, "\r\n" );
	vector < Vector3 >		positions;
	vector < Vector3 >		normals;
	vector < Vector2 >		texcoords;
	vector < Vector3 >		faces;
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
			
		}
	}
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
