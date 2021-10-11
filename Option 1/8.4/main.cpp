/*�������� ������ ������ ��������� ������. ���������� ��������� ������ � ��� ������. � ������ ������ ���� ����������� �� ���������, ����������� � ����������� �����������, ����������� ����������� � ����������.
���������� ������:
� ������������� ������� �������� ���������;
� ���������� � ��������� ������ ��������;
� �������� ��������;
� ����� �������� �� ��������� ����� ������ (�������� ���������������
����);
� ����� ��������� ������ �� �����;
� �������� ������.
��������� ������� ������ ��������� ������, ����������� ���������
����� ��������� ������� 7.4.
*/
#include <iostream>
#include <time.h>

using namespace std;

//1. ������� �������, ������� ��������� ������ �������� L2,
//������� � ���� �� ������� �� L1, ������� ������ � ���� �� ������ ����.

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
			Head = new Node<T>; //���� ������ ����, �� ������� ������ �������
			Head->Data = key;
			Head->NextPtr = nullptr;
		}
		else 
		{
			Node<T>* ptr = this->Head; //������� ��������� ����������
			// ���� �� ������,���� �� ������� �� ���������� ���������
			while (ptr->NextPtr!=nullptr)
				ptr = ptr->NextPtr;
			ptr->NextPtr = new Node<T>; // ��������� � ����� ������
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

	Node<T>* find_el(T key)//����� �������� �� ��������� ����� ������ (�������� ��������������� ����);
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
	int counter = 0;//�������
	Node<T>* ptr = this->Head; //������� ��������� ����������
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
	int counter = 0;//�������
	Node<T>* ptr = this->Head; //������� ��������� ����������
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
void Function(List<T> L1, List<T>& L2)//1. ������� �������, ������� ��������� ������ �������� L2,
									 //������� � ���� �� ������� �� L1, ������� ������ � ���� �� ������ ����.
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

