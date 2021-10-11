#include <iostream>
/*6. Задано число n в формате signed short int. Вывести на экран значения 0-го,
2-го и 15-го битов представления в ЭВМ этого числа. Объяснить результат.
Инвертировать биты 1, 15. Вывести и объяснить результат.*/
using namespace std;

int main()
{
	signed short int n = 0;
	cin >> n;
	for (int i = 0; i < 16; ++i)
		cout << ((n >> i) & 1);
	cout << "\n0 bit - " << (n & 1);
	cout << "\n2 bit - " << ((n >> 2) & 1);
	cout << "\n15 bit - " << ((n >> 15) & 1);
	n ^= (1 << 1);
	n ^= (1 << 15);
	cout << "\nInvert 1 bit - " << ((n >> 1) & 1);
	cout << "\nInvert 15 bit - " << ((n >> 15) & 1);
	cout << "\n";
	for (int i = 0; i < 16; ++i)
		cout << ((n >> i) & 1);
}