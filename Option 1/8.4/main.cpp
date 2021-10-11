/*ќбъ€вить шаблон класса ЂЋинейный списокї. ќпределить структуру класса и его методы. ¬ классе должен быть конструктор по умолчанию, конструктор с формальными параметрами, конструктор копировани€ и деструктор.
ќпределить методы:
Х инициализаци€ первого элемента структуры;
Х добавлени€ в структуру нового элемента;
Х удаление элемента;
Х поиск элемента по заданному ключу поиска (значению информационного
пол€);
Х вывод элементов списка на экран;
Х удалени€ списка.
»спользу€ объекты класса ЂЋинейный списокї, реализовать алгоритмы
своих вариантов заданий 7.4.
*/
#include <iostream>
#include <time.h>

using namespace std;

//1. ќписать функцию, котора€ формирует список символов L2,
//включив в него те символы из L1, которые вход€т в него по одному разу.

template<typename T>
class Node
{
public:
	T Data;
	Node* NextPtr;
};
template<typename T>
class List
{
	Node<T>* Head;
	int Size;
public:
	List() : Head(nullptr), Size(0)
	{

	}
	List(int size)
	{
		Head = new Node<T>;
		Head->Data = rand() % ('z' - 'a' + 1) + 'a';
		Size = size--;
		Node<T>* ptr = Head;
		for (int i = 0; i < size; ++i)
		{
			ptr->NextPtr = new Node<T>;
			ptr->NextPtr->Data = rand() % ('z' - 'a' + 1) + 'a';
			ptr = ptr->NextPtr;
		}
		ptr->NextPtr = nullptr;
	}
	List(const List<T>& other) : Head(nullptr), Size(0)
	{
		Node<T>* ptr = other.Head;
		while (ptr)
		{
			push_back(ptr->Data);
			ptr = ptr->NextPtr;
		}
	}

	int size()
	{
		return Size;
	}

	void push_back(T key)
	{
		if (!Head) 
		{
			Head = new Node<T>; //если список пуст, то создаем первый элемент
			Head->Data = key;
			Head->NextPtr = nullptr;
		}
		else 
		{
			Node<T>* ptr = this->Head; //создаем временную переменную
			// идем по списку,пока не доходим до последнего эллемента
			while (ptr->NextPtr!=nullptr)
				ptr = ptr->NextPtr;
			ptr->NextPtr = new Node<T>; // добавл€ем в конец списка
			ptr->NextPtr->Data = key;
			ptr->NextPtr->NextPtr = nullptr;
		}
		Size++;
	}

	void del_el(T key)
	{
		Node<T>* ptr = Head;
		if (ptr->Data == key)
		{
			Head = ptr->NextPtr;
			delete ptr;
		}
		else
		{
			while (ptr->NextPtr->Data != key)
			{
				ptr = ptr->NextPtr;
			}
			Node<T>* p = ptr->NextPtr->NextPtr;
			delete ptr->NextPtr;
			ptr->NextPtr = p;
		}
		Size--;
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

	void output()
	{
		Node<T>* ptr = Head;
		while (ptr!=nullptr)
		{
			cout << ptr->Data << " ";
			ptr = ptr->NextPtr;
		}
		cout << endl;
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

	T& operator[](int index);

	const T& operator[](int index) const;

	~List()
	{
		del_all();
	}
};

template<typename T>
T& List<T>::operator[](int index)
{
	int counter = 0;//счетчик
	Node<T>* ptr = this->Head; //создаем временную переменную
	while (ptr)
	{
		if (counter == index)
			return ptr->Data;
		ptr = ptr->NextPtr;
		counter++;
	}
	//throw std::invalid_argument("invalid index");
}

template<typename T>
const T& List<T>::operator[](int index) const
{
	int counter = 0;//счетчик
	Node<T>* ptr = this->Head; //создаем временную переменную
	while (ptr)
	{
		if (counter == index)
			return ptr->Data;
		ptr = ptr->NextPtr;
		counter++;
	}
	//throw std::invalid_argument("invalid index");
}

template<typename T>
void Function(List<T> L1, List<T>& L2)//1. ќписать функцию, котора€ формирует список символов L2,
									 //включив в него те символы из L1, которые вход€т в него по одному разу.
{
	for (int i = 0; i < L1.size(); i++) 
	{
		bool find = false;
		for (int j = 0; j < L1.size(); j++)
		{
			if (L1[i] == L1[j] && i!=j) 
			{
				find = true;
				break;
			}
		}
		if (!find) 
		{
			L2.push_back(L1[i]);
		}
	}
}

int main()
{
	srand(time(NULL));
	List<char> L1(20);

	L1.output();

	List<char> L2;

	Function(L1, L2);

	L2.output();

	return 0;
}

