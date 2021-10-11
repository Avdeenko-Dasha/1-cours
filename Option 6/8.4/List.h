#pragma once
#include <iostream>
using namespace std;

class List
{
	struct Node
	{
		char data;
		Node* next;
	};
	Node* Head;
	int Size;
public:
	List()
	{
		Size = 0;
		Head = NULL;
	}
	List(int n)
	{
		for (int i = 0; i < n; ++i)
			add('0');
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

	void add(char data)
	{
		Node* elem = new Node;
		elem->data = data;
		elem->next = NULL;
		if (!Head)
			Head = elem;
		else
		{
			Node* pointer = Head;
			while (pointer->next)
				pointer = pointer->next;
			pointer->next = elem;
		}
		Size++;
	}
	void del_el(char key)
	{
		Node* pointer = Head;
		if (pointer->data == key)
		{
			Head = pointer->next;
			delete pointer;
		}
		else
		{
			while (pointer->next->data != key)
				pointer = pointer->next;
			Node* p = pointer->next->next;
			delete pointer->next;
			pointer->next = p;
		}
		Size--;
	}
	int size()
	{
		return Size;
	}
	void print()
	{
		Node* pointer = Head;
		while (pointer)
		{
			cout << pointer->data << " ";
			pointer = pointer->next;
		}
		cout << '\n';
	}
	void clear()
	{
		Size = 0;
		Node* ptr;
		while (Head)
		{
			ptr = Head;
			Head = ptr->next;
			delete ptr;
		}
	}
	void random()
	{
		Node* pointer = Head;
		while (pointer)
		{
			pointer->data = rand() % 26 + 97;
			pointer = pointer->next;
		}
	}
	Node* find(char key)
	{
		Node* pointer = Head;
		while (pointer != NULL && pointer->data != key)
			pointer = pointer->next;
		return pointer;
	}
	void foo(List& L1, List& L2)
	{
		Node* ptr_1 = L1.Head;
		while (ptr_1)
		{
			Node* p = L2.find(ptr_1->data);
			if (p)
				add(ptr_1->data);
			ptr_1 = ptr_1->next;
		}
		Node* ptr = Head;
		while (ptr)
		{
			Node* p = ptr->next;
			Node* x = ptr->next;
			while (p)
			{
				if (p->data == ptr->data)
					del_el(p->data);
				p = p->next;
			}
			ptr = x;
		}
	}

	~List()
	{
		clear();
	}
};
