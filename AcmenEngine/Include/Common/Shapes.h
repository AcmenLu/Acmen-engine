#pragma once
namespace Acmen
{
class Shapes: public RenderObject
{
public:
	Matrix4					mTransform;

public:
	inline Shapes( ):mTransform( Matrix4( ) ){ }
	inline Shapes::Shapes( vector< Vertex > vertices, vector< _dword > indices )
		: RenderObject( vertices, indices ),mTransform( Matrix4( ) ) { }
	inline ~Shapes( ) { };

	inline Matrix4& GetTransform( )
		{ return mTransform; }
	inline _void SetTransform( Matrix4 transform )
		{ mTransform = transform; }

	_bool CreateShader( );
	_bool SetUniform( );
	inline _void Update( _float elapse ){ };
	_void Render( _float elapse );
};
}