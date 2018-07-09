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

	inline virtual _bool IsVisible( )
		{ return mVisible; }
	inline virtual _void SetVisible( _bool value )
		{ mVisible = value; }

	inline virtual _bool IsEnableTouch( )
		{ return mEnableTouch; }
	inline virtual _void SetEnableTouch( _bool value )
		{ mEnableTouch = value; }

	inline virtual _bool GetZOrder( )
		{ return mZOrder; }
	inline virtual _void SetZOrder( _long value )
		{ mZOrder = value; }

	inline virtual Vector2& GetPosition( )
		{ return mPosition; }
	inline virtual _void SetPosition( _float x, _float y )
		{ mPosition.x = x; mPosition.y = y; }

	inline virtual Vector2& GetSize( )
		{ return mSize; }
	inline virtual _void SetSize( _float x, _float y )
		{ mSize.x = x; mSize.y = y; }

	inline virtual string& GetName( )
		{ return mName; }
	inline virtual _void SetTransform( string name )
		{ mName = name; }

	inline virtual Matrix4& GetTransform( )
		{ return mTransform; }
	inline virtual _void SetTransform( Matrix4 transform )
		{ mTransform = transform; }

	virtual _bool VisibleByCamera( ){ return _true; }
	virtual _void UpdateTransform( Matrix4 partenmat );
	virtual _void Visit( Renderer* renderer, Matrix4 parentmat );
	virtual _void Draw( Renderer* renderer ) = 0;
	virtual _void OnRender( _float elapse ){ }
};

}