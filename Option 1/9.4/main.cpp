#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <vector>
#include <set>

//Дана программа на С++.Проанализировать программу за один просмотр и
//записать в выходной файл построчно :
//1. все ключевые слова, встречающиеся в этой программе, указав количество появлений для каждого ключевого слова 

using namespace std;

bool is_keyword(string word)//база данных
{
    string keyw_path = "D:\\Учеба\\Прога\\Лабы\\9. БИБЛИОТЕКА ШАБЛОНОВ STL\\9.4\\key_words.txt";//все ключевые слова в этом файле
    ifstream fin(keyw_path);//открываем наш файл
    string line;
    while (getline(fin, line))//считываем содержимое файла в переменную лайн
    {
        if (word == line)//если слово которое мы передаем есть в базе то возвращаем тру
        {
            fin.close();
            return true;
        }
    }
    fin.close();
    return false;
}

bool is_alpha(char symbol)//ограничили слова только буквами
{
    return 'a' <= symbol && symbol <= 'z';
}

int main()
{
    string directory= "main.cpp";//мы в строчку заносим путь к файлу, который мы будем читать
    ifstream fin(directory);//открываем файл по этому пути
    string line;//строчка лайн будет содержать все содержимое файла
    map<string, vector<int>> keywords;//для хранения совпадающих слов
    int line_num = 0;//счетчик для занесения слов
    while (getline(fin, line))//пока не закончится наш файл
    {
        line_num++;
        int start = 0;//точка начала чтения файла, чтобы не считытвать слова заново
        bool is_word = false;//флажок для поиска места остановки
        for (int i = 0; i < line.length(); i++)//по всей длине файла
        {
            if (!is_word && is_alpha(line[i]))//если наше слово есть
            {
                is_word = true;//флажок поднимается
                start = i;//устанавливаем позицию
            }
            else if (is_word && !is_alpha(line[i]))//если слова нет
            {
                is_word = false;//флажок опускаем
                string word = string(line.begin() + start, line.begin() + i);//сравниваем с базой данных
                if (is_keyword(word))//если такое слово есть то добавляем его в наш массив
                {
                    keywords[word].push_back(line_num);//занесение слова
                }
            }
        }
    }
    fin.close();

    for (auto keyword : keywords)//вывод пока кейвордс не закончится
    {
        cout << "  \"" << keyword.first << "\": " << keyword.second.size();
        cout << endl;
    }

    return 0;
}