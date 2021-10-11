#pragma once
#include <iostream>
#include <ctime>
#include <iomanip>
#include <algorithm>
using namespace std;

enum WidthValues
{
    widthNum = 18,
    widthSign = 8,
    widthOrder = 10,
    widthMant = 12,
    widthLine = 44,
};

union FloatUnion 
{
    float num; 
    struct InNumber 
    {
        unsigned long long mantissa : 23;
        unsigned long long order : 8;
        unsigned long long sign : 1;
    }numData;
};

void draw_line(int n);

void generateData(FloatUnion& st);
void output(FloatUnion& st);

bool compNum(FloatUnion& number1, FloatUnion& number2);

