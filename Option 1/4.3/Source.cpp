// 1. �������� � ����� ������ �����, ������� ������� �� ��� �� ����, ��� � ������ ����� � �������� ������ ��������.
#include <iostream>
/*#include <windows.h> // ��� OemToAnsi
#include <iomanip>
#include <stdio.h> //��� gets_s � puts
*/
using namespace std;
int main()
{
	setlocale(0, "rus");
	const int n = 80;
	char s[n] = { 0 };
	char m[n] = { 0 };
	char res[n] = { 0 };
	char r[] = " ;//.,?!;:()-";

	cout << "������� ������ ";
	cin.getline(s, n, '\n');
	
		bool flag = 0;
		for (int i = 0; s[i] && flag == 0; i++)//���������� � ������ m ������ ����� ������
		{
			for (int k = 0; r[k]; k++)
				if (r[k] == s[i])
					flag = 1;
			if (flag == 0)
				m[i] = s[i];
		}
	

	cout << m << endl;
	for (int i = 0, c = 0; s[i]; i++)
	{

		bool flag_razd = 0;//�������, ���� �����������
		bool flag_word = 1;// �������, ���� ����� ��������
		int j = i;

		for (; s[j] && flag_razd == 0; j++)
		{
			for (int k = 0; r[k]; k++)
				if (s[j] == r[k])
					flag_razd = 1;//����� ����� �����������

			int flag21 = 0;
			if (flag_razd == 0)//���� ��� ������ � �� �����������
				for (int k = 0; m[k]; k++)
					if (s[j] == m[k])//���������� �������� ������ � ������� 1 �����
						flag21 = 1;//���� ����� ���������

			if (flag_word == 1 && flag21 == 0 && flag_razd == 0) flag_word = 0;//��������� �������� �� ����� ������
		}
		if (s[j]) j--;//���������� j �������� ����������� ��� ����-�����������

		for (; i < j && flag_word == 1; i++, c++)//���� ����� �������� ����� ��� � �������
		{
			res[c] = s[i];
		}
		if (flag_word == 1)//������ ������ ����� �������
		{
			res[c] = ' ';
			c++;
		}
		i = j;//��� �� i ���� �� ����� j  � �� �� ��������� ������ �����.
	}

	cout << endl << res;

	return(0);

}
