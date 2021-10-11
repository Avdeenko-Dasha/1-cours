#include <iostream>
#include <ctime>
using namespace std;

//1. ƒаны натуральное число n, действительные числа x1, x2, ... xn.
//–азработать программу вычислени€ значени€ выражени€ следующего вида: x1*xn + x2*xn-1 + x3 * xn-2 + .... + xn*x1

template<typename T>
class Node
{
public:
	T Data;
	Node* NextPtr;
	Node* PredPtr;
};
template<typename T>
class List
{
private:
	Node<T>* Head;
	Node<T>* Tail;
	int Size;
public:
	List()
	{
		Head = nullptr;
		Tail = nullptr;
		Size = 0;
	}
	List(int size)
	{
		Head = new Node<T>;
		Head->Data = rand() % 1000/10.0;
		Size = size--;
		Node<T>* ptr = Head;
		for (int i = 0; i < size; ++i)
		{
			ptr->NextPtr = new Node<T>;
			ptr->NextPtr->Data = rand() % 1000 / 10.0;
			ptr->NextPtr->PredPtr = ptr;
			ptr = ptr->NextPtr;
		}
		Tail = ptr;
		ptr->NextPtr = nullptr;
	}
	List(const List<T>& other) : Head(nullptr), Tail(nullptr), Size(0)
	{
		Node<T>* ptr = other.Head;
		while (ptr)
		{
			push_back(ptr->Data);
			ptr = ptr->NextPtr;
		}
	}

	void push_back(T key)
	{
		if (!Head)
		{
			Head = new Node<T>; //если список пуст, то создаем первый элемент
			Head->Data = key;
			Head->NextPtr = nullptr;
			Head->PredPtr = nullptr;
			Tail = Head;
		}
		else
		{
			Node<T>* ptr = this->Head; //создаем временную переменную
			// идем по списку,пока не доходим до последнего эллемента
			while (ptr->NextPtr != nullptr)
				ptr = ptr->NextPtr;
			ptr->NextPtr = new Node<T>; // добавл€ем в конец списка
			ptr->NextPtr->Data = key;
			ptr->NextPtr->PredPtr = ptr;
			ptr->NextPtr->NextPtr = nullptr;
			Tail = ptr->NextPtr;
		}
		Size++;
	}
	void del_all()
	{
		Node<T>* ptr;
		while (Head)
		{
			ptr = Head;
			Head = ptr->NextPtr;
			delete ptr;
		}
		Size = 0;
	}
	void del_el(T key)
	{
		Node<T>* ptr = Head;
		if (ptr->Data == key)
		{
			Head = ptr->NextPtr;
			delete ptr;
		}
		else if (Tail->Data == key)
		{
			Tail = Tail->PredPtr;
			delete Tail->NextPtr;
			Tail->NextPtr = nullptr;
		}
		else
		{
			while (ptr->NextPtr->Data != key)
			{
				ptr = ptr->NextPtr;
			}
			ptr->NextPtr->NextPtr->PredPtr = ptr;
			Node<T>* p = ptr->NextPtr->NextPtr;
			delete ptr->NextPtr;
			ptr->NextPtr = p;
		}
		Size--;
	}
	void output()
	{
		Node<T>* ptr = Head;
		while (ptr != nullptr)
		{
			cout << ptr->Data << " ";
			ptr = ptr->NextPtr;
		}
		cout << endl;
	}
	Node<T>* find_el(T key)//поиск элемента по заданному ключу поиска (значению информационного пол€);
	{
		Node<T>* ptr = Head;
		while (ptr->Data != key)
		{
			ptr = ptr->NextPtr;
		}
		return ptr;
	}
	double function()
	{
		Node<T>* ptr = Head;
		Node<T>* help = Tail;
		int n = Size;
		double res = 0;
		for (int i = 0; i <= n/2; ++i)
		{
			res += ptr->Data * help->Data;
			ptr = ptr->NextPtr;
			help = help->PredPtr;
		}
		return 2*res;
	}
	~List()
	{
		del_all();
	}
};

int main()
{
	srand(time(NULL));
	List<double> a(4);
	a.output();
	double x = a.function();
	cout << x;
	return 0;
}