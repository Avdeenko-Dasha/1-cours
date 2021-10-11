#pragma once
#include "class1.h"
class Term_Deposit : public Demond_Deposit//—рочный вклад
{
protected:
	int Term_month;//срок вклада в мес€цах
//public:
	Term_Deposit()
	{
		Term_month = 0;
	}
	Term_Deposit(string data_creat, double interest_rate,
		double sum, string data_last_interest, int term_month)
		: Demond_Deposit(data_creat, interest_rate, sum, data_last_interest)
	{
		Set_term_month(term_month);
	}

	void Set_term_month(int term_month)
	{
		if (term_month < 0)
			throw std::invalid_argument("term must be");
		Term_month = term_month;
	}
	int Get_term_month()
	{
		return Term_month;
	}
	void Print() override
	{
		Demond_Deposit::Print();
		cout << "Term_month: " << Term_month << endl;
	}
	/*void print(std::ostream& str = std::cout) {
		Demand_deposit::print(str);
		str << "Term_month: " << Term_month << endl;
	}*/
};
