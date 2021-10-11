#include <stack>
#include <vector>
#include <iostream>
#include <string>
#include <map>

using namespace std;

vector <string> polish_notation(string);//������ �������� ������
bool is_digit(char);//������� ������������ ����� �� ���� ��������
bool is_operation(char);//������� ������������ �������� �� ���� �������
int from_str_to_int(string);//������� �������� �������� ������ � ������� ���������
int polska_counter(vector <string>);//������� ����������� �������� ���������

int main()
{
	string expression;//���������
	cout << "Enter the expression: ";
	getline(cin, expression);
	vector <string> polska = polish_notation(expression);//�������� ������ ���������

	cout << "Counted value: " << polska_counter(polska) << endl;//����� ����������
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
			counter.push_back(from_str_to_int(x));//��������� � ������ ��������� �����
		}
		else//� ����������� �� ��������� ������ �������� ��� ������
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
			counter.pop_back();//������� ��������� �������
		}
	}
	return counter[0];
}


vector <string> polish_notation(string expression)
{
	map <char, int> priority =//����������� ���������� ����������
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

	for (int i = 0; i < expression.length(); i++)//���� �� ���� ������ ���������
	{
		if (is_digit(expression[i]))//���� ������� �����
		{
			if (!X.empty() && is_digit(expression[i - 1]))//���� ���������� ������� ���� �����
			{
				X.back() += expression[i];//� ��������� ������� ��������� �����
			}
			else
			{
				X.push_back(expression.substr(i, 1));//��������� ���� ������� � ����� ������ �������
			}
		}
		else if (is_operation(expression[i]))//���� ������� ��������
		{
			while (!Y.empty() && priority[Y.top()[0]] > priority[expression[i]])//���� �������������� ������ ����� �� ����� ���� ���������� ������ ��������
			{
				X.push_back(Y.top());//��������� � ����� ������ ������� ��������
				Y.pop();//������� ������� �������
			}
			Y.push(expression.substr(i, 1));//��������� � ���� ��� �������� �� ������
		}
		else if (expression[i] == '(')//��������� �������� � ����, ���� ��� ����������� � ���������
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
	return '0' <= str && str <= '9';//��������� ��, ���� ��������� ������ �� 0 �� 9
}

bool is_operation(char str)
{
	return str == '+' || str == '-' || str == '*' || str == '/' || str == '%';//��������� ��, ���� �������� ������ �������� + - * / ��� % 
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
		number = number * 10 + x - '0';//��������� ������ ����� � �����
	}
	return number;
}