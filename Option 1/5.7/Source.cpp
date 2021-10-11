/*����������� ��������� � �������;*/
#include <iostream>
#include <iomanip>
#include "Header.h"
using namespace std;

template < typename T >
void sort_exchange(T* a, int n, int& k_sravn, int& k_perem)
{
	for (int i = 1; i < n; i++)//��������� ������� �� ������� N-1 ���
		for (int j = n - 1; j >= i; j--)//������ � N-1-�� �������� ����� �� i-��
		{
			if (a[j - 1] > a[j])
			{
				T x = a[j - 1];
				a[j - 1] = a[j];// ����� ��������� � ������ ������������� �������
				a[j] = x;
				k_perem+=3;
			}
			k_sravn++;
		}
}

template < typename T >
void sort_insertion(T* a, int n, int& k_sravn, int& k_perem)
{
	for (int i = 1; i < n; i++)// ������� �� ��������������� ��������� �������
	{
		T x = a[i]; //������ ���������� ��������
		k_perem++;
		int j = i - 1;// ��������� ���� ����� ������� �� �������
		while (k_sravn++ , x < a[j])
		{
			a[j + 1] = a[j];// ����� �������� j-�� �������� �� 1 ������� ������
			j--;
			k_perem++;
			if (j < 0)// ������� ������ ��� ���������� ����� �������
				break;
		}
		a[j + 1] = x; // ������� ������� ��������
		k_perem++;
	}
}

int main()
{
	const int n = 100;
	int a[n] = { 0 };
	int x = 0;
	int k_sravn = 0, k_perem = 0;
	cout << "select:" << endl << "1 - ascending " << endl << "2 - descending " << endl << "3 - randomly " << endl;
	cin >> x;
	if (x == 1) ascending(a, n);
	else if (x == 2) descending(a, n);
	else if (x == 3) random(a, n);
	else cout << "error";
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl << "Exchange sort:" << endl;

	sort_exchange(a, n, k_sravn, k_perem);

	for (int i = 0; i < n; i++)
	{
		cout << a[i] << " ";
	}
	cout << "k_sravn = " << k_sravn << " k_perem = " << k_perem;

	k_sravn = 0;
	k_perem = 0;
	if (x == 1) ascending(a, n);
	else if (x == 2) descending(a, n);
	else if (x == 3) random(a, n);
	else cout << "error";

	cout << endl << "Sort by insertion:" << endl;

	sort_insertion(a, n, k_sravn, k_perem);

	for (int i = 0; i < n; i++)
	{
		cout << a[i] << " ";
	}
	cout << "k_sravn = " << k_sravn << " k_perem = " << k_perem;
	return 0;
}
