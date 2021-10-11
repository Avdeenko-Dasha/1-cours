#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
	srand(time(NULL));
	int n = 0;
	cin >> n;
	int** matrix_A = new int*[n];
	for (int i = 0; i < n; ++i)
		matrix_A[i] = new int[n];
	int** matrix_B = new int*[n];
	for (int i = 0; i < n; ++i)
		matrix_B[i] = new int[n];

	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			matrix_A[i][j] = rand() % 100;

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
			cout << matrix_A[i][j] << " ";
		cout << endl;
	}

	int max = 0;
	for (int i = 0; i < n; ++i)
	{
		max = 0;
		for (int j = 0; j < n; ++j)
		{
			for (int s = 0; s <= i; ++s)
				for (int k = 0; k <= j; ++k)
					if (matrix_A[s][k] > max)
						max = matrix_A[s][k];
			matrix_B[i][j] = max;
		}
	}

	cout << endl;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
			cout << matrix_B[i][j] << " ";
		cout << endl;
	}

	for (int i = 0; i < n; ++i)
		delete matrix_A[i];
	delete matrix_A;
	for (int i = 0; i < n; ++i)
		delete matrix_B[i];
	delete matrix_B;
	return 0;
}