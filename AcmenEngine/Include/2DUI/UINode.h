#pragma once
namespace Acmen
{

class UINode: public RenderObject
{
public:
	static _void SortByZOrder( vector<UINode* >& nodes );

protected:
	_bool				mVisible;
	_bool				mEnableTouch;
	_long				mZOrder;
	Vector2				mPosition;
	Vector2				mSize;
	vector<UINode*>		mChildren;
	UINode*				mParent;
	string				mName;
	Matrix4				mTransform;

public:
	inline UINode( )
		: mVisible( _true ), mEnableTouch( _false ), mZOrder( 0 ), mPosition( Vector2( ) ), mSize( Vector2( ) ),
		mParent( _null ), mName( "" ), mTransform( Matrix4( ) ) { }
	~UINode( );

	virtual _bool IsVisible( )
		{ return mVisible; }
	virtual _void SetVisible( _bool value )
		{ mVisible = value; }

	virtual _bool IsEnableTouch( )
		{ return mEnableTouch; }
	virtual _void SetEnableTouch( _bool value )
		{ mEnableTouch = value; }

	virtual _bool GetZOrder( )
		{ return mZOrder; }
	virtual _void SetZOrder( _long value )
		{ mZOrder = value; }

	virtual Vector2& GetPosition( )
		{ return mPosition; }
	virtual _void SetPosition( _float x, _float y );

	virtual Vector2& GetSize( )
		{ return mSize; }
	virtual _void SetSize( _float x, _float y );

	virtual string& GetName( )
		{ return mName; }
	virtual _void SetTransform( string name )
		{ mName = name; }

	virtual Matrix4& GetTransform( )
		{ return mTransform; }
	virtual _void SetTransform( Matrix4 transform )
		{ mTransform = transform; }

	virtual _void PositionChanged( ) { }
	virtual _void SizeChanged( ){ }
	virtual _bool VisibleByCamera( ){ return _true; }
	virtual _void UpdateTransform( Matrix4 partenmat );
	virtual _void Visit( Renderer* renderer, Matrix4 parentmat );
	virtual _void Draw( Renderer* renderer ) = 0;
	virtual _void OnRender( _float elapse ){ }
};

}