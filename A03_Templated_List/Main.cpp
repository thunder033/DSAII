#include "Main.h"
#include "TemplatedList.h"
using namespace std;

void main(void) {

	TemplatedList<int> intList = TemplatedList<int>();
	intList.Push(3);
	intList.Push(4);
	intList.Push(2);

	intList.Print();

	cout << intList.GetSize() << endl;
	int myInt = intList.Pop();
	cout << intList.GetSize() << endl;
	intList.Push(5);
	cout << myInt << endl;

	//TemplatedList<int>* intList2 = new TemplatedList(intList);
	TemplatedList<int> intList2(intList);
	TemplatedList<int> intList3 = TemplatedList<int>();
	//intList3 = intList;

	intList.~TemplatedList();
	//intList2.~TemplatedList();
	//intList3.~TemplatedList();

	cout << "Press Enter to continue...";
	getchar();
}