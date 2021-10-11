#include "Header.h"
#include <string>
using namespace std;

int main()
{
    string str1;
    cout << "4.1 Enter a rim. number ";
    getline(cin, str1);
    chislo(str1);
    
    string chislo_2ss = ("0");
    cout << "4.2 Enter number in 2 ss ";
    getline(cin, chislo_2ss);
    perevod(chislo_2ss);
   
    string st;
    string t = " ;//.,?!;:()-";
    cout << "4.3 Enter the string ";
    getline(cin, st);
    stroka(st, t);
    return(0);
}
