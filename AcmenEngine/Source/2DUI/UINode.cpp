#include "Acmen.h"
#include <algorithm> 
_bool LessSort( UINode* node1, UINode* node2 )
{
	return node1->GetZOrder( ) < node2->GetZOrder( );
}

_void UINode::SortByZOrder( vector<UINode* >& nodes )
{
	sort( nodes.begin( ), nodes.end( ), LessSort );
}

UINode::~UINode( )
{
	for ( _dword i = 0; i < mChildren.size( ); i ++ )
		SAFE_RELESE( mChildren[i] );
}

_void UINode::SetPosition( _float x, _float y )
{
	mPosition.x = x;
	mPosition.y = y;
	PositionChanged( );
}

_void UINode::SetSize( _float x, _float y )
{
	mSize.x = x;
	mSize.y = y;
	SizeChanged( );
}

_void UINode::UpdateTransform( Matrix4 partenmat )
{
	//mTransform *= partenmat;
}

_void UINode::Visit( Renderer* renderer, Matrix4 parentmat )
{
	if ( mVisible == _false )
		return;

	UpdateTransform( parentmat );

	if ( VisibleByCamera( ) == _false )
		return;

	Draw( renderer );
	if ( mChildren.size( ) > 0 )
	{
		SortByZOrder( mChildren );
		for ( UINode* node : mChildren )
			node->Visit( renderer, mTransform );
	}
}