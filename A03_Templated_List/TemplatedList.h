#pragma once

#include <iostream>
using namespace std;

template<class T>
class TemplatedList
{
	//number of items memory is allocated for
	int size;
	//number of items stored
	int entries;
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
	void Swap(TemplatedList& other) {
		std::swap(entries, other.entries);
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
	void Push(T item)
	{
		//if the allocated memory is full
		if (size < entries + 1) {
			//create a temp pointer and allocate more memory
			T* tempData = new T[size * 2];
			//copy the existing data into the new memory
			//memcpy(tempData, data, size * sizeof(T));
			copy(data, data + size, tempData);
			//deallocate old memory
			delete[] data;
			//point to new data
			data = tempData;
			//save the new size
			size *= 2;
		}

		//add item at the next available location
		*(data + entries++) = item;

	};

	//get the last item and remove it from the list
	T Pop()
	{
		return *(data + --entries);
	};

	//indicates if there are any items in the list
	bool IsEmpty()
	{
		return entries > 0;
	};

	//print out the list to the console
	void Print() {
		cout << *this;
	}

	//create stream containing size of list and contents
	friend ostream& operator<<(ostream& os, const TemplatedList& list)
	{
		os << list.entries << " items in list: " << endl;
		for (size_t i = 0; i < list.entries; i++)
		{
			os << i << ": " << list[i] << endl;
		}
		return os;
	};

	//index operator overrides
	T operator [](int i) const
	{
		return *(data + i);
	}

	T & operator [](int i)
	{
		return *(data + i);
	}

	//Constructors
	//default constructor for simple initialization
	TemplatedList<T>() 
		: size(1),
		entries(0),
		data(new T[size])
	{};

	//constructor the allocates memory for specified number of items
	TemplatedList<T>(int _entries) 
		: size(1), 
		entries(_entries), 
		data(nullptr)
	{
		//figure out how much memory to allocate (next power of 2, i.e. 5 => 8, 30 => 32)
		while (size < _entries) {
			size *= 2;
		}
		data = new T[size];
	};

	//Destructor
	~TemplatedList<T>()
	{
		Release();
	};

	//Copy Constructor
	TemplatedList(const TemplatedList<T>& other) 
		: size(other.size),
		entries(other.entries),
		data(new T[other.size])
	{
		//copy other data into this new list
		//TemplatedList<T> temp(other.entries);
		//memcpy(temp.data, other.data, sizeof(T) * other.size);
		//Swap(temp);

		//there's not practical reason to use memcpy so just using std::copy
		copy(other.data, other.data + other.size, data);
	};

	//Copy Assignment operator
	//Pass by value executes copy ctor
	TemplatedList& operator=(TemplatedList rhs)
	{
		//don't need a self check here
		Swap(rhs);
		return *this;
	};
};