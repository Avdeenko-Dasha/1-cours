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
	Array(Array&& other) noexcept// онструктор перемещени€ передаетс€ ссылка на временный объект rvalue ссылка
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

	Array& operator =(const Array& other)// ќператор копировани€
	{
		cout << "Copy operator" << endl;
		Del_all();
		Arr.resize(other.Arr.size());
		for (int i = 0; i < Arr.size(); i++)
			Arr[i] = other.Arr[i]->Clone();
		return *this;
	}
	Array& operator =(Array&& other)//оператор перемещени€
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
	Demond_Deposit deposit1("09.05.21", 10, 500, "20.05.21");// первый элемент
	//deposit1.Print();
	//cout << endl;
	Conditional_Contribution deposit2("10.05.21", 5, 1000, "19.05.21", "before marriage");
	//deposit2.Print();
	//cout << endl;
	Term_Irrevocable_Deposit deposit3;
	//deposit3.Print();
	//cout << endl;
	Term_Revocable_Deposit deposit4;// второй элемент
	//deposit4.Print();
	//cout << endl;
	Demond_Deposit* p = &deposit2;

	Array arr;//создаем сразу пустой массив(вызываетс€ конструктор по умолчанию)

	arr.Add(p);// добавл€ем первый элемент
	p = &deposit4;
	arr.Add(p);//добавл€ем второй элемент
	arr.output();//выводи массив состо€щий из двух элементов

	Array arr2(arr);//создаем новый массив с помощью конструктора копировани€
	arr2.output();//выводим его

	Array arr3;//создаем пустой массив
	arr3 = arr;//заполн€ем пустой массив с помощью оператора копировани€
	arr3.output();//выводим

	Array arr4(move(arr3));//создаем новый массив использу€ конструктор перемещени€
	arr4.output();//выводим его
	arr3.output();//массив 3 стал пустым так как данные перемести в массив 4

	arr4.Del_all();//провер€ем функцию удалени€

	arr4.output();//пытаемс€ вывести, но ничего не выходит

	arr4 = move(arr);//перемещаем данные первого массива в 4 с помощью оператора перемещени€
	arr4.output();//выводим его
	arr.output();//первый массив стал пустым так как данные переместились

	// ¬се функции, методы и операторы работают. ћожете засчитать 10.2 сразу, чтобы на зачете не нужно было тратить на нее врем€?)

	return 0;
}