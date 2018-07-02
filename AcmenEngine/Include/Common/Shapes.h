#pragma once
namespace Acmen
{
class Shapes: public RenderObject
{
public:
	Matrix4					mTransform;
	_bool					mIsInited;

public:
	inline Shapes( ):mTransform( Matrix4( ) ), mIsInited( _false ){ }
	Shapes( vector< Vertex > vertices, vector< _dword > indices );

	~Shapes( );

	_void InitShape( );
	_void InitShader( );
	_void BindShaderData( );
	_void Render( );
};
}