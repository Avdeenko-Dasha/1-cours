//��������� ������� ��� �������� ������������������ �������� 
//������ ����������� ����� k.���������� k - � ����� ������������������ :
//  1525125625..., � ������� �������� ������ ������� 5; 
#include <iostream>
using namespace std;

//1 5 25 125 625 3125 15625 78125 390625 1953125 9765625

int main() {
	setlocale(0, "rus");
	int cifri = 0;
	int power = 0;
	int element;
	int temp;
	int k;
	cout << "������� k ";
	cin >> k;


	while (cifri < k) 
	{
		element = pow(5, power);
		temp = element;

		while (temp) 
		{
			temp /= 10;
			cifri++;
			//cout << cifri << ' ' << temp << endl;
		}

		power++;
	}

	//cout << cifri << ' ' << element << endl;

	while (cifri > k) 
	{
		cifri--;
		element /= 10;
		//cout << endl << cifri << ' ' << element << endl;
	}
	element %= 10;

	cout <<"����� ������������������ ��� ������� "<< k << " ����� "<< element << endl;
	system("pause");
	return 0;
}