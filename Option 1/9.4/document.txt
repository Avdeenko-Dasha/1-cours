//7.3.ЛИНЕЙНЫЙ СПИСОК СТРУКТУР
//Создать связанную структуру данных – список. Разработать функции для
//выполнения базовых операций над линейными связанными структурами,
//содержащими записи со сведениями о студентах : ФИО, дата рождения, курс, успеваемость.
//При добавлении элемента данных в список обеспечить упорядоченность по алфавиту фамилий.
//Оценить асимптотическую сложность алгоритма.
//1. По исходному списку определить ФИО самого младшего студента на каждом курсе.
//Сформировать список из этих студентов, удалив их из исходного списка.
#include <iostream>
#include <iomanip>
#include <ctime>

using namespace std;

struct student
{
    char surname[50] = { 0 }; //фамилия
    char name[50] = { 0 }; //имя
    char fathername[50] = { 0 };//отчество
    short age = 0; //возраст
    short sex = 0; //пол 0 - women, 1 - men
    short course = 0; //курс
    float progress = 0; //отметка
    student* next = NULL;
};

void find(student* st, student* top, student*& pointer)// ищем указатель на элемент перед вставкой нашего студента
{
	pointer = top;
	while (top != NULL && strcmp(st->surname, top->surname) > 0)
	{
		pointer = top;
		top = top->next;
	}
}

void random(student*& st)// Заполняем студента данными
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

void add(student*& top, student*& st)//Добавление нового студента в список
{
	if (top == NULL)//если это первый студент в списке
	{
		top = st;
	}
	else
	{
		if (strcmp(st->surname, top->surname) < 0)//Записываем студентов в алфавитном порядке
		{
			st->next = top;
			top = st;
		}
		else
		{
			student* pointer = NULL;
			find(st, top, pointer);//Ищем указатель на элемент, который стоит перед нашим студентом
			st->next = pointer->next;
			pointer->next = st;
		}
	}
}

void output(student* top)//Вывод списка
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

void jun_st(student*& top, student*& top_1)//Ищем младшего студента и вставляем его в новый список, вырезая из предыдущего
{
	for (int i = 0; i < 4;)
	{
		student* previous = NULL;
		student* little = NULL;
		while (i < 4 && little == NULL)//ищем первого студента с какого-то курса
		{
			++i;
			little = top;
			while (little != NULL && little->course != i)
			{
				previous = little;//указатель на елемент перед студентом
				little = little->next;
			}
		}
		student* run = little;// Бегунок
		if (run && run->next)//Смотрим есть ли первый студент на курсе и не последний ли он в нашем списке
		{
			while (true)//идем по циклу, пока не закончится список
			{
				if (run->next->course == i && little->age > run->next->age)// Ищем младшего студента с курса
				{
					previous = run;
					little = run->next;
				}
				if (run->next->next)
					run = run->next;
				else break;
			}
			if (run->next->course == i && little->age > run->next->age)//проверяем последнего студента в списке
			{
				previous = run;
				little = run->next;
			}
		}

		if (previous)// Записываем в новый список найденного младшего студента
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
	for (int i = 0; i < n; ++i)//Заполняем исходный список
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