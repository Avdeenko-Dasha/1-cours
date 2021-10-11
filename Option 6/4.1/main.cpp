#include <iostream>

using namespace std;

int main()
{
	const int MAX = 100;
	char text[MAX];
	char str[MAX];
	//cin >> text;
	//cout << text;
	cin.getline(text, MAX);

	char simbol;
	unsigned int k = 0;
	int count;

	for (int i = 0; text[i]; ++i)
	{
		simbol = text[i];
		if (simbol == ' ')
			str[k++] = simbol;
		else
		{
			count = 0;
			for (int j = 0; text[j]; ++j)
				if (text[j] == simbol)
					++count;
			if (count <= 2)
				str[k++] = simbol;
		}
	}
	str[k] = '\0';
	cout << str;
}