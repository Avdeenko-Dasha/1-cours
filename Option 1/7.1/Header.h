#pragma once
#include <iostream>
#include <iomanip>
#include <fstream>
#include <ios>
#include <streambuf>

using namespace std;

void sort_exchange(int* a, int n)
{
	for (int i = 1; i < n; i++)//повторять проходы по массиву N-1 раз
		for (int j = n - 1; j >= i; j--)//проход с N-1-го элемента вверх до i-го
		{
			if (a[j - 1] > a[j])
			{
				int x = a[j - 1];
				a[j - 1] = a[j];// обмен элементов в случае неправильного порядка
				a[j] = x;
			}
		}
}


void random(ofstream& file, int n, int k)
{

	srand(time(NULL));
	int arr;
	for (int i = 0; i < k; ++i)
	{
		arr = rand() % n;
		file << arr;
		file << "\n";
	}
}

void output(int* res, int m)
{
	for (int i = 0; i < m; ++i)
	{
		cout << res[i] << " ";
	}
	cout << endl;
}

void function_arr(bool* arr, ifstream& file, int n)
{
	int k = 0;
	int m = 0;
	for (int i = 0; i < n; ++i)
	{
		file >> k;
		for (int j = 0; j < n; ++j)
		{
			if (k == j)
			{
				arr[j] = 1;
				break;
			}
		}
	}
	for (int i = 0; i < n; ++i)
	{
		if (arr[i] == 1)
		{
			m++;
		}
	}
	int* res = new int[m];
	int j = 0;
	for (int i = 0; i < m; ++i)
	{
		while (j < n)
		{
			if (arr[j] == 1)
			{
				res[i] = j;
				++j;
				break;
			}
			++j;
		}
	}
	sort_exchange(res, m);
	output(res, m);
}

