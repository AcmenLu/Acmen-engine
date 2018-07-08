#pragma once
namespace Acmen
{

class UINode
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

	inline _bool IsVisible( )
		{ return mVisible; }
	inline _void SetVisible( _bool value )
		{ mVisible = value; }

	inline _bool IsEnableTouch( )
		{ return mEnableTouch; }
	inline _void SetEnableTouch( _bool value )
		{ mEnableTouch = value; }

	inline _bool GetZOrder( )
		{ return mZOrder; }
	inline _void SetZOrder( _long value )
		{ mZOrder = value; }

	inline Vector2& GetPosition( )
		{ return mPosition; }
	inline _void SetPosition( _float x, _float y )
		{ mPosition.x = x; mPosition.y = y; }

	inline Vector2& GetSize( )
		{ return mSize; }
	inline _void SetSize( _float x, _float y )
		{ mSize.x = x; mSize.y = y; }

	inline string& GetName( )
		{ return mName; }
	inline _void SetTransform( string name )
		{ mName = name; }

	inline Matrix4& GetTransform( )
		{ return mTransform; }
	inline _void SetTransform( Matrix4 transform )
		{ mTransform = transform; }

	virtual _bool VisibleByCamera( ){ return _true; }
	virtual _void UpdateTransform( Matrix4 partenmat );
	virtual _void Visit( Renderer renderer, Matrix4 parentmat );
	virtual _void Draw( Renderer renderer ) = 0;
};

}