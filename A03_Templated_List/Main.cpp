#include "Main.h"
#include "TemplatedList.h"
using namespace std;

void main(void) {

	TemplatedList<int> intList = TemplatedList<int>();
	intList.Push(3);
	intList.Push(4);
	intList.Push(2);

	intList[1] = 22;
	cout << "Int List item 1: " << intList[1] << endl;
	intList.Print();

	cout << intList.GetSize() << endl;
	int myInt = intList.Pop();
	cout << intList.GetSize() << endl;
	intList.Push(5);
	cout << myInt << endl;

	TemplatedList<int> intList2(intList);
	TemplatedList<int> intList3 = TemplatedList<int>();
	intList3.Push(10);
	intList2 = intList3;

	cout << (intList3.IsEmpty() ? "List 3 has items" : "List 3 is empty") << endl;
	intList3.Pop();
	cout << (intList3.IsEmpty() ? "List 3 has items" : "List 3 is empty") << endl;

	cout << intList << endl;
	cout << intList2 << endl;
	cout << intList3 << endl;

	intList.~TemplatedList();
	intList2.~TemplatedList();
	intList3.~TemplatedList();

	cout << "Press Enter to continue...";
	getchar();
}