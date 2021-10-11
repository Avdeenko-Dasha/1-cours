#include <iostream>
#include <string>
#include <stack>


using namespace std;


void perevod_v_polish_zapis(string start, string& finish)
{
	stack<char> st;

	for (int i = 0; start[i]; ++i)
	{
		char simbol = start[i];
		if (simbol == '(')
			st.emplace(simbol);
		else if (simbol == '*' || simbol == '/' || simbol == '%')
			st.emplace(simbol);
		else if (simbol == '+' || simbol == '-')
		{
			if (!st.empty())
			{
				char el = st.top();
				while (el == '*' || el == '/' || el == '%')
				{
					finish += el;
					st.pop();
					el = st.top();
				}
			}
			st.emplace(simbol);
		}
		else if (simbol == ')')
		{

			char el = st.top();
			while (el != '(')
			{
				finish += el;
				st.pop();
				el = st.top();
			}
			st.pop();
		}
		else finish += simbol;
	}
	while (!st.empty())
	{
		finish += st.top();
		st.pop();
	}
}
double consider(double y, double x, char simbol)
{
	if (simbol == '+')
		return x + y;
	if (simbol == '-')
		return x - y;
	if (simbol == '*')
		return x * y;
	if (simbol == '/')
		return x / y;
	if (simbol == '%')
	{
		int z = x, s = y;
		return z % s;
	}
}
double compute(string start)
{
	string oper = "+-*/%";
	stack<double> st;

	for (int i = 0; i < start.size(); ++i)
	{
		bool flag = true;
		for (int j = 0; j < oper.size(); ++j)
			if (start[i] == oper[j])
			{
				flag = false;
				break;
			}
		if (!flag)
		{
			double x = st.top();
			st.pop();
			double y = st.top();
			st.pop();
			st.emplace(consider(x, y, start[i]));
		}
		else
			st.emplace(start[i]-48);
	}
	return st.top();
}

int main()
{
	string expression;
	getline(cin, expression);
	string polish_zapis;
	perevod_v_polish_zapis(expression, polish_zapis);
	cout << polish_zapis << endl;
	cout << compute(polish_zapis);
	return 0;
}