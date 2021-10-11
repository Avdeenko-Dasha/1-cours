#include <iostream>

using namespace std;

int main()
{
	int k = 0;
	int x = 10;
	cin >> k;
	for (int i = 1; i < k / 2; ++i)
		++x;
	if (k % 2 == 0)
		k = x % 10;
	else
		k = x / 10;
	cout << k;
	return 0;
}