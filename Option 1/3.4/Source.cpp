//3.4. УПОРЯДОЧЕННОСТЬ ЗНАЧЕНИЙ В МАТРИЦАХ Дана действительная матрица порядка n? m.
//Перебор строк/столбцов матрицы осуществить с использованием указателей. Обосновать выбор метода сортировки. 
//1. Упорядочить столбцы по неубыванию первых элементов.
#include <iostream> 
#include <iomanip>
#include <stdlib.h> 
#include <time.h>

using namespace std;



int main()
{
	srand(time(NULL));
	const int n = 5, m = 7;

	int  a[n][m], * s[m];// массив указателей

	for (int i = 0; i < m; i++) s[i] = &a[0][i];//заполняем массив указателей ссылками на первый элемент каждого столбца

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			a[i][j] = rand() % 199 - 99;
			cout << setw(3) << a[i][j];
		}
		cout << endl;
	}

	for (int r = m - 1; r >= 1; r--)
		for (int i = 1; i <= r; i++)
			if (*s[i] < *s[i - 1]) swap(s[i], s[i - 1]);//Ссортируем ссылки по неубыванию элементов  

	int b[n][m] = { 0 };
	for (int j = 0; j < m; j++)
		for (int i = 0; i < n; i++)
			b[i][j] = *(s[j] + i * m);//Заполняем массив просортированными столбцами 

	cout << "\n\n";
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
			cout << setw(3) << *(*(b+i)+j);
		cout << endl;
	}
	return (0);
}

