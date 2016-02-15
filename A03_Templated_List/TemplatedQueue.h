#pragma once

#include <iostream>
using namespace std;

template<class T>
class TemplatedQueue
{
	//number of items memory is allocated for
	int size;
	//number of items stored
	int entries;
	//number of items removed from queue
	int dequeuedEntries;
	//pointer to data
	T* data;

	//free memory for data
	void Release()
	{
		if (data != nullptr) {
			delete[] data;
			data = nullptr;
		}
		entries = 0;
		size = 1;
	};

	//swap two templated lists
	void Swap(TemplatedQueue& other) {
		std::swap(entries, other.entries);
		std::swap(dequeuedEntries, other.dequeuedEntries);
		std::swap(size, other.size);
		std::swap(data, other.data);
	};
public:

	//get number of items in list
	int GetSize()
	{
		return entries;
	};

	//add new item to list
	void Enqueue(T item)
	{
		//if the allocated memory is full
		if (size < entries + 1) {

			int currentEntries = entries - dequeuedEntries;
			size = pow(2, ceil(log2(currentEntries + 1)));

			//create a temp pointer and allocate more memory
			T* tempData = new T[size];
			//copy the existing data into the new memory
			copy(data + dequeuedEntries, data + entries, tempData);
			//deallocate old memory
			delete[] data;
			//point to new data
			data = tempData;

			entries = currentEntries;
			dequeuedEntries = 0;
		}

		//add item at the next available location
		*(data + entries++) = item;

	};

	//get the last item and remove it from the list
	T Dequeue()
	{
		return *(data + dequeuedEntries++);
	};

	//indicates if there are any items in the list
	bool IsEmpty()
	{
		return entries >= dequeuedEntries;
	};

	//print out the list to the console
	void Print() {
		cout << *this;
	}

	//create stream containing size of list and contents
	friend ostream& operator<<(ostream& os, const TemplatedQueue& list)
	{
		os << (list.entries - list.dequeuedEntries) << " items in list: " << endl;
		for (size_t i = list.dequeuedEntries; i < list.entries; i++)
		{
			os << i << ": " << list[i] << endl;
		}
		return os;
	};

	//Constructors
	//default constructor for simple initialization
	TemplatedQueue<T>()
		: size(1),
		entries(0),
		dequeuedEntries(0),
		data(new T[size])
	{};

	//constructor the allocates memory for specified number of items
	TemplatedQueue<T>(int _entries)
		: size(1),
		entries(_entries),
		dequeuedEntries(0),
		data(nullptr)
	{
		//figure out how much memory to allocate (next power of 2, i.e. 5 => 8, 30 => 32)
		while (size < _entries) {
			size *= 2;
		}
		data = new T[size];
	};

	//Destructor
	~TemplatedQueue<T>()
	{
		Release();
	};

	//Copy Constructor
	TemplatedQueue(const TemplatedQueue<T>& other)
		: size(other.size),
		entries(other.entries),
		dequeuedEntries(other.dequeuedEntries),
		data(new T[other.size])
	{
		//copy other data into this new list
		//TemplatedQueue<T> temp(other.entries);
		//memcpy(temp.data, other.data, sizeof(T) * other.size);
		//Swap(temp);

		//there's not practical reason to use memcpy so just using std::copy
		copy(other.data, other.data + other.size, data);
	};

	//Copy Assignment operator
	//Pass by value executes copy ctor
	TemplatedQueue& operator=(TemplatedQueue rhs)
	{
		//don't need a self check here
		Swap(rhs);
		return *this;
	};
};