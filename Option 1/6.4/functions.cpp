#include "Header.h"

void draw_line(int n) 
{
    for (int i = 0; i < n; ++i) 
    {
        cout << "-";
    }
    cout << endl;
}

void generateData(FloatUnion& st)
{
    st.numData.mantissa = rand() % 8388607; // 2^23
    st.numData.order = rand() % 256; // 2^8
    st.numData.sign = rand() % 2; // 2^1
}

void output(FloatUnion& st) 
{
    cout.width(widthNum); cout << st.num;
    cout.width(widthSign); cout << st.numData.sign;
    cout.width(widthOrder); cout << st.numData.order;
    cout.width(widthMant); cout << st.numData.mantissa << endl;
}

bool compNum(FloatUnion& number1, FloatUnion& number2)
{
    return number1.num < number2.num;
}
