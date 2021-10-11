#pragma once
#include <iostream>
#include <iomanip>
#include <ios>
#include <streambuf>
#include <fstream>

using namespace std;

void sort_exchange(double* a, int n)
{
	for (int i = 1; i < n; i++)//повторять проходы по массиву N-1 раз
		for (int j = n - 1; j >= i; j--)//проход с N-1-го элемента вверх до i-го
		{
			if (a[j - 1] > a[j])
			{
				double x = a[j - 1];
				a[j - 1] = a[j];// обмен элементов в случае неправильного порядка
				a[j] = x;
			}
		}
}

void yourself(ofstream& file, int n)
{
	/*double* arr = new double[n];
	for (int i = 0; i < n; ++i)
	{
		cin >> arr[i];
	}*/
	double x;
	//sort_exchange(arr, n);
	for (int i = 0; i < n; ++i)
	{
		cin >> x;
		file << x;
		file << " ";
	}
}

void yourself_bin(ofstream& file, int n)
{
	double* arr = new double[n];
	for (int i = 0; i < n; ++i)
	{
		cin >> arr[i];
	}
	sort_exchange(arr, n);
	for (int i = 0; i < n; ++i)
	{
		file.write(reinterpret_cast<const char*>(&arr[i]), sizeof(arr[i]));
	}
}

void random(ofstream& file, int n)
{
	double* arr = new double[n];
	for (int i = 0; i < n; ++i)
	{
		arr[i] = rand() % 1000 / 100.0;
	}
	sort_exchange(arr, n);
	for (int i = 0; i < n; ++i)
	{
		file << arr[i];
		file << " ";
	}
}

void random_bin(ofstream& file, int n)
{
	double* arr = new double[n];
	for (int i = 0; i < n; ++i)
	{
		arr[i] = rand() % 1000 / 100.0;
	}
	sort_exchange(arr, n);
	for (int i = 0; i < n; ++i)
	{
		file.write(reinterpret_cast<const char*>(&arr[i]), sizeof(arr[i]));
	}
}

void Sort(ifstream& f, ifstream& g, ofstream& f_and_g)
{
	{
		double i = 0, j = 0;
		f >> i;
		g >> j;
		while (!f.eof() && !g.eof())
		{
			if (j < i)
			{
				f_and_g << j;
				f_and_g << " ";
				g >> j;
			}
			else
			{
				f_and_g << i;
				f_and_g << " ";
				f >> i;
			}
		}
		while (!f.eof())
		{
			f_and_g << i;
			f_and_g << " ";
			f >> i;
		}
		while (!g.eof())
		{
			f_and_g << j;
			f_and_g << " ";
			g >> j;
		}
	}
}

void Sort_bin(ifstream& f, ifstream& g, ofstream& f_and_g)
{
	{
		double i = 0, j = 0;
	    f.read(reinterpret_cast<char*>(&i), sizeof(double));
		g.read(reinterpret_cast<char*>(&j), sizeof(double));
		while (!f.eof() && !g.eof())
		{
			if (j < i)
			{
				f_and_g.write(reinterpret_cast<const char*>(&j), sizeof(double));
				g.read(reinterpret_cast<char*>(&j), sizeof(double));
			}
			else
			{
				f_and_g.write(reinterpret_cast<const char*>(&i), sizeof(double));
				f.read(reinterpret_cast<char*>(&i), sizeof(double));
			}
		}
		while (!f.eof())
		{
			f_and_g.write(reinterpret_cast<const char*>(&i), sizeof(double));
			f.read(reinterpret_cast<char*>(&i), sizeof(double));
		}
		while (!g.eof())
		{
			f_and_g.write(reinterpret_cast<const char*>(&j), sizeof(double));
			g.read(reinterpret_cast<char*>(&j), sizeof(double));
		}
	}
}

//void read_file(ifstream& infile, int MAX)
//{
//	double v;
//	for (int i = 0; i < MAX && !infile.eof(); ++i)//до достижения конца файла
//	{
//		infile.read(reinterpret_cast<char*>(&v), sizeof(double));// чтение строки из файла infile
//		cout << v << " ";
//	}
//	cout << endl << endl << endl;
//}

void output()
{
	cout << "Start " << endl;
	ifstream final_list("text.bin", ios::binary);
	double v;
	if (!final_list.is_open())
	{
		cout << "Error";
		return;
	}
	while (final_list.read(reinterpret_cast<char*>(&v), sizeof(double)))
	{
		cout << v << " ";
	}
	final_list.close();
	cout << "Finish";

}