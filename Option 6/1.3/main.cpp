#include <iostream>

using namespace std;

int main()
{
	double x1 = 0, x2 = 0, x3 = 0, x4 = 0;
	cin >> x1 >> x2 >> x3 >> x4;
	if (x1 > x2)
		swap(x1, x2);
	if (x3 > x4)
		swap(x3, x4);
	if (x3 > x2)
		swap(x3, x2);
	x1 > x2 ? swap(x1, x2) : swap(x1, x1);
	x3 > x4 ? swap(x3, x4) : swap(x1, x1);
	x3 > x2 ? swap(x3, x2) : swap(x1, x1);
	cout << x1 << " < " << x2 << " > " << x3 << " < " << x4;
	return 0;
}