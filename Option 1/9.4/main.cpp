#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <vector>
#include <set>

//���� ��������� �� �++.���������������� ��������� �� ���� �������� �
//�������� � �������� ���� ��������� :
//1. ��� �������� �����, ������������� � ���� ���������, ������ ���������� ��������� ��� ������� ��������� ����� 

using namespace std;

bool is_keyword(string word)//���� ������
{
    string keyw_path = "D:\\�����\\�����\\����\\9. ���������� �������� STL\\9.4\\key_words.txt";//��� �������� ����� � ���� �����
    ifstream fin(keyw_path);//��������� ��� ����
    string line;
    while (getline(fin, line))//��������� ���������� ����� � ���������� ����
    {
        if (word == line)//���� ����� ������� �� �������� ���� � ���� �� ���������� ���
        {
            fin.close();
            return true;
        }
    }
    fin.close();
    return false;
}

bool is_alpha(char symbol)//���������� ����� ������ �������
{
    return 'a' <= symbol && symbol <= 'z';
}

int main()
{
    string directory= "main.cpp";//�� � ������� ������� ���� � �����, ������� �� ����� ������
    ifstream fin(directory);//��������� ���� �� ����� ����
    string line;//������� ���� ����� ��������� ��� ���������� �����
    map<string, vector<int>> keywords;//��� �������� ����������� ����
    int line_num = 0;//������� ��� ��������� ����
    while (getline(fin, line))//���� �� ���������� ��� ����
    {
        line_num++;
        int start = 0;//����� ������ ������ �����, ����� �� ���������� ����� ������
        bool is_word = false;//������ ��� ������ ����� ���������
        for (int i = 0; i < line.length(); i++)//�� ���� ����� �����
        {
            if (!is_word && is_alpha(line[i]))//���� ���� ����� ����
            {
                is_word = true;//������ �����������
                start = i;//������������� �������
            }
            else if (is_word && !is_alpha(line[i]))//���� ����� ���
            {
                is_word = false;//������ ��������
                string word = string(line.begin() + start, line.begin() + i);//���������� � ����� ������
                if (is_keyword(word))//���� ����� ����� ���� �� ��������� ��� � ��� ������
                {
                    keywords[word].push_back(line_num);//��������� �����
                }
            }
        }
    }
    fin.close();

    for (auto keyword : keywords)//����� ���� �������� �� ����������
    {
        cout << "  \"" << keyword.first << "\": " << keyword.second.size();
        cout << endl;
    }

    return 0;
}