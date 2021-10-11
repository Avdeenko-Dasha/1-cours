/*Дан массив чисел произвольной длины. Отсортировать массив, используя сортировку слияниями.
Создать шаблоны функций для сортировок, заполнения массивов, вывода результатов.
Сравнение элементов массива оформить отдельной функцией.
Перегрузить функцию сравнения элементов для массива С-строк.
Выполнить сортировки массивов для данных разных типов: целых, вещественных, символьных, С- строк, 
используя написанные функции.*/
#include <iostream>
#include <iomanip>
#include "Header.h"

using namespace std;


template <typename T>
void yourself(T* a, int n)
{
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
}

template <typename T>
void random(T* a, int n) 
{
	for (int i = 0; i < n; ++i) 
	{
		a[i] = (rand() % 100) * 1.1;
	}
}


template <typename T>
void output(T* a, int n)
{
	for (int i = 0; i < n; ++i)
	{
		cout << a[i] << " ";
	}
	cout << endl;
}



int main()
{
	srand(time(NULL));
	const int n = 5;
	int a[n] = { 0 };
	cout << "Filling the array:" << endl << "1 - fill in yourself" << endl << "2 - fill with random numbers" << endl;
	int x = 0;
	cin >> x;
	if (x == 1) yourself(a, n);
	else if (x == 2) random(a, n);
	else cout << "Error";
    output(a, n);
	MergeSort(a, 0, n-1);  //вызов сортирующей процедуры
	output(a, n);

	/// ////////////////////////// C - строки //////////////////////////////////////
	cout << endl << "C-stroki:";

	char** str = new char* [n];
	for (int i = 0; i < n; ++i) 
	{
		str[i] = new char[n];
	}

	cout << endl << "Filling the array:" << endl << "1 - fill in yourself" << endl << "2 - fill with random numbers" << endl;
	x = 0;
	cin >> x;
	if (x == 1)
	{
		for (int i = 0; i < n; ++i)
		{
			cin >> str[i];
		}
	}
	else if (x == 2)
		for (int i = 0; i < n; ++i)
		{
			random(str[i], rand() % n);
		}
	else cout << "Error";

	
	for (int i = 0; i < n; ++i) 
	{
		cout << str[i] << " ";
	}
	cout << endl;

	MergeSort(str, 0, n - 1);

	for (int i = 0; i < n; ++i) 
	{
		cout << str[i] << " ";
	}
	cout << endl;

	return 0;
}