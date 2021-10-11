//Выполнить задание, используя динамическое выделение памяти для одномерного массива.
//Дано(в текстовом файле) n > 10^9 натуральных чисел(каждое число <=10^4)
//Ограничение на объем используемой памяти 1 Мб.
//Получить массив за один просмотр элементов файла :
//1. в котором все числа исходного файла расположены по возрастанию значений
#include "Header.h"

int main()
{
	const int n = 10;
	vector<bool> arr(n, 0);
	//bool arr[n] = { 0 };
	int m = 0;
	int k = 10;
	ofstream in_file("text.txt");
	if (!in_file.is_open())
	{
		cout << "Error 1";
	}
	else
	{
		cout << "File is open successfully" << endl;
		random(in_file, n, k);
		in_file.close();
	}

	ifstream file("text.txt");
	if (!file.is_open())
	{
		cout << "Error 2";
	}
	else
	{
		cout << "File is open successfully" << endl;
		function_arr(arr, file, n);
		in_file.close();
	}
}