#pragma once
namespace Acmen
{
class Shapes: public RenderObject
{
public:
	vector< Vertex >		mVertices;
	vector< _dword >		mIndices;
	Matrix4					mTransform;
	Shader*					mShader;
	_dword					mVAO;
	_bool					mIsInited;

public:
	inline Shapes( ):mTransform( Matrix4( ) ), mIsInited( _false ), mShader( _null ) { }
	inline Shapes( vector< Vertex > vertices, vector< _dword > indices )
		: mVertices( vertices ), mIndices( indices ), mTransform( Matrix4( ) ), mIsInited( _false ), mShader( _null ) { }
	~Shapes( );

	_void InitShape( );
	_void InitVAO( );
	_void InitShader( );
	_void BindShaderData( );
	_void Render( );
};
}