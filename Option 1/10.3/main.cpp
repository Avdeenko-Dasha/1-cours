#include "class_array.h"
#include "class1.h"
#include "class2.h"
#include "class3.h"
#include "class4.h"
#include <fstream>


int main()
{
	Array arr;
	ifstream file("text.txt");
	if (!file.is_open())
		cout << "Error 1";
	else
		arr.read(file);//Записываем данные из файла в массив
	file.close();

	arr.output();
	Demond_Deposit deposit1("09.05.21", 10, 500, "20.05.21");// первый элемент
	Conditional_Contribution deposit2("10.05.21", 5, 1000, "19.05.21", "before marriage");
	Term_Irrevocable_Deposit deposit3;
	Term_Revocable_Deposit deposit4;// второй элемент
	
	ofstream f("text.txt");
	if (!f.is_open())
	{
		cout << "Error 2";
	}
	else
	{
		f << arr << endl;//Записываем данные из массива в файл
	}
	f.close();

	return 0;
}