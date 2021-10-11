#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;
void foo(char* r, int size);
void str_del(char* str, int pos, int n, int size);
int main()
{
    //setlocale(0, "rus");
    char s[255];
    cin.getline(s, 255, '\n');
    int size = strlen(s);
    foo(s, size);
    cout << s;
}
void foo(char*r, int size)
{
    int n = strlen(r);
    if(n > 2)
    for (int i = 2; r[i] != 0; i++)
    {
        
        if (r[i] == r[i - 1] && r[i] == r[i-2])
        {
            str_del(r, i-2, 3, size);
            i = (2 > i - 2) ? 1 : i - 3;
            n -= 3;
        }
        if (n < 3) break;
    }
    
}
void str_del(char* str, int pos, int n, int size)
{
    for (int i = pos; i<pos+n; i++)
    {  
        if (str[i] == 0)
        {
            str[pos] = 0;
            return;
        }
    }
    int i;
    if (pos < size)
    {
        for (i = pos + n; str[i] != 0; i++)
        {
            str[i - n] = str[i];
        }
        str[i - n] = 0;
    }
}
