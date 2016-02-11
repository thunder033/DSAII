#include "Mesh.h"
#include <iostream>

using namespace std;

Mesh::Mesh()
{
	name = "";
}

Mesh::Mesh(string filename)
{
	name = filename;
}

ostream& operator<<(ostream& os, const Mesh& mesh)
{
	os << mesh.name;
	return os;
}

Mesh::~Mesh()
{
}
