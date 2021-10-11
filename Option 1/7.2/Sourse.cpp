#include "Header.h"

using namespace std;

void output(double* res, int n)
{
	for (int i = 0; i < n; ++i)
	{
		cout << res[i] << " ";
	}
	cout << endl;
}

void fill_vector(double* vector, int n)
{
	for (int i = 0; i < n; ++i)
	{
		vector[i] = rand() % 1000 / 100.0;
	}
	output(vector, n);
}

void fill_matrix_1(double* matrix, int n)
{
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			matrix[i * n + j] = rand() % 1000 / 100.0;
			cout << matrix[i * n + j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

void fill_matrix_2(double** matrix, int n)
{
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			matrix[i][j] = rand() % 1000 / 100.0;
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

void res_1(double* A_1, double* x, double* y, int n)
{
	double* sum = new double[n];
	for (int i = 0; i < n; ++i)
	{
		sum[i] = x[i] + y[i];
	}

	double* res = new double[n];
	double k = 0;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			k += A_1[i * n + j] * sum[j];
		}
		res[i] = k;
		k = 0;
	}
	output(res, n);
	delete[] sum;
	delete[] res;
}

void res_2(double** A_2, double* x, double* y, int n)
{
	double* sum = new double[n];
	for (int i = 0; i < n; ++i)
	{
		sum[i] = x[i] + y[i];
	}

	double* res = new double[n];
	double k = 0;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			k += A_2[i][j] * sum[j];
		}
		res[i] = k;
		k = 0;
	}
	output(res, n);
	delete[] sum;
	delete[] res;
}

int main()
{
	srand(time(NULL));
	int n = 0;
	cout << "n = ";
	cin >> n;

	double* A_1 = new double[n * n];
	double** A_2 = new double* [n];
	for (int i = 0; i < n; ++i)
	{
		A_2[i] = new double[n];
	}
	double* x = new double[n];
	double* y = new double[n];

	cout << "Matrix A1:" << endl;
	fill_matrix_1(A_1, n);
	cout << "Matrix A2:" << endl;
	fill_matrix_2(A_2, n);
	cout << "Vector x:" << endl;
	fill_vector(x, n);
	cout << endl << "Vector y:" << endl;
	fill_vector(y, n);
	cout << endl << "A1 * (x + y) = ";
	res_1(A_1, x, y, n);
	cout << endl << "A2 * (x + y) = ";
	res_2(A_2, x, y, n);

	delete[] A_1;
	for (int i = 0; i < n; i++)
	{
		delete[] A_2[i];
	}
	delete[] A_2;
	delete[] x;
	delete[] y;

	return 0;
}