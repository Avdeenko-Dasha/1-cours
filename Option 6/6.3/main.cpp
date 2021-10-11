#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct student
{
	int number = 0;
	string fio;
	bool sex = 0;// 0 женщина 1 мужчина
	int age = 0;
	int kurs = 0;
	double ball = 0;
};

void enter_data_txt(ofstream& file_cin, int n, student* group1)
{
	for (int i = 0; i < n; ++i)
	{
		file_cin << group1[i].number << '\n';
		file_cin << group1[i].fio << '\n';
		file_cin << group1[i].sex << '\n';
		file_cin << group1[i].age << '\n';
		file_cin << group1[i].kurs << '\n';
		file_cin << group1[i].ball << '\n';
		file_cin << '\n';
	}
}
int functiom_for_txt(ofstream& file_finish, int n, student* group)
{
	int size = 0;
	for (int i = 0; i < n; ++i)
		if (group[i].ball >= 9)
		{
			file_finish << group[i].number << '\n';
			file_finish << group[i].fio << '\n';
			file_finish << group[i].sex << '\n';
			file_finish << group[i].age << '\n';
			file_finish << group[i].kurs << '\n';
			file_finish << group[i].ball << '\n';
			file_finish << '\n';
			size++;
		}
	return size;
}
void print_for_txt(ifstream& file_cout, int n)
{
	student* group = new student[n];
	for (int i = 0; i < n; ++i)
	{
		file_cout >> group[i].number;
		getline(file_cout, group[i].fio);
		getline(file_cout, group[i].fio);
		file_cout >> group[i].sex;
		file_cout >> group[i].age;
		file_cout >> group[i].kurs;
		file_cout >> group[i].ball;
	}
	for (int i = 0; i < n; ++i)
	{
		cout << "Number: " << group[i].number;
		cout << "\nFIO: " << group[i].fio;
		cout << "\nSex: " << group[i].sex;
		cout << "\nAge: " << group[i].age;
		cout << "\nKurs: " << group[i].kurs;
		cout << "\nBall: " << group[i].ball;
	}
}

void for_txt(int n, student* group)
{
	
	ofstream file_cin;
	file_cin.open("File.txt");
	if (!file_cin.is_open())
		cout << "Error 1";
	else
		enter_data_txt(file_cin, n, group);
	file_cin.close();

	ifstream file_cout;
	file_cout.open("File.txt");
	if (!file_cout.is_open())
		cout << "Error 2";
	else
		for (int i = 0; i < n; ++i)
		{
			file_cout >> group[i].number;
			getline(file_cout, group[i].fio);
			getline(file_cout, group[i].fio);
			file_cout >> group[i].sex;
			file_cout >> group[i].age;
			file_cout >> group[i].kurs;
			file_cout >> group[i].ball;
		}
    file_cout.close();

	int x = 0;
	ofstream file_finish;
	file_finish.open("File_end.txt");
	if (!file_finish.is_open())
		cout << "Error 3";
	else
		x = functiom_for_txt(file_finish, n, group);
	file_finish.close();

	ifstream file_final;
	file_final.open("File_end.txt");
	if (!file_final.is_open())
		cout << "Error 4";
	else
		print_for_txt(file_final, x);
	file_final.close();
}


