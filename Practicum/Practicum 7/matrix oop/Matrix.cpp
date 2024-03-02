#include "Matrix.h"

void Matrix::copyFrom(const Matrix& other) {

	row = other.row;
	column = other.column;
	matrix = new int* [row];
	for (size_t i = 0; i < row; i++)
	{
		matrix[i] = new int[column] {0};
	}
	for (size_t i = 0; i < row; i++)
	{
		for (size_t j = 0; j < column; j++)
		{
			matrix[i][j] = other.matrix[i][j];
		}

	}
}
void Matrix::free() {
	for (size_t i = 0; i < row; i++)
	{
		delete[] matrix[i];
	}
	delete[] matrix;
}
void Matrix::moveFrom(Matrix&& other) {
	matrix = other.matrix;
	row = other.row;
	column = other.column;
	other.matrix = nullptr;
	other.row = other.column = 0;
}
Matrix::Matrix() {
	row = column = 2;
	matrix = new int* [2];
	for (size_t i = 0; i < row; i++)
	{
		matrix[i] = new int[2] {0};
	}
}
Matrix::Matrix(const Matrix& other) {
	copyFrom(other);
}
Matrix& Matrix::operator=(const Matrix& other) {
	if (this != &other) {
		free();
		copyFrom(other);
	}
	return *this;
}
Matrix::~Matrix() {
	free();
}

Matrix::Matrix(Matrix&& other) {
	moveFrom(std::move(other));
}
Matrix& Matrix::operator=(Matrix&& other) {
	if (this != &other) {
		free();
		moveFrom(std::move(other));
	}
	return *this;
}
Matrix::Matrix(size_t row, size_t column):row(row),column(column) {
	matrix = new int* [row];
	for (size_t i = 0; i < row; i++)
	{
		matrix[i] = new int[column] {0};
	}
}
size_t Matrix::getRow() const
{
	return row;
}
size_t Matrix::getColumns() const
{
	return column;
}
int** Matrix::getMatrix() const
{
	return matrix;
}
Matrix& Matrix::operator+=(const Matrix& other) {
	if (row != other.row && column != other.column) {
		throw std::invalid_argument("Different size of matrices");
	}
	for (size_t i = 0; i < row; i++)
	{
		for (size_t j = 0; j < column; j++)
		{
			matrix[i][j] += other.matrix[i][j];
		}
	}
	return *this;
}
Matrix& Matrix::operator-=(const Matrix& other) {
	if (row != other.row && column != other.column) {
		throw std::invalid_argument("Different size of matrices");
	}
	for (size_t i = 0; i < row; i++)
	{
		for (size_t j = 0; j < column; j++)
		{
			matrix[i][j] -= other.matrix[i][j];
		}
	}
	return *this;
}
std::ostream& operator<<(std::ostream& os, const Matrix& mtr) {
	for (size_t i = 0; i < mtr.row; i++)
	{
		for (size_t j = 0; j < mtr.column; j++)
		{
			os << mtr.matrix[i][j] << " ";
		}
		os << std::endl;
	}
	std::cout << std::endl;
	return os;
}
Matrix& Matrix::operator*=(const Matrix& other) {
	if (column != other.row) {
		throw std::invalid_argument("Different size of matrices");
	}
	int rows1 = row;
	int cols1 = column;
	int cols2 = other.column;
	Matrix newMatrix(row, other.column);
	for (int i = 0; i < rows1; i++) {
		for (int j = 0; j < cols2; j++) {
			for (int k = 0; k < cols1; k++) {
				newMatrix.matrix[i][j] += matrix[i][k] * other.matrix[k][j];
			}
		}
	}
	*this = std::move(newMatrix);
	return *this;

}
Matrix& Matrix::operator*=(int scalar) {
	for (size_t i = 0; i < row; i++)
	{
		for (size_t j = 0; j < column; j++)
		{
			matrix[i][j] *= scalar;
		}
	}
	return *this;
}
Matrix operator+(const Matrix& lhs, const Matrix& rhs) {
	Matrix result(lhs);
	result += rhs;
	return result;
}
Matrix operator-(const Matrix& lhs, const Matrix& rhs) {
	Matrix result(lhs);
	result -= rhs;
	return result;
}
Matrix operator*(const Matrix& lhs, const Matrix& rhs) {
	Matrix result(lhs);
	result *= rhs;
	return result;
}
Matrix operator*(const Matrix& mtr, int scalar) {
	Matrix result(mtr);
	result *= scalar;
	return result;
}
bool operator==(const Matrix& lhs, const Matrix& rhs) {
	if (lhs.getRow() != rhs.getRow() && lhs.getColumns() != rhs.getColumns()) {
		throw std::invalid_argument("Different size of matrices");
	}
	for (size_t i = 0; i < lhs.getRow(); i++)
	{
		for (size_t j = 0; j < rhs.getColumns(); j++)
		{
			if (lhs.getMatrix()[i][j] != rhs.getMatrix()[i][j]) {
				return false;
			}
		}
	}
	return true;
}
bool operator!=(const Matrix& lhs, const Matrix& rhs) {
	return !(lhs == rhs);
}
int* Matrix::operator[](int ind) const {
	return matrix[ind];
}
int*& Matrix::operator[](int ind) {
	return matrix[ind];
}