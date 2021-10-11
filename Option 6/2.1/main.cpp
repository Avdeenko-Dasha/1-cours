#include <iostream>

using namespace std;

int main()
{
	unsigned int n = 0;
	cin >> n;
	bool flag = true;
	int x = 0, y = 0;
	while (n)
	{
		 y = n / 10;
		 x = n % 10;
		while (y)
		{
			if (x == y % 10)
			{
				flag = false;
				break;
			}
			y /= 10;
		}
		n /= 10;
		if (!flag)
			break;
	}
	if (flag)
		cout << "YES";
	else cout << "NO";
	return 0;
}