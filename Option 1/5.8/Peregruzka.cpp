#include <iostream>
#include <ctime>
//////////////////////// int ///////////////////////////
void random(int* a, int n)
{
	for (int i = 0; i < n; i++)
		a[i] = rand() % 10;
}
//////////////////////// char ///////////////////////////
void random(char* a, int n)
{
	for (int i = 0; i < n; i++)
		a[i] = 65 + rand() % 26;
	a[n] = '\0';
}
//////////////////////// float ///////////////////////////
void random(float* a, int n)
{
	for (int i = 0; i < n; i++)
		a[i] = rand() % 1000 / 100.0;
}
//////////////////////////////////// short ///////////////////////////////
void random(short* a, int n)
{
	for (int i = 0; i < n; i++)
		a[i] = rand() % 100;
}
/////////////////////////////////////// double ///////////////////////
void random(double* a, int n)
{
	for (int i = 0; i < n; i++)
		a[i] = rand() % 100;
}
/////////////////////////////////// long ///////////////////////////
void random(long* a, int n)
{
	for (int i = 0; i < n; i++)
		a[i] = rand() % 100;
}
////////////////////////////// long long ////////////////////////////////
void random(long long* a, int n)
{
	for (int i = 0; i < n; i++)
		a[i] = rand() % 100;
}