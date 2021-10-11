#include <iostream>
#include <ctime>
//////////////////////// int ///////////////////////////
void ascending(int* a, int n)
{
	for (int i = 0; i < n; i++)
		a[i] = i + 1;
}
void descending(int* a, int n)
{
	for (int i = n - 1; i >= 0; i--)
		a[i] = n - i;
}
void random(int* a, int n)
{
	srand(time(NULL));
	for (int i = 0; i < n; i++)
		a[i] = rand() % 10;
}
//////////////////////// char ///////////////////////////
void ascending(char* a, int n)
{
	for (int i = 0; i < n; i++)
		a[i] = 65 + i;
}
void descending(char* a, int n)
{
	for (int i = n - 1; i >= 0; i--)
		a[i] = 64 + n - i;
}
void random(char* a, int n)
{
	srand(time(NULL));
	for (int i = 0; i < n; i++)
		a[i] = 65 + rand() % 26;
}
//////////////////////// float ///////////////////////////
void ascending(float* a, int n)
{
	for (int i = 0; i < n; i++)
		a[i] = i + 1.0 / (i + 1);
}
void descending(float* a, int n)
{
	for (int i = n - 1; i >= 0; i--)
		a[i] = n - (i + 1.0 / (i + 1));
}
void random(float* a, int n)
{
	srand(time(NULL));
	for (int i = 0; i < n; i++)
		a[i] = rand() % 1000 / 100.0;
}
//////////////////////////////////// short ///////////////////////////////
void ascending(short* a, int n)
{
	for (int i = 0; i < n; i++)
		a[i] = i + 1;
}
void descending(short* a, int n)
{
	for (int i = n - 1; i >= 0; i--)
		a[i] = n - i;
}
void random(short* a, int n)
{
	srand(time(NULL));
	for (int i = 0; i < n; i++)
		a[i] = rand() % 10;
}
/////////////////////////////////////// double ///////////////////////
void ascending(double* a, int n)
{
	for (int i = 0; i < n; i++)
		a[i] = i + 1.0 / (i + 1);
}
void descending(double* a, int n)
{
	for (int i = n - 1; i >= 0; i--)
		a[i] = n - (i + 1.0 / (i + 1));
}
void random(double* a, int n)
{
	srand(time(NULL));
	for (int i = 0; i < n; i++)
		a[i] = rand() % 10;
}
/////////////////////////////////// long ///////////////////////////
void ascending(long* a, int n)
{
	for (int i = 0; i < n; i++)
		a[i] = i + 1;
}
void descending(long* a, int n)
{
	for (int i = n - 1; i >= 0; i--)
		a[i] = n - i;
}
void random(long* a, int n)
{
	srand(time(NULL));
	for (int i = 0; i < n; i++)
		a[i] = rand() % 10;
}
////////////////////////////// long long ////////////////////////////////
void ascending(long long* a, int n)
{
	for (int i = 0; i < n; i++)
		a[i] = i + 1;
}
void descending(long long* a, int n)
{
	for (int i = n - 1; i >= 0; i--)
		a[i] = n - i;
}
void random(long long* a, int n)
{
	srand(time(NULL));
	for (int i = 0; i < n; i++)
		a[i] = rand() % 10;
}