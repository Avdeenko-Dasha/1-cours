#include <iostream>
#include <string>
#include <list>

using namespace std;

struct student
{
	string fio;
	string date_birth;
	int kurs = 0;
	double ball = 0;
	student* next = NULL;
	student()
	{
		int j = rand() % 10 + 3;
		fio += rand() % ('Z' - 'A' + 1) + 'A';
		for (; j >= 0; --j)
			fio += rand() % ('z' - 'a' + 1) + 'a';
		fio += ' ';
		j = rand() % 10 + 3;
		fio += rand() % ('Z' - 'A' + 1) + 'A';
		for (; j >= 0; --j)
			fio += rand() % ('z' - 'a' + 1) + 'a';
		fio += ' ';
		j = rand() % 10 + 3;
		fio += rand() % ('Z' - 'A' + 1) + 'A';
		for (; j >= 0; --j)
			fio += rand() % ('z' - 'a' + 1) + 'a';
		fio += '\0';
		date_birth += rand() % ('9' - '0' + 1) + '0';
		date_birth += rand() % ('9' - '0' + 1) + '0';
		date_birth += '.';
		date_birth += rand() % ('9' - '0' + 1) + '0';
		date_birth += rand() % ('9' - '0' + 1) + '0';
		date_birth += '.';
		date_birth += rand() % ('2' - '0' + 1) + '0';
		date_birth += rand() % ('9' - '0' + 1) + '0';
		date_birth += rand() % ('9' - '0' + 1) + '0';
		date_birth += rand() % ('9' - '0' + 1) + '0';
		date_birth += '\0';
		kurs = rand() % 5 + 1;
		ball = rand() % 10 + 1;
		next = NULL;
	}
};
void print(list<student> spisok)
{
	while (!spisok.empty())
	{
		list<student> ::iterator top;
		top = spisok.begin();
		cout << "\nFIO: " << top->fio;
		cout << "\nDate of Birth: " << top->date_birth;
		cout << "\nKurs: " << top->kurs;
		cout << "\nBall: " << top->ball << '\n';
		spisok.pop_front();
	}
}
void foo(list<student>& spisok, list<student>& new_spisok)
{
	list<student> ::iterator top = spisok.begin();
	while (top != spisok.end())
	{
		if (top->ball >= 9)
		{
			new_spisok.push_back(*top);
			spisok.erase(top++);
		}
		else 
			top++;
	}
}

void program_7_3()
{
	int n = 25;
	list<student> spisok;
	for (int i = 0; i < n; ++i)
		spisok.push_back(student());

	print(spisok);

	list<student> new_spisok;
	foo(spisok, new_spisok);

	cout << "\nNew spisok:\n";
	print(new_spisok);
	cout << "\nSpisok:\n";
	print(spisok);
}

void print(list<int> spisok)
{
	for(auto top = spisok.begin(); top != spisok.end(); ++top)
		cout << *top << " ";
	cout << '\n';
}
void foo(list<int> top_1, list<int> top_2, list<int>& top)
{
	for(auto pointer_1 = top_1.begin(), pointer_2 = top_2.begin(); pointer_1!=top_1.end(); pointer_1++)
	{
		int elem = *pointer_1;
		pointer_2 = top_2.begin();
		while (pointer_2 != top_2.end())
		{
			if (elem == *pointer_2)
			{
				auto pointer = top.begin();
				bool flag = true;
				while (pointer != top.end())
				{
					if (elem == *pointer)
					{
						flag = false;
						break;
					}
					pointer++;
				}
				if (flag)
					top.push_back(*pointer_2);
				break;
			}
			pointer_2++;
		}
		pointer_1++;
	}
}

void program_7_4()
{
	list<int> top_1;
	int n = 20;
	for (int i = 0; i < n; ++i)
		top_1.push_back(rand() % 10);

	list<int> top_2;
	n = 20;
	for (int i = 0; i < n; ++i)
		top_2.push_back(rand() % 10);

	print(top_1);
	print(top_2);

	list<int> top;

	foo(top_1, top_2, top);
	print(top);
}

void print(list<double> spisok)
{
	for (auto top = spisok.begin(); top != spisok.end(); ++top)
		cout << *top << " ";
	cout << '\n';
}
double function(list<double> l)
{
	auto start = l.begin();
	auto finish = l.end();
	finish--;
	double x = 1;
	for (int i = 0; i < l.size() / 2; ++i)
	{
		x *= (*start - *finish);
		start++;
		finish--;
	}
	return x;
}

void program_7_6()
{
	list<double> L;
	int n = 3;
	for (int i = 0; i < 2 * n; ++i)
		L.push_back(rand() % 100 / 10.0);
	print(L);
	cout << function(L);
}

int main()
{
	cout << "7.3: \n";
	program_7_3();
	cout << "\n7.4: \n";
	program_7_4();
	cout << "\n7.6: \n";
	program_7_6();
	return 0;
}