#include <time.h>
#include <fstream>
#include "class.h"

template<typename T>
void sort_exchange(vector<T> a, int n)
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

template<typename T>
void function_arr(vector<T> arr, ifstream& file, int n)
{
	int k = 0;
	int m = 0;
	for (int i = 0; i < n; ++i)
	{
		file >> k;
		for (int j = 0; j < n; ++j)
			if (k == j)
			{
				arr[j] = 1;
				break;
			}
	}
	for (int i = 0; i < n; ++i)
		if (arr[i] == 1)
			m++;
	vector<int> res(m);
	//int* res = new int[m];
	int j = 0;
	for (int i = 0; i < m; ++i)
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
	sort_exchange(res, m);
	//output(res, m);
	cout << res;
}

int main()
{
	srand(time(NULL));
	const int n = 10000;
	//bool arr[n] = { 0 };
	vector<bool> arr(n);
	int m = 0;
	int k = 10;
	ofstream in_file("text.txt");
	if (!in_file.is_open())
		cout << "Error 1";
	else
	{
		cout << "File is open successfully" << endl;
		random(in_file, n, k);
		in_file.close();
	}

	ifstream file("text.txt");
	if (!file.is_open())
		cout << "Error 2";
	else
	{
		cout << "File is open successfully" << endl;
		function_arr(arr, file, n);
		in_file.close();
	}

	return 0;
}