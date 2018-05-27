#include "Acmen.h"

Model::Model( const String& filename )
{
	LoadMeshsFromFile( filename );
}

_void Model::Render( )
{
	if ( mMeshs.size( ) <= 0 )
		return;

	for ( _dword i = 0; i < mMeshs.size( ); i ++ )
		mMeshs[i]->Render( );

}

_void Model::LoadMeshsFromFile( const String& filename )
{
	File file = File( );
	file.Open( filename, "r" );
	String* str = _null;
	Mesh* mesh = _null;
	while ( ( str = file.ReadLine( str ) ) != _null )
	{
		str->Trim( '\n' );
		if ( String::StartWith( *str, "mtllib" ) )
		{
			Trace::TraceString( "Strat with mtllib" );
		}
		else if ( String::StartWith( *str, "o" ) )
		{
			ReadValueFromStr( *str, OBJECT );
		}
		else if ( String::StartWith( *str, "vt" ) )
		{
			ReadValueFromStr( *str, TEXCOORD );
		}
		else if ( String::StartWith( *str, "vn" ) )
		{
			ReadValueFromStr( *str, NORMAL );
		}
		else if ( String::StartWith( *str, "v" ) )
		{
			ReadValueFromStr( *str, POSITION );
		}
		else if ( String::StartWith( *str, "usemtl" ) )
		{
			Trace::TraceString( "Strat with usemtl" );
		}
		else if ( String::StartWith( *str, "f" ) )
		{
			ReadValueFromStr( *str, FACE );
		}
	}

	EndMesh( );
	file.Close( );
}

_void Model::StartMesh( String& loginname )
{

}

_void Model::EndMesh( )
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
		mMeshs.push_back( mesh );
	}
	mPositions.clear( );
	mNormals.clear( );
	mTexcoords.clear( );
}

_void Model::ReadValueFromStr( String& strs, ObjType types )
{
	vector< String*> list;
	strs.Split( ' ', list );
	if ( types == OBJECT && list.size( ) == 2 )
	{
		EndMesh( );
		StartMesh( *list[1] );
	}
	else if ( ( types == POSITION || types == NORMAL ) && list.size( ) == 4 )
	{
		Vector3 vec = Vector3( String::StrToFloat( *list[1] ), String::StrToFloat( *list[2] ), String::StrToFloat( *list[3] ) );
		if ( types == POSITION )
			mPositions.push_back( vec );
		else
			mNormals.push_back( vec );
	}
	else if ( types == TEXCOORD && list.size( ) == 3 )
	{
		mTexcoords.push_back( Vector2( String::StrToFloat( *list[1] ), String::StrToFloat( *list[2] ) ) );
	}
	else if ( types == FACE && list.size( ) > 1 )
	{
		for ( _dword i = 1; i < list.size( ); i ++ )
		{
			vector< String* > tmp;
			list[i]->Trim( ' ' );
			list[i]->Split( '/', tmp );
			if ( tmp.size( ) == 3 )
			{
				FaceVertex face;
				face.mVIndex = String::StrToDword( *tmp[0] );
				face.mTIndex = String::StrToDword( *tmp[1] );
				face.mNIndex = String::StrToDword( *tmp[2] );
				mFaces.push_back( face );
			}
		}
	}
}
