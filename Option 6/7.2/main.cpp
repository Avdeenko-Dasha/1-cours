#include <iostream>
#include <iomanip>

using namespace std;

void multiplication(double** matrix1, double**& matrix2, int n)
{
	double** matr = new double* [n];
	for (int i = 0; i < n; ++i)
		matr[i] = new double[n];
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			matr[i][j] = matrix2[i][j];


	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
		{
			double sum = 0;
			for (int k = 0; k < n; ++k)
				sum += matrix1[i][k] * matr[k][j];
			matrix2[i][j] = sum;
		}
	for (int i = 0; i < n; ++i)
		delete[] matr[i];
	delete[] matr;
}
void multiplication(double* matrix1, double*& matrix2, int n)
{
	double* matr = new double[n * n];
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			matr[i * n + j] = matrix2[i * n + j];

	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
		{
			double sum = 0;
			for (int k = 0; k < n; ++k)
				sum += matrix1[i * n + k] * matr[k * n + j];
			matrix2[i * n + j] = sum;
		}

	delete[] matr;
}

void pow_matrix(double**& matrix, int n, int p)
{
	double** matr = new double* [n];
	for (int i = 0; i < n; ++i)
		matr[i] = new double[n];

	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			matr[i][j] = matrix[i][j];

	for (int i = 1; i < p; ++i)
		multiplication(matr, matrix, n);
	
	for (int i = 0; i < n; ++i)
		delete[] matr[i];
	delete[] matr;
}
void pow_matrix(double*& matrix, int n, int p)
{
	double* matr = new double [n*n];

	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			matr[i*n +j] = matrix[i*n +j];

	for (int i = 1; i < p; ++i)
		multiplication(matr, matrix, n);

	delete[] matr;
}

void enter_data(double** matrix, int n)
{
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			matrix[i][j] = rand() % 100 / 10.0;
}
void enter_data(double* matrix, int n)
{
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			matrix[i * n + j] = rand() % 100 / 10.0;
}

void print(double** matrix, int n)
{
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
			cout << setw(10) << matrix[i][j];
		cout << '\n';
	}
	cout << '\n';
}
void print(double* matrix, int n)
{
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
			cout << setw(10) << matrix[i * n + j];
		cout << '\n';
	}
	cout << '\n';
}

int main()
{
	int n = 0;
	cout << "Size matrix: ";
	cin >> n;
	int p = 0;
	cout << "Pow: ";
	cin >> p;

	double** matrix_1 = new double* [n];
	for (int i = 0; i < n; ++i)
		matrix_1[i] = new double[n];
	double* matrix_2 = new double[n * n];
	 
	enter_data(matrix_1, n);
	enter_data(matrix_2, n);

	print(matrix_1, n);
	print(matrix_2, n);

	pow_matrix(matrix_1, n, p);
	pow_matrix(matrix_2, n, p);

	print(matrix_1, n);
	print(matrix_2, n);

	delete[] matrix_2;
	for (int i = 0; i < n; ++i)
		delete[] matrix_1[i];
	delete[] matrix_1;

	return 0;
}