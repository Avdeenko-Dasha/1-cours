#include <iostream>
#include <iomanip>

using namespace std;

struct list
{
	int l = 0;
	int top = 0;
	int end = 0;
	bool empty = true;
	int* arr;
	list(int size)
	{
		l = size;
		arr = new int[size];
	}
};

void add(list*& top, int el)
{
	if (top->empty)
	{
		top->top = 0;
		top->arr[0] = el;
		top->empty = false;
		top->end = 0;
	}
	else
	{
		top->end++;
		if (top->end < top->l)
			top->arr[top->end] = el;
		if (top->end == top->l)
			top->end--;
	}
}

void print(list* top)
{
	if(!top->empty)
		for (int i = top->top; i <= top->end; ++i)
			cout << top->arr[i] << " ";
	cout << "\n\n";
}

void foo(list* top_1, list* top_2, list*& top)
{
	for (int i = 0; i <= top_1->end; ++i)
	{
		int elem = top_1->arr[i];
		for (int j = 0; j <= top_2->end; ++j)
			if (elem == top_2->arr[j])
			{
				bool flag = true;
				for (int k = 0; k <= top->end; ++k)
					if (elem == top->arr[k])
					{
						flag = false;
						break;
					}
				if (flag)
					add(top, elem);
			}
	}
}

int main()
{
	//srand(time(NULL));
	int l = 10;
	list* top_1 = new list(l);
	for (int i = 0; i < l; ++i)
		add(top_1, rand() % 10);
	print(top_1);

	list* top_2 = new list(l);
	for (int i = 0; i < l; ++i)
		add(top_2, rand() % 10);
	print(top_2);

	list* top = new list(l);
	foo(top_1, top_2, top);
	print(top);
	return 0;
}