#pragma once
#include "class1.h"
#include "Object.h"
#include <vector>
#include <string>

class Array
{
private:
	vector<Demond_Deposit*> Arr;
	map<string, int> types;//������� ������ ������� � �� ��������, ����� ������������ switch case
public:
	Array()
	{
		types.try_emplace("Demond_Deposit", 1);
		types.try_emplace("Conditional_Contribution", 2);
		types.try_emplace("Term_Irrevocable_Deposit", 3);
		types.try_emplace("Term_Revocable_Deposit", 4);
	}
	Array(const Array& other)
	{
		cout << "Copy constr" << endl;
		Arr.resize(other.Arr.size());
		for (int i = 0; i < Arr.size(); ++i)
			Arr[i] = other.Arr[i]->Clone();
		types.try_emplace("Demond_Deposit", 1);
		types.try_emplace("Conditional_Contribution", 2);
		types.try_emplace("Term_Irrevocable_Deposit", 3);
		types.try_emplace("Term_Revocable_Deposit", 4);
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
	int Size()
	{
		return Arr.size();
	}
	void Del_all()
	{
		Arr.clear();
		Arr.shrink_to_fit();
	}
	void setSize(int size)//�������������� ������ ����� ��� ������� �������
	{
		if (size < 0)//���������� ����������
		{
			cout << "SIZE " << size << " IS NOT ALLOWED" << endl;
			exit(0);
		}

		vector<Demond_Deposit*> newArr(size);
		for (int i = 0; i < size; ++i)//��� �������� ������� ������� �������� � �� ������������� ��������� ����� 0
		{
			if (i < Arr.size())
				newArr[i] = Arr[i];
			else
				newArr[i] = nullptr;
		}

		Arr.clear();
		Arr.shrink_to_fit();//������� ������ ������
		Arr.resize(size);//� ������������ ��� � �����
		Arr = newArr;
	}
	void output()
	{
		for (int i = 0; i < Arr.size(); ++i)
		{
			Arr[i]->Print();
			cout << endl;
		}
	}

	//void Write()
	void read(ifstream& in)//�������, ������� ���������� ������ �� ����� � ������
	{
		int size = 0;
		while (!in.eof())//���� ���� ���� �� ����������
		{
			string currentLine;//������� ������� ������
			currentLine.clear();

			getline(in, currentLine);//��������� ������� ������ (������) ������� �����
			
			if (currentLine.empty())//���� ������ ������, �� ���������� ��
				continue;

			Object factory;

			map<string, int>::iterator it = types.find(currentLine);//��������� ������� �� ������ ���������� ����� ������
			if (it != types.end())//���� ������ ������� �� ������� � if
			{
				switch (it->second)//������� ����� ������ ������� � ���������� � ������ ������ ������
				{
				case 1:
					setSize(size + 1);//������� ��������� ������ ������� ��� �������
					Arr[size] = factory.create("Demond_Deposit");//� ������� ������� create ��������� ��� ������ ������������ �������
					Arr[size++]->read(in);//��������� ������ ���� ������� ������� �� �����
					break;
				case 2:
					setSize(size + 1);
					Arr[size] = factory.create("Conditional_Contribution");
					Arr[size++]->read(in);
					break;
				case 3:
					setSize(size + 1);
					Arr[size] = factory.create("Term_Irrevocable_Deposit");
					Arr[size++]->read(in);
					break;
				case 4:
					setSize(size + 1);
					Arr[size] = factory.create("Term_Revocable_Deposit");
					Arr[size++]->read(in);
					break;
				default:
					break;
				}
			}
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
	
	friend ostream& operator <<(ostream& out, const Array& arr)//���������� ��������� ������, ����� �������� ������ � ����
	{
		for (int i = 0; i < arr.Arr.size(); ++i)
		{
			if (arr.Arr[i])
				out << *arr.Arr[i] << endl;
		}
		return out;
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
