#include <iostream>
#include <iomanip>

using namespace std;

void spiral(int** matrix, int n)
{
	int k = 1;

	int str = n - 1;
	int stl = n;
	int kr = 0;
	int kl = 0;
	int i = n - 1;
	int j = 0;

	while (true)
	{
		if (k == n * n + 1)
			break;
		for (; j < stl; ++j)
			matrix[i][j] = k++;
		stl--;
		i--;
		j--;
		if (k == n * n + 1)
			break;
		for (; i >= kr; --i)
			matrix[i][j] = k++;
		kr++;
		j--;
		i++;
		if (k == n * n + 1)
			break;
		for (; j >= kl; --j)
			matrix[i][j] = k++;
		kl++;
		i++;
		j++;
		if (k == n * n + 1)
			break;
		for (; i < str; ++i)
			matrix[i][j] = k++;
		j++;
		i--;
		str--;
	}
}

int main()
{
	int matrix[100][100] = { 0 };
	int n = 10;

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
			cout << setw(4)<< matrix[i][j];
		cout << endl;
	}
	cout << endl;

	

	return 0;
}