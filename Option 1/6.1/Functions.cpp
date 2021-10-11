#include "Header.h"
#include <string>
//4.1. Если заданный текст является правильной записью римскими цифрами целого числа от 1 до 1999,
//то получить это число. 
void chislo(string rim_ch)
{
    const int MAX = 100;
    int arr[MAX] = { 0 };
    int x = 0;
    for (int i = 0; i < rim_ch.length(); i++)//Присваиваем значению буквы ее значение в цифре
    {
        switch (rim_ch[i])
        {
        case 'I':
            arr[i] = 1;
            break;
        case 'V':
            arr[i] = 5;
            break;
        case 'X':
            arr[i] = 10;
            break;
        case 'L':
            arr[i] = 50;
            break;
        case 'C':
            arr[i] = 100;
            break;
        case 'D':
            arr[i] = 500;
            break;
        case 'M':
            arr[i] = 1000;
            break;
        default:
            cout << "Error";
            x = 1;
            break;
        }
    }
    int k = 0;
    for (int j = 0; j < rim_ch.length(); j++)//VII K=0+5+1+1 IV K=0+1-5
    {
        if (arr[j] >= arr[j + 1])
            k += arr[j];
        else
            k -= arr[j];

        if (arr[j] == arr[j + 1] && arr[j] == arr[j + 2] && arr[j] == arr[j + 3] && arr[j] != 0)//IIII Ошибка
        {
            cout << "Error 2" << endl;
            x = 2;
            break;
        }

        if (arr[j] == arr[j + 2] && arr[j] != arr[j + 1])//IVI Ошибка
        {
            cout << "Error 3" << endl;
            x = 3;
            break;
        }
    }
    if (x == 0)
        cout << "Number = " << k << endl;
}
//4.2 Написать программу перевода вещественных чисел из двоичной системы счисления в шестнадцатеричную.
void perevod(string chislo_2ss)
{
    string whole_part;
    string fraction_part;
    {
        int i = 0;
        for (; chislo_2ss[i] && chislo_2ss[i] != '.'; i++)
            whole_part += chislo_2ss[i];//1
        i++;
        for (; chislo_2ss[i]; i++)
            fraction_part += chislo_2ss[i];
    }
    while (whole_part.length() % 4 != 0)
        whole_part = '0' + whole_part;

    while (fraction_part.length() % 4 != 0)
        fraction_part = fraction_part + '0';

    string result;
    {
        char res = 0;
        for (int i = 0; i < whole_part.length(); i += 4)
        {
            res += (whole_part[i] - '0') * 8;
            res += (whole_part[i + 1] - '0') * 4;
            res += (whole_part[i + 2] - '0') * 2;
            res += (whole_part[i + 3] - '0');
            res += '0';
            if (res >= 58) res += 7;
            result += res;
        }
        result += '.';
        for (int i = 0; i < fraction_part.length(); i += 4)
        {
            res = (fraction_part[i] - '0') * 8;
            res += (fraction_part[i + 1] - '0') * 4;
            res += (fraction_part[i + 2] - '0') * 2;
            res += (fraction_part[i + 3] - '0');
            res += '0';
            if (res >= 58) res += 7;
            result += res;
        }
    }
    cout << result << endl;
}
//4.3 Записать в новую строку слова, которые состоят из тех же букв, что и первое слово в заданной строке символов.
void stroka(string s, string r)
{
    s += ' ';
    int begin = s.find_first_not_of(r, 0);
    int k_bukv_1_slova = s.find_first_of(r, begin) - begin;
    string word_1;
    for (int i = begin, j = 0; j < k_bukv_1_slova; i++, j++)
        word_1 += s[i];
    string res;
    for (int i = begin, rasd = 0; i < s.length(); i = s.find_first_not_of(r, rasd + 1))
    {
        rasd = s.find_first_of(r, i);
        if (s.find_first_not_of(word_1, i) >= rasd)
        {
            for (; i < rasd; i++)
                res += s[i];
            res += ' ';
        }
    }
    cout << res;
}