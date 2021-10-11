#include <iostream>

using namespace std;

struct Tree
{
	int data = 0;
	Tree* left = NULL;
	Tree* right = NULL;
};

Tree* find(Tree* top, int x)
{
	if (!top)
		return NULL;
	Tree* p;
	if (top->data > x)
		p = find(top->left, x);
	else
		p = find(top->right, x);
	if (p != NULL)
		return p;
	else
		return top;
}

void add(Tree*& top, int x)
{
	Tree* pnew = new Tree;
	pnew->data = x;
	if (!top)
		top = pnew;
	else
	{
		Tree* pointer = find(top, x);
		if (pointer->data > x)
			pointer->left = pnew;
		else
			pointer->right = pnew;
	}
}

void print(Tree* top)
{
	if (top)
	{
		print(top->left);
		cout << top->data << " ";
		print(top->right);
	}
}

void print_level(Tree* top, int level)
{
	if (top)
	{
		print_level(top->left, level + 1);
		for (int i = 0; i < level; ++i)
			cout << "   ";
		cout << top->data << '\n';
		print_level(top->right, level + 1);
	}
	
}

void foo(Tree* top)
{
	if (top)
		if (top->left == NULL && top->right == NULL)
			cout << top->data << " ";
		else
		{
			foo(top->left);
			foo(top->right);
		}
}

int main()
{
	Tree* top = NULL;
	int n = 8;
	int arr[] = { 20, 10, 8, 12, 30, 25, 34, 22 };
	for (int i = 0; i < n; ++i)
		add(top, arr[i]);
	print(top);
	cout << '\n';
	print_level(top, 0);
	cout << '\n';
	foo(top);
	return 0;
}