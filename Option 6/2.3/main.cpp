#include <iostream>
#include <iomanip>
/*������������ ����� � ��� ������� �����, ����� �������� � ������ �������
�����, ������������� �� �����������, �������� ������� ������. ������� k-��
������������ �����. */

using namespace std;

int main()
{
	int kol = 0;
	cin >> kol;
	int i = 0;//�������
	int n = 0;//������� �����
	while (i < kol)
	{
		++n;
		bool pr = true;
		for (int k = 2; k <= n / 2; k++)
			if (!(n % k))
			{
				pr = false;
				break;
			}
		if (pr)
			++i;
	}
	i = 0;
	kol = n;
	n = 0;
	while (i < kol)
	{
		++n;
		bool pr = true;
		for (int k = 2; k <= n / 2; k++)
			if (!(n % k))
			{
				pr = false;
				break;
			}
		if (pr)
			++i;
	}
	cout << n;
	return 0;
}