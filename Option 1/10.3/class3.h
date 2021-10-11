#pragma once
#include "class().h"

class Term_Irrevocable_Deposit : public Term_Deposit//������� ����������� �����
{
protected:
	int Additional_contributions;//������ � ������� �������� ����������� �������������� ������ �� �����
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

	Term_Irrevocable_Deposit* Clone() override
	{
		return new Term_Irrevocable_Deposit(*this);
	}

	void Print() override
	{
		Term_Deposit::Print();
		cout << "Additional_contributions: " << Additional_contributions << endl;
	}
	const char* getType() const override
	{
		return "Term_Irrevocable_Deposit";
	}
	void Write(ostream& file) override
	{
		Term_Deposit::Write(file);
		file << Additional_contributions << endl;
	}
	void read(ifstream& file) override
	{
		Term_Deposit::read(file);
		file >> Additional_contributions;
	}
};

