#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>
#include <string>

using namespace std;

void program_7_1()
{
	int n = 1000;
	vector<int> arr(n, 0);
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
}

void enter_data(vector<vector<double>>& matrix, int n)
{
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			matrix[i][j] = rand() % 100 / 10.0;
}
void enter_data(vector<double>& matrix, int n)
{
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			matrix[i * n + j] = rand() % 100 / 10.0;
}
void print(vector<vector<double>> matrix, int n)
{
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
			cout << setw(10) << matrix[i][j];
		cout << '\n';
	}
	cout << '\n';
}
void print(vector<double> matrix, int n)
{
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
			cout << setw(10) << matrix[i * n + j];
		cout << '\n';
	}
	cout << '\n';
}
void multiplication(vector<vector<double>> matrix1, vector<vector<double>>& matrix2, int n)
{
	vector<vector<double>>matr(n, vector<double>(n));
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			matr[i][j] = matrix2[i][j];


	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
		{
			double sum = 0;
			for (int k = 0; k < n; ++k)
				sum += matrix1[i][k] * matr[k][j];
			matrix2[i][j] = sum;
		}
	for (int i = 0; i < n; ++i)
		matr[i].clear();
	matr.clear();
}
void multiplication(vector<double> matrix1, vector<double>& matrix2, int n)
{
	vector<double> matr (n * n);
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			matr[i * n + j] = matrix2[i * n + j];

	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
		{
			double sum = 0;
			for (int k = 0; k < n; ++k)
				sum += matrix1[i * n + k] * matr[k * n + j];
			matrix2[i * n + j] = sum;
		}

	matr.clear();
}
void pow_matrix(vector<vector<double>>& matrix, int n, int p)
{
	vector<vector<double>>matr(n, vector<double>(n));

	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			matr[i][j] = matrix[i][j];

	for (int i = 1; i < p; ++i)
		multiplication(matr, matrix, n);

	for (int i = 0; i < n; ++i)
		matr[i].clear();
	matr.clear();
}
void pow_matrix(vector<double>& matrix, int n, int p)
{
	vector<double> matr (n * n);

	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			matr[i * n + j] = matrix[i * n + j];

	for (int i = 1; i < p; ++i)
		multiplication(matr, matrix, n);

	matr.clear();
}

void program_7_2()
{
	int n = 0;
	cout << "Size matrix: ";
	cin >> n;
	int p = 0;
	cout << "Pow: ";
	cin >> p;

	vector<vector<double>> matrix_1(n, vector<double>(n));
	vector<double> matrix_2(n * n);

	enter_data(matrix_1, n);
	enter_data(matrix_2, n);

	print(matrix_1, n);
	print(matrix_2, n);

	pow_matrix(matrix_1, n, p);
	pow_matrix(matrix_2, n, p);

	print(matrix_1, n);
	print(matrix_2, n);
}

void words(string text, string& word, int pos)
{
	char separators[] = " .,:;!?-()";
	bool flag = true;
	for (int j = pos; j < text.size(); ++j)
	{
		flag = true;
		for (int k = 0; separators[k]; ++k)
			if (text[j] == separators[k])
			{
				flag = false;
				break;
			}
		if (flag)
			word.push_back(text[j]);
		else break;
	}

}
void create_array(vector<string>& array, string text)
{
	int pos = 0;
	int count = 1;
	char separators[] = " .,:;!?-()";
	for (int i = 0; i < text.size(); ++i)
		for (int j = 0; separators[j]; ++j)
			if (text[i] == separators[j])
			{
				++count;
				break;
			}
	string word;
	array.resize(count);
	for (int i = 0; i < count; ++i)
	{
		words(text, word, pos);
		pos += word.size() + 1;
		array[i] = word;
		word.clear();
	}
}
void create_stroka(string& text, vector<string> array)
{
	text.clear();
	int count = array.size();

	while (count)
	{
		int max_size = 0;
		int pos = 0;
		for (int i = 0; i < array.size(); ++i)
			if (array[i].size() > max_size)
			{
				max_size = array[i].size();
				pos = i;
			}
		text += array[pos];
		text += ' ';
		array[pos].clear();
		count--;
	}
}

void program_5_3()
{
	string text;
	cout << "Text: ";
	getline(cin, text);
	getline(cin, text);
	vector<string> array;
	create_array(array, text);
	create_stroka(text, array);
	cout << text;
}

int main()
{
	cout << "7.1 : \n";
	program_7_1();
	cout << "\n7.2 : \n";
	program_7_2();
	cout << "\n5.3 : \n";
	program_5_3();
	return 0;
}