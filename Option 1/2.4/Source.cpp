//1. ���� �������������� ����� � (0 < x <= 1). 
//��������� �������� ����� � ��������� E = 1e�6 � ������� ���������� ���������.
//�������, ��� ��������� �������� ����������, ���� ��������� ��������� �� ����������� �������� ������ E
#include <iostream>
using namespace std;
int main()
{
    setlocale(0, "rus");
    double x, n, st, verx, sum;
    int fact, sn, niz, k;
    cout << "������� ����� x (0 < x <= 1) ";
    cin >> x;
    sum = 0;
    n = 1;
    sn = 1;
    verx = x;
    fact = 1;
    k = 1;
    while (abs(n) >= 1e-6) //n=((-1)^k*x^2k+1)/(k!*(2k+1))
    {
        n = 0;
        verx *= -1 * x * x;
        fact*=k;
        sn += 2;
        k++;
        niz = fact * sn;
        n = verx / niz;
        sum += n;
    }
    cout << "����� ����� " << sum << " ���������� ��������� " << k;
    return 0;
}