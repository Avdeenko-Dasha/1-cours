#include <iostream>

using namespace std;

int main()
{
	const int max = 100;
	char text[max];
	cin.getline(text, max);
	char separators[] = " .,:;!?-()";
	char consonants[] = "bcdfghjklmnpqrstvwxzBCDFGHJKLMNPQRSTVWXZ";

	int count_consonants = 0;
	int max_word = 0;
	int start_pos = 0;
	int finish_pos = 0;
	bool flag = true;
	int mass_pos[max] = { 0 };
	int kolvo_pos = 0;

	for (int i = 0; text[i]; ++i)
	{
		flag = true;
		for (int j = 0; separators[j]; ++j)
			if (text[i] == separators[j])
			{
				flag = false;
				if (count_consonants > max_word)
				{
					max_word = count_consonants;
					mass_pos[0] = i;
					kolvo_pos = 0;
				}
				else if (count_consonants == max_word)
				{
					++kolvo_pos;
					mass_pos[kolvo_pos] = i;
				}
				count_consonants = 0;
				break;
			}
		if (flag)
			for (int k = 0; consonants[k]; ++k)
				if (text[i] == consonants[k])
				{
					++count_consonants;
					break;
				}
		if (text[i + 1] == '\0')
		{
			if (count_consonants > max_word)
			{
				max_word = count_consonants;
				mass_pos[0] = i + 1;
				kolvo_pos = 0;
			}
			else if (count_consonants == max_word)
			{
				++kolvo_pos;
				mass_pos[kolvo_pos] = i + 1;
			}
		}
	}

	char word[max];
	int kol = 0;
	for (int i = mass_pos[kolvo_pos] - 1; i >= 0; --i)
	{
		flag = true;
		for (int j = 0; separators[j]; ++j)
			if (text[i] == separators[j])
				flag = false;
		if (flag)
			word[kol++] = text[i];
		else
		{
			word[kol++] = ' ';
			--kolvo_pos;
			i = mass_pos[kolvo_pos];
		}
	}
	word[kol] = '\0';

	for (int i = strlen(word) - 1; i >= 0; --i)
		cout << word[i];


	return 0;
}