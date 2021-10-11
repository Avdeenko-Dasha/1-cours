//Вводится последовательность целых чисел.
//Определить количество элементов в наиболее длинной подпоследовательности подряд идущих чисел, упорядоченных по убыванию.
#include <iostream>  

using namespace std;
int main()
{
    setlocale(0, "rus");
    int n, x, posl, res, predel;
    cout << " Ведите длину последовательности ";
    cin >> n;
    cout << "Введите члены последовательности " << endl;
    posl = 0;
    res = 0;
    predel = 1e9;
    while (n > 0)
    {
        cin >> x;
        if (x < predel)
        {
            posl++;
        }
        else
        {
            res = max(posl, res);
            posl = 1;
        }
        predel = x;
        n--;
    }
    res = max(posl, res);
    cout << "Длина наибольшей убывающей подпоследовательноси  " << res;
	return 0;
}