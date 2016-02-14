#pragma once

#include <iostream>
using namespace std;

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

	void Swap(TemplatedList& other) {
		swap(entries, other.entries);
		swap(size, other.size);
		swap(data, other.data);
	};
public:
	int GetSize()
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
	bool IsEmpty()
	{
		return entries > 0;
	};
	void Print() {
		cout << *this;
	}

	friend ostream& operator<<(ostream& os, const TemplatedList& list)
	{
		os << list.entries << " items in list: " << endl;
		for (size_t i = 0; i < list.entries; i++)
		{
			os << i << ": " << list[i] << endl;
		}
		return os;
	};

	T operator [](int i) const
	{
		return *(data + i);
	}

	T & operator [](int i)
	{
		return *(data + i);
	}

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
	TemplatedList(const TemplatedList& other) {
		cout << "Called Copy Constructor" << endl;
		TemplatedList<T> temp(other.entries);
		memcpy(&temp, &other, sizeof(TemplatedList));
		Swap(temp);
	};

	//Copy Assignment operator
	//template <class T>
	TemplatedList& operator=(TemplatedList other)
	{
		cout << "Called Copy Assignment" << endl;
		if (this != &other && false)
		{
			Release();
			TemplatedList<T> temp(other.GetSize());
			memcpy(&temp, &other, sizeof(TemplatedList));
			Swap(temp);
		}
		Swap(other);
		return *this;
	};
};

