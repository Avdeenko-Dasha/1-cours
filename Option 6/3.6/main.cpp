#include<iostream>
#include <iomanip>

using namespace std;

void sum(int* subtr, int* subtrahend, int size_subtr, int& size_subtrahend)
{
	int length = 0;
	if (size_subtr > size_subtrahend)
		length = size_subtr + 1;
	else
		length = size_subtrahend + 1;

	for (int i = 0; i < length; ++i)
	{
		subtrahend[i] += subtr[i];
		subtrahend[i + 1] += (subtrahend[i] / 10);
		subtrahend[i] %= 10;
	}

	if (subtrahend[length - 1] == 0)
		--length;
	size_subtrahend = length;
}

void difference(int* number_1, int* subtrahend, int* slag, int& size_slag)
{
	if (size_slag > 1)
		for (int i = 0; i < size_slag; ++i)
		{
			if (i < size_slag - 1)
			{
				number_1[i + 1]--;
				slag[i] += 10 + number_1[i];
			}
			else
				slag[i] += number_1[i];
			slag[i] -= subtrahend[i];
			if (slag[i] / 10 > 0)
			{
				slag[i + 1]++;
				slag[i] %= 10;
			}
		}
	else
		slag[0] = number_1[0] - subtrahend[0];
}

void subtraction(int* number_1, int* subtrahend, int limit, int size_subtrahend, int* slag, int& size_slag)
{
	int k = 3;
	if (limit > size_subtrahend)
	{
		k = 1;
		size_slag = limit;
	}
	else if (size_subtrahend > limit)
	{
		k = 2;
		size_slag = size_subtrahend;
	}
	else
	{
		size_slag = limit;
		for (int i = size_slag - 1; i >= 0; --i)
		{
			if (number_1[i] > subtrahend[i])
			{
				k = 1;
				break;
			}
			if (subtrahend[i] > number_1[i])
			{
				k = 2;
				break;
			}
		}
	}
	if (k == 1)
		difference(number_1, subtrahend, slag, size_slag);
	if (k == 2)
		difference(subtrahend, number_1, slag, size_slag);
}

void multiplication(int* result, int& length, int* number_2, int* slag, int size_number_2, int size_slag)
{
	length = size_number_2 + size_slag + 1;
	for (int i = 0; i < size_number_2; ++i)
		for (int j = 0; j < size_slag; ++j)
			result[i + j] += number_2[i] * slag[j];
	for (int i = 0; i < length; ++i)
	{
		result[i + 1] += result[i] / 10;
		result[i] %= 10;
	}
	while (result[length] == 0)
		--length;
	++length;
}

bool check(int* subtrahend, int size_subtrahend, int* number, int limit)
{
	if (size_subtrahend != limit)
		return true;
	else
		for (int i = 0; i < limit; ++i)
			if (subtrahend[i] != number[i])
				return true;
	return false;
}

void fan(int& length, int* number_2, int* result, int& size_number_2, int size_slag, int* slag, int limit, int* number_1, int* number_3)
{
	for (int i = length - 1; i >= 0; --i)
		number_2[i] = result[i];
	size_number_2 = length;
	for (int i = length - 1; i >= 0; --i)
		result[i] = 0;
	for (int i = size_slag - 1; i >= 0; --i)
		slag[i] = 0;
	length = 0;
	for (int i = limit - 1; i >= 0; --i)
		number_1[i] = number_3[i];
}

int main()
{
	srand(time(NULL));
	int number_1[100] = { 0 };
	int limit = rand() % 4 + 1;
	for (int i = limit - 1; i >= 0; --i)
		number_1[i] = rand() % 9 + 1;


	int number_2[100000] = { 0 };
	for (int i = limit - 1; i >= 0; --i)
		number_2[i] = number_1[i];

	int number_3[100] = { 0 };
	for (int i = limit - 1; i >= 0; --i)
		number_3[i] = number_1[i];

	int slag[100] = { 0 };
	int result[100000] = { 0 };
	int subtr[100] = { 0 };
	int subtrahend[100] = { 0 };


	int size_number_2 = limit;
	int size_slag = limit;
	int size_subtrahend = 1;
	int size_subtr = 1;
	int length = 0;


	subtrahend[0] = 1;
	subtr[0] = 1;

	
	for (int i = limit - 1; i >= 0; --i)
		cout << number_1[i];
	cout << endl;

	while (check(subtrahend, size_subtrahend, number_1, limit))
	{
		subtraction(number_1, subtrahend, limit, size_subtrahend, slag, size_slag);
		sum(subtr, subtrahend, size_subtr, size_subtrahend);
		multiplication(result, length, number_2, slag, size_number_2, size_slag);
		fan(length, number_2, result, size_number_2, size_slag, slag, limit, number_1, number_3);
	}

	int count = 0;

	for (int i = size_number_2 - 1; i >= 0; --i)
		if (number_2[i] == 7)
			count++;

	cout << count;
	
}