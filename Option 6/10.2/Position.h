#pragma once
#include <iostream>
class Position
{
protected:
	double Xmin;
	double Ymin;
	double Xmax;
	double Ymax;
public:
	Position()
	{
		Xmin = 0, Ymin = 0, Xmax = 0, Ymax = 0;
	}
	Position(double xmin, double ymin, double xmax, double ymax)
	{
		Set_Xmin(xmin);
		Set_Ymin(ymin);
		Set_Xmax(xmax);
		Set_Ymax(ymax);
	}
	
	void Set_Xmin(double xmin)
	{
		if (xmin < 0)
			throw std::invalid_argument("Bad parametr");
		else Xmin = xmin;
	}
	void Set_Ymin(double ymin)
	{
		if (ymin < 0)
			throw std::invalid_argument("Bad parametr");
		else Ymin = ymin;
	}
	void Set_Xmax(double xmax)
	{
		if (xmax < 0)
			throw std::invalid_argument("Bad parametr");
		else Xmax = xmax;
	}
	void Set_Ymax(double ymax)
	{
		if (ymax < 0)
			throw std::invalid_argument("Bad parametr");
		else Ymax = ymax;
	}

	double Get_Xmin()
	{
		return Xmin;
	}
	double Get_Ymin()
	{
		return Ymin;
	}
	double Get_Xmax()
	{
		return Xmax;
	}
	double Get_Ymax()
	{
		return Ymax;
	}

	virtual void Print()
	{
		std::cout << "Position: (" << Xmin << ", " << Ymin << "; " << Xmax << ", " << Ymax << ")\n";
	}

	virtual ~Position() = default;
};
