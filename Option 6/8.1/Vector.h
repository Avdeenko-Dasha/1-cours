#pragma once

template<typename T>
class Vector
{
	int size;
	T* arr;
public:
	Vector();
	Vector(int n);
	Vector(int n, T value);
	Vector(const Vector& other);

	int Size();
	void resize(int n);
	void random();
	void push_back(int value);
	void pop_back();
	void clear();

	T& operator[] (int n);
	const T& operator[] (int n) const;
	
	~Vector();
};

template<typename T>
std::ostream& operator<<(std::ostream& output, Vector<T>& a)
{
	for (int i = 0; i < a.Size(); ++i)
		output << a[i] << " ";
	output << '\n';
	return output;
}

template<typename T>
std::istream& operator>>(std::istream& input, Vector<T>& a)
{
	for (int i = 0; i < a.Size(); ++i)
		input >> a[i];
	return input;
}

template<typename T>
inline Vector<T>::Vector()
{
	size = 0;
	arr = NULL;
}

template<typename T>
inline Vector<T>::Vector(int n)
{
	arr = new T[n];
	size = n;
	for (int i = 0; i < n; ++i)
		arr[i] = 0;
}

template<typename T>
inline Vector<T>::Vector(int n, T value)
{
	size = n;
	arr = new T[n];
	for (int i = 0; i < n; ++i)
		arr[i] = value;
}

template<typename T>
inline Vector<T>::Vector(const Vector& other)
{
	size = other.size;
	arr = new T[size];
	for (int i = 0; i < size; ++i)
		arr[i] = other.arr[i];
}

template<typename T>
inline int Vector<T>::Size()
{
	return size;
}

template<typename T>
inline void Vector<T>::resize(int n)
{
	T* new_arr = new T[n];
	if (n > size)
	{
		for (int i = 0; i < size; ++i)
			new_arr[i] = arr[i];
		for (int i = size; i < n; ++i)
			new_arr[i] = 0;
	}
	else
		for (int i = 0; i < n; ++i)
			new_arr[i] = arr[i];
	delete[] arr;
	arr = new_arr;
	size = n;
}

template<typename T>
inline void Vector<T>::random()
{
	for (int i = 0; i < size; ++i)
		arr[i] = rand() % 10;
}

template<typename T>
inline void Vector<T>::push_back(int value)
{
	T* new_arr = new T[size + 1];
	for (int i = 0; i < size; ++i)
		new_arr[i] = arr[i];
	new_arr[size] = value;
	size++;
	delete[] arr;
	arr = new_arr;
}

template<typename T>
inline void Vector<T>::pop_back()
{
	size--;
	T* new_arr = new T[size];
	for (int i = 0; i < size; ++i)
		new_arr[i] = arr[i];
	delete[] arr;
	arr = new_arr;
}

template<typename T>
inline void Vector<T>::clear()
{
	delete[] arr;
	arr = NULL;
	size = 0;
}

template<typename T>
inline T& Vector<T>::operator[](int n)
{
	if (n < size && n >= 0)
		return arr[n];
	else
		return arr[size - 1];
}

template<typename T>
inline const T& Vector<T>::operator[](int n) const
{
	if (n < size && n >= 0)
		return arr[n];
	else
		return arr[size - 1];
}

template<typename T>
inline Vector<T>::~Vector()
{
	clear();
}

