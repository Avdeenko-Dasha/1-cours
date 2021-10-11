//3.7 1. ������ ������������� ������ ����������� ������� � � ������������� ������ b ������������ n. ����� ������ � = A^2 * b. 
//����������� ���������� ���������� ������� A, ���� �� i > j ������� a ij= 0. 
//������ � �������� ������������������ ���������, ��������������� ������ �������. 
#include <iostream>
#include <iomanip>
#include <time.h>

using namespace std;

int main()
{       srand(time(NULL));
		setlocale(0, "");

		int n;
		cout << "������� n: ";
		cin >> n;

		int msize = (n + 1) * n / 2;
		int* m = new int[msize];
		int* b = new int[n];
		int* c = new int[n] {0};
		int* temp = new int[n] {0};

		int i, q, w, e;
		int pos = 0;


		for (i = 0; i < msize; i++)  //�������
			m[i] = rand() % 19 - 9;

		for (i = 0; i < n; i++) // ������
			b[i] = rand() % 19 - 9;


		int r = 0;
		for (i = 0; i < n; i++)//���
		{ 
			for (q = i; q < n; q++)//��� ���������� ��� �������
				temp[q] = b[q];
			for (w = i; w < n; w++) // ��������� ������� �� ������
			{
				temp[w] *= m[r];
				r++;
			}
			for (e = 0; e < n; e++)// ������������ �������
				c[i] += temp[e];
		}

		cout << "\n\n";
		for (i = 0; i < n; i++)
		{
			for (q = 0; q < i; q++)
				cout << setw(4) << "0";

			for (w = i; w < n; w++) // ����� �������
			{ 
				cout << setw(4) << m[pos];
				pos++;
			}
			cout << setw(10) << b[i] << setw(10) << c[i] << "\n\n";
		}

		delete[] m;
		delete[] b;
		delete[] c;
		cout << "\n";
		system("pause");
		return 0;
	}
