//1. ���� �������� ����� �������� ���������� ������� �������� ������� ������ ����� �� 1 �� 1999,
//�� �������� ��� �����. 
#include <iostream>
#include <windows.h> // ��� OemToAnsi
#include <iomanip>
#include <stdio.h> //���  gets_s � puts
#include <string.h>

using namespace std;
int main()
{
    setlocale(0, "rus");
    const int MAX = 100;
    int arr[MAX] = { 0 };
    char str1[MAX] = { 0 };
    int  k = 0;
    cout << "������� ����� ";
    cin.getline(str1, MAX);

    for (int i = 0; str1[i]; i++)//����������� �������� ����� �� �������� � �����
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
            cout << "������";
            exit(0);
        }
    }

    for (int j = 0; str1[j]; j++)//VII K=0+5+1+1 IV K=0+1-5
    {
        if (arr[j] >= arr[j + 1])
            k += arr[j];
        else
            k -= arr[j];

        if (arr[j] == arr[j + 1] && arr[j] == arr[j + 2] && arr[j] == arr[j + 3] && arr[j] != 0)//IIII ������
        {
            cout << " ������ " << endl;
            return 0;
        }

        if (arr[j] == arr[j + 2] && arr[j] != arr[j + 1])//IVI ������
        {
            cout << " ������ " << endl;
            exit(0);
        }
    }
    cout << "����� = " << k << endl;
    return(0);
}