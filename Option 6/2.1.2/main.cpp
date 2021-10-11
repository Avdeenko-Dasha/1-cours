#include <iostream>

using namespace std;
/*6. Определить сумму k цифр дробной части заданного положительного вещественного числа,
которые следуют за n-ой цифрой.*/
int main()
{
	double number = 0;
	int start_position = 0;
	int count = 0;
	int total = 0;
	cin >> number;
	cin >> start_position;
	cin >> count;
	double fractional_part = number - int(number);

	for (int i = 0; i < start_position; i++)
		fractional_part *= 10;

	for (int i = 0; i < count; i++)
	{
		fractional_part *= 10;
		int digit = int(fractional_part) % 10;
		total += digit;
	}
	cout << total;

	return 0;
}