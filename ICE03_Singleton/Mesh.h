#pragma once
#include <string>

using namespace std;

class Mesh
{
private:
	string name;
public:
	Mesh();
	Mesh(string);
	friend ostream& operator<<(ostream& os, const Mesh& mesh);
	~Mesh();
};

