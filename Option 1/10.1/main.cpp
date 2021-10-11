#include "class1.h"
#include "class2.h"
#include "class3.h"
#include "class4.h"

int main()
{
	Demond_Deposit deposit1("09.05.21", 10, 500, "20.05.21");
	deposit1.Print();
	cout << endl;
	Conditional_Contribution deposit2("10.05.21", 5, 1000, "19.05.21", "before marriage");
	deposit2.Print();
	cout << endl;
	Term_Irrevocable_Deposit deposit3;
	deposit3.Print();
	cout << endl;
	Term_Revocable_Deposit deposit4;
	deposit4.Print();
	cout << endl;
	return 0;
}