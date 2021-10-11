#pragma once
#include <iostream>

using namespace std;

class Tree
{
	struct Node
	{
		int data;
		Node* right;
		Node* left;
	};
	Node* Root;
	int Size;
	void del_all(Node* top)
	{
		if (top)
		{
			del_all(top->left);
			del_all(top->right);
			delete top;
			top = NULL;
		}
	}
	void del_one(Node* Root, int data)
	{
		if (!Root)
			return;
		if (data == Root->data)
		{
			delete Root;
			Root = NULL;
			return;
		}
		del_one(Root->left, data);
		del_one(Root->right, data);
	}
	Node* find(Node* Root, int data)
	{
		if (!Root)
			return NULL;
		Node* pointer;
		if (data < Root->data)
			pointer = find(Root->left, data);
		else
			pointer = find(Root->right, data);

		if (pointer)
			return pointer;
		else
			return Root;
	}
	void print_tree_level(Node* Root, int level = 0)
	{
		if (Root)
		{
			print_tree_level(Root->left, level + 1);
			for (int i = 0; i < level; ++i)
				cout << "   ";
			cout << Root->data << '\n';
			print_tree_level(Root->right, level + 1);
		}
	}
	void print_tree(Node* top)
	{
		if (top)
		{
			print_tree(top->left);
			cout << top->data;
			print_tree(top->right);
		}
	}
	void function(Node* Root)
	{
		if (!Root)
			return;
		if (Root->left == NULL && Root->right == NULL)
			cout << Root->data << " ";
		function(Root->left);
		function(Root->right);
	}
	void copy_tree(Node* other, Node*& top)
	{
		if (other)
		{
			add(other->data);
			copy_tree(other, top->left);
			copy_tree(other, top->right);
		}
	}
public:
	Tree()
	{
		Root = NULL;
		Size = 0;
	}
	Tree(int n)
	{
		for (int i = 0; i < n; ++i)
			add(rand() % 10);
	}
	Tree(Tree*& other)
	{
		Root = NULL;
		copy_tree(other->Root, Root);
	}

	void add(int data)
	{
		Node* elem = new Node;
		elem->left = NULL;
		elem->right = NULL;
		elem->data = data;
		if (!Root)
			Root = elem;
		else
		{
			Node* pointer = find(Root, data);
			if (data < pointer->data)
				pointer->left = elem;
			else
				pointer->right = elem;
		}
	}
	void print()
	{
		print_tree(Root);
		cout << endl << endl;
		print_tree_level(Root, 0);
	}
	void del_el(int data)
	{
		del_one(Root, data);
	}
	void del_tree()
	{
		del_all(Root);
		Root = NULL;
	}
	void foo()
	{
		function(Root);
	}

	~Tree()
	{
		del_all(Root);
	}
};

