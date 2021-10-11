#include <math.h>
#include <iostream> 
#include <iomanip>
using namespace std;
// подынтегральные функции
double f1(double x, double s, double t)
{
	//return t * atan(pow(x, 1.0 / 5.0)) / (x * x + s * sin(x));
	return x;
}

void Sum(double a, double b, double h, double s, double t, double (*pf) (double x, double s, double t), double& S)// функция выч/ интеграла по методу левых прямоугольников
{
	double x, sum;
	x = a;
	sum = 0;
	while (x < b - h/2)
	{
		sum = sum + (*pf)(x, s, t); //накопление суммы высот
		x = x + h;
	}
	//вычисление площади
	S = h * sum;
}

void Vych_Int(double a, double b, double eps, double s, double t, double (*pf)(double x, double s, double t), double& I, int& k)
{
	int n = 4;//инициализация количества разбиений
	double h = (b - a) / n; //определение шага интегрирования
	double S1 = 0, S2 = 0;// переменные для значений сумм с шагом h и с шагом h/2	
	Sum(a, b, h, s, t, pf, S1);// вызов функции Sum c шагом h : в S1 возвращается сумма
	k = 0;
	// запуск процесса двойного пересчета
	do
	{
		S2 = S1;// сохраняем значение интеграла предыдущего шага
		n *= 2; //увеличение количества отрезков разбиения и уменьшение шага интегрирования в 2 раза
		h = (b - a) / n;
		Sum(a, b, h, s, t, pf, S1);//вызов функции Sum с шагом h=h/2
		k++;
	} while (fabs(S1 - S2) > eps);
	I = S1;
}


void main()
{
	double a = 0.1, b = 1.2, eps=1e-6; // отрезок интегрирования, точность
	double Int; // значение интеграла
	int K_iter; // количество итераций
	
	
	cout << "s" << setw(5) << "t" << setw(5) << "Int" << setw(10) << "K_iter" << endl;

	for (double s = 0; s <= 0.5; s += 0.1)
	{
		for (double t = 0.6; t <= 1.8; t += 0.4)
		{
			Vych_Int(a, b, eps, s, t, &f1, Int, K_iter);//вычисление интеграла для f1
			cout << s << setw(5) << t << setw(10) << Int << setw(5) << K_iter << endl;
		}
		cout << endl;
	}
}
