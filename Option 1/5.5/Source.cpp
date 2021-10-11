/*Вычислить корень уравнения 0 )( =xf на отрезке [a; b] с точностью  =10–6, 
используя заданный метод (М = 1 – метод половинного деления, М = 2 – метод касательных, М = 3 – метод хорд) для заданных функций. 
Вычисление корня уравнения оформить в виде функции с функциональным параметром,
параметры a, b,  , s – в виде аргументов по умолчанию. 
Результат представить в виде таблицы (s – значение параметра, х – вычисленный корень уравнения, 
f(x) – значение функции в найденной точке х,
k_iter – количество итераций цикла для получения корня с заданной точностью): */
#include <iostream>  
#include <iomanip>
using namespace std;

double F1(double x, double s) 
{
	return x * x - 3;
}
double F2(double x, double s)
{
	return exp(-s * x) - 2 + x * x;
}

double FindRoot1(double (*f)(double, double), double a, double b, double s, int& k_iter, double eps = 1e-6)
{
	double c = (a + b) / 2;
	while (abs((b - a) / 2) > eps)
	{
		c = (a + b) / 2;
		if ((f(a, s) * f(c, s)) > 0) a = c;
		else b = c;
		k_iter++;
	}
	return c;
}

int main()
{
	//Интервал, погрешность и корень:
	double a = 1, b = 3, eps = 1e-6, x;
	double x0 = 1;
	const int N = 100;
	double s = 0.1;
	int k_iter = 0;
	
	//Метод половинного деления
	x = FindRoot1(&F1, a, b, s, k_iter);
	cout << setw(3) << "s" << setw(7) << "x" << setw(13) << "F(X)" << setw(9) << "k_iter" << endl;
	cout << setw(4) << "--" << setw(9) << x << setw(13) << F1(x, s) << setw(3) << k_iter << endl;

	while (s <= 1.3)
	{
		k_iter = 0;
		x = FindRoot1(&F2, a, b, s, k_iter);
		cout << setw(4) << s << setw(9) << x << setw(13) << F2(x, s) << setw(3) << k_iter << endl;
		s += 0.3;
	}
	return 0;
}


	

