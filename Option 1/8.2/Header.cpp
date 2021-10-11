#include "Header.h"

complex_number& complex_number::operator=(const complex_number& r)
{
	m_re = r.m_re;
	m_im = r.m_im;
	return *this;
}

complex_number& complex_number::operator=(double r)
{
	m_re = r;
	m_im = 0;
	return *this;
}

complex_number complex_number::operator+()
{
	return *this;
}

complex_number complex_number::operator+(complex_number& r)
{
	complex_number z(m_re + r.m_re, m_im + r.m_im);
	return z;
}

complex_number complex_number::operator+(double r)
{
	complex_number z(m_re + r, m_im);
	return z;
}

complex_number complex_number::operator-()
{
	m_re = -m_re;
	m_im = -m_im;
	return *this;
}

complex_number complex_number::operator-(complex_number& r)
{
	complex_number z(m_re - r.m_re, m_im - r.m_im);
	return z;
}

complex_number complex_number::operator-(double r)
{
	complex_number z(m_re - r, m_im);
	return z;
}

complex_number complex_number::operator*(complex_number& r)
{
	complex_number z(m_re * r.m_re - m_im * r.m_im, m_re * r.m_re + m_im * r.m_im);
	return z;
}

complex_number complex_number::operator*(double r)
{
	complex_number z(m_re * r, m_im * r);
	return z;
}

complex_number complex_number::operator/(complex_number& r)
{
	double d = r.m_re * r.m_re + r.m_im * r.m_im;
	complex_number z((m_re * r.m_re + m_im * r.m_im) / d, (m_re * r.m_re + m_im * r.m_im) / d);
	return z;
}

complex_number complex_number::operator/(double r)
{
	complex_number z(m_re / r, m_im / r);
	return z;
}

complex_number& complex_number::Pow(int p)
{
	double r = sqrt(m_re * m_re + m_im * m_im);
	double a = atan(abs(m_im / m_re));
	double cos_r = cos(p * a);
	double sin_r = sin(p * a);
	r = pow(r, p);
	m_re = r * cos_r;
	m_im = r * sin_r;
	return *this;
}

complex_number& complex_number::Sqrt()
{
	double r = sqrt(m_re * m_re + m_im * m_im);
	double a = atan(abs(m_im / m_re));
	double cos_r = cos(a / 2);
	double sin_r = sin(a / 2);
	r = sqrt(abs(r));

	m_re = r * cos_r;
	m_im = r * sin_r;
	return *this;
}

complex_number operator+(double l, complex_number& r)
{
	r.m_re = l + r.m_re;
	return r;
}

complex_number operator-(double l, complex_number& r)
{
	r.m_re = l - r.m_re;
	r.m_im = -r.m_im;
	return r;
}

complex_number operator*(double l, complex_number& r)
{
	r.m_re = l * r.m_re;
	r.m_im = l * r.m_im;
	return r;
}

complex_number operator/(double l, complex_number& r)
{
	complex_number z(l, 0);
	r = z / r;
	return r;
}

istream& operator>>(istream& str, complex_number& r)
{
	double re = 0, im = 0;
	str >> re >> im;
	r = complex_number(re, im);
	return str;
}

ostream& operator<<(ostream& str, complex_number& r)
{
	if (r.m_im < 0)
		return str << r.m_re << r.m_im << "i";
	else return str << r.m_re << "+" << r.m_im << "i";
}
