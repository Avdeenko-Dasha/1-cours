//  Вычислить значение многочлена для заданного n в точках хi  [х0; хm] (хi = х0 + i*dх, i = 0, 1, …) двумя способами:
//суммируя элементы по возрастанию степени x и по схеме Горнера.
// Посчитать количество операций сложения и умножения в том и другом случае. 
//y=nx^2n+...+4x^8+3x^6+2x^4+1x^2+10; x0=1 xm=2 dx=0.25;
#include <iostream>
#include <iomanip>
using namespace std;
int main() {
	setlocale(0, "rus");
	int ksl1, ksl2, kumn1, kumn2, n, i, k;
	double x0, xn, y, sum, x, slag;
	cout << "Введите n" << endl;
	cin >> n;
	x = 0.75;
	cout <<setw(4)<< "x" << setw(10)<< "y" <<setw(10)<< "Cуммы "<< setw(9)<< " Умножения"<<endl;
	while (x < 2)
	{
		x += 0.25;
		xn = 1;
		y = 10;
		ksl1 = 0;
		kumn1 = 0;
		ksl2 = 0;
		kumn2 = 0;
		double x2 = x * x;
		cout << setw(4)<< x << ' ';
		for (i = 1; i <= n; i++)
		{
			xn *= x2;
			double temp = i * xn;
			y += temp;
			ksl1++;
			kumn1 += 2;
			//	cout << y << " ";
		}
		cout << setw(10)<<setprecision(5) << y;
		cout << setw(5) << ksl1 << setw(9) << kumn1 << endl;
		sum = 0;
		for (k = n; k >= 1; k--)//y=nx^2n+...+4x^8+3x^6+2x^4+1x^2+10;
		{
			sum += k;
			sum *= x2;
			ksl2++;
			kumn2++;
		}
		sum += 10;
		cout << setw(15)<< setprecision(5) << sum;
		cout <<setw(5) << ksl2 << setw(9) << kumn2 << endl;
	}
	system("pause");
	return 0;
}