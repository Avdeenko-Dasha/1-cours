/*� ��������� �������� ��������� ������� B �� �������� ������������� ������� � ������� n (n <= 100).
���������� ��������, ��������� ��� ������� ������.   
1.��������� ������� B, ������ ������� ����� �������� �� ��������� ��������� ��������������� ������ ������� �.
���������� �������� ����������� �������
B ����� ����������� ���������� ��������� ��������� � ������, ������ � ������� ������ ��������� ��������� ������.*/
#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <time.h>

using namespace std;


const unsigned int DIM1 = 100;
const unsigned int DIM2 = 100;

int ary[DIM1][DIM2];
int b[DIM1][DIM2];
int i, j, k, l;

int main()
{
    setlocale(0, "rus");
    cout << "������� ������� ������� n<=100 ";
    /* int m = 1;
     for (int i = 0; i < DIM1; i++)
     {
         for (int j = 0; j < DIM2; j++)
         {
             ary[i][j] = m;
             m++;
         }
     }*/
    int n;
    cin >> n;
    srand(time(0));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            ary[i][j] = rand() % 10;

    cout << "��������� �������" << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cout << setw(4) << ary[i][j];
        cout << endl;
    }
    cout << endl;


    int powt = 0, razn = 0, max = 0;


    for (int i = 0; i < n; i++)
    {
        razn = 1;
        for (int k = 0; k < n - 1; k++)
        {
            powt = 0;
            for (int j = k + 1; j < n; j++)
                if (ary[i][k] == ary[i][j]) powt++;//����� ���������� �������� ������� � 
            if (powt == 0) razn++;//����������� ���������� ��������� ��������� ������� �
        }
        if (razn > max) max = razn;
    }

    for(k=0; k<n; k++)
        for (l = 0; l < max; l++)//������� � ��������� ������
            b[k][l] = 0;

    for (int i = 0; i < n; i++)//������
    {
        l = 0;
        for (int k = 0; k < n - 1; k++)//�������
        {
            powt = 0;
            for (int j = k + 1; j < n; j++)
                if (ary[i][k] == ary[i][j]) powt++;//���� ������������� �������� ������� �
            if (powt == 0)
            {
                b[i][l] = ary[i][k];//��������� ������� � ���������� ���������� ������� �
                l++;
            }
        }
        b[i][l] = ary[i][n-1];
    }

    cout << "�������� �������" << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < max; j++)
            cout << setw(4) << b[i][j];
        cout << endl;
    }
    cout << endl;
    return 0;
}