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
	_void LoadModel( const string& filename );

private:
	_void processNode( _void* node, _void* scene );
	Mesh* processMesh( _void* mesh, _void* scene );
	vector<Texture*> loadMaterialTextures( _void *mat, _dword type );
};

}