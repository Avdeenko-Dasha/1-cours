#pragma once
#include <map>
#include "class_array.h"
#include "class1.h"
#include "class2.h"
#include "class3.h"
#include "class4.h"

class Object//����� ������� ������� ������ ��� ������
{
	map<string, Demond_Deposit*> objects;//������ ������� ������ 2 ��������(�������� ������ � ��������� �� ������ ������)

	void Add_object_type(Demond_Deposit* obj)//��������� ������ ���������
	{
		objects.try_emplace(obj->getType(), obj);//���� push_back ������ ��� map
	}
public:
	Object()//��������� ��� ������� � map
	{
		Add_object_type(new Demond_Deposit());
		Add_object_type(new Conditional_Contribution());
		Add_object_type(new Term_Irrevocable_Deposit());
		Add_object_type(new Term_Revocable_Deposit());
	}
	~Object()
	{
		for (map<string, Demond_Deposit*>::iterator it = objects.begin(); it != objects.end(); ++it)
			delete it->second;
		objects.clear();//������� map
	}

	Demond_Deposit* create(const char* typeName)//���� ������ ��� ������ ������
	{
		map<string, Demond_Deposit*> ::iterator it = objects.find(typeName);//��������� ������� ���� ������ � ����� ���������
		if (it == objects.end())//���� �� �����
			return nullptr;
		return it->second->Clone();// ��������� ������������� ������ ��� ������
	}
};
