#pragma once
#include "vector.h"
class Matrix
{
	int row;
	int col;
	vector<double>* matrix;

	int id;
	static int number;

public:
	Matrix() : row(0), col(0), matrix(nullptr)
	{
		id = ++number;
	}
	Matrix(int m, int n)
	{
		id = ++number;
		row = m;
		col = n;
		matrix = new vector<double>[row];
		for (int i = 0; i < row; i++)
			matrix[i].assign(col);
	}
	Matrix(int m, int n, double value)
	{
		id = ++number;
		row = m;
		col = n;
		matrix = new vector<double>[row];
		for (int i = 0; i < row; ++i)
			matrix[i].assign(col, value);
	}
	Matrix(Matrix& other)
	{
		id = ++number;
		row = other.row;
		col = other.col;
		matrix = new vector<double>[row];
		for (int i = 0; i < row; i++)
			matrix[i].assign(col);

		for (int i = 0; i < row; ++i)
			for (int j = 0; j < col; ++j)
				matrix[i][j] = other.matrix[i][j];
	}

	void Print()
	{
		cout << "Matrix " << id << endl;
		for (int i = 0; i < row; ++i)
		{
			for (int j = 0; j < col; ++j)
				cout << matrix[i][j] << " ";
			cout << endl;
		}
		cout << endl;
	}
	void random()
	{
		for (int i = 0; i < row; ++i)
			for (int j = 0; j < col; ++j)
				matrix[i][j] = rand() % 100 / 10.0;
	}
	void resize(int rows, int columns)
	{
		auto* new_vector = new vector<double>[rows];
		for (int i = 0; i < rows; i++)
			new_vector[i].assign(columns);
		int min_r = rows <= this->row ? rows : this->row;
		int min_c = columns <= this->col ? columns : this->col;
		for (int i = 0; i < min_r; i++)
		{
			for (int j = 0; j < min_c; j++)
			{
				new_vector[i][j] = matrix[i][j];
			}
		}
		if (rows > min_r)
		{
			for (int i = min_r; i < rows; i++)
			{
				for (int j = 0; j < min_c; j++)
				{
					new_vector[i][j] = 0;
				}
			}
		}
		if (columns > min_c)
		{
			for (int j = min_c; j < columns; j++)
			{
				for (int i = 0; i < min_r; i++)
				{
					new_vector[i][j] = 0;
				}
			}
		}
		this->row = rows;
		this->col = columns;
		delete[] matrix;
		matrix = new_vector;
	}

	Matrix operator+(const Matrix& other)
	{
		if (row != other.row || col != other.col)
			throw invalid_argument("Error");

		//number--;
		Matrix temp(*this);
		for (int i = 0; i < row; i++)
			for (int j = 0; j < col; j++)
				temp.matrix[i][j] += other.matrix[i][j];

		return temp;
	}
	Matrix operator-(const Matrix& other)
	{
		if (row != other.row || col != other.col)
			throw invalid_argument("Error");

		//number--;
		Matrix temp(*this);
		for (int i = 0; i < row; i++)
			for (int j = 0; j < col; j++)
				temp.matrix[i][j] -= other.matrix[i][j];
		return temp;
	}
	Matrix operator*(const Matrix& other)
	{
		if (col != other.row)
			throw invalid_argument("Error");

		//number--;
		Matrix temp(row, other.col);
		for (int i = 0; i < row; i++)
			for (int j = 0; j < other.col; j++)
				for (int k = 0; k < col; k++)
					temp.matrix[i][j] += matrix[i][k] * other.matrix[k][j];

		return temp;
	}

	Matrix& operator =(const Matrix& other)
	{
		row = other.row;
		col = other.col;
		delete[] matrix;
		matrix = new vector<double>[row];
		for (int i = 0; i < row; ++i)
			matrix[i].assign(col);
		for (int i = 0; i < row; ++i)
			for (int j = 0; j < col; ++j)
				matrix[i][j] = other.matrix[i][j];
		return *this;
	}
	vector<double>& operator[](unsigned int index)
	{
		if (index >= row)
			throw invalid_argument("bad index");
		return matrix[index];
	}

	friend ostream& operator<<(ostream& out, const Matrix& other);

	friend istream& operator>>(istream& in, Matrix& other);

	~Matrix()
	{
		--number;
		//delete[] matrix;
	}

};

int Matrix::number = 0;

istream& operator>>(istream& in, Matrix& other)
{
	for (int i = 0; i < other.row; i++)
	{
		cout << "Enter " << other.col << " values of " << i << " rows: ";
		for (int j = 0; j < other.col; j++)
			in >> other.matrix[i][j];
		cout << endl;
	}
	cout << endl;
	return in;
}

ostream& operator<<(ostream& out, const Matrix& other) {
	out << "Matrix " << other.id << endl;
	for (int i = 0; i < other.row; i++)
	{
		for (int j = 0; j < other.col; j++)
			out << other.matrix[i][j] << " ";
		out << endl;
	}
	return out;
}
