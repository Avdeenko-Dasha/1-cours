//Написать программу перевода вещественных чисел из двоичной системы счисления в шестнадцатеричную. 
#include <iostream>
#include <windows.h> // для OemToAnsi
#include <iomanip>
#include <stdio.h> //Для  gets_s и puts
#include <string.h>

using namespace std;
int main()
{
    setlocale(0, "rus");
    const int n = 80;
    char s[n] = { 0 };
    char r[n] = { 0 };
    char c[n] = { 0 };
    char d[n] = { 0 };

    cout << "Введите число в 2 сс ";
    cin.getline(s, n);
    {
        int i = 0;
        for (; s[i] && s[i] != '.'; i++)
            c[i] = s[i];
        i++;
        for (int k = 0; s[i]; i++, k++)
            d[k] = s[i];
    }
    // cout << d << endl;
    while (strlen(c) % 4 != 0)
    {
        int i = strlen(c) + 1;
        if (n <= i) i = n - 2;
        for (; i > 0; i--)
        {
            c[i] = c[i - 1];
        }
        c[0] = '0';
    }
    cout << c << endl;
    {
        int i = strlen(d);
        while (strlen(d) % 4 != 0)
        {
            d[i] = '0';
            i++;
        }
        d[i] = '\0';
    }
    //cout << c << "." << d;
    {
        int k = 0;
        for (int i = 0; c[i]; i += 4, k++)
        {
            r[k] = (c[i] - '0') * 8;
            r[k] += (c[i + 1] - '0') * 4;
            r[k] += (c[i + 2] - '0') * 2;
            r[k] += (c[i + 3] - '0');
            r[k] += '0';
            if (r[k] >= 58) r[k] += 7;
        }
        //cout << r << ".";
        r[k] = '.';
        k++;
        for (int i = 0; d[i]; i += 4, k++)
        {
            r[k] = (d[i] - '0') * 8;
            r[k] += (d[i + 1] - '0') * 4;
            r[k] += (d[i + 2] - '0') * 2;
            r[k] += (d[i + 3] - '0');
            r[k] += '0';
            if (r[k] >= 58) r[k] += 7;
        }
    }
    cout << r << endl;

    return(0);
}
