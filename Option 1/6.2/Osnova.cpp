/*Выполнить задания для текстового и бинарного файлов.
Задания выполнить через функции. Размер файлов <= 64GiB.
1. В файлах f и g содержатся вещественные числа, упорядоченные по возрастанию.
Получить за один проход файл чисел, упорядоченный по возрастанию, путем слияния файлов f и g. */
#include "Header.h"

int main()
{
		//////////////////////////////////////// Текстовые файлы ///////////////////////////

		srand(time(NULL));
		int n = 100;
		int k_sim_f = 0;
		int k_sim_g = 0;

		int x = 0;
		cout << "File F" << endl;
		cout << "1 - Fill in the file yourself" << endl << "2 - Fill the file randomly " << endl;
		cin >> x;

		ofstream f_vvod("text_f.txt");//создать объект для записи данных в файл
		ofstream f_vvod_bin("text_f.bin", ios :: binary);

		if (!f_vvod.is_open())
		{
			cout << "Error 1.1";
		}
		else if(!f_vvod_bin.is_open())
		{
			cout << "Error 1.2";
		}
		else
		{
			cout << "Reading is successfully" << endl;
			switch (x)
			{
			case 1:
				yourself(f_vvod, n);
				f_vvod.close();
				yourself_bin(f_vvod_bin, n);
				f_vvod_bin.close();
				break;
			case 2:
				random(f_vvod, n);
				f_vvod.close();
				random_bin(f_vvod_bin, n);
				f_vvod_bin.close();
				break;
			default:
				cout << "Error 1.3";
				break;
			}
		}

		cout << "File G" << endl;
		cout << "1 - Fill in the file yourself" << endl << "2 - Fill the file randomly " << endl;
		cin >> x;

		ofstream g_vvod("text_g.txt");//создать объект для записи данных в файл
		ofstream g_vvod_bin("text_g.bin");

		if (!g_vvod.is_open())
		{
			cout << "Error 2.1";
		}
		else if (!g_vvod_bin.is_open())
		{
			cout << "Error 2.2";
		}
		else
		{
			cout << "Reading is successfully" << endl;
			switch (x)
			{
			case 1:
				yourself(g_vvod, n);
				g_vvod.close();
				yourself_bin(g_vvod_bin, n);
				g_vvod_bin.close();
				break;
			case 2:
				random(g_vvod, n);
				g_vvod.close();
				random_bin(g_vvod_bin, n);
				g_vvod_bin.close();
				break;
			default:
				cout << "Error 2.3";
				break;
			}
		}

		ifstream f("text_f.txt"); // Объект для считывания инфы из файла
		ifstream g("text_g.txt"); // Объект для считывания инфы из файла
		ofstream f_and_g("text.txt");


		ifstream f_bin("text_f.bin", ios::binary); // Объект для считывания инфы из файла
		ifstream g_bin("text_g.bin", ios::binary); // Объект для считывания инфы из файла
		ofstream f_and_g_bin("text.bin", ios :: binary);

		if (!f.is_open() && !g.is_open())
		{
			cout << "Error 3.1" << endl;
		}
			else if (!f_bin.is_open() && !g_bin.is_open())
		{
			cout << "Error 3.2" << endl;
		}
		else
		{
			Sort(f, g, f_and_g);
			Sort_bin(f_bin, g_bin, f_and_g_bin);
			f.close();
			g.close();
			f_and_g.close();
			f_bin.close();
			g_bin.close();
			f_and_g_bin.close();
		}

		//ifstream res_bin("text.bin");
		//read_file(res_bin, n*n);
		output();

	return 0;
}