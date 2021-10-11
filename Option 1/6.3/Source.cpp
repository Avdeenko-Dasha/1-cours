//Написать программу для работы с базой данных, содержащей записи со
//сведениями о студентах : ФИО, возраст, курс, успеваемость, в которой
//должны выполняться следующие действия :
//• создание файла
//• просмотр файла
//Выполнить задания для текстового и бинарного файлов.
//1. По исходному файлу определить ФИО самого младшего студента на каждом курсе. Сформировать файл из этих студентов.
#include "Header.h"

int main()
{
    const int n = 5;
    bd group[n] = { };

    ofstream f_vvod("text_f.txt");//создать объект для записи данных в файл
    ofstream f_vvod_bin("text_f.bin");

    if (!f_vvod.is_open())
    {
        cout << "Error 1";
    }
    else if (!f_vvod_bin.is_open())
    {
        cout << "Error 2";
    }
    else
    {
        cout << "Reading is successfully" << endl;//Создание исходного файла
        for (int i = 0; i < n; ++i)
        {
            group[i].nom = i + 1;
            f_vvod << group[i].nom << ". ";

            cout << "Full Name: ";
            cin.getline(group[i].fio, '\n');
            f_vvod << group[i].fio << " ";

            cout << "Age: ";
            cin >> group[i].age;
            f_vvod << group[i].age << " ";

            cout << "Kurs: ";
            cin >> group[i].kurs;
            f_vvod << group[i].kurs << " ";

            cout << "Academic performance: ";
            cin >> group[i].s_ball;
            f_vvod << group[i].s_ball << "\n";
            
            cout << endl;
            cin.get();
        }
        f_vvod_bin.write(reinterpret_cast<char*>(group), sizeof(bd)*n);
        f_vvod.close();
        f_vvod_bin.close();
    }
    output(group, n);

    ofstream file("text.txt");
    ofstream file_bin("text.bin");
    int age = 0;
    if (!file.is_open())
    {
        cout << "Error 2";
    }
    else
    {
        cout << "Reading is successfully" << endl;
        int odin_kurs = 1;
        while (odin_kurs < 5)
        {
            int k = 0;
            int* age_st = new int[n];
            for (int i = 0; i < n; ++i)//0 kurs 1  age 10
            {
                if (group[i].kurs == odin_kurs)
                {
                    age_st[k] = group[i].age;
                    k++;
                }
            }
            int x = 0;
            for (int i = 0; i < k; i++) // i - номер прохода
            {
                for (int j = k - 1; j > i; j--) // внутренний цикл прохода
                {
                    if (age_st[j - 1] > age_st[j])
                    {
                        x = age_st[j - 1];
                        age_st[j - 1] = age_st[j];
                        age_st[j] = x;
                    }
                }
            }
            age = age_st[0];

            for (int i = 0; i < n; ++i)
            {
                if (group[i].kurs == odin_kurs && group[i].age == age)
                {
                    file << group[i].fio;
                    file << "\n";
                    file_bin.write(reinterpret_cast<char*>(&group[i].fio), sizeof(group[i].fio));
                }
            }
            delete [] age_st;
            odin_kurs++;
        }
        file.close();
        file_bin.close();
    }
    return 0;
}