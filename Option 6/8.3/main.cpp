#include "Number.h"

int main()
{
	Number num;
	Number two;
	two.perevod_num(10);
	num.perevod_num(8);
	cout << two << endl;
	cout << num << endl;
	num.sum(two);
	cout << num;
	return 0;
}