#include <iostream>
#include <string>
#include <fstream>
/*6.  омпоненты файла f Ц целые числа, причем положительных чисел столько же,
сколько отрицательных. ѕолучить файл g из чисел исходного файла, в котором
записаны 2 положительных числа, затем 2 отрицательных и т. д*/
using namespace std;

void enter_data(ofstream& f_out, int& n)
{
	cout << "Size: ";
	cin >> n;
	cout << "Enter numbers: ";
	int x = 0;
	for (int i = 0; i < n; ++i)
	{
		cin >> x;
		f_out << x << ' ';
	}
	f_out << '\n';
}
void print(ifstream& f_in)
{
	string str;
	while (!f_in.eof())
	{
		getline(f_in, str);
		cout << str;
	}
}
void function_for_file_txt(ifstream& f_in, ofstream& f_out, int n)
{
	string str;
	string number;
	int x = 0;
	int pos_start = 0;
	int pos_finish = 0;
	int i = 0, j = 0;
	int* arr_number_negativ = new int[n / 2];
	int* arr_number_positiv = new int[n / 2];

	getline(f_in, str);//считывает до перехода на новую строку

	while (pos_finish != -1)
	{
		pos_finish = str.find(' ', pos_start);
		if (pos_finish != -1)
		{
			number.assign(str, pos_start, pos_finish - pos_start);
			pos_start = pos_finish + 1;
			x = atoi(number.c_str());
			if (x < 0)
				arr_number_negativ[i++] = x;
			else
				arr_number_positiv[j++] = x;
		}
	}

	i = 0;
	j = 0;
	while (i < n / 2)
	{
		f_out << arr_number_positiv[i++] << ' ';
		if (i < n / 2)
			f_out << arr_number_positiv[i++] << ' ';

		f_out << arr_number_negativ[j++] << ' ';
		if (j < n / 2)
			f_out << arr_number_negativ[j++] << ' ';
	}
	f_out << '\n';
	delete[] arr_number_negativ;
	delete[] arr_number_positiv;
}

void for_file_txt()
{
	ofstream f_out;
	f_out.open("File_f.txt");
	int n = 0;

	if (!f_out.is_open())
		cout << "Error 1";
	else
		enter_data(f_out, n);
	f_out.close();

	ifstream f_in;
	f_in.open("File_f.txt");
	f_out.open("File_g.txt");

	if (!f_in.is_open() || !f_out.is_open())
		cout << "Error 2";
	else
		function_for_file_txt(f_in, f_out, n);

	f_out.close();
	f_in.close();


	f_in.open("File_g.txt");
	if (!f_in.is_open())
		cout << "Error 3";
	else
		print(f_in);

	f_in.close();
}

void print_bin(ifstream& f_in)
{
	int v;
	while (f_in.read(reinterpret_cast<char*>(&v), sizeof(int)))
		cout << v << " ";
}
void enter_data_bin(ofstream& f_out, int& n)
{
	cout << "Size: ";
	cin >> n;
	cout << "Enter numbers: ";
	int x = 0;
	for (int i = 0; i < n; ++i)
	{
		cin >> x;
		f_out.write(reinterpret_cast<const char*>(&x), sizeof(int));
	}
}
void function_for_file_bin(ifstream& f_in, ofstream& f_out, int n)
{
	string str;
	string number;
	int x = 0;
	int pos_start = 0;
	int pos_finish = 0;
	int i = 0, j = 0;
	int* arr_number_negativ = new int[n / 2];
	int* arr_number_positiv = new int[n / 2];
	
	while (!f_in.eof())
	{
		f_in.read(reinterpret_cast<char*>(&x), sizeof(int));
		if (x < 0)
		{
			if (i < n / 2)
				arr_number_negativ[i++] = x;
		}
		else
			if (j < n / 2)
				arr_number_positiv[j++] = x;
	}
	i = 0;
	j = 0;
	while (i < n / 2)
	{
		f_out.write(reinterpret_cast<const char*>(&arr_number_positiv[i++]), sizeof(int));
		if (i < n / 2)
			f_out.write(reinterpret_cast<const char*>(&arr_number_positiv[i++]), sizeof(int));

		f_out.write(reinterpret_cast<const char*>(&arr_number_negativ[j++]), sizeof(int));
		if (j < n / 2)
			f_out.write(reinterpret_cast<const char*>(&arr_number_negativ[j++]), sizeof(int));
	}

	delete[] arr_number_negativ;
	delete[] arr_number_positiv;
}

void for_file_bin()
{
	ofstream f_out;
	f_out.open("File_f.txt", ios::binary);
	int n = 0;

	if (!f_out.is_open())
		cout << "Error 1";
	else
		enter_data_bin(f_out, n);
	f_out.close();

	ifstream f_in;
	f_in.open("File_f.txt", ios::binary);
	f_out.open("File_g.txt", ios::binary);

	if (!f_in.is_open() || !f_out.is_open())
		cout << "Error 2";
	else
		function_for_file_bin(f_in, f_out, n);

	f_out.close();
	f_in.close();


	f_in.open("File_g.txt", ios::binary);
	if (!f_in.is_open())
		cout << "Error 3";
	else
		print_bin(f_in);

	f_in.close();

}

int main()
{
	cout << "For file txt:\n";
	for_file_txt();
	cout << "\n\n\nFor file bin:\n";
	for_file_bin();
	return 0;
}