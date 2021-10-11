//1. Дано действительное число х (0 < x <= 1). 
//Вычислить заданную сумму с точностью E = 1e–6 и указать количество слагаемых.
//Считать, что требуемая точность достигнута, если очередное слагаемое по абсолютному значению меньше E
#include <iostream>
using namespace std;
int main()
{
    setlocale(0, "rus");
    double x, n, st, verx, sum;
    int fact, sn, niz, k;
    cout << "Введите число x (0 < x <= 1) ";
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
    cout << "Сумма равна " << sum << " Количество слагаемых " << k;
    return 0;
}