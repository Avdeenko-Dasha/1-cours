//1. Если заданный текст является правильной записью римскими цифрами целого числа от 1 до 1999,
//то получить это число. 
#include <iostream>
#include <windows.h> // для OemToAnsi
#include <iomanip>
#include <stdio.h> //Для  gets_s и puts
#include <string.h>

using namespace std;
int main()
{
    setlocale(0, "rus");
    const int MAX = 100;
    int arr[MAX] = { 0 };
    char str1[MAX] = { 0 };
    int  k = 0;
    cout << "Введите число ";
    cin.getline(str1, MAX);

    for (int i = 0; str1[i]; i++)//Присваиваем значению буквы ее значение в цифре
    {
        if (str1[i] == 'I')
            arr[i] = 1;
        else if (str1[i] == 'V')
            arr[i] = 5;
        else if (str1[i] == 'X')
            arr[i] = 10;
        else if (str1[i] == 'L')
            arr[i] = 50;
        else if (str1[i] == 'C')
            arr[i] = 100;
        else if (str1[i] == 'D')
            arr[i] = 500;
        else if (str1[i] == 'M')
            arr[i] = 1000;
        else
        {
            cout << "Ошибка";
            exit(0);
        }
    }

    for (int j = 0; str1[j]; j++)//VII K=0+5+1+1 IV K=0+1-5
    {
        if (arr[j] >= arr[j + 1])
            k += arr[j];
        else
            k -= arr[j];

        if (arr[j] == arr[j + 1] && arr[j] == arr[j + 2] && arr[j] == arr[j + 3] && arr[j] != 0)//IIII Ошибка
        {
            cout << " Ошибка " << endl;
            return 0;
        }

        if (arr[j] == arr[j + 2] && arr[j] != arr[j + 1])//IVI Ошибка
        {
            cout << " Ошибка " << endl;
            exit(0);
        }
    }
    cout << "Число = " << k << endl;
    return(0);
}