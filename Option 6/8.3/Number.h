#pragma once
#include <iostream>
#include <string>

using namespace std;

class Number
{
	int size;
	int* arr;
public:
	Number()
	{
		size = 256;
		arr = new int[size];
		for (int i = 0; i < size; ++i)
			arr[i] = 0;
	}
	Number(int n)
	{
		size = n;
		arr = new int[n];
		for (int i = 0; i < n; ++i)
			arr[i] = 0;
	}
	Number(Number& other)
	{
		size = other.size;
		arr = new int[size];
		for (int i = 0; i < size; ++i)
			arr[i] = other.arr[i];
	}

	int getsize()
	{
		return size;
	}
	void resize(int n)
	{
		int* other = new int[n];
		if (size > n)
			for (int i = n - 1, j = size - 1; i >= 0; --i, --j)
				other[i] = arr[j];
		else
		{
			int i = size - 1;
			for (; i >= n; --i)
				other[i] = arr[i];
			for (; i >= 0; --i)
				other[i] = arr[i];
		}
		size = n;
		delete[] arr;
		arr = other;
	}
	void perevod_2(int pov)
	{
		size = pov + 1;
		delete[] arr;
		arr = new int[size];
		for (int i = 0; i < size - 1; ++i)
			arr[i] = 0;
		arr[size - 1] = 1;
	}
	void perevod_num(int num)
	{
		int i = 0; 
		int x = num;
		for (; x > 1; ++i)
			x = x / 2;
		resize(i + 1);
		int j = 0;
		for (; j < i; ++j)
		{
			arr[j] = num % 2;
			num = num / 2;
		}
		arr[j] = 1;
	}

	void sum(Number& slag)
	{
		int n = 0;
		int* other = NULL;
		if (size > slag.size)
		{
			n = size + 1;
			other = new int[n];
			for (int i = 0; i < slag.size; ++i)
			{
				int sum = arr[i] + slag.arr[i];
				bool flag = true;
				if (sum > 1)
				{
					other[i] = 0;
					flag = false;
				}
				else other[i] = sum;

				if (flag == false)
					arr[i + 1] += 1;
			}
			for (int i = slag.size; i < size; ++i)
			{
				if (arr[i] > 1)
					if (i + 1 < size)
					{
						arr[i + 1] += 1;
						other[i] = 0;
					}
					else
					{
						other[i] = 0;
						other[i + 1] = 1;
					}
				else other[i] = arr[i];
			}
		}
		else
		{
			n = slag.size + 1;
			other = new int[n];
			for (int i = 0; i < size; ++i)
			{
				int sum = arr[i] + slag.arr[i];
				bool flag = true;
				if (sum > 1)
				{
					other[i] = 0;
					flag = false;
				}
				else other[i] = sum;

				if (flag == false)
					slag.arr[i + 1] += 1;
			}
			for (int i = size; i < slag.size; ++i)
			{
				if (slag.arr[i] > 1)
					if (i + 1 < slag.size)
					{
						slag.arr[i + 1] += 1;
						other[i] = 0;
					}
					else
					{
						other[i] = 0;
						other[i + 1] = 1;
					}
				else other[i] = slag.arr[i];
			}
		}
		delete[] arr;
		size = n;
		arr = other;
	}


	int& operator[](int pos)
	{
		if (pos >= 0 && pos < size)
			return arr[pos];
		else return arr[size - 1];
	}
	const int& operator[](int pos) const
	{
		if (pos >= 0 && pos < size)
			return arr[pos];
		else return arr[size - 1];
	}
	~Number()
	{
		size = 0;
		delete[] arr;
		arr = NULL;
	}
};

ostream& operator << (ostream& outp, Number& a)
{
	for (int i = a.getsize() - 1; i >= 0; --i)
		outp << a[i];
	return outp;
}

istream& operator >> (istream& inp, Number& a)
{
	string x;
	getline(inp, x);
	int j = 0;
	for (int i = a.getsize() - 1; i >= 0 && j < x.size(); --i, ++j)
	{
		int z = x[j] - 48;
		a[i] = z;
	}
	a.resize(x.size());
	return inp;
}