#include "Header.h"

template<class T>
void sort_obmenom(T* arr, int n, int& sr, int& per)
{
	for (int k = n - 1; k > 0; --k)
	{
		bool flag = false;
		for (int i = 0; i < k; ++i)
			if (arr[i] > arr[i + 1])
			{
				swap(arr[i], arr[i + 1]);
				sr++;
				per++;
				flag = true;
			}
		if (!flag)
			break;
	}
}
template<class T>
void fast_sort(T* arr, int l, int r, int& sr, int& per)
{
	T el = arr[(l + r) / 2];
	int i = l;
	int j = r;
	while (i <= j)
	{
		sr++;
		while (arr[i] < el)
		{
			sr++;
			++i;
		}
		while (arr[j] > el)
		{
			sr++;
			--j;
		}
		if (i <= j)
		{
			sr++;
			per++;
			swap(arr[i], arr[j]);
			i++;
			j--;
		}
	}
	if (l < j)
	{
		sr++;
		fast_sort(arr, l, j, sr, per);
	}
	if (i < r)
	{
		sr++;
		fast_sort(arr, i, r, sr, per);
	}
	return;
}

int main()
{
		srand(time(NULL));
		int n = 0;
		cout << "Size: ";
		cin >> n;
		int* arr = new int[n];
		for (int i = 0; i < n; ++i)
			arr[i] = 0;
		int x = 0;
		int kolvo_sr = 0, kolvo_per = 0;
		cout << "Array filling method:\n1 - Random\n2 - Ascending\n3 - Desending\n";
		while (x == 0)
		{
			cin >> x;
			if (x == 1)
				random(arr, n);
			else if (x == 2)
				ascending(arr, n);
			else if (x == 3)
				descending(arr, n);
			else
			{
				cout << "Error! Try again!\n";
				x = 0;
			}
		}
		cout << "Print array?\n1 - Yes\n2 - No\n";
		cin >> x;
		if (x == 1)
			for (int i = 0; i < n; ++i)
				cout << arr[i] << " ";
		cout << "\nChosen method of sort:\n1 - Quick sort\n2 - Sort by exchange\n";
		x = 0;
		while (x == 0)
		{
			cin >> x;
			if (x == 1)
				fast_sort(arr, 0, n - 1, kolvo_sr, kolvo_per);
			else if (x == 2)
				sort_obmenom(arr, n, kolvo_sr, kolvo_per);
			else
			{
				cout << "Error! Try again!\n";
				x = 0;
			}
		}
		cout << "Print array?\n1 - Yes\n2 - No\n";
		cin >> x;
		if (x == 1)
			for (int i = 0; i < n; ++i)
				cout << arr[i] << " ";
		cout << "\nPrint number of comparisons?(k_sravn)\n1 - Yes\n2 - No\n";
		cin >> x;
		if (x == 1)
			cout << "k_sravn = "<<kolvo_sr;
		cout << "\nPrint number of movements?(k_perem)\n1 - Yes\n2 - No\n";
		cin >> x;
		if (x == 1)
			cout << "k_perem = "<< kolvo_per;
		return 0;
}
