#include <iostream>

using namespace std;

struct SP
{
	int key;//номер смежной вершины
	SP* next;//указатель на следующую смежную вершину
};
struct GRAF
{
	int nv;// номер вершины
	SP* spis_sv;

	GRAF* next;
};
void add(SP*& top, int el)
{
	SP* new_el = new SP;
	new_el->key = el;
	new_el->next = NULL;
	if (!top)
		top = new_el;
	else
	{
		SP* pointer = top;
		while (pointer->next != NULL)
			pointer = pointer->next;
		new_el->next = pointer;
		pointer->next = new_el;
		new_el->next = NULL;
	}
}



void add_vertex(GRAF*& top, int v)
{
	GRAF* new_vert = new GRAF;
	new_vert->nv = v;
	new_vert->next = NULL;
	new_vert->spis_sv = NULL;
	if (!top)
		top = new_vert;
	else
	{
		GRAF* pointer = top;
		while (pointer->next != NULL)
			pointer = pointer->next;
		new_vert->next = pointer;
		pointer->next = new_vert;
		new_vert->next = NULL;
	}
}

void add_adge(GRAF*& top, int from, int to)
{
	GRAF* pointer = top;
	while (pointer->nv != from)
		pointer = pointer->next;
	add(pointer->spis_sv, to);
}

void add_arc(GRAF*& top, int from, int to)
{
	GRAF* pointer = top;
	while (pointer->nv != from)
		pointer = pointer->next;
	while (pointer->nv != to && pointer->next != NULL)
	{
		int next_v = pointer->next->nv;
		add(pointer->spis_sv, next_v);
		pointer = pointer->next;
	}
}

void print(GRAF* top)
{
	GRAF* pointer = top;
	while (pointer != NULL)
	{
		cout << pointer->nv << " : ";
		SP* p = pointer->spis_sv;
		while (p != NULL)
		{
			cout << p->key << " ";
			p = p->next;
		}
		cout << '\n';
		pointer = pointer->next;
	}
}

int main()
{
	int n = 7;
	GRAF* top = NULL;
	for (int i = 0; i < n; ++i)
		add_vertex(top, i + 1);
	add_arc(top, 1, 4);
	add_adge(top, 1, 5);
	add_adge(top, 5, 1);
	add_arc(top, 5, 6);
	add_adge(top, 5, 7);
	print(top);

	return 0;
}