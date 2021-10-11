// 1. Записать в новую строку слова, которые состоят из тех же букв, что и первое слово в заданной строке символов.
#include <iostream>
/*#include <windows.h> // для OemToAnsi
#include <iomanip>
#include <stdio.h> //Для gets_s и puts
*/
using namespace std;
int main()
{
	setlocale(0, "rus");
	const int n = 80;
	char s[n] = { 0 };
	char m[n] = { 0 };
	char res[n] = { 0 };
	char r[] = " ;//.,?!;:()-";

	cout << "Введите строку ";
	cin.getline(s, n, '\n');
	
		bool flag = 0;
		for (int i = 0; s[i] && flag == 0; i++)//Записываем в строку m первое слово строки
		{
			for (int k = 0; r[k]; k++)
				if (r[k] == s[i])
					flag = 1;
			if (flag == 0)
				m[i] = s[i];
		}
	

	cout << m << endl;
	for (int i = 0, c = 0; s[i]; i++)
	{

		bool flag_razd = 0;//поднять, если разделитель
		bool flag_word = 1;// поднять, если слово подходит
		int j = i;

		for (; s[j] && flag_razd == 0; j++)
		{
			for (int k = 0; r[k]; k++)
				if (s[j] == r[k])
					flag_razd = 1;//Когда слово закончилось

			int flag21 = 0;
			if (flag_razd == 0)//Если это бувква а не разделитель
				for (int k = 0; m[k]; k++)
					if (s[j] == m[k])//Сравниваем элементы строки с буквами 1 слова
						flag21 = 1;//Если буквы совпадают

			if (flag_word == 1 && flag21 == 0 && flag_razd == 0) flag_word = 0;//Проверяем подходит ли слово строки
		}
		if (s[j]) j--;//Возвращаем j значение разделителя или нуль-терминатора

		for (; i < j && flag_word == 1; i++, c++)//Если слово подходит пишем его в строчку
		{
			res[c] = s[i];
		}
		if (flag_word == 1)//Делаем пробел между словами
		{
			res[c] = ' ';
			c++;
		}
		i = j;//Что бы i было на месте j  и мы не проверяли лишние числа.
	}

	cout << endl << res;

	return(0);

}
