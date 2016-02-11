#pragma once
#include <vector>
#include "Mesh.h"

using namespace std;

class MeshManager
{
private:
	static MeshManager* s_instance;
public:
	vector<Mesh*> meshes;
	Mesh* AddModel(string);
	void PrintContents();
	static MeshManager *instance();
	static void ReleaseInstance();
};