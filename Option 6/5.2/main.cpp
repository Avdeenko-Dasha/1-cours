/*6. Ќаписать функцию вставки подстроки SS в строку S с позиции номер n.
»спользу€ эту функцию, вставить в строку-выражение вокруг символа С+Т недостающие пробелы.
Ќапример: У3+ 5+(x+ 2)Ф -> У3 + 5 + (x + 2)Ф.*/
#include <iostream>

using namespace std;

void foo(char* stroka, char* podstroka, int n)
{
	char help[100];
	int i = 0;
	for(int k = 0; stroka[k]; ++k)
	{
		if(i != n - 1)
		help[i++] = stroka[k];
		else
		{
			for (int j = 0; podstroka[j]; ++j)
			{
				help[i++] = podstroka[j];
			}
			help[i++] = stroka[k];
		}
	}
	help[i] = '\0';
	for (int k = 0; help[k]; ++k)
		stroka[k] = help[k];
	stroka[i] = '\0';
}

int main()
{
	//const int max = 100;
	char stroka[100] = "3+ 5+(x+ 2)";
	//cout << "Stroka: ";
	//cin.getline(stroka, max);
	char podstroka[] = " ";
	//cout << "Podstroka: ";
	//cin.getline(podstroka, max);
	int pos = 0;
	int x = 1;
	while (true)
	{
		cout << "Stroka: " << stroka;
		cout << "\nPosition: ";
		cin >> pos;
		foo(stroka, podstroka, pos);
		cout << "\nNew stroka: " << stroka;
		cout << "\n 1 - continue \n";
		cin >> x;
		if (x != 1)
			break;
	}
	return 0;
}