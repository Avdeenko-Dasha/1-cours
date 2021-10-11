#pragma once
#include "Human.h"
#include <string>

class Bicycles : public Human
{
protected:
	std::string bike_color;
public:
	Bicycles()
	{
		bike_color = {};
	}
	Bicycles(double Xmin, double Ymin, double Xmax, double Ymax, char sex, char baby, char glasses, char beard, std::string color) 
		: Human(Xmin, Ymin, Xmax, Ymax, sex, baby, glasses, beard)
	{
		Set_bike_color(color);
	}
	
	void Set_bike_color(std::string color)
	{
		if (color.empty())
			throw std::invalid_argument("The line is empty");
		else bike_color = color;
	}
	std::string Get_bike_color()
	{
		return bike_color;
	}

	void Print() override
	{
		Human::Print();
		std::cout << "\nBike color: " << bike_color;
	}
};
