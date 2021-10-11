#include <iostream>
#include <iomanip>
/*Сверхпростое число — это простое число, номер которого в списке простых
чисел, упорядоченном по возрастанию, является простым числом. Найдите k-ое
сверхпростое число. */

using namespace std;

int main()
{
	int kol = 0;
	cin >> kol;
	bool* arr = new bool[kol * kol];
	arr[0] = false;
	arr[1] = true;
	for (int i = 2; i < kol * kol; ++i)
	{
		arr[i] = true;
		for (int j = 2; j < kol * kol; ++j)
			if (i != j && i % j == 0)
			{
				arr[i] = false;
				break;
			}
	}
	int i = 0;
	int j = 0;
	while (i < kol)
	{
		if (arr[j])
			++i;
		++j;
	}
	kol = j - 1;
	i = 0;
	j = 0;
	while (i < kol)
	{
		if (arr[j])
			++i;
		++j;
	}
	cout << j - 1 << '\n';
	return 0;
}