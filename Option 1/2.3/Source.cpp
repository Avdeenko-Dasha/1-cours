//1. ���� ����������� n. �������� ��� ��� ������� ��������.
#include <iostream>
using namespace std; 
int main()
{
    setlocale(0, "rus");
    int n, k, l;
    cout << "������� ����� n ";
    cin >> n;
    cout << "��� ������� �������� ����� " << n << " ����� ";
    for (int i = 2; /*n>=1 && */i<=n; i++) 
    {
        k = 0;
        for (l = 2; l <= i - 1; l++)
        {
            if (i % l == 0)
            {
                k = 1;
            }
        }
        if (k == 0 && n % i == 0)
        {
            cout << i << " ";
        }
    }
    return 0;
}