#include <stack>
#include <vector>
#include <iostream>
#include <string>
#include <map>

using namespace std;

vector <string> polish_notation(string);//вектор польской записи
bool is_digit(char);//функци€ определ€юща€ цифра ли этот эелемент
bool is_operation(char);//функци€ определ€юща€ операци€ ли этот элемент
int from_str_to_int(string);//функци€ перевода польской записи в обычное выражение
int polska_counter(vector <string>);//функци€ вычисл€юща€ значение выражени€

int main()
{
	string expression;//выражение
	cout << "Enter the expression: ";
	getline(cin, expression);
	vector <string> polska = polish_notation(expression);//польска€ запись выражени€

	cout << "Counted value: " << polska_counter(polska) << endl;//вывод результата
	return 0;
}

int polska_counter(vector <string> expression)
{
	vector <int> counter;
	for (int i = 0; i < expression.size(); ++i)
	{
		string x = expression[i];
		if (is_digit(x[0]))
		{
			counter.push_back(from_str_to_int(x));//добавл€ем в вектор интовское число
		}
		else//в зависимости от оператора делаем операцию над числам
		{
			if (x == "+")
				*(counter.end() - 2) += counter.back();
			if (x == "-")
				*(counter.end() - 2) -= counter.back();
			if (x == "*")
				*(counter.end() - 2) *= counter.back();
			if (x == "/")
				*(counter.end() - 2) /= counter.back();
			if (x == "%")
				*(counter.end() - 2) %= counter.back();
			counter.pop_back();//удал€ем последний элемент
		}
	}
	return counter[0];
}


vector <string> polish_notation(string expression)
{
	map <char, int> priority =//расставл€ем приоритеты операторов
	{
		{'+', 2},
		{'-', 2},
		{'*', 3},
		{'/', 3},
		{'%', 3},
		{'=', 0},
	};

	vector <string> X;
	stack <string> Y;

	for (int i = 0; i < expression.length(); i++)//идем по всей строке выражени€
	{
		if (is_digit(expression[i]))//если элемент цифра
		{
			if (!X.empty() && is_digit(expression[i - 1]))//если предыдущий элемент тоже цифра
			{
				X.back() += expression[i];//в последний элемент добавл€ет цифру
			}
			else
			{
				X.push_back(expression.substr(i, 1));//добавл€ем этот элемент в конец нашего вектора
			}
		}
		else if (is_operation(expression[i]))//если элемент оператор
		{
			while (!Y.empty() && priority[Y.top()[0]] > priority[expression[i]])//пока приоритетность нашего стэка не будет выше приоритета нашего элемента
			{
				X.push_back(Y.top());//добавл€ем в конец нашего вектора оператор
				Y.pop();//удал€ем верхний элемент
			}
			Y.push(expression.substr(i, 1));//добавл€ем в стек наш оператор из строки
		}
		else if (expression[i] == '(')//добавл€ем скобочки в стек, если они встречаютс€ в выражении
			Y.push(expression.substr(i, 1));
		else if (expression[i] == ')')
		{
			while (!Y.empty() && Y.top() != "(")
			{
				X.push_back(Y.top());
				Y.pop();
			}
			if (!Y.empty())
				Y.pop();
		}
	}
	while (!Y.empty())
	{
		X.push_back(Y.top());
		Y.pop();
	}
	return X;
}

bool is_digit(char str)
{
	return '0' <= str && str <= '9';//возращаем да, если значесние строки от 0 до 9
}

bool is_operation(char str)
{
	return str == '+' || str == '-' || str == '*' || str == '/' || str == '%';//возращаем да, если значение строки €вл€етс€ + - * / или % 
}

int from_str_to_int(string str_number)
{
	int number = 0;
	//for (char x : str_number)
	//{
	//	number = number * 10 + x - '0';
	//}
	for (int i = 0; i < str_number.size(); ++i)
	{
		char x = str_number[i];
		number = number * 10 + x - '0';//переводим строку числа в число
	}
	return number;
}