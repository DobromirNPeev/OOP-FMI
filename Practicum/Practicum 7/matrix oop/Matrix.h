#pragma once

#include <iostream>
class Matrix
{
	int** matrix=nullptr;
	size_t row=0;
	size_t column=0;
	void copyFrom(const Matrix& other);
	void free();
	void moveFrom(Matrix&& other);
public:
	Matrix();
	Matrix(const Matrix& other);
	Matrix& operator=(const Matrix& other);
	~Matrix();

	Matrix(Matrix&& other);
	Matrix& operator=(Matrix&& other);
	Matrix(size_t row, size_t column);
	size_t getRow() const;
	size_t getColumns() const;
	int** getMatrix() const;
	Matrix& operator+=(const Matrix& other);
	Matrix& operator-=(const Matrix& other);
	Matrix& operator*=(const Matrix& other);
	Matrix& operator*=(int scalar);
	int* operator[](int ind) const;
	int*& operator[](int ind);
	friend std::ostream& operator<<(std::ostream& os, const Matrix& mtr);
};
Matrix operator+(const Matrix& lhs,const Matrix& rhs);
Matrix operator-(const Matrix& lhs, const Matrix& rhs);
Matrix operator*(const Matrix& lhs, const Matrix& rhs);
Matrix operator*(const Matrix& mtr,int scalar);
bool operator==(const Matrix& lhs, const Matrix& rhs);
bool operator!=(const Matrix& lhs, const Matrix& rhs);
std::ostream& operator<<(std::ostream& os, const Matrix& mtr);