#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
	int i = 1;
	double x = 1;
	int n = 0;
	cin >> n;
	double pow = x;
	double x_2 = x;
	double y = 10;
	while (x <= 2)
	{
		pow = x;
		y = 10;
		for (int k = 2; k <= 2*n; k += 2)
		{
			x_2 = x;
			for (int j = 1; j < k; ++j)
				x_2 *= pow;
			for (int j = 0; j < k/2 + 1; ++j)
				x_2 = -x_2;
			y += k * x_2;
		}
		cout << setw(4) << x << "|" << setw(8) << y << "|\n";
		x = 1 + i * 0.25;
		++i;
	}
	cout << endl << endl;
	x = 1;
	i = 1;
	while (x <= 2)
	{
		y = 0;
		pow = x * x;
		for (int k = 2 * n; k >= 2; k -= 2)
		{
			x_2 = k;
			for (int j = 0; j < k/2 + 1; ++j)
				x_2 = -x_2;
			y += x_2;
			y *= pow;
		}
		y += 10;
		cout << setw(4) << x << "|" << setw(8) << y << "|\n";
		x = 1 + i * 0.25;
		++i;
	}
	return 0;
}