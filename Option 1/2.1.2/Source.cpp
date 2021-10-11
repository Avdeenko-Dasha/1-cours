//1. Определить, сколько среди первых k цифр дробной части заданного положительного вещественного числа, цифр 9.
#include <iostream>
using namespace std;
int main()
{
    setlocale(0, "rus");
    int k, s, a;
    double n;
    a = 0;
    cout << "Введите число n ";
    cin >> n;
    cout << "Введите число k ";
    cin >> k;
    n = n - int(n);
    s = 0;        //0,454435 k=3 
    for (int i = 0; i < k; i++)
    {
        n = n * 10;
        s = int(n);
        if (s==9)
        {
            a++;
        }
        n = n - int(n);
    }
    cout << "Количество цифр 9 среди первых "<< k << " цифр дробной части заданного числа = " << a << endl;
    return 0;
}