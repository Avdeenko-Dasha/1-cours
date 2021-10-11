#include <iostream>
#include <string>
#include <cstdlib>

void fun_for_4_1()
{
	std::string text;
	std::string str;
	getline(std::cin, text);

	int pos = 0;
	char simbol;
	for (int i = 0; text[i]; ++i)
	{
		simbol = text[i];
		pos = text.find(simbol, i + 1);
		if (pos != -1)
		{
			pos = text.find(simbol, pos + 1);
			if (pos != -1)
				pos = i;
			while (pos != -1)
			{
				text.erase(pos, 1);
				pos = text.find(simbol, pos + 1);
			}
		}
	}
	std::cout << text;
}

void fun_for_4_2()
{
	std::string number_10;
	std::string number_16;
	getline(std::cin, number_10);
	double num = atof(number_10.c_str());
	std::string perevod = "0123456789ABCDEF";
	int whole_part = (int)num;
	double fruction = num - whole_part;
	int arr[100] = { 0 };
	int n = 0;
	while (whole_part > 16)
	{
		arr[n++] = whole_part % 16;
		whole_part = whole_part / 16;
	}
	arr[n] = whole_part;
	int k = 0;
	int pos = n;
	int simbol = 0;
	for (int i = n; i >= 0; --i)
	{
		simbol = arr[i];
		number_16.push_back(perevod[simbol]);
	}
	number_16.push_back('.');
	for (int i = 0; i < 4; ++i)
	{
		fruction *= 16;
		arr[++n] = (int)fruction;
		fruction -= arr[n];
	}
	for (int i = pos + 1; i <= n; ++i)
	{
		simbol = arr[i];
		number_16.push_back(perevod[simbol]);
	}
	std::cout << number_16;
}

void fun_for_4_3()
{
	std::string text;
	getline(std::cin, text);
	std::string separators = " .,:;!?-()";
	std::string consonants = "bcdfghjklmnpqrstvwxzBCDFGHJKLMNPQRSTVWXZ";
	std::string word;
	std::string max_word;

	int count_consonants = 0;
	int start_pos = -1;
	int finish_pos = 0;
	int pos_simbol = -1;
	int count_max = 0;

	while (finish_pos != -1)
	{
		finish_pos = text.find_first_of(separators, start_pos + 1);
		if (start_pos == -1)
			start_pos = 0;
		word.assign(text, start_pos, finish_pos - start_pos);
		start_pos = finish_pos;
		while (true)
		{
			pos_simbol = word.find_first_of(consonants, pos_simbol+1);
			if (pos_simbol != -1)
				count_consonants++;
			else break;
		}
		if (count_consonants > count_max)
		{
			count_max = count_consonants;
			max_word.erase(0);
			max_word.assign(word);
		}
		else if (count_consonants == count_max)
		{
			max_word += word;
		}
		word.erase(0);
		count_consonants = 0;
	}
	std::cout << max_word;
}

int main()
{
	fun_for_4_1();
	fun_for_4_2();
	fun_for_4_3();
	return 0;
}