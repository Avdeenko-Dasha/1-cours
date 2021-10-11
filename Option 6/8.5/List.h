#pragma once
#include<iostream>

using namespace std;

class List
{
	struct Node
	{
		double data;
		Node* next;
		Node* prev;
	};

	int Size;
	Node* Head;
	Node* Tail;
public:
	List()
	{
		Size = 0;
		Head = NULL;
		Tail = NULL;
	}
	List(int n)
	{
		for (int i = 0; i < n; ++i)
			add(i + 1);
	}
	List(List& other)
	{
		Node* pointer = other.Head;
		while (pointer)
		{
			add(pointer->data);
			pointer = pointer->next;
		}
	}

	void add(double data)
	{
		Node* elem = new Node;
		elem->data = data;
		elem->next = NULL;
		elem->prev = NULL;
		if (!Head)
		{
			Head = elem;
			Tail = elem;
		}
		else
		{
			Node* pointer = Tail;
			elem->prev = pointer;
			pointer->next = elem;
			Tail = elem;
		}
		Size++;
	}
	void del_el(double key)
	{
		Node* pointer = Head;
		if (pointer->data == key)
		{
			Head = pointer->next;
			delete pointer;
		}
		else if (Tail->data == key)
		{
			pointer = Tail;
			Tail = pointer->prev;
			delete pointer;
		}
		else
		{
			while (pointer->next->data != key)
				pointer = pointer->next;
			Node* p = pointer->next->next;
			p->prev = pointer;
			delete pointer->next;
			pointer->next = p;
		}
		Size--;
	}
	void random()
	{
		Node* ptr = Head;
		while (ptr)
		{
			ptr->data = rand() % 100 / 10.0;
			ptr = ptr->next;
		}
	}
	void print()
	{
		Node* pointer = Head;
		while (pointer)
		{
			cout << pointer->data << " ";
			pointer = pointer->next;
		}
		cout << endl;
	}
	void clear()
	{
		Node* pointer;
		while (Head)
		{
			pointer = Head;
			Head = pointer->next;
			delete pointer;
		}
	}

	Node* find(double key)
	{
		Node* pointer = Head;
		while (pointer != NULL && pointer->data != key)
			pointer = pointer->next;
		return pointer;
	}
	double function()
	{
		Node* start = Head;
		Node* finish = Tail;
		double x = 1;
		for (int i = 0; i < Size / 2; ++i)
		{
			x *= start->data - finish->data;
			start = start->next;
			finish = finish->prev;
		}
		return x;
	}

	~List()
	{
		clear();
	}
};