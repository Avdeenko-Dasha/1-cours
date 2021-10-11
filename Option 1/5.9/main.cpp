#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <iostream>

using namespace std;

const int BS = 8;
bool board[BS][BS], a[8];
int h = 0;

void print_board()//Вывод расстановки
{
    h++;
    //cout << endl;
    //for (int i = 0; i < BS; i++)
    //{
    //    for (int j = 0; j < BS; j++)
    //        if (board[i][j])
    //            cout << "1" << " ";//вывод позиции, где есть ладья
    //        else
    //            cout << "0" << " ";//вывод позиции без ладьи
    //    cout << endl;
    //}

}

void find_positioning(int ii)//рекурсивная функция определения расстановки, вызывающая ее вывод на экран
{
    if (ii == 8)//во всех строках есть ладья
    {
        print_board();//вызываем функцию вывода
        return;
    }
    for (int i = 0; i < BS; i++)//идем по всей доске
        if (!a[i])//если в строке нет ладьи то фходим в иф
        {
            a[i] = true;//ставим ладью в строчку
            board[ii][i] = true;//определяем её координаты
            find_positioning(ii + 1);//обрабатываем все строки
            board[ii][i] = false;//меняем расположение ладьи на следующее возможное
            a[i] = false;//убираем ладью из прошлого места
        }
}

int main()
{
    find_positioning(0);
    cout << h;
    return 0;
}