#include "Main.h"
#include "TemplatedList.h"
using namespace std;

#define _SCL_SECURE_NO_WARNINGS
#pragma warning(disable:4996)

void main(void) {

	TemplatedList<int>* intList = new TemplatedList<int>();
	intList->Push(3);
	intList->Push(4);
	intList->Push(2);

	intList->Print();

	cout << intList->length() << endl;
	cout << intList->Pop() << endl;
	cout << intList->length() << endl;

	delete intList;

	cout << "Press Enter to continue...";
	getchar();
}