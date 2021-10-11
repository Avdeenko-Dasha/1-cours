#include "List.h"

int main()
{
	int n = 0;
	cin >> n;
	List spisok(n);
	spisok.random();
	spisok.print();

	cout << spisok.function();

	return 0;
}