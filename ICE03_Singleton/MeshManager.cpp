#include "MeshManager.h"
#include <iostream>

MeshManager* MeshManager::s_instance = nullptr;

MeshManager* MeshManager::instance() {
	if (s_instance == nullptr) {
		s_instance = new MeshManager;
	}
	return s_instance;
}

void MeshManager::ReleaseInstance() {
	if (s_instance != nullptr) {
		delete s_instance;
		s_instance = nullptr;
	}
}

Mesh* MeshManager::AddModel(string filename) {
	Mesh* mesh = new Mesh(filename);
	meshes.push_back(mesh);
	return mesh;
}

void MeshManager::PrintContents() {
	cout << meshes.size() << " Meshes:" << endl;
	for (vector<Mesh*>::iterator it = meshes.begin(); it != meshes.end(); ++it)
	{
		cout << **it << endl;
	}
}