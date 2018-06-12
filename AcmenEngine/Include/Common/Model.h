#pragma once
namespace Acmen
{

class Model : public RenderObject
{
public:
	vector< Mesh* > mMeshs;
	string			mResName;

public:
	Model( ) = default;
	Model( const string& filename );
	~Model( ) = default;
	virtual _void Render( );
};

}