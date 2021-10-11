/*Выполнить следующее задание для заданного текста. Оформить задание в виде набора функций:
функция выделение слова (лексемы), функция создания массива слов, функция получения результирующей строки.*/
#include <iostream>
#include <iomanip>
using namespace std;
void add_word(char* str, char** arr);
void arr_word(char*str, char** arr, int i);
void the_end(char** arr, char* result);
int main()
{
    char arr[127][255] = { 0 };
    char result[255] = { 0 };
    char* p_arr[127] = { NULL };
    for (int i = 0 ; i < 127; i++)
        p_arr[i] = arr[i];
    
    char str[255] = { 0 };
    cin.getline(str, 255, '\n');
    add_word(str, p_arr);
    the_end(p_arr, result);
    cout << result;
    return 0;
}
void add_word(char* str, char** arr)
{
    char word[255] = { 0 };
    char separator[] = " ,.?!;:()";
    int k = 0;
    int i1 = 0;
    for (int i = 0; str[i]; i++)
    {
        bool flag = 0;
        for (int j = 0; separator[j]; j++)
            if (str[i] == separator[j])  flag = 1;
        
        if (flag == 0)
        {
            word[k] = str[i];
            k++;
        }
        else
        {
            word[k] = '\0';
            arr_word(word, arr, i1);
            k = 0;
            i1++;
            for (int k = 0; word[k]; k++)
                word[k] = '\0';
        }
    }
    word[k] = '\0';
    arr_word(word, arr, i1);
}
void arr_word(char* word, char** arr, int i)
{
    for (int j = 0; word[j]; j++)
        arr[i][j] = word[j];
    
    if (++i < 127) arr[i][0] = '\0';
}
void the_end(char** arr, char* result)
{
    int l = 0;
    for (int i = 0; arr[i + 1][0]; i++)
        for (int j = i + 1; arr[j][0]; j++)
        {
            bool flag = 1;
            int k_j = strlen(arr[j]) - 1;//0
            for (int k_i = 0; arr[i][k_i] && flag == 1; k_i++)
            {
                if (arr[j][k_j] != arr[i][k_i])
                    flag = 0;
                k_j--;
            }
            if (flag == 1)
            {
                
                for (int k_i = 0; arr[i][k_i]; k_i++)
                {
                    result[l] = arr[i][k_i];
                    l++;
                }
                result[l] = ' ';
                l++;
                for (int k_j = 0; arr[j][k_j]; k_j++)
                {
                    result[l] = arr[j][k_j];
                    l++;
                }
                result[l] = ' ';
                l++;
            }
        }
}
