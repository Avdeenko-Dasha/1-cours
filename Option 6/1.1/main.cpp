#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	int s = 0, t = 0;
	double x = 0;
	cin >> s >> t >> x;
	double y = pow(x, t);
	y = (sin(y) * sin(y)) / (log(y * sqrt(1 + pow(x, s))));
	cout << y;
	return 0;
}