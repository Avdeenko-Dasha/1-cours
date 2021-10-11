#include "Header.h"

void random(int* arr, int n)
{
	for (int i = 0; i < n; ++i)
		arr[i] = rand() % 10;
}
void random(double* arr, int n)
{
	for (int i = 0; i < n; ++i)
		arr[i] = rand() % 100 / 10.0;
}
void random(char* arr, int n)
{
	for (int i = 0; i < n; ++i)
	{
		arr[i] = rand() % 26 + 65;
	}
}
