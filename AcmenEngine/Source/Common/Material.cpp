#include "Acmen.h"

Material::~Material( )
{
	for ( _dword i = 0; i < mNormalMaps.size( ); i ++ )
		SAFE_RELESE( mNormalMaps[i] );

	for ( _dword i = 0; i < mDiffuseMaps.size( ); i ++ )
		SAFE_RELESE( mDiffuseMaps[i] );

	for ( _dword i = 0; i < mSpecularMaps.size( ); i ++ )
		SAFE_RELESE( mSpecularMaps[i] );

	for ( _dword i = 0; i < mHeightMaps.size( ); i ++ )
		SAFE_RELESE( mHeightMaps[i] );
}