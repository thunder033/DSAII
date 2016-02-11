#include "Main.h"
#include "Mesh.h"
#include "MeshManager.h"

using namespace std;

int main(void) {

	MeshManager* oMeshManager = MeshManager::instance();

	oMeshManager->PrintContents();
	oMeshManager->AddModel("Duck.obj");
	oMeshManager->AddModel("Horse.obj");
	oMeshManager->AddModel("Bird.obj");
	oMeshManager->AddModel("Dog.obj");
	oMeshManager->PrintContents();
	MeshManager::ReleaseInstance();

	getchar();
	return 0;
}