void enter_data_bin(ofstream& file_cin, int n, student* group)
{
	for (int i = 0; i < n; ++i)
	{
		file_cin.write(reinterpret_cast <char*>(&group[i].number), sizeof(int));
		file_cin.write(reinterpret_cast <char*>(&group[i].fio), sizeof(string));
		file_cin.write(reinterpret_cast <char*>(&group[i].sex), sizeof(bool));
		file_cin.write(reinterpret_cast <char*>(&group[i].age), sizeof(int));
		file_cin.write(reinterpret_cast <char*>(&group[i].kurs), sizeof(int));
		file_cin.write(reinterpret_cast <char*>(&group[i].ball), sizeof(double));
	}
}
int functiom_for_bin(ofstream& file_cin, int n, student* group)
{
	int size = 0;
	for (int i = 0; i < n; ++i)
		if (group[i].ball >= 9)
		{
			file_cin.write(reinterpret_cast <char*>(&group[i].number), sizeof(int));
			file_cin.write(reinterpret_cast <char*>(&group[i].fio), sizeof(string));
			file_cin.write(reinterpret_cast <char*>(&group[i].sex), sizeof(bool));
			file_cin.write(reinterpret_cast <char*>(&group[i].age), sizeof(int));
			file_cin.write(reinterpret_cast <char*>(&group[i].kurs), sizeof(int));
			file_cin.write(reinterpret_cast <char*>(&group[i].ball), sizeof(double));
			size++;
		}
	return size;
}
void print_for_bin(ifstream& file_cout, int n)
{
	student* group = new student[n];
	for (int i = 0; i < n; ++i)
	{
		file_cout.read(reinterpret_cast <char*>(&group[i].number), sizeof(int));
		file_cout.read(reinterpret_cast <char*>(&group[i].fio), sizeof(string));
		file_cout.read(reinterpret_cast <char*>(&group[i].sex), sizeof(bool));
		file_cout.read(reinterpret_cast <char*>(&group[i].age), sizeof(int));
		file_cout.read(reinterpret_cast <char*>(&group[i].kurs), sizeof(int));
		file_cout.read(reinterpret_cast <char*>(&group[i].ball), sizeof(double));
	}
	for (int i = 0; i < n; ++i)
	{
		cout << "Number: " << group[i].number;
		cout << "\nFIO: " << group[i].fio;
		cout << "\nSex: " << group[i].sex;
		cout << "\nAge: " << group[i].age;
		cout << "\nKurs: " << group[i].kurs;
		cout << "\nBall: " << group[i].ball;
	}
}

void for_bin(int n, student* group)
{

	ofstream file_cin;
	file_cin.open("File.bin", ios::binary);
	if (!file_cin.is_open())
		cout << "Error 1";
	else
		enter_data_bin(file_cin, n, group);
	file_cin.close();

	ifstream file_cout;
	file_cout.open("File.bin", ios::binary);
	if (!file_cout.is_open())
		cout << "Error 2";
	else
		for (int i = 0; i < n; ++i)
		{
			file_cout.read(reinterpret_cast <char*>(&group[i].number), sizeof(int));
			file_cout.read(reinterpret_cast <char*>(&group[i].fio), sizeof(string));
			file_cout.read(reinterpret_cast <char*>(&group[i].sex), sizeof(bool));
			file_cout.read(reinterpret_cast <char*>(&group[i].age), sizeof(int));
			file_cout.read(reinterpret_cast <char*>(&group[i].kurs), sizeof(int));
			file_cout.read(reinterpret_cast <char*>(&group[i].ball), sizeof(double));
		}
	file_cout.close();

	int x = 0;
	ofstream file_finish;
	file_finish.open("File_end.bin", ios::binary);
	if (!file_finish.is_open())
		cout << "Error 3";
	else
		x = functiom_for_bin(file_finish, n, group);
	file_finish.close();

	ifstream file_final;
	file_final.open("File_end.bin", ios::binary);
	if (!file_final.is_open())
		cout << "Error 4";
	else
		print_for_bin(file_final, x);
	file_final.close();
}

int main()
{
	cout << "Number of students: ";
	int n = 2;
	cin >> n;
	student* group1 = new student[n];
	for (int i = 0; i < n; ++i)
	{
		cout << "Student number - " << i + 1;
		group1[i].number = i + 1;
		cout << "\nSex (0 - woman, 1 - man): ";
		cin >> group1[i].sex;
		cout << "Age: ";
		cin >> group1[i].age;
		cout << "Kurs: ";
		cin >> group1[i].kurs;
		cout << "Ball: ";
		cin >> group1[i].ball;
		cout << "FIO: ";
		getline(cin, group1[i].fio);
		getline(cin, group1[i].fio);
	}

	cout << "\nFor txt: \n";
	for_txt(n, group1);
	cout << "\n\n\nFor bin: \n";
	for_bin(n, group1);

	return 0;
	
}