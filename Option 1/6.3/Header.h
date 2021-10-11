#pragma once
#include <iostream>
#include <iomanip>
#include <fstream>
#include <conio.h>

using namespace std;

struct bd
{
    int nom;
    char fio[60];
    int age;
    int kurs;
    double s_ball;
};


void output(const bd group[], int n)
{
    for (int i = 0; i < n; ++i)
    {
        cout << group[i].nom << " ";
        cout << "Full Name " << group[i].fio << " Age " << group[i].age << " Kurs " << group[i].kurs;
        cout << " Academic performance: " << group[i].s_ball << endl;
    }
}