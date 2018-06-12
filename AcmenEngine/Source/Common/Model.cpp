#include "Acmen.h"

Model::Model( const string& filename ): mResName( "" )
{
	mResName = filename;
	ModelLoader loader = ModelLoader( );
	loader.LoadMeshsFromFile( filename, mMeshs );
}

_void Model::Render( )
{
	if ( mMeshs.size( ) <= 0 )
		return;

	for ( _dword i = 0; i < mMeshs.size( ); i ++ )
		mMeshs[i]->Render( );
}