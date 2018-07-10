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

	virtual _void OnRender( _float elapse ) = 0;

};

}