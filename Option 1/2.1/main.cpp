//2.1.1. ????????? ???????, ??????? ????? ?????, ??????????? ? ?????????? ???????????? ?????? ????.
//????? n ???????? ? ??????????. 
//1. ???? ??????????? n. ????? ??, ??? ??? ????? ???????? ?????? ??? ?????????? ????? ?
#include <iostream>
using namespace std;
int main()
{
    setlocale(0, "rus");
    int n, a[10] = { 0 }, s;
    cout << "??????? ????? n ";
    cin >> n;
    s = 0;
    while (n > 0)
    {
        a[n % 10]++;
        n /= 10;
    }
    for (int i = 0; i <= 9; i++)
    {
        if (a[i] == 2)
        {
            s++;
        }
        if (a[i] >= 3)
        {
            s = 3;
        }
    }
    if (s == 1)
    {
        cout << "?????";
    }
    else 
    {
        cout << "???????";
    }
    return 0;
}