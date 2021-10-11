#pragma once
#include <iostream>
#include <conio.h>

using namespace std;

class String
{
	int size;
	char* arr;
public:
	String();
	String(int n);
	String(String& other);

	void insert_symbol(int pos, char symbol);
	void delete_space();
	void clear();
	int Size();
	void push_back(char value);
	void random();
	void yourself();
	void print();
	void foo(String other);

	char& operator[](int pos);
	const char& operator[](int pos) const;

	~String();
};

//istream& operator >> (istream& input, String& a)
//{
//	int size = a.Size();
//	char x = 0;
//	x = _getch();
//	cout << x;
//	for (int i = 0; i < size && x != '\r'; i++) 
//	{
//		a[i] = x;
//		x = 0;
//		x = _getch();
//		cout << x;
//	}
//
//	while (x != '\r') 
//	{
//		a.push_back(x);
//		x = 0;
//		x = _getch();
//		cout << x;
//	}
//	cout << "\n";
//	return input;
//}
//
//ostream& operator <<(ostream& outp, String& a)
//{
//	for (int i = 0; i < a.Size(); ++i)
//		outp << a[i];
//	outp << '\n';
//	return outp;
//}
