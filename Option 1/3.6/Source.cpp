/*3.6. ������������� �������� ��� ������������� �������ջ ����� 
1. ������� ������������������ dk, dk�1, �, d0 ���������� ���� ����� N * M, 
��� N, M � ����������� �����, N, M > 10^10 ,
�.�. ����� ������������� ������������������, � ������� ������ ���� di ������������� ������� 
0 <= di  <= 9  � dk*10^k + dk�1*10^(k�1) + � d0   =   N * M. */
#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <algorithm>

using namespace std;


int N[100];
int M[100];
int umn[100], c[100];
int i, j, k, l;

int main()
{
    setlocale(0, "rus");
    int DIM1 = rand()%3;
    int DIM2 = rand()%2;
    cout << "����� N = ";
    for (int i = 0; i < DIM1; i++)
    {
        if (i == 0)
            N[i] = rand() % 9 + 1;
        else
            N[i] = rand() % 10;
        cout << N[i];
    }
    cout <<endl<< "����� M = ";
    for (int i = 0; i < DIM2; i++)
    {
        if(i == 0)
            M[i] = rand()%9+1;
        else
            M[i] = rand() % 10;
        cout << M[i];
    }
    cout << endl;
    reverse(N, N + DIM1);
    reverse(M, M + DIM2);
    for (int i = 0; i < DIM1; i++)
    {
        int k = 0;
        for (int j = 0 ; j < DIM2; j++)
            c[i + j ] += N[i] * M[j];//�������� ������ ������� N �� ������ �������� �
    }
    int DIM3 = DIM1 + DIM2 + 1;
    for (int i = 0; i < DIM3; i++)
    {
        c[i + 1] += c[i] / 10;// ��������� � ������ ������� ����� ������� ����� 
        c[i] %= 10;
    }

    while (c[DIM3] == 0)//��������� ����� ��������� ���������
        DIM3--;
    cout << "M*N= ";
    for (int i = DIM3; i >= 0; i--)
        cout << c[i];
    return 0;
}
