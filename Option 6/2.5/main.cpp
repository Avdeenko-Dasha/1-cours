/*6. ¬водитс€ последовательность целых чисел. ќпределить количество элементов 
в наиболее длинной подпоследовательности подр€д идущих чисел,
представл€ющих собой степени двойки.*/
#include <iostream>

using namespace std;

int main()
{
	int n = 1, x, count = 0, k = 0;
	bool flag;
	while (n != 0)
	{
		cin >> n;
		flag = true;
		x = n;
		if (x > 1)
			for (int i = 0; i <= x; ++i)
				if (x % 2 != 0 && x > 1)
				{
					flag = false;
					break;
				}
				else x = x / 2;
		else flag = false;
		if (flag)
			count++;
		else
		{
			if (k < count)
				k = count;
			count = 0;
		}
	}
	if (k < count)
		cout << count;
	else
		cout << k;
	return 0;
}