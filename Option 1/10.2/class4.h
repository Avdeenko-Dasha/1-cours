#pragma once
#pragma once
#include "class().h"
class Term_Revocable_Deposit : public Term_Deposit//Срочный отзывной вклад
{
protected:
	double Reduced_rate;//годовая процентная ставка(пониженная) в случае досрочного расторжения договора
	int Initial_amount;//начальная сумма (для пересчёта процентов по пониженной ставке)

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

	void Print() override
	{
		Term_Deposit::Print();
		cout << "Redused_rate: " << Reduced_rate << endl;
		cout << "Initial amounth: " << Initial_amount << endl;
	}

	Term_Revocable_Deposit* Clone() override
	{
		return new Term_Revocable_Deposit(*this);
	}

};
