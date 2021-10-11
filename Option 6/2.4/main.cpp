#include <iostream>

using namespace std;

int main()
{
	double x = 0;
	cin >> x;
	double sum = 0;
	double slag = 1;
	int k = 1;
	int fact = 1;
	double pow = x;
	while (slag >= 1e-6)
	{
		for (int i = 1; i < 2 * k - 1; ++i)
			x = x * pow;
		for (int i = 0; i < k + 1; ++i)
			x = -x;
		for (int i = 1; i <= 2 * k + 1; ++i)
			fact *= i;
		slag = x / ((2 * k - 1) * fact);
		sum += slag;
		x = pow;
		++k;
	}
	cout << sum;
	return 0;
}