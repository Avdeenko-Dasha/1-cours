//8.6.КЛАСС «БИНАРНОЕ ДЕРЕВО»
//Объявить шаблон класса «Бинарное дерево».Определить структуру класса
//и его методы.В классе должен быть конструктор по умолчанию, конструктор
//с формальными параметрами, конструктор копирования и деструктор.
//Определить методы :
//• инициализация первого элемента структуры;
//• запись в структуру нового элемента;
//• поиск элемента по заданному ключу поиска(значению информационного
//	поля);
//• вывод элементов дерева на экран;
//• удаления всех элементов дерева.
//Используя объекты класса «Бинарное дерево», реализовать алгоритм своего
//варианта задания 7.7.
//7.7.БИНАРНОЕ ДЕРЕВО ПОИСКА
//По заданной последовательности различных целых чисел построить соответствующее бинарное дерево поиска T как динамическую структуру данных.
//Выполнить следующие задания и вывести элементы дерева на экран.Оценить
//асимптотическую сложность алгоритма.
//1. Определяет значение самого левого листа дерева.

#include <iostream> 

using namespace std;

class Node
{
public:
	int Data;
	Node* left;
	Node* right;
};

class Tree
{
private:
	Node* Root;


	Node* find_el(Node* top, int d)
	{
		if (!top)
			return NULL;
		Node* p;
		if (d < top->Data)
			p = find_el(top->left, d);
		else
			p = find_el(top->right, d);
		return p ? p : top;
	}
	void copy_tree(Node* top1, Node*& top2)// копия дерева
	{
		if (top1)
		{
			add(top1->Data); //добавление узла в новое дерево
			copy_tree(top1->left, top2); //обход левого поддерева
			copy_tree(top1->right, top2); //обход правого поддерева
		}
	}
	void print_tree_level(Node* top, int level)// обход дерева и вывод значений по уровням
	{
		if (top)
		{
			print_tree_level(top->left, level + 1);//обход левого поддерева
			for (int i = 0; i < level; i++)
				cout << " ";
			cout << top->Data << endl;
			print_tree_level(top->right, level + 1);//обход правого поддерева
		}
	}
	void print_tree(Node* top)// обход дерева и вывод значений в отсортированном порядке
	{
		if (top)
		{
			print_tree(top->left); //обход левого поддерева
			cout << top->Data << " ";
			print_tree(top->right);//обход правого поддерева
		}
	}
	void del_tree(Node*& top)// удаление дерева
	{
		if (top)
		{
			del_tree(top->left); //обход левого поддерева
			del_tree(top->right);//обход правого поддерева
			delete top; // освобождение памяти
			top = NULL;
		}
	}
public:
	Tree()
	{
		Root = nullptr;
	}
	Tree(int Size)
	{
		Root = nullptr;
		for (int i = 0; i < Size; ++i)
		{
			add(rand() % 10);
		}
		/*int b[] = { 8, 3, 10, 1, 6, 14, 4, 7, 13 };
		for (int i = 0; i < 9; ++i)
		{
			add(b[i]);
		}*/
	}
	Tree(const Tree& other)
	{
		Root = nullptr;
		copy_tree(other.Root, Root);
	}

	int function()
	{
		Node* str = Root;
		while (str->left != nullptr)
			str = str->left;
		return str->Data;
	}
	Node* find(int data)
	{
		return find_el(Root, data);
	}
	void add(int data)// включение нового узла в дерево
	{
		Node* pnew = new Node;
		pnew->Data = data;
		pnew->left = nullptr;
		pnew->right = nullptr;
		if (!Root)
			Root = pnew;
		else
		{
			Node* ptr;
			ptr = search(data);
			if (data < ptr->Data)
				ptr->left = pnew;
			else
				ptr->right = pnew;
		}
	}
	Node* search(int data)	// поиск места для нового узла возвращаем адрес узла, после которого нужно добавить новый элемент
	{
		Node* ptr = Root;
		Node* help = Root;
		while (ptr)
		{
			help = ptr;
			if (data < ptr->Data)
				ptr = ptr->left;
			else
				ptr = ptr->right;
		}
		return help;
	}
	void print()
	{
		print_tree_level(Root, 0);
		cout << endl;
		print_tree(Root);
	}
	void del()
	{
		del_tree(Root);
	}

	~Tree()
	{
		del();
	}
};

void main()
{

	Tree iva(9);
	iva.print();
	{
		Tree dub(iva);
		cout << endl;
		dub.print();
	}
	cout << endl;
	iva.print();
}