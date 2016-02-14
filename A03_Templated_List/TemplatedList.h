#pragma once

#include <iostream>
using namespace std;

#define _SCL_SECURE_NO_WARNINGS
#pragma warning(disable:4996)

template<class T>
class TemplatedList
{
	T* data;
	int entries;
	int size;
	void Release()
	{
		if (data != nullptr) {
			delete[] data;
			data = nullptr;
		}
		entries = 0;
	};
	void Swap(TemplatedList<T>& other) {
		swap(this->entries, other.entries);
		swap(this->size, other.size);
		swap(this->data, other.data);
	};
public:
	int length()
	{
		return entries;
	};
	void Push(T item)
	{
		if (size < entries + 1) {
			//T* tempData = static_cast<T*>(malloc(size * 2 * sizeof(T)));
			T* tempData = new T[size * 2];
			//memcpy(tempData, data, size * sizeof(T));
			copy(data, data + size, tempData);
			delete[] data;
			data = tempData;
			size *= 2;
		}

		*(data + entries++) = item;

	};
	T Pop()
	{
		return *(data + --entries);
	};
	bool isEmpty()
	{
		return entries > 0;
	};
	void Print() {
		cout << entries << " items in list: " << endl;
		for (size_t i = 0; i < entries; i++)
		{
			cout << *(data + i) << endl;
		}
	}

	friend ostream& operator<<(ostream& os, const TemplatedList& list)
	{

	};

	//Constructors
	TemplatedList<T>() : data(nullptr), entries(0) 
	{
		size = 1;
		data = new T[size];
	};
	TemplatedList<T>(int _entries) : data(nullptr)
	{
		entries = _entries;
		size = 1;
		while (size < _entries) {
			size = size * 2;
		}
		data = new T[size];
		//data = static_cast<T*>(malloc(tempSize * sizeof(T)));
	};

	//Destructor
	~TemplatedList<T>()
	{
		Release();
	};

	//Copy Constructor
	TemplatedList<T>(const TemplatedList &other) {
		TemplatedList<T> temp(other.size());
		memcpy(&temp, &other, sizeof(TemplatedList));
		Swap(temp);
	};

	//Copy Assignment operator
	TemplatedList<T>& operator=(const TemplatedList<T>& other)
	{
		if (this != &other)
		{
			Release();
			TemplatedList<T> temp(other.length());
			memcpy(&temp, &other, sizeof(TemplatedList));
			Swap(temp);
		}
		return *this;
	};
};

