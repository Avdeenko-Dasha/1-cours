#include <iostream>

using namespace std;

int& foo(int* arr, int n)
{
	int max = 0;
	int pos = 0;
	for (int i = 0; i < n; ++i)
		if (arr[i] > max)
		{
			max = arr[i];
			pos = i;
		}
	int number_Fib = 1;
	int f0 = 1;
	int f1 = 1;
	int max_f = 0;
	int perem = 0;
	bool flag;
	for (int i = 0; i < n; ++i)
	{
		perem = arr[i];
		flag = false;
		number_Fib = 1;
		f0 = 1;
		f1 = 1;
		while (true)
		{
			if (number_Fib == perem)
			{
				flag = true;
				break;
			}
			else if(number_Fib > perem)
				break;

			number_Fib = f0 + f1;
			f0 = f1;
			f1 = number_Fib;
		}
		if (flag)
			if (perem > max_f)
				max_f = perem;
	}
	if (max_f == 0)
	{
		arr[pos] = 0;
		return max;
	}
	else
	{
		for (int i = 0; i < n; ++i)
			if (arr[i] == max_f)
			{
				pos = i;
				break;
			}
		arr[pos] = 0;
		return max_f;
	}
	
}
int main()
{
	int n = 0;
	cin >> n;
	int* arr = new int[n];
	int max = 0;
	for (int i = 0; i < n; ++i)
	{
		cin >> arr[i];
	}
	max = foo(arr, n);
	cout << max << '\n';
	for (int i = 0; i < n; ++i)
		cout << arr[i] << " ";
	return 0;
}