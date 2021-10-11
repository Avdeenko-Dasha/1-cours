#pragma once
#include <iostream>
#include <exception>
#include <cmath>
#include <iomanip>
#include <ctime>

using namespace std;

template <typename T>
class vector
{
private:
	int size;
	T* arr;
public:
	vector() : size(0), arr(nullptr)
	{

	}

	vector(int n)
	{
		size = n;
		arr = new T[n];
		for (int i = 0; i < size; ++i)
			arr[i] = 0;
	}

	vector(int n, T value)
	{
		vector = new T[n];
		for (int i = 0; i < n; ++i)
			vector[i] = value;
		size = n;
	}

	vector(const vector& other)
	{
		size = other.size;
		arr = new T[size];
		for (int i = 0; i < size; ++i)
			arr[i] = other.arr[i];
	}

	int Size()
	{
		return size;
	}

	void assign(int size)
	{
		delete[] arr;
		arr = new T[size];
		for (int i = 0; i < size; i++)
			arr[i] = 0;
		this->size = size;
	}

	void assign(int size, T value)
	{
		delete[] arr;
		arr = new T[size];
		for (int i = 0; i < size; i++)
			arr[i] = value;
		this->size = size;
	}

	void push_back(T el)
	{
		size++;
		T* arr2 = new T[size];

		for (int i = 0; i < size - 1; ++i)
			arr2[i] = arr[i];

		arr2[size - 1] = el;
		delete[] arr;
		arr = arr2;
	}

	void pop_back()
	{
		size--;
		T* arr2 = new T[size];

		for (int i = 0; i < size; ++i)
			arr2[i] = arr[i];

		delete[] arr;
		arr = arr2;
	}

	void resize(int n)
	{
		T* arr1 = new T[n];
		if (n <= size)
		{
			for (int i = 0; i < n; ++i)
				arr1[i] = arr[i];
		}
		else
		{
			for (int i = 0; i < size; ++i)
				arr1[i] = arr[i];
			for (int i = size; i < n; ++i)
				arr1[i] = 0;
		}
		delete[] arr;
		arr = arr1;
		size = n;
	}

	void clear()
	{
		size = 0;
		delete[] arr;
		arr = NULL;
	}

	void random()
	{
		for (int i = 0; i < size; ++i)
			arr[i] = rand() % 100;
	}

	T& operator [](int n)
	{
		if (n < size)
			return arr[n];
		else
			return arr[size - 1];
	}

	const T& operator [](int n) const
	{
		if (n < size)
			return arr[n];
		else
			return arr[size - 1];
	}

	vector<T>& operator =(const vector<T>& other)
	{
		if (this != &other)
		{
			size = other.size;
			delete[] arr;
			arr = new T[size];
			for (int i = 0; i < size; ++i)
				arr[i] = other.arr[i];
		}
		return *this;
	}

	~vector()
	{
		delete[] arr;
	}
};

template <typename T>
ostream& operator << (ostream& outp, vector<T>& a)
{
	for (int i = 0; i < a.Size(); ++i)
		outp << a[i] << " ";
	outp << endl;
	return outp;
}

template <typename T>
istream& operator >> (istream& inp, vector<T>& a)
{
	for (int i = 0; i < a.Size(); ++i)
		inp >> a[i];
	return inp;
}


