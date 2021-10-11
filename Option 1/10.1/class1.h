#pragma once
#include <iostream>

using namespace std;

class Demond_Deposit//Вклад до востребования (бессрочный вклад)
{
protected:
	static int staticInt;
	int Account_number; //номер счёта
	string Data_creat;//дата создания вклада
	double Interest_rate;//годовая процентная ставка
	double Sum;//текущая сумма
	string Data_last_interest;//дата последнего начисления процентов
public:

	Demond_Deposit()
	{
		Account_number = staticInt;
		staticInt++;
		Data_creat = '0';
		Interest_rate = 0;
		Sum = 0;
		Data_last_interest = '0';
	}
	Demond_Deposit(string data_creat, double interest_rate, double sum, string data_last_interest)
	{
		Account_number = staticInt;
		staticInt++;
		Set_data_creat(data_creat);
		Set_interest_rate(interest_rate);
		Set_sum(sum);
		Set_data_last_interest(data_last_interest);
	}

	void Set_data_creat(string data_creat)
	{
		if (data_creat.size() == 0)
			throw std::invalid_argument("data must be");
		Data_creat = data_creat;
	}
	void Set_interest_rate(double interest_rate)
	{
		if (interest_rate < 0)
			throw std::invalid_argument("rate must be >= 0");
		Interest_rate = interest_rate;
	}
	void Set_sum(double sum)
	{
		if (sum < 0)
			throw std::invalid_argument("sum must be >= 0");
		Sum = sum;
	}
	void Set_data_last_interest(string data_last_interest)
	{
		if (data_last_interest.size() == 0)
			throw std::invalid_argument("data must be");
		Data_last_interest = data_last_interest;
	}

	int Get_account_number()
	{
		return Account_number;
	}
	string Get_data_creat()
	{
		return Data_creat;
	}
	double Get_interest_rate()
	{
		return Interest_rate;
	}
	double Get_sum()
	{
		return Sum;
	}
	string Get_data_last_interest()
	{
		return Data_last_interest;
	}

	virtual void Print()
	{
		cout << "Number: " << Account_number << endl;
		cout << "Data creat: " << Data_creat << endl;
		cout << "Interest rate: " << Interest_rate << endl;
		cout << "Sum: " << Sum << endl;
		cout << "Last data: " << Data_last_interest << endl;
	}

	/*virtual void print(std::ostream& str = std::cout) {
		str << typeid(*this).name() << endl;
		str << "Number is: " << Account_number << endl;
		str << "Data is: " << Data_creat << endl;
		str << "Annual interest rate is: " << Interest_rate << endl;
		str << "Summa is: " << Sum;
		str << "Last data is: " << Data_last_interest << endl;
	}

	friend std::ostream& operator << (std::ostream& str, Demand_deposit& d) {
		d.print(str);
		return str;
	}*/

	virtual ~Demond_Deposit() = default;
};
int Demond_Deposit::staticInt = 1;
