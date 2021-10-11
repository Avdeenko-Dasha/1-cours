#include "Header.h"

int main()
{
	const int n = 10;

	bool arr[n] = { 0 };
	int m = 0;
	int k = 10;
	ofstream in_file("text.txt");
	if (!in_file.is_open())
	{
		cout << "Error 1";
	}
	else
	{
		cout << "File is open successfully" << endl;
		random(in_file, n, k);
		in_file.close();
	}

	ifstream file("text.txt");
	if (!file.is_open())
	{
		cout << "Error 2";
	}
	else
	{
		cout << "File is open successfully" << endl;
		function_arr(arr, file, n);
		in_file.close();
	}
}