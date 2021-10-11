#include "Header.h"



void ascending(int* a, int n)
{
	for (int i = 0; i < n; ++i)
		a[i] = i + 1;
}
void descending(int* a, int n)
{
	for (int i = n - 1; i >= 0; --i)
		a[i] = n - i;
}
void random(int* a, int n)
{
	for (int i = 0; i < n; ++i)
		a[i] = rand() % 10;
}

void ascending(char* a, int n)
{
	for (int i = 0; i < n; ++i)
		a[i] = i + 65;
}
void descending(char* a, int n)
{
	for (int i = n - 1; i >= 0; --i)
		a[i] = 64 + n - i;
}
void random(char* a, int n)
{
	for (int i = 0; i < n; ++i)
		a[i] = 64 + rand() % 26;
}

void ascending(float* a, int n)
{
	for (int i = 0; i < n; ++i)
		a[i] = i + 1.0;
}
void descending(float* a, int n)
{
	for (int i = n - 1; i >= 0; --i)
		a[i] = n - (i + 1.0);
}
void random(float* a, int n)
{
	for (int i = 0; i < n; ++i)
		a[i] = rand() % 100 / 10.0;
}

void ascending(double* a, int n)
{
	for (int i = 0; i < n; ++i)
		a[i] = i + 1.0 / (i + 1);
}
void descending(double* a, int n)
{
	for (int i = n - 1; i >= 0; --i)
		a[i] = n - (i + 1.0 / (i + 1));
}
void random(double* a, int n)
{
	for (int i = 0; i < n; ++i)
		a[i] = rand() % 100 / 10.0;
}

void ascending(short* a, int n)
{
	for (int i = 0; i < n; ++i)
		a[i] = i + 1.0 / (i + 1);
}
void descending(short* a, int n)
{
	for (int i = n - 1; i >= 0; --i)
		a[i] = n - (i + 1.0 / (i + 1));
}
void random(short* a, int n)
{
	for (int i = 0; i < n; ++i)
		a[i] = rand() % 100 / 10.0;
}

void ascending(long* a, int n)
{
	for (int i = 0; i < n; ++i)
		a[i] = i + 1;
}
void descending(long* a, int n)
{
	for (int i = n - 1; i >= 0; --i)
		a[i] = n - i;
}
void random(long* a, int n)
{
	for (int i = 0; i < n; ++i)
		a[i] = rand() % 100 + 10;
}

void ascending(long long* a, int n)
{
	for (int i = 0; i < n; ++i)
		a[i] = i + 1;
}
void descending(long long* a, int n)
{
	for (int i = n - 1; i >= 0; --i)
		a[i] = n - i;
}
void random(long long* a, int n)
{
	for (int i = 0; i < n; ++i)
		a[i] = rand() % 1000 + 10;
}

void ascending(bool* a, int n)
{
	for (int i = 0; i < n/2; ++i)
		a[i] = 0;
	for (int i = n / 2; i < n; ++i)
		a[i] = 1;
}
void descending(bool* a, int n)
{
	for (int i = 0; i < n / 2; ++i)
		a[i] = 1;
	for (int i = n / 2; i < n; ++i)
		a[i] = 0;
}
void random(bool* a, int n)
{
	for (int i = 0; i < n; ++i)
		a[i] = rand() % 1 + 0;
}

