#pragma once
#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

class complex_number
{
	double m_re;//действительная часть
	double m_im;//мнимая часть
public:
	complex_number()
	{
		m_re = 0;
		m_im = 0;
	}
	complex_number(double m_re, double m_im)
	{
		this->m_re = m_re;
		this->m_im = m_im;
	}
	complex_number(complex_number& other)
	{
		m_re = other.m_re;
		m_im = other.m_im;
	}
	~complex_number() {}

	complex_number& operator = (const complex_number&);
	complex_number& operator = (double);

	complex_number operator + ();//Унарный +
	complex_number operator + (complex_number& ); // + два комплексных числа
	complex_number operator + (double);// Компл + вещ
	friend complex_number operator + (double, complex_number&);// Вещ + компл


	complex_number operator - ();// Унарный -
	complex_number operator - (complex_number&); // - два комплексных числа
	complex_number operator - (double);// Компл - вещ
	friend complex_number operator - (double, complex_number&);// Вещ - компл


	complex_number operator * (complex_number&);// * два компл числа
	complex_number operator * (double);//компл * вещ
	friend complex_number operator * (double, complex_number&);// Вещ * компл


	complex_number operator / (complex_number&);// / два компл числа
	complex_number operator / (double);//компле / вещ
	friend complex_number operator / (double, complex_number&);// Вещ / компл

	friend istream& operator >> (istream&, complex_number&); // Ввод комплексного числа
	friend ostream& operator << (ostream&, complex_number&);// Вывод комплексного числа
	

	complex_number& Pow(int p);
	complex_number& Sqrt();
};
