#pragma once
#include "Position.h"

class Human : public Position
{
protected:
	char sex;
	char baby;
	char glasses;
	char beard;
public:
	Human()
	{
		sex = 0;
		baby = 0;
		glasses = 0;
		beard = 0;
	}
	Human(double Xmin, double Ymin, double Xmax, double Ymax, char sex, char baby, char glasses, char beard)
		: Position(Xmin, Ymin, Xmax, Ymax)
	{
		Set_sex(sex);
		Set_baby(baby);
		Set_glasses(glasses);
		Set_beard(beard);
	}

	void Set_sex(char sex)
	{
		if (sex != 1 && sex != 0)
			throw std::invalid_argument("Wrong gender introduction");
		else
			this->sex = sex;

	}
	void Set_baby(char baby)
	{
		if (baby != 1 && baby != 0)
			throw std::invalid_argument("Wrong baby introduction");
		else this->baby = baby;
	}
	void Set_glasses(char glasses)
	{
		if (glasses != 1 && glasses != 0)
			throw std::invalid_argument("Wrong glasses introduction");
		else this->glasses = glasses;
	}
	void Set_beard(char beard)
	{
		if (beard != 1 && beard != 0)
			throw std::invalid_argument("Wrong beard introduction");
		else this->beard = beard;
	}

	char Get_sex()
	{
		return sex;
	}
	char Get_baby()
	{
		return baby;
	}
	char Get_glasses()
	{
		return glasses;
	}
	char Get_beard()
	{
		return beard;
	}

	void Print() override
	{
		Position::Print();
		std::cout << "Human\nSex: ";
		if (sex == 1)
			std::cout << "man";
		else if (sex == 0)
			std::cout << "woman";
		else
			std::cout << "failed to determine";

		std::cout << "\nChild: ";
		if (sex == 1)
			std::cout << "yes";
		else if (sex == 0)
			std::cout << "no";
		else
			std::cout << "failed to determine";

		std::cout << "\nGlasses: ";
		if (sex == 1)
			std::cout << "yes";
		else if (sex == 0)
			std::cout << "no";
		else
			std::cout << "failed to determine";

		std::cout << "\nBeard: ";
		if (sex == 1)
			std::cout << "yes";
		else if (sex == 0)
			std::cout << "no";
		else
			std::cout << "failed to determine";
	}
};
