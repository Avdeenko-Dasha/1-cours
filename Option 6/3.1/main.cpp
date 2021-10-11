#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
	srand(time(NULL));
	int n = 0;
	cout << "Size: ";
	cin >> n;
	int* arr = new int[n];
	cout << "1 - Random\n";
	cout << "2 - Self-entry\n";
	int x = 0;
	while (true)
	{
		cin >> x;
		if (x == 1)
		{
			for (int i = 0; i < n; ++i)
				arr[i] = rand() % 19 - 9;
			break;
		}
		else if (x == 2)
		{
			for (int i = 0; i < n; ++i)
			{
				cin >> x;
				arr[i] = x;
			}
			break;
		}
		cout << "Error! Try again\n";
	}
	int* array = new int[n];
	x = 0;

	for (int i = 0; i < n; ++i)
		if (arr[i] > 0)
		{
			array[x] = arr[i];
			++x;
		}
	for (int i = 0; i < n; ++i)
		if(arr[i] == 0)
		{
			array[x] = arr[i];
			++x;
		}
	for (int i = 0; i < n; ++i)
		if (arr[i] < 0)
		{
			array[x] = arr[i];
			++x;
		}

	for (int i = 0; i < n; ++i)
		cout << arr[i] << " ";
	cout << '\n';
	for (int i = 0; i < n; ++i)
		cout << array[i] << " ";
}