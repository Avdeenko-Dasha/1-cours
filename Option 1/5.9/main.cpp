#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <iostream>

using namespace std;

const int BS = 8;
bool board[BS][BS], a[8];
int h = 0;

void print_board()//����� �����������
{
    h++;
    //cout << endl;
    //for (int i = 0; i < BS; i++)
    //{
    //    for (int j = 0; j < BS; j++)
    //        if (board[i][j])
    //            cout << "1" << " ";//����� �������, ��� ���� �����
    //        else
    //            cout << "0" << " ";//����� ������� ��� �����
    //    cout << endl;
    //}

}

void find_positioning(int ii)//����������� ������� ����������� �����������, ���������� �� ����� �� �����
{
    if (ii == 8)//�� ���� ������� ���� �����
    {
        print_board();//�������� ������� ������
        return;
    }
    for (int i = 0; i < BS; i++)//���� �� ���� �����
        if (!a[i])//���� � ������ ��� ����� �� ������ � ��
        {
            a[i] = true;//������ ����� � �������
            board[ii][i] = true;//���������� � ����������
            find_positioning(ii + 1);//������������ ��� ������
            board[ii][i] = false;//������ ������������ ����� �� ��������� ���������
            a[i] = false;//������� ����� �� �������� �����
        }
}

int main()
{
    find_positioning(0);
    cout << h;
    return 0;
}