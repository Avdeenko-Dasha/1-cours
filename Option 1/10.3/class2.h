#pragma once
#include "class1.h"
class Conditional_Contribution : public Demond_Deposit//Условный вклад 
{
protected:
	string Closing_condition;//условие закрытия вклада
public:
	Conditional_Contribution()
	{
		Closing_condition = {};
	}
	Conditional_Contribution(string data_creat, double interest_rate,
		double sum, string data_last_interest, string closing_condition)
		: Demond_Deposit(data_creat, interest_rate, sum, data_last_interest)
	{
		Set_closing_conduction(closing_condition);
	}

	void Set_closing_conduction(string closing_conduction)
	{
		if (closing_conduction.size() == 0)
			throw std::invalid_argument("conduction must be");
		Closing_condition = closing_conduction;
	}
	string Get_closing_conduction()
	{
		return Closing_condition;
	}
	const char* getType() const override
	{
		return "Conditional_Contribution";
	}
	Conditional_Contribution* Clone() override
	{
		return new Conditional_Contribution(*this);
	}

	void Print() override
	{
		Demond_Deposit::Print();
		cout << "Closing_condition: " << Closing_condition << endl;
	}

	void Write(ostream& file) override
	{
		Demond_Deposit::Write(file);
		file << Closing_condition << endl;
	}

	void read(ifstream& file) override
	{
		Demond_Deposit::read(file);
		file >> Closing_condition;
	}
};

