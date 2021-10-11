#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	srand(time(NULL));
	int matrix_A[100][100] = { 0 };
	int matrix_B[100][100] = { 0 };
	int n = 10;
	//cin >> n;

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			matrix_A[i][j] = rand() % 10;
			cout << setw(4) << matrix_A[i][j];
		}
		cout << '\n';
	}


	/*int k = 0;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
		{
			int min = INT_MAX;

			if (j >= i)
			{
				for (int k = 0; k < n; ++k)
					for (int z = j - i + k; z < n; ++z)
						if (matrix_A[k][z] <= min)
							min = matrix_A[k][z];
			}
			else
			{
				for (int k = 0; k <= i - j; ++k)
					for (int z = 0; z < n; ++z)
						if (matrix_A[k][z] <= min)
							min = matrix_A[k][z];
				int x = 1;
				for (int k = i - j + x; k < n; ++k)
				{
					for (int z = x; z < n; ++z)
						if (matrix_A[k][z] <= min)
							min = matrix_A[k][z];
					++x;
				}
			}
			matrix_B[i][j] = min;
		}*/


	matrix_B[0][n - 1] = matrix_A[0][n - 1];
	for (int j = n - 2; j >= 0; --j)
	{
		matrix_B[0][j] = matrix_B[0][j + 1];
		for (int ia = 0, ja = j; ia < n && ja < n; ++ia, ++ja)
			if (matrix_B[0][j] > matrix_A[ia][ja])
				matrix_B[0][j] = matrix_A[ia][ja];
		for (int ia = 1, ja = j + 1; ia < n && ja < n; ++ia, ++ja)
			matrix_B[ia][ja] = matrix_B[0][j];
	}

	for (int i = 1; i < n; ++i)
	{
		matrix_B[i][0] = matrix_B[i - 1][0];
		for (int ia = i, ja = 0; ia < n && ja < n; ++ia, ++ja)
			if (matrix_B[i][0] > matrix_A[ia][ja])
				matrix_B[i][0] = matrix_A[ia][ja];
		for (int ia = i + 1, ja = 1; ia < n && ja < n; ++ia, ++ja)
			matrix_B[ia][ja] = matrix_B[i][0];
	}
	cout << endl;

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
			cout << setw(4) << matrix_B[i][j];
		cout << '\n';
	}

	return 0;
}


		
