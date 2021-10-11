#include <iostream>
#include <iomanip>

using namespace std;

int n = 5;

void sqrt(int* matrix_B)
{
	int matrix[100] = { 0 };
	int num = 0;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			num = 0;
			for (int k = 0; k < n; ++k)
			{
				if (i == j)
					num += matrix_B[i * n + j + k] * matrix_B[(i + k) * n + j];
				else
					num += matrix_B[i * n + k] * matrix_B[k * n + j];
			}
			matrix[i * n + j] = num;
		}
	}
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			matrix_B[i * n + j] = matrix[i * n + j];
}
void sum(int* matrix_B, int* matrix_E)
{
	for (int i = 0; i < n * n; ++i)
		matrix_B[i] += matrix_E[i];
}
void multiplication(int* matrix_A, int* matrix_B, int* matrix_C)
{
	int num = 0;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			num = 0;
			for (int k = 0; k < n; ++k)
			{
				if (i == j)
					num += matrix_A[i * n + j + k] * matrix_B[(i + k) * n + j];
				else
					num += matrix_A[i * n + k] * matrix_B[k * n + j];
			}
			matrix_C[i * n + j] = num;
		}
	}
}
void print(int* matrix)
{
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
			cout << setw(6) << matrix[i * n + j];
		cout << '\n';
	}
	cout << endl;
}

int main()
{
	srand(time(NULL));
	int matrix_A[100] = { 0 };
	int matrix_B[100] = { 0 };
	int matrix_E[100] = { 0 };
	int matrix_C[100] = { 0 };

	cin >> n;

	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			if (j >= i)
				matrix_A[i * n + j] = rand() % 10;

	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			if (j >= i)
				matrix_B[i * n + j] = rand() % 10;	

	for (int i = 0; i < n * n; ++i)
		matrix_E[i] = 1;

	sqrt(matrix_B);
	sum(matrix_B, matrix_E);
	print(matrix_A);
	print(matrix_B);
	multiplication(matrix_A, matrix_B, matrix_C);
	print(matrix_C);
	

	return 0;
}