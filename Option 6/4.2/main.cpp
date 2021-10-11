#include <iostream>
#include <stdlib.h>

using namespace std;

int main()
{
	const int max = 100;
	char number_10[100];
	char number_16[100];
	cin.getline(number_10, max);
	double num;
	num = atof(number_10);
	int whole_part = (int)num;
	double fruction = num - whole_part;
	int arr[100] = { 0 };
	int n = 0;
	while(whole_part>16)
	{
		arr[n++] = whole_part % 16;
		whole_part = whole_part / 16;
	}
	arr[n] = whole_part;
	int k = 0;
	int pos = n;
	for (int i = n; i >= 0; --i)
	{
		if (arr[i] < 10)
			number_16[k++] = arr[i]+48;
		else if (arr[i] == 10)
			number_16[k++] = 'A';
		else if (arr[i] == 11)
			number_16[k++] = 'B';
		else if (arr[i] == 12)
			number_16[k++] = 'C';
		else if (arr[i] == 13)
			number_16[k++] = 'D';
		else if (arr[i] == 14)
			number_16[k++] = 'E';
		else if (arr[i] == 15)
			number_16[k++] = 'F';
	}
	number_16[k++] = '.';
	for (int i = 0; i < 4; ++i)
	{
		fruction *= 16;
		arr[++n] = (int)fruction;
		fruction -= arr[n];
	}
	for (int i = pos+1; i <= n; ++i)
	{
		if (arr[i] < 10)
			number_16[k++] = arr[i]+48;
		else if (arr[i] == 10)
			number_16[k++] = 'A';
		else if (arr[i] == 11)
			number_16[k++] = 'B';
		else if (arr[i] == 12)
			number_16[k++] = 'C';
		else if (arr[i] == 13)
			number_16[k++] = 'D';
		else if (arr[i] == 14)
			number_16[k++] = 'E';
		else if (arr[i] == 15)
			number_16[k++] = 'F';
	}
	number_16[k] = '\0';
	cout << number_16;

	return 0;
}