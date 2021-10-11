#include "class.h"

Number& Number::operator+(const Number& n)
{
	Number* res = new Number;
	for (int i = res->Size - 1; i >= 0; --i)
		res->Mass[i] = n.Mass[i] + Mass[i];
	res->perekid();
	return *res;
}

Number& Number::operator*(int n)
{
	if (n >= 10)
		throw std::invalid_argument("bad number");

	Number* res = new Number;
	for (int i = res->Size - 1; i >= 0; --i)
		res->Mass[i] = Mass[i] * n;
	res->perekid();
	return *res;
}

Number& Number::operator*(const Number& n)
{
	Number* res = new Number;
	for (int i = Size - 1; i >= 0; --i)
	{
		Number x = (*this) * n.Mass[i];
		x <<= Size - 1 - i;
		*res = *res + x;
	}
	return *res;
}

Number& Number::operator<<=(const int n)//смещение влево на n знаков
{
	for (int i = 0; i < Size - n; ++i)
		Mass[i] = Mass[i + n];

	for (int i = Size - n; i < Size; ++i)
		Mass[i] = 0;

	return *this;
}

Number& Number::operator=(const Number& n)
{
	for (int i = 0; i < Size; ++i)
		Mass[i] = n.Mass[i];
	return *this;
}

int& Number::operator[](const int i)
{
	if (i < 0 || i >= Size)
		throw std::invalid_argument("bad index");

	return Mass[i];
}

istream& operator>>(istream& str, Number& r)
{
	for (int i = 0; i < r.Size; ++i)
		str >> r.Mass[i];
	return str;
}

ostream& operator<<(ostream& str, Number& r)
{
	int i = 0;
	while (!r.Mass[i])
		i++;
	if (i != r.Size)
		for (; i < r.Size; ++i)
			str << r.Mass[i];
	else str << 0;
	return str;
}
