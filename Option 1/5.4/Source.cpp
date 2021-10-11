/*Напишите функцию, возвращающую ссылку на минимальное число, 
встречающееся в заданном массиве произвольного размера (аргумент функции) ровно один раз. 
Если такого числа нет, то возвратить ссылку на любое из минимальных чисел массива.
Замените этот элемент нулевым значением.*/
#include <iostream>  
using namespace std;

int& rmax(int n, int d[])
{
    int number = 0;
    int singl_el[100] = { 0 };
    int number_el[100] = { 0 };
    int l = 0;
    int size = 1;
    for (int i = 0; i < n; i++)
    {
        bool flag = 0;
        for (int j = 0; j < n; j++)
        {
            if (d[i] == d[j] && i != j)
            {
                flag = 1;
            }  
        }
        if (flag == 0 && size != l)
        {
            size = l;
            singl_el[l] = d[i];
            number_el[l] = i;
            l++;
        }
    }
    int k = 0;
    if (l > 0)
    {
        if (l > 1)
            for (int i = 1; i < size; i++) //определение минимального элемента
                if (singl_el[k] < singl_el[i])
                {
                    k = k;
                    number = number_el[i];
                }
                else
                {
                    k = i;
                    number = number_el[i];
                }
        else number = number_el[0];
        return d[number];
    }
    else
    {
        for (int i = 1; i < n; i++)
            if (d[k] < d[i])
                k = k;
            else k = i;
        return d[k];
    }
}

void main()
{
    int n = 0;
    cin >> n;
    int x[100] = { 0 }; 
    for (int i = 0; i < n; i++)
    {
        cin >> x[i];
    }
    cout << " min = " << rmax(n, x);
    cout << endl;   
    rmax(n, x) = 0; // «левосторонний» вызов функции позволяет занести 0 в минимальный элемент массива 
    for (int i = 0; i < n; i++)
        cout << "   " << x[i];
    cout << endl;
}
