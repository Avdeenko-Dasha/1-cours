#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>

/*
Ќайти повтор€ющиес€ элементы и вывести их на экран

ќбъедин€ющий тип unsigned int дл€ хранени€ номеров автомобилей, битовые
пол€: 4 дес€тичных разр€да (0..9999), две заглавных латинских буквы, цифра кода области (1..7).*/

using namespace std;



union car_number
{
	unsigned int x;
	struct numb
	{
		unsigned int number : 14;
		unsigned char letter1 : 7;
		unsigned char letter2 : 7;
		unsigned int kod : 4;
	}num;
};

void enter_data(car_number& car)
{
	car.num.number = rand() % 9999 + 1000;
	car.num.letter1 = rand() % 26 + 65;
	car.num.letter2 = rand() % 26 + 65;
	car.num.kod = rand() % 9 + 1;
}
void print_number_car(car_number& car)
{
	cout << car.num.number << car.num.letter1 << car.num.letter2 << car.num.kod << '\n';
}

bool sravn_num(car_number& num1, car_number& num2)
{
	if (num1.num.number < num2.num.number)
		return true;
	return false;
}

bool povtor(car_number& num, int pos, int n, car_number* arr)
{
	for (int i = 0; i < n; ++i)
		if (i != pos)
			if (arr[i].num.number == num.num.number && arr[i].num.letter1 == num.num.letter1)
				if (arr[i].num.letter2 == num.num.letter2 && arr[i].num.kod == num.num.kod)
					return true;
			
	return false;
}

int main()
{
	srand(time(NULL));
	
	int n = rand() % 99999+1;
	car_number* arr = new car_number[n];
	for (int i = 0; i < n; ++i)
		enter_data(arr[i]);
	

	sort(arr, arr + n, sravn_num);
	//cout << "Arr:\n";
	//for (int i = 0; i < n; ++i)
	//	print_number_car(arr[i]);

	cout << "\n\nPovtor:\n";
	for (int i = 0; i < n; ++i)
		if (povtor(arr[i], i, n, arr))
			print_number_car(arr[i]);
	

	return 0;
}
