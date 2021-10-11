//7.5.ЛИНЕЙНЫЕ СПИСКИ КАК ДИНАМИЧЕСКАЯ СТРУКТУРА ДАННЫХ
//Выполнить задания, используя связанные динамические структуры данных в виде массивов.
//Оценить асимптотическую сложность алгоритма.
//1. Описать функцию, которая формирует список символов L2, включив в него те символы из L1,
//которые входят в него по одному разу.
#include <iostream>
#include <time.h>

using namespace std;

struct list
{
	char* l;
	int* p;
	int n;
	int nz;
	int end;
};

void random(list& l)
{
	l.nz = 0;
	l.n = 10;
	l.end = l.n - 1;
	l.l = new char[l.n];
	l.p = new int[l.n];
	for (int i = 0; i < l.n; ++i)
	{
		l.l[i] = rand() % ('z' - 'a' + 1) + 'a';
		l.p[i] = i + 1;
	}
	l.p[l.end] = -1;
}

void output(list l)
{
	for (int i = l.nz; i>=0; i = l.p[i])
	{
		cout << l.l[i] << " ";
	}
	cout << endl;
}

void function(list l1, list& l2)
{
	l2.n = l1.n;
	l2.l = new char[l2.n];
	l2.p = new int[l2.n];
	l2.nz = 0;
	l2.end = 0;
	for (int i = l1.nz; i >= 0; i = l1.p[i])
	{
		bool flag = 1;
		for (int j = l1.nz; j >= 0 && flag == 1; j = l1.p[j])
		{
			if (l1.l[i] == l1.l[j] && i != j)
			{
				flag = 0;
			}
		}
		if (flag)
		{
			l2.l[l2.end] = l1.l[i];
			l2.p[l2.end] = l2.end + 1;
			l2.end++;
		}
	}
	l2.p[l2.end - 1] = -1;
}

int main()
{
	srand(time(NULL));
	list l1;
	random(l1);
	cout << "L1 : ";
	output(l1);
	list l2;
	function(l1, l2);
	cout << "L2 : ";
	output(l2);
	return 0;
}