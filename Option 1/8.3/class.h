#pragma once
#include <iostream>

using namespace std;

class Number
{
private:
	int* Mass;
	int Size;

	void perekid()
	{
		for (int i = Size - 1; i > 0; --i)
		{
			Mass[i - 1] += Mass[i] / 10;
			Mass[i] = Mass[i] % 10;
		}
		Mass[0] = Mass[0] % 10;
	}
public:
	Number() : Size(32)
	{
		Mass = new int[Size];
		for (int i = 0; i < Size; ++i)
			Mass[i] = 0;
	}
	Number(string s)
	{
		Size = 32;
		Mass = new int[Size];
		int i = Size - 1;

		for (int j = s.size() - 1; i >= 0 && j >= 0; --i, --j)
			Mass[i] = s[j] - '0';

		for (; i >= 0; --i)
			Mass[i] = 0;
	}
	Number(const Number& other)
	{
		Size = other.Size;
		Mass = new int[Size];
		for (int i = 0; i < Size; ++i)
			Mass[i] = other.Mass[i];
	}



	Number& operator + (const Number& );
	Number& operator *(int );
	Number& operator* (const Number&);


	Number& operator <<= (const int n);//смещение влево на n знаков

	Number& operator = (const Number&);
	

	friend istream& operator >> (istream&, Number& );

	friend ostream& operator << (ostream&, Number&);

	int& operator[](const int i);

	~Number()
	{
		delete[] Mass;
	}
};