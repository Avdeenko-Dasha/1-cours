//��� ������ ����� �����, ���������� n ���������.
//��� ������������ ������������� ����������� �������� �������� ������� ��������� �������: ��� �������� � ��������������,
//����������� �������� (� ��� ����� ���������), ��� ������ ����������� ��������. 
//1. �������� ��� ���������� ��������, ������������� � ������� ����� ������ ����. 
#include <iostream>  
#include <limits.h>

using namespace std;
int main()
{
    setlocale(0, "rus");
    const int m = 10000;
    int a[m] = { 0 };
    int b[m] = { 0 };
    int n = 0;
    cout << "������� ���������� ��������� ������� " << endl;
    cin >> n;
    cout << "������� �������� �������" << endl;
    for (int i = 0; i < n; i++)
        cin >> a[i];

    int k = 0;
    for (int i = 0; i < n; i++)
        for (int z = i + 1; z < n; z++)
            if (a[i] == a[z])
            {
                bool flag = false;
                for (int j = 0; j < k; j++)
                {
                    if (a[i] == b[j])
                    {
                        flag = true;
                        break;
                    }
                }

                if (flag == false)
                {
                    b[k] = a[i];
                    cout << b[k] << " ";
                    k++;
                }
            }
    return 0;
}//1 2 3 11 3 1 1 1 4 5