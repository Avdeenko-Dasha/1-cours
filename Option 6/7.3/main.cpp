#include <iostream>
#include <string>

using namespace std;

struct student
{
	string fio;
	string date_birth;
	int kurs = 0;
	double ball = 0;
	student* next = NULL;
};

void find(student* st, student* top, student*& pointer)
{
	pointer = top;
	while (top != NULL && strcmp(st->fio.c_str(), top->fio.c_str()) > 0)
	{
		pointer = top;
		top = top->next;
	}
}
void add(student*& top, student* st)
{
	if (top == NULL)
	{
		top = st;
		top->next = NULL;
	}
	else
		if (strcmp(st->fio.c_str(), top->fio.c_str()) < 0)
		{
			st->next = top;
			top = st;
		}
		else
		{
			student* pointer = NULL;
			find(st, top, pointer);
			st->next = pointer->next;
			pointer->next = st;
		}
}

void print(student* top)
{
	while (top != NULL)
	{
		cout << "\nFIO: " << top->fio;
		cout << "\nDate of Birth: " << top->date_birth;
		cout << "\nKurs: " << top->kurs;
		cout << "\nBall: " << top->ball << '\n';
		top = top->next;
	}
}

void yourself(student*& top, int n)
{
	for (int i = 0; i < n; ++i)
	{
		student* st = new student;
		cout << "FIO: ";
		getline(cin, st->fio);
		cout << "Date of Birth: ";
		getline(cin, st->date_birth);
		cout << "Kurs: ";
		cin >> st->kurs;
		cout << "Ball: ";
		cin >> st->ball;
		st->next = NULL;
		add(top, st);
	}
}
void random(student*& top, int n)
{
	for (int i = 0; i < n; ++i)
	{
		student* st = new student;
		int j = rand() % 10 + 3;
		st->fio += rand() % ('Z' - 'A' + 1) + 'A';
		for (; j >= 0; --j)
			st->fio += rand() % ('z' - 'a' + 1) + 'a';
		st->fio += ' ';
		j = rand() % 10 + 3;
		st->fio += rand() % ('Z' - 'A' + 1) + 'A';
		for (; j >= 0; --j)
			st->fio += rand() % ('z' - 'a' + 1) + 'a';
		st->fio += ' ';
		j = rand() % 10 + 3;
		st->fio += rand() % ('Z' - 'A' + 1) + 'A';
		for (; j >= 0; --j)
			st->fio += rand() % ('z' - 'a' + 1) + 'a';
		st->fio += '\0';
		st->date_birth += rand() % ('9' - '0' + 1) + '0';
		st->date_birth += rand() % ('9' - '0' + 1) + '0';
		st->date_birth += '.';
		st->date_birth += rand() % ('9' - '0' + 1) + '0';
		st->date_birth += rand() % ('9' - '0' + 1) + '0';
		st->date_birth += '.';
		st->date_birth += rand() % ('2' - '0' + 1) + '0';
		st->date_birth += rand() % ('9' - '0' + 1) + '0';
		st->date_birth += rand() % ('9' - '0' + 1) + '0';
		st->date_birth += rand() % ('9' - '0' + 1) + '0';
		st->date_birth += '\0';
		st->kurs = rand() % 5 + 1;
		st->ball = rand() % 10 + 1;
		st->next = NULL;
		add(top, st);
	}
}

void del(student*& top, student* elem)
{

	if (top == elem)
		top = top->next;
	else
	{
		student* pointer = top;

		while (pointer->next != elem)
			pointer = pointer->next;

		pointer->next = elem->next;
	}
}

void foo(student*& top, student*& top_1)
{
	student* elem = top;
	while (elem != NULL)
	{
		if (elem->ball >= 9)
		{
			student* el = elem;
			del(top, elem);
			elem = elem->next;
			el->next = NULL;
			add(top_1, el);
		}
		if(elem!=NULL)
		elem = elem->next;
	}
}

int main()
{
	student* top = NULL;
	int n = 25;
	random(top, n);
	print(top);
	student* top_1 = NULL;
	foo(top, top_1);
	cout << "\n\n\n";
	print(top_1);
	cout << "\n\n\n";
	print(top);
	return 0;
}