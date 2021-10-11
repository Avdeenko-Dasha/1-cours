#pragma once
#include <iostream>
using namespace std;

template <typename T>
class vector
{
private:
	int size;
	T* arr;
public:
	vector();

	vector(int n);

	vector(int, T);

	vector(const vector& other);

	int Size();

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

	void push_back(T el);

	void pop_back();

	void resize(int n);

	void clear();

	void random();

	T& operator [](int n);

	const T& operator [](int n) const;

	vector<T>& operator =(const vector<T>& other);

	~vector();
};


template<typename T>
vector<T>::vector()
{
	size = 0;
	arr = NULL;
}

template<typename T>
vector<T>::vector(int n)
{
	size = n;
	arr = new T[n];
	for (int i = 0; i < size; ++i)
		arr[i] = 0;
}

template<typename T>
vector<T>::vector(int n, T value)
{
	vector = new T[n];
	for (int i = 0; i < n; ++i)
		vector[i] = value;
	size = n;
}

template<typename T>
vector<T>::vector(const vector& other)
{
	size = other.size;
	arr = new T[size];
	for (int i = 0; i < size; ++i)
		arr[i] = other.arr[i];
}

template<typename T>
int vector<T>::Size()
{
	return size;
}

template<typename T>
void vector<T>::push_back(T el)
{
	size++;
	T* arr2 = new T[size];

	for (int i = 0; i < size - 1; ++i)
		arr2[i] = arr[i];

	arr2[size - 1] = el;
	delete[] arr;
	arr = arr2;
}

template<typename T>
void vector<T>::pop_back()
{
	size--;
	T* arr2 = new T[size];

	for (int i = 0; i < size; ++i)
		arr2[i] = arr[i];

	delete[] arr;
	arr = arr2;
}

template<typename T>
void vector<T>::resize(int n)
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

template<typename T>
void vector<T>::clear()
{
	size = 0;
	delete[] arr;
	arr = NULL;
}

template<typename T>
void vector<T>::random()
{
	for (int i = 0; i < size; ++i)
		arr[i] = rand() % 100;
}

template<typename T>
T& vector<T>::operator[](int n)
{
	if (n < size)
		return arr[n];
	else
		return arr[size - 1];
}

template<typename T>
const T& vector<T>::operator[](int n) const 
{
	if (n < size)
		return arr[n];
	else
		return arr[size - 1];
}

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

template<typename T>
inline vector<T>& vector<T>::operator=(const vector<T>& other)
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

template<typename T>
vector<T>::~vector()
{
	cout << "Destruct " << this << endl;
	delete[] arr;
}


