#pragma once
#include "class().h"
class Term_Revocable_Deposit : public Term_Deposit//??????? ???????? ?????
{
protected:
	double Reduced_rate;//??????? ?????????? ??????(??????????) ? ?????? ?????????? ??????????? ????????
	int Initial_amount;//????????? ????? (??? ????????? ????????? ?? ?????????? ??????)

public:
	Term_Revocable_Deposit()
	{
		Reduced_rate = 0;
		Initial_amount = 0;
	}
	Term_Revocable_Deposit(string data_creat, double interest_rate,
		double sum, string data_last_interest, int term_month, double reduced_rate, int initial_amount)
		: Term_Deposit(data_creat, interest_rate, sum, data_last_interest, term_month)
	{
		Set_redused_rate(reduced_rate);
		Set_initial_amount(initial_amount);
	}

	void Set_redused_rate(double redused_rate)
	{
		if (redused_rate < 0)
			throw std::invalid_argument("rate must be");
		Reduced_rate = redused_rate;
	}
	void Set_initial_amount(int initial_amount)
	{
		if (initial_amount < 0)
			throw std::invalid_argument("initial amount must be");
		Initial_amount = initial_amount;
	}

	double Get_redused_rate() 
	{
		return Reduced_rate;
	}
	int Get_initial_amounth()
	{
		return Initial_amount;
	}

	Term_Revocable_Deposit* Clone() override
	{
		return new Term_Revocable_Deposit(*this);
	}

	const char* getType() const override
	{
		return "Term_Revocable_Deposit";
	}

	void Print() override
	{
		Term_Deposit::Print();
		cout << "Redused_rate: " << Reduced_rate << endl;
		cout << "Initial amounth: " << Initial_amount << endl;
	}

	void Write(ostream& file) override
	{
		Term_Deposit::Write(file);
		file << Reduced_rate << endl;
		file << Initial_amount << endl;
	}

	void read(ifstream& file) override
	{
		Term_Deposit::read(file);
		file >> Reduced_rate;
		file >> Initial_amount;
	}
};

