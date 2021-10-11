#pragma once
#include "class1.h"
#include "class2.h"
#include "class3.h"
#include "class4.h"

template<typename T>
class Node
{
public:
	T* Data;
	Node<T>* NextPtr;
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
	List(const List<T>& other) : Head(nullptr), Size(0)
	{
		Node<T>* ptr = other.Head;
		while (ptr)
		{
			push_back(ptr->Data);
			ptr = ptr->NextPtr;
		}
	}
	List(List<T>&& other)
	{
		Node<T>* ptr = other.Head;
		while (ptr)
		{
			push_back(ptr->Data);
			ptr = ptr->NextPtr;
		}
		other.del_all();
	}

	int size()
	{
		return Size;
	}

	void push_back(T* key)
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
			while (ptr->NextPtr != nullptr)
				ptr = ptr->NextPtr;
			ptr->NextPtr = new Node<T>; // добавляем в конец списка
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

	Node<T>* find_el(T key)//поиск элемента по заданному ключу поиска (значению информационного поля);
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
		while (ptr != nullptr)
		{
			ptr->Data->Print();///////////
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

	List& operator =(const List& other)// Оператор копирования
	{
		del_all();
		Node<T>* ptr = other.Head;
		while (ptr)
		{
			push_back(ptr->Data);
			ptr = ptr->NextPtr;
		}
		return *this;
	}
	List& operator =(List&& other)//оператор перемещения
	{
		del_all();
		Node<T>* ptr = other.Head;
		while (ptr)
		{
			push_back(ptr->Data);
			ptr = ptr->NextPtr;
		}
		other.del_all();
		return *this;
	}

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
