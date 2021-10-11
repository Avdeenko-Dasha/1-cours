//3.2. ���������� ����� ������� �� ����� �������� ������� 
//�������� ���������� ������� B ������� n, 
//������ ������� bij ������� ����� ��������� �� ��������� �������� ���������� ������� � ������� n, 
//������������� � ����������� ������� (������� �������), ������������ ���������������� ��������� i, j �� �������. 
#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <time.h>

    using namespace std;

    
   

    int main()
    {
        const unsigned int DIM1 = 5;
        const unsigned int DIM2 = 5;

        int ary[DIM1][DIM2];
        int b[DIM1][DIM2];
        int i, j, k, l;
        setlocale(0, "rus");
       /* int m = 1;
        for (int i = 0; i < DIM1; i++)
        {
            for (int j = 0; j < DIM2; j++)
            {
                ary[i][j] = m;
                m++;
            }
        }*/
        srand(time(0));
        for (int i = 0; i < DIM1; i++)
            for (int j = 0; j < DIM2; j++)
                ary[i][j] = rand() % 10;

        cout << "��������� �������" << endl;
        for (int i = 0; i < DIM1; i++)
        {
            for (int j = 0; j < DIM2; j++) 
                cout << setw(4) << ary[i][j];
            cout << endl;
        }
        cout << endl;

        for (int i = 0; i < DIM1; i++)
            for (int j = 0; j < DIM2; j++)
            {
                int max = INT_MIN;
                for (k = 0; k < DIM1; k++)
                    for (l = 0; l < DIM2; l++)
                    {
                        if (i == k || j == l)
                            continue;
                        if (ary[k][l] > max)
                            max = ary[k][l];
                    }
                b[i][j] = max;
            }

        cout << "�������� �������" << endl;
        for (int i = 0; i < DIM1; i++)
        {
            for (int j = 0; j < DIM2; j++)
                cout << setw(4) << b[i][j];
            cout << endl;
        }
        cout << endl;
        return 0;
    }