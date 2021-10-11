#include "List.h"

int main()
{
	List spisok_1(20);
	spisok_1.random();
	spisok_1.print();

	List spisok_2(15);
	spisok_2.random();
	spisok_2.print();

	List spisok;
	spisok.foo(spisok_1, spisok_2);
	spisok.print();
	return 0;
}