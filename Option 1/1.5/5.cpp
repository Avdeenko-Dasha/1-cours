#include <iostream>;
#include <math.h>;
using namespace std;
int main()
{
	setlocale(0, "rus");
	double a1, b1, c1, a2, b2, c2, x, y;
	cout << "������� a1 " << endl;
	cin >> a1;
	cout << "������� b1 " << endl;
	cin >> b1;
	cout << "������� c1 " << endl;
	cin >> c1;
	cout << "������� a2 " << endl;
	cin >> a2;
	cout << "������� b2 " << endl;
	cin >> b2;
	cout << "������� c2 " << endl;
	cin >> c2;
	if (abs(a1 * b2 - b1 * a2)>1e-12)
	{
		x = (b1 * c2 - b2 * c1) / (a1 * b2 - a2 * b1);
		y = (c1 * a2 - a1 * c2) / (a1 * b2 - a2 * b1);
		cout << "x = " << x << "   y = " << y << endl;
	}
	else cout << "��� ������ ���������" << endl;
	system("pause");
	return 0;
}
