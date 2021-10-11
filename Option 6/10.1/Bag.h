#pragma once
#include "Position.h"

class Bag : public Position
{
protected:
	std::string times_of_day;
public:
	Bag()
	{
		times_of_day = {};
	}
	Bag(double Xmin, double Ymin, double Xmax, double Ymax, std::string times_of_day)
		: Position(Xmin, Ymin, Xmax, Ymax)
	{
		Set_times_of_day(times_of_day);
	}

	void Set_times_of_day(std::string times_of_day)
	{
		if (times_of_day.empty())
			throw std::invalid_argument("The line is empty");
		else this->times_of_day = times_of_day;
	}
	std::string Get_times_of_day()
	{
		return times_of_day;
	}

	void Print() override
	{
		Position::Print();
		std::cout << "\nBag\nTimes_of_day: " << times_of_day;
	}
};
