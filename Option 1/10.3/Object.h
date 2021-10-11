#pragma once
#include <map>
#include "class_array.h"
#include "class1.h"
#include "class2.h"
#include "class3.h"
#include "class4.h"

class Object//класс который создает нужный нам объект
{
	map<string, Demond_Deposit*> objects;//список который хранит 2 значения(название класса и указатель на объект класса)

	void Add_object_type(Demond_Deposit* obj)//заполняет список объектами
	{
		objects.try_emplace(obj->getType(), obj);//типо push_back только для map
	}
public:
	Object()//Добавляем все объекты в map
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
		objects.clear();//очищаем map
	}

	Demond_Deposit* create(const char* typeName)//ищем нужный нам объект класса
	{
		map<string, Demond_Deposit*> ::iterator it = objects.find(typeName);//итерратор который ищет объект с таким названием
		if (it == objects.end())//если не нашел
			return nullptr;
		return it->second->Clone();// возращаем скопированный нужный нам объект
	}
};
