#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
	srand(time(NULL));
	int n = 0, m = 0;
	cin >> n >> m;
	double matrix[100][100] = { 0 };

	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			//matrix[i][j] = rand() % 1000 / 10.0;
			*(*(matrix + i) + j) = rand() % 1000 / 10.0;

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
			//cout << matrix[i][j] << " ";
			cout << setw(6) << *(*(matrix + i) + j);
		cout << '\n';
	}
	cout << endl;
	int k = 0;

	while (k < n)
	{
		//double max = matrix[k][m - 1];
		double max = *(*(matrix + k) + m - 1);
		int pos = k;
		for (int i = k + 1; i < n; ++i)
			//if (matrix[i][m - 1] >= max)
			if(*(*(matrix+i)+m-1)>= max)
			{
				//max = matrix[i][m - 1];
				max = *(*(matrix + i) + m - 1);
				pos = i;
			}

		for (int j = 0; j < m; ++j)
			//swap(matrix[k][j], matrix[pos][j]);
			swap(*(*(matrix + k) + j), *(*(matrix + pos) + j));
			++k;
	}


	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
			//cout << matrix[i][j] << " ";
			cout << setw(6) << *(*(matrix + i) + j);
		cout << '\n';
	}

	return 0;
}