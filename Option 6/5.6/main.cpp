#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

//Прототип ф-ции вычисления интеграла по критерию двойного пересчета
void Vych_Int(double a, double b, double eps, double(*pf)(double, double, double), double& I, int& k, double s, double t);

//Прототип функции вычисления интеграла по методу средних прямоугольников
void Sum(double a, double b, double h, double(*pf)(double, double, double), double& S, double s, double t);

//Прототипы подынтегральных функций
double foo(double, double, double);

void main()
{
	double a = 1, b = 2, eps = 1e-6;
	double Int = 0;
	int k_iter = 0;

	cout << "  s:   t:    Int:   k_iter:\n";

	for (double s = 0; s <= 0.5; s += 0.1)
	{
		for (double t = 0.5; t <= 2.5; t += 0.5)
		{
			cout << setw(4) << s << setw(5) << t;
			k_iter = 0;
			Vych_Int(a, b, eps, &foo, Int, k_iter, s, t);
			cout << setw(10) << Int << setw(4) << k_iter << '\n';
		}
		cout << '\n';
	}
	

}

void Vych_Int(double a, double b, double eps, double(*pf)(double, double, double), double& I, int& k, double s, double t)
{
	int n = 4;//Кол-во разбиений
	double h = (b - a) / n;//Определение шага интегрирования
	double S1 = 0;//Значение суммы с шагом h
	double S2 = 0;//Значение суммы с шагом h/2

	Sum(a, b, h, pf, S1, s, t);//В S1 возращается сумма с шагом h
	
	do//Запуск процесса двойного пересчета
	{
		S2 = S1;//Сохраняем значение интеграла предыдущего шага
		n *= 2;//Увеличение кол-ва отрезков разбиения
		h = (b - a) / n;//уменьшение шага интегрирования в 2 раза

		Sum(a, b, h, pf, S1, s, t);//В S1 возращается сумма с шагом h = h/2
		k++;
	} while (fabs(S1 - S2) > eps);
	I = S1;
}

void Sum(double a, double b, double h, double(*pf)(double, double, double), double& S, double s, double t)
{
	double x = a, sum = 0;
	while (x < b)
	{
		sum = sum + (*pf)(x + h/2, s, t);
		x = x + h;
	}
	S = h * sum;
}

double foo(double x, double s, double t)
{
	return (1.0 + pow(x, t) + x*x)/sqrt(x*x*x + 1)*(1.0-sin(s*x));
}
