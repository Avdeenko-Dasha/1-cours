/*. Получить текст, в котором слова исходного текста упорядочены по длине слов.*/
/*функция выделение слова (лексемы), 
функция создания массива слов, 
функция получения результирующей строки.*/
#include <iostream>

using namespace std;

void words(char* text, char* word, int pos)
{
	
	char separators[] = " .,:;!?-()";
	int i = 0;
	bool flag = true;
	for (int j = pos; text[j]; ++j)
	{
		flag = true;
		for (int k = 0; separators[k]; ++k)
			if (text[j] == separators[k])
			{
				flag = false;
				break;
			}
		if (flag)
			word[i++] = text[j];
		else break;
	}
	word[i] = '\0';
}
int create_array(char** array, char* word, char* text)
{
	int pos = 0;
	int count = 1;
	char separators[] = " .,:;!?-()";
	for (int i = 0; text[i]; ++i)
		for (int j = 0; separators[j]; ++j)
			if (text[i] == separators[j])
			{
				++count;
				break;
			}
	for (int i = 0; i < count; ++i)
	{
		words(text, word, pos);
		pos += strlen(word) + 1;
		for (int j = 0; word[j]; ++j)
			array[i][j] = word[j];
		array[i][strlen(word)] = '\0';
	}
	return count;
}
void create_stroka(char* text, char** array, int n)
{
	text[0] = '\0';
	int k = 0;
	int count = n;

	while (count)
	{
		int max_size = 0;
		int pos = 0;
		for (int i = 0; i < n; ++i)
			if (strlen(array[i]) > max_size)
			{
				max_size = strlen(array[i]);
				pos = i;
			}
		for (int j = 0; array[pos][j]; ++j)
			text[k++] = array[pos][j];
		text[k++] = ' ';
		array[pos][0] = '\0';
		count--;
	}

	text[k] = '\0';
}


int main()
{
	char text[100];
	cout << "Text: ";
	cin.getline(text, 100);
	char word[100];
	char** array = new char* [100];
	for (int i = 0; i < 100; ++i)
		array[i] = new char[100];
	int n = create_array(array, word, text);
	create_stroka(text, array, n);
	cout << text;
	return 0;
}