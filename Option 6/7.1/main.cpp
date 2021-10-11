#include <iostream>
#include <fstream>

using namespace std;

int main()
{
	int n = 1000;
	int* arr = new int[n];
	for (int i = 0; i < n; ++i)
		arr[i] = 0;
	ofstream file_f;
	file_f.open("File.txt");
	if (!file_f.is_open())
		cout << "Error 1";
	else
	{
		for (int i = 0; i < 99; ++i)
			file_f << rand() % 1000 << " ";
	}
	file_f.close();

	ifstream file;
	file.open("File.txt");
	if (!file.is_open())
		cout << "Error 2";
	else
	{
		int a;
		while (!file.eof())
		{
			file >> a;
			arr[a] += 1;
		}
		for (int i = 0; i < n; ++i)
			if (arr[i] != 0 && arr[i] > 1)
				cout << i << " ";
	}
	file.close();
	return 0;
}