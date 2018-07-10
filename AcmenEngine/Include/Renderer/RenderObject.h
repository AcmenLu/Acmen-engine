#pragma once

namespace Acmen
{

class RenderObject
{
protected:
	Matrix4		mTransform;

public:
	inline RenderObject( ) : mTransform( Matrix4( ) ){ }
	inline ~RenderObject( ) { }

	virtual Matrix4& GetTransform( )
		{ return mTransform; }
	virtual _void SetTransform( Matrix4& mat4 )
		{ mTransform = mat4; }

	virtual _void OnRender( _float elapse ) = 0;
};

}