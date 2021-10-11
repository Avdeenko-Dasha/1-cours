#include <iostream>
#include <iomanip>

using namespace std;

struct list
{
	int el = 0;
	list* next = NULL;
};

void add(list*& top, list* elem)
{
	list* el = new list;
	el->el = elem->el;
	el->next = NULL;
	if (top == NULL)
	{
		top = el;
		top->next = NULL;
	}
	else
	{
		list* t = top;
		list* pointer = t;
		while (t != NULL)
		{
			pointer = t;
			t = t->next;
		}
		pointer->next = el;
		//elem->next = NULL;
	}

}
void print(list* top)
{
	while (top != NULL)
	{
		cout << top->el << " ";
		top = top->next;
	}
	cout << "\n\n";
}

void foo(list* top_1, list* top_2, list*& top)
{
	list* pointer_2 = top_2;
	list* pointer_1 = top_1;
	while (pointer_1 != NULL)
	{
		int elem = pointer_1->el;
		while (pointer_2 != NULL)
		{
			if (elem == pointer_2->el)
			{
				list* pointer = top;
				bool flag = true;
				while (pointer != NULL)
				{
					if (elem == pointer->el)
					{
						flag = false;
						break;
					}
					pointer = pointer->next;
				}
				if (flag)
					add(top, pointer_2);
				break;
			}
			pointer_2 = pointer_2->next;
		}
		pointer_2 = top_2;
		pointer_1 = pointer_1->next;
	}
}

int main()
{
	//srand(time(NULL));
	list* top_1 = NULL;
	int n = 20;
	for (int i = 0; i < n; ++i)
	{
		list* elem = new list;
		elem->el = rand() % 10;
		
		add(top_1, elem);
	}
	list* top_2 = NULL;
	n = 20;
	for (int i = 0; i < n; ++i)
	{
		list* elem = new list;
		elem->el = rand() % 10;
		elem->next = NULL;
		add(top_2, elem);
	}
	list* top = NULL;

	print(top_1);
	print(top_2);
	foo(top_1, top_2, top);
	print(top);
}