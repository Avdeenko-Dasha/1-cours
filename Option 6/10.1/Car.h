#pragma once
#include "Position.h"

class Car : public Position
{
protected:
	std::string color;
	std::string number;
	bool taxi;
public:
	Car()
	{
		color = {};
		number = {};
		taxi = 0;
	}
	Car(double xmin, double ymin, double xmax, double ymax, std::string color, std::string number, bool taxi)
		: Position(xmin, ymin, xmax, ymax)
	{
		Set_color(color);
		Set_number(number);
		Set_taxi(taxi);
	}

	void Set_color(std::string color)
	{
		if (color.empty())
			throw std::invalid_argument("The line is empty");
		else this->color = color;
	}
	void Set_number(std::string number)
	{
		if (number.empty())
			throw std::invalid_argument("The line is empty");
		else this->number = number;
	}
	void Set_taxi(bool taxi)
	{
		this->taxi = taxi;
	}

	std::string Get_color()
	{
		return color;
	}
	std::string Get_number()
	{
		return number;
	}
	bool Get_taxi()
	{
		return taxi;
	}

	void Print() override
	{
		Position::Print();
		std::cout << "\nCar\nColor: " << color << "\nNumber: " << number << "\nTaxi: ";
		if (taxi)
			std::cout << "yes";
		else
			std::cout << "no";
	}
};
