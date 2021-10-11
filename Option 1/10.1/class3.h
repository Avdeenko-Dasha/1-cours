#pragma once
#include "class().h"

class Term_Irrevocable_Deposit : public Term_Deposit//Срочный безотзывной вклад
{
protected:
	int Additional_contributions;//период в течении которого допускаются дополнительные взносы во вклад
public:
	Term_Irrevocable_Deposit()
	{
		Additional_contributions = 0;
	}
	Term_Irrevocable_Deposit(string data_creat, double interest_rate,
		double sum, string data_last_interest, int term_month, int additional_contributions)
		: Term_Deposit(data_creat, interest_rate, sum, data_last_interest, term_month)
	{
		Set_additional_contributons(additional_contributions);
	}

	void Set_additional_contributons(int additional_contributions)
	{
		if (additional_contributions < 0)
			throw std::invalid_argument("contributions must be");
		Additional_contributions = additional_contributions;
	}
	int Get_additional_contributons()
	{
		return Additional_contributions;
	}
	void Print() override
	{
		Term_Deposit::Print();
		cout << "Additional_contributions: " << Additional_contributions << endl;
	}

	/*void print(std::ostream& str = std::cout) {
		Term_deposit::print(str);
		str << "Additional_contributions: " << Additional_contributions << endl;
	}*/
};
