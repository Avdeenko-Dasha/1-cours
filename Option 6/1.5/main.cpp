#include <iostream>

using namespace std;

int main()
{
	double x1 = 0, x2 = 0, x3 = 0, y1 = 0, y2 = 0, y3 = 0, x = 0, y = 0;
	cout << "Vertex 1 ";
	cin >> x1 >> y1;
	cout << "Vertex 2 ";
	cin >> x2 >> y2;
	cout << "Vertex 3 ";
	cin >> x3 >> y3;
	if (y2 > y1)
	{
		swap(x2, x1);
		swap(y2, y1);
	}
	if (y3 > y1)
	{
		swap(x3, x1);
		swap(y3, y1);
	}
	if (x3 > x2)
	{
		swap(x2, x3);
		swap(y2, y3);
	}
	if (x1 == 0 && y1 == 0)
		cout << "YES";
	else if (x2 == 0 && y2 == 0)
		cout << "YES";
	else if (x3 == 0 && y3 == 0)
		cout << "YES";
	else
	{
		double b12 = 0, b13 = 0, b23 = 0;
		b12 = y1 - ((y2 - y1) / (x2 - x1)) * x1;
		b13 = y1 - ((y3 - y1) / (x3 - x1)) * x1;
		b23 = y2 - (y3 - y2) / (x3 - x2) * x2;
		if (b12 >= 0 && b13 >= 0 && b23 <= 0)
			cout << "YES";
		else
			cout << "NO";
	}
	return 0;
}