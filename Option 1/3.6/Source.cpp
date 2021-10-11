/*3.6. »—ѕќЋ№«ќ¬јЌ»≈ ћј——»¬ќ¬ ƒЋя ѕ–≈ƒ—“ј¬Ћ≈Ќ»я ЂƒЋ»ЌЌџ’ї „»—≈Ћ 
1. ¬ывести последовательность dk, dkЦ1, Е, d0 дес€тичных цифр числа N * M, 
где N, M Ц натуральные числа, N, M > 10^10 ,
т.е. такую целочисленную последовательность, в которой каждый член di удовлетвор€ет условию 
0 <= di  <= 9  и dk*10^k + dkЦ1*10^(kЦ1) + Е d0   =   N * M. */
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
    cout << "„исло N = ";
    for (int i = 0; i < DIM1; i++)
    {
        if (i == 0)
            N[i] = rand() % 9 + 1;
        else
            N[i] = rand() % 10;
        cout << N[i];
    }
    cout <<endl<< "„исло M = ";
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
            c[i + j ] += N[i] * M[j];//”множаем каждый элемент N на каждый эелемент ћ
    }
    int DIM3 = DIM1 + DIM2 + 1;
    for (int i = 0; i < DIM3; i++)
    {
        c[i + 1] += c[i] / 10;// ѕереносим в другие разр€ды числа которые нужно 
        c[i] %= 10;
    }

    while (c[DIM3] == 0)//ѕровер€ем длину конечного умножени€
        DIM3--;
    cout << "M*N= ";
    for (int i = DIM3; i >= 0; i--)
        cout << c[i];
    return 0;
}
