
#include <iostream>
#include <list>
#include <vector>
#include <time.h>

using namespace std;

//1. ƒаны натуральное число n, действительные числа x1, x2, ... xn.
//–азработать программу вычислени€ значени€ выражени€ следующего вида: x1*xn + x2*xn-1 + x3 * xn-2 + .... + xn*x1

void output(list<double>& L)
{
	list<double>::iterator p = L.begin();
	while (p != L.end()) // итератор на элемент, следующий
	{ // за последним в списке
		cout << *p << " ";
		++p;
	}
	cout << endl;
}
void output(vector<double>& L)
{
	for (unsigned int i = 0; i < L.size(); ++i)
		cout << L[i] << " ";
	cout << endl;
}

void random(int n, list<double>& L)
{
	for (int i = 0; i < n; i++)

	{
		double x = rand() % 1000 / 10.0;
		L.push_back(x);
	}
}
void random(int n, vector<double>& L)
{
	for (int i = 0; i < n; i++)
	{
		double x = rand() % 1000 / 10.0;
		L.push_back(x);
	}
}

double function(list<double>& L)
{
	double res = 0;
	int n = L.size() / 2;
	list<double>::iterator ptr = L.begin();
	list<double>::iterator help = L.end();
	--help;
	for (int i = 0; i <= n ; ++i)
	{
		res += *ptr++ * *help--;
	}
	return 2*res;
}
double function(vector<double>& L)
{
	double res = 0;
	int n = L.size() / 2;
	vector<double>::iterator ptr = L.begin();
	vector<double>::iterator help = L.end();
	--help;
	for (int i = 0; i <= n; ++i)
	{
		res += *ptr++ * *help--;
	}
	return 2 * res;
}

int main()
{
	srand(time(NULL));
	int n = 3;
	double x = 0;

	list<double> L1;
	random(n, L1);
	output(L1);
	x = function(L1);
	cout << x << endl;

	vector<double> L2;
	random(n, L2);
	output(L2);
	x = function(L2);
	cout << x << endl;

	return 0;
}

