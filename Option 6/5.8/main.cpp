#include "Header.h"

template<class T>
void merge(T* arr, int p, int q, int r)
{
	int n1 = q - p + 1;
	int n2 = r - q;

	T* L = new T[n1];
	T* M = new T[n2];

	for (int i = 0; i < n1; ++i)
		L[i] = arr[p + i];
	for (int j = 0; j < n2; ++j)
		M[j] = arr[q + 1 + j];

	int i = 0, j = 0, k = p;

	while (i < n1 && j < n2)
		if (L[i] <= M[j])
			arr[k++] = L[i++];
		else 
			arr[k++] = M[j++];

	while (i < n1)
		arr[k++] = L[i++];

	while (j < n2)
		arr[k++] = M[j++];
	delete[] L;
	delete[] M;
}
void merge(char* arr, int p, int q, int r)
{
	int n1 = q - p + 1;
	int n2 = r - q;

	char* L = new char[n1];
	char* M = new char[n2];

	for (int i = 0; i < n1; ++i)
		L[i] = arr[p + i];
	for (int j = 0; j < n2; ++j)
		M[j] = arr[q + 1 + j];

	int i = 0, j = 0, k = p;

	while (i < n1 && j < n2)
		if (L[i] + 64 <= M[j] + 64)
			arr[k++] = L[i++];
		else
			arr[k++] = M[j++];

	while (i < n1)
		arr[k++] = L[i++];

	while (j < n2)
		arr[k++] = M[j++];
	delete[] L;
	delete[] M;
}
template<class T>
void MergeSort(T* arr, int p, int r)
{
	if (p >= r)
		return;
	int q = (p + r) / 2;
	MergeSort(arr, p, q);
	MergeSort(arr, q + 1, r);
	merge(arr, p, q, r);
}
template<class T>
void print(T* arr, int n)
{
	for (int i = 0; i < n; ++i)
	{
		cout << arr[i] << " ";
	}
	cout << '\n';
}
template<class T>
void yourself(T* arr, int n)
{
	for (int i = 0; i < n; ++i)
	{
		cin >> arr[i];
	}
}

int main()
{
	int n = 0;
	cout << "Size: ";
	cin >> n;
	char* arr = new char[n];
	int x = 0;
	cout << "Choose a way to fill the array:\n1 - Introduce yourself\n2 - Fill in randomly\n";
	while (x == 0)
	{
		cin >> x;
		if (x == 1)
			yourself(arr, n);
		else if (x == 2)
			random(arr, n);
		else
		{
			cout << "Error:(\nTru again!\n";
			x = 0;
		}
	}
	cout << "Your array: ";
	print(arr, n);
	MergeSort(arr, 0, n - 1);
	cout << "Your sorted array: ";
	print(arr, n);
	return 0;
}