#include <iostream>

using namespace std;

struct Node
{
	double a = 0;
	Node* next = NULL;
	Node* previous = NULL;
};

struct List
{
	Node* Head = NULL;
	Node* Tail = NULL;
	int size = 0;
};

void add(List*& l, Node* elem)
{
	if (l->Head == NULL)
		l->Head = elem;
	else
	{
		Node* pointer = l->Head;
		while (pointer->next != NULL)
		{
			pointer = pointer->next;
		}
		elem->previous = pointer;
		pointer->next = elem;
		l->Tail = elem;
	}
	l->size++;
}

void print(List* l)
{
	Node* pointer = l->Head;
	while (pointer != NULL)
	{
		cout << pointer->a << " ";
		pointer = pointer->next;
	}
	cout << "\n";
	/*while (l->Tail != NULL)
	{
		cout << l->Tail->a << " ";
		l->Tail = l->Tail->previous;
	}
	cout << "\n";*/
}

double function(List* l)
{
	Node* start = l->Head;
	Node* finish = l->Tail;
	double x = 1;
	for (int i = 0; i < l->size / 2; ++i)
	{
		x *= start->a - finish->a;
		start = start->next;
		finish = finish->previous;
	}
	return x;
}

int main()
{
	List* L = new List;
	int n = 3;
	for (int i = 0; i < 2 * n; ++i)
	{
		Node* elem = new Node;
		elem->a = rand() % 100 / 10.0;
		add(L, elem);
	}
	print(L);
	cout << function(L);
	return 0;
}