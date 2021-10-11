#include <iostream>

using namespace std;

int main()
{
	double x = 0, y = 0;
	cin >> x >> y;
	if (y <= 2 - x * x)
		if (y >= x && x <= 0)
			cout << "YES";
		else if (y <= x && x >= 0)
			cout << "YES";
		else cout << "NO";
	return 0;
}