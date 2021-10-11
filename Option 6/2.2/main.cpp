#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
	double x0 = -0.5, dx = 0.1;
	double x = 0;
	double y = 0;
	cout << "1:" << endl;
	for (int i = 0; x < 0.5; ++i)
	{
		x = x0 + i * dx;
		y = 1 / (1 + x) + x - 1;
		cout << setw(4) << "x: " << setw(4) << x << setw(4) << "y: " << y << '\n';

	}
	cout << "\n2:" << endl;
	double z = 0;
	x = 0;
	for (int i = 0; x < 0.5; ++i)
	{
		y = 0;
		x = x0 + i * dx;
		z = 1;
		cout << setw(4) << "x: " << setw(4) << x;
		while (abs(z)>= 1e-6)
		{
			y += z;
			z *= -x;
		}
		y += x - 1;
		cout << setw(4) << "y: " << y << '\n';
	}
	return 0;
}