
#include "Acmen.h"

void Renderer::OnRender( _float elapse )
{
	glClearColor( 0.2f, 0.3f, 0.3f, 1.0f );
	for ( _dword i = 0; i < mRenderList.size( ); i++ )
		mRenderList[i]->Render( );

	glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
}

void Renderer::ClearRenderList( )
{
	for ( _dword i = mRenderList.size( ) - 1; i >= 0 ; i-- )
	{
		RenderObject* object = mRenderList[i];
		mRenderList.pop_back( );
		object->~RenderObject( );
	}
}

void Renderer::AddRenderObject( RenderObject* object )
{
	_bool isAtList = _false;
	for ( _dword i = 0; i < mRenderList.size( ); i++ )
	{
		if ( object == mRenderList[i] )
			isAtList = _true;
	}

	if ( isAtList == _false )
		mRenderList.push_back( object );
}

void Renderer::RemoveRenderObject( RenderObject* object )
{
	for ( _dword i = 0; i < mRenderList.size( ); i++ )
	{
		if ( object == mRenderList[i] )
			mRenderList.erase( mRenderList.begin( ) + i );
	}
}