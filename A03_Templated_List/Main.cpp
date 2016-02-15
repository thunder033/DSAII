#include "Main.h"
#include "TemplatedList.h"
#include "TemplatedQueue.h"
using namespace std;

void main(void) {

	//Test Basic Constructor
	cout << "Create TemplateList<int>" << endl;
	TemplatedList<int> intList = TemplatedList<int>();
	//Push adds one item: entries = 1, size = 1
	cout << "Push int 3" << endl;
	intList.Push(3);
	//Push adds 2nd item, expands memory: entries = 2, size = 2
	cout << "Push int 4" << endl;
	intList.Push(4);
	//Push adds 3rd item, expands memory: entries = 3, size = 4
	cout << "Push int 2" << endl;
	intList.Push(2);
	cout << endl;

	//usage of GetSize
	cout << "size before pop: " << intList.GetSize() << endl;
	//usage of Pop, removes and returns last item
	cout << "pop on intList:" << intList.Pop() << endl;
	//Check size again, output popped item
	cout << "size after pop: " << intList.GetSize() << endl;
	cout << endl;

	//Usage of operator[] overload
	cout << "Set intList[1] to 22..." << endl;
	intList[1] = 22; //setter
	cout << "Expecting intList[1] = 22" << endl;
	cout << "Int List item 1: " << intList[1] << endl; //getter
	cout << endl;

	//Print out list
	intList.Print();
	cout << endl;

	//Test Copy Ctor Overload
	cout << "create 2nd list with copy constructor" << endl;
	TemplatedList<int> intList2(intList);

	//Test Copy Assignemnt overload
	cout << "create 3rd list" << endl;
	TemplatedList<int> intList3 = TemplatedList<int>();
	cout << "add an item" << endl;
	intList3.Push(10);
	cout << "use copy assignment operator" << endl;
	intList2 = intList3;
	cout << endl;

	//Usage of IsEmpty()
	cout << "Using is empty" << endl;
	cout << (intList3.IsEmpty() ? "List 3 has items" : "List 3 is empty") << endl;
	cout << "pop from intList3:" << intList3.Pop() << endl;
	cout << (intList3.IsEmpty() ? "List 3 has items" : "List 3 is empty") << endl;
	cout << endl;

	//print out contents of all 3 lists to verify no memory issues
	cout << "Verify list contents:" << endl;
	cout << intList << endl;
	cout << intList2 << endl;
	cout << intList3 << endl;
	cout << endl;

	//clear contents of all 3 lists
	cout << "Deallocate all lists" << endl;
	intList.~TemplatedList();
	intList2.~TemplatedList();
	intList3.~TemplatedList();

	cout << "Start Templated Queue" << endl;
	TemplatedQueue<float> myQ = TemplatedQueue<float>();
	//Entries, Size, DequeuedEntries
	myQ.Enqueue(33); //1, 1, 0
	myQ.Enqueue(34); //2, 2, 0
	myQ.Enqueue(35); //3, 4, 0
	myQ.Enqueue(36); //4, 4, 0

	//Entries, Size, DequeuedEntries
	cout << myQ.Dequeue() << endl; //4, 4, 1
	cout << myQ.Dequeue() << endl; //4, 4, 2
	//enqueing here triggers memeory re-allocation and indexes reset
	myQ.Enqueue(37);			   //3, 4, 0
	cout << myQ.Dequeue() << endl; //2, 4, 1
	cout << myQ.Dequeue() << endl; //1, 4, 2
	cout << myQ.Dequeue() << endl; //0, 4, 3

	myQ.~TemplatedQueue();

	cout << "Press Enter to continue...";
	getchar();
}