#include "String.h"

String::String()
{
	size = 0;
	arr = NULL;
}

String::String(int n)
{
	size = n;
	arr = new char[n];
	for (int i = 0; i < size; ++i)
		arr[i] = ' ';
}

String::String(String& other)
{
	size = other.size;
	arr = new char[size];
	for (int i = 0; i < size; ++i)
		arr[i] = other.arr[i];
}

void String::insert_symbol(int pos, char symbol)
{
	size++;
	char* new_arr = new char[size + 1];
	for (int i = 0; i < pos; ++i)
		new_arr[i] = arr[i];
	new_arr[pos] = symbol;
	for (int i = pos + 1; i < size; ++i)
		new_arr[i] = arr[i - 1];
	delete[] arr;
	arr = new_arr;
}

void String::delete_space()
{
	int count = 0;
	for (int i = 0; i < size; ++i)
		if (arr[i] == ' ')
			count++;
	if (count > 0)
	{
		char* new_arr = new char[size - count];
		int j = 0;
		for (int i = 0; i < size; ++i)
			if (arr[i] != ' ')
				new_arr[j++] = arr[i];
		size = size - count;
		delete[] arr;
		arr = new_arr;
	}
}

void String::clear()
{
	size = 0;
	delete[] arr;
	arr = NULL;
}

int String::Size()
{
	return size;
}

void String::push_back(char value)
{
	char* new_arr = new char[size + 1];
	for (int i = 0; i < size; ++i)
		new_arr[i] = arr[i];
	new_arr[size] = value;
	size++;
	delete[] arr;
	arr = new_arr;
}

void String::random()
{
	for (int i = 0; i < size; ++i)
		arr[i] = rand() % 26 + 97;
}

void String::yourself()
{
	char value;
	for (int i = 0; i < size; ++i)
	{
		cin >> value;
		arr[i] = value;
	}
}

void String::print()
{
	for (int i = 0; i < size; ++i)
		cout << arr[i];
	cout << '\n';
}

void String::foo(String other)
{
	int size_other = other.Size();
	bool flag = false;
	char el;
	for (int i = 0; i < size_other; ++i)
	{
		el = other.arr[i];
		flag = false;
		for (int j = 0; j < size; ++j)
			if (arr[j] == el)
			{
				flag = true;
				break;
			}
		if (!flag)
			insert_symbol(i, el);
	}
}

char& String::operator[](int pos)
{
	if (pos >= 0 && pos < size)
		return arr[pos];
	else
		return arr[size - 1];
}

const char& String::operator[](int pos) const
{
	if (pos >= 0 && pos < size)
		return arr[pos];
	else
		return arr[size - 1];
}

String::~String()
{
	clear();
}
