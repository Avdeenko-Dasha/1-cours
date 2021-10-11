//1. Дано натуральное n. Получить все его простые делители.
#include <iostream>
using namespace std; 
int main()
{
    setlocale(0, "rus");
    int n, k, l;
    cout << "Введите число n ";
    cin >> n;
    cout << "Все простые делители числа " << n << " равны ";
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