#include "class1.h"
#include "class2.h"
#include "class3.h"
#include "class4.h"
#include <vector>


class Array
{
private:
	vector<Demond_Deposit*> Arr;
public:
	Array()
	{

	}
	Array(const Array& other)
	{
		cout << "Copy constr" << endl;
		Arr.resize(other.Arr.size());
		for (int i = 0; i < Arr.size(); ++i)
			Arr[i] = other.Arr[i]->Clone();
	}
	Array(Array&& other) noexcept//����������� ����������� ���������� ������ �� ��������� ������ rvalue ������
	{
		cout << "Perem constr" << endl;
		Arr = move(other.Arr);
	}
	

	void Add(Demond_Deposit* el)
	{
		Arr.push_back(el);
	}
	void Del_el(Demond_Deposit* el)
	{
		for (auto i = Arr.begin(); i != Arr.end(); ++i)
		{
			if (*i == el)
			{
				Arr.erase(i);
				break;
			}
		}
	}
	void Del_all()
	{
		Arr.clear();
		Arr.shrink_to_fit();
	}
	void output()
	{
		for (int i = 0; i < Arr.size(); ++i)
		{
			Arr[i]->Print();
			cout << endl;
		}
	}

	Array& operator =(const Array& other)// �������� �����������
	{
		cout << "Copy operator" << endl;
		Del_all();
		Arr.resize(other.Arr.size());
		for (int i = 0; i < Arr.size(); i++)
			Arr[i] = other.Arr[i]->Clone();
		return *this;
	}
	Array& operator =(Array&& other)//�������� �����������
	{
		cout << "Perem operator" << endl;
		Arr = move(other.Arr);
		return*this;
	}

	Demond_Deposit*& operator[](int i)
	{
		if (i < 0)
			throw invalid_argument("bad index");

		if (i >= Arr.size())
			throw invalid_argument("bad index");

		return Arr[i];
	}

	~Array()
	{
		Del_all();
	}
};

int main()
{
	Demond_Deposit deposit1("09.05.21", 10, 500, "20.05.21");// ������ �������
	//deposit1.Print();
	//cout << endl;
	Conditional_Contribution deposit2("10.05.21", 5, 1000, "19.05.21", "before marriage");
	//deposit2.Print();
	//cout << endl;
	Term_Irrevocable_Deposit deposit3;
	//deposit3.Print();
	//cout << endl;
	Term_Revocable_Deposit deposit4;// ������ �������
	//deposit4.Print();
	//cout << endl;
	Demond_Deposit* p = &deposit2;

	Array arr;//������� ����� ������ ������(���������� ����������� �� ���������)

	arr.Add(p);// ��������� ������ �������
	p = &deposit4;
	arr.Add(p);//��������� ������ �������
	arr.output();//������ ������ ��������� �� ���� ���������

	Array arr2(arr);//������� ����� ������ � ������� ������������ �����������
	arr2.output();//������� ���

	Array arr3;//������� ������ ������
	arr3 = arr;//��������� ������ ������ � ������� ��������� �����������
	arr3.output();//�������

	Array arr4(move(arr3));//������� ����� ������ ��������� ����������� �����������
	arr4.output();//������� ���
	arr3.output();//������ 3 ���� ������ ��� ��� ������ ��������� � ������ 4

	arr4.Del_all();//��������� ������� ��������

	arr4.output();//�������� �������, �� ������ �� �������

	arr4 = move(arr);//���������� ������ ������� ������� � 4 � ������� ��������� �����������
	arr4.output();//������� ���
	arr.output();//������ ������ ���� ������ ��� ��� ������ �������������

	// ��� �������, ������ � ��������� ��������. ������ ��������� 10.2 �����, ����� �� ������ �� ����� ���� ������� �� ��� �����?)

	return 0;
}