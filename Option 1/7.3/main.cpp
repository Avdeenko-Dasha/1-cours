//7.3.�������� ������ ��������
//������� ��������� ��������� ������ � ������. ����������� ������� ���
//���������� ������� �������� ��� ��������� ���������� �����������,
//����������� ������ �� ���������� � ��������� : ���, ���� ��������, ����, ������������.
//��� ���������� �������� ������ � ������ ���������� ��������������� �� �������� �������.
//������� ��������������� ��������� ���������.
//1. �� ��������� ������ ���������� ��� ������ �������� �������� �� ������ �����.
//������������ ������ �� ���� ���������, ������ �� �� ��������� ������.
#include <iostream>
#include <iomanip>
#include <ctime>

using namespace std;

struct student
{
    char surname[50] = { 0 }; //�������
    char name[50] = { 0 }; //���
    char fathername[50] = { 0 };//��������
    short age = 0; //�������
    short sex = 0; //��� 0 - women, 1 - men
    short course = 0; //����
    float progress = 0; //�������
    student* next = NULL;
};

void find(student* st, student* top, student*& pointer)// ���� ��������� �� ������� ����� �������� ������ ��������
{
	pointer = top;
	while (top != NULL && strcmp(st->surname, top->surname) > 0)
	{
		pointer = top;
		top = top->next;
	}
}

void random(student*& st)// ��������� �������� �������
{
	int i = rand() % 10 + 3;
	st->surname[0] = rand() % ('Z' - 'A' + 1) + 'A';
	for (int j = 1; j < i; ++j)
	{
		st->surname[j] = rand() % ('z' - 'a' + 1) + 'a';
	}
	st->surname[i] = '\0';

	i = rand() % 10 + 3;
	st->name[0] = rand() % ('Z' - 'A' + 1) + 'A';
	for (int j = 1; j < i; ++j)
	{
		st->name[j] = rand() % ('z' - 'a' + 1) + 'a';
	}
	st->name[i] = '\0';

	i = rand() % 10 + 3;
	st->fathername[0] = rand() % ('Z' - 'A' + 1) + 'A';
	for (int j = 1; j < i; ++j)
	{
		st->fathername[j] = rand() % ('z' - 'a' + 1) + 'a';
	}
	st->fathername[i] = '\0';

	i = rand() % 50 + 17;
	st->age = i;

	i = rand() % 1;
	st->sex = i;

	i = rand() % 4 + 1;
	st->course = i;

	float j = rand() % 100 / 10.0;
	st->progress = j;

	st->next = NULL;
}

void add(student*& top, student*& st)//���������� ������ �������� � ������
{
	if (top == NULL)//���� ��� ������ ������� � ������
	{
		top = st;
	}
	else
	{
		if (strcmp(st->surname, top->surname) < 0)//���������� ��������� � ���������� �������
		{
			st->next = top;
			top = st;
		}
		else
		{
			student* pointer = NULL;
			find(st, top, pointer);//���� ��������� �� �������, ������� ����� ����� ����� ���������
			st->next = pointer->next;
			pointer->next = st;
		}
	}
}

void output(student* top)//����� ������
{
	int i = 0;
	while (top != NULL)
	{
		cout << i++ << " ";
		cout << top->surname << " ";
		//cout << top->name << " ";
		//cout << top->fathername << " ";
		cout << top->age << " ";
		//cout << top->sex << " ";
		cout << top->course << " ";
		//cout << top->progress << " ";
		cout << endl;
		top = top->next;
	}
}	

void jun_st(student*& top, student*& top_1)//���� �������� �������� � ��������� ��� � ����� ������, ������� �� �����������
{
	for (int i = 0; i < 4;)
	{
		student* previous = NULL;
		student* little = NULL;
		while (i < 4 && little == NULL)//���� ������� �������� � ������-�� �����
		{
			++i;
			little = top;
			while (little != NULL && little->course != i)
			{
				previous = little;//��������� �� ������� ����� ���������
				little = little->next;
			}
		}
		student* run = little;// �������
		if (run && run->next)//������� ���� �� ������ ������� �� ����� � �� ��������� �� �� � ����� ������
		{
			while (true)//���� �� �����, ���� �� ���������� ������
			{
				if (run->next->course == i && little->age > run->next->age)// ���� �������� �������� � �����
				{
					previous = run;
					little = run->next;
				}
				if (run->next->next)
					run = run->next;
				else break;
			}
			if (run->next->course == i && little->age > run->next->age)//��������� ���������� �������� � ������
			{
				previous = run;
				little = run->next;
			}
		}

		if (previous)// ���������� � ����� ������ ���������� �������� ��������
		{
			previous->next = little->next;
			little->next = NULL;
			add(top_1, little);
		}
		else if (top)
		{
			top = top->next;
			little->next = NULL;
			add(top_1, little);
		}
		else top = NULL;
	}
}

int main()
{
	srand(time(NULL));
	int n = 10;
	student* top = NULL;
	for (int i = 0; i < n; ++i)//��������� �������� ������
	{
		student* st = new student;
		random(st);
		add(top, st);
	}
	output(top);
	student* top_1 = NULL;
	jun_st(top, top_1);
	cout << "_________________________________________\n";
	output(top_1);
	cout << "_________________________________________\n";
	output(top);
	return 0;
}