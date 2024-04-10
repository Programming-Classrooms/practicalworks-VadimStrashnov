#ifndef MYMATRIX_HPP
#define MYMATRIX_HPP

#include <iostream>
#include <exception>


class Matrix
{
private:
	double** arr = new double*;
	uint32_t rows;
	uint32_t colums;
public:
	Matrix(uint32_t, uint32_t);
	Matrix(const Matrix&);

	void setElement(uint32_t, uint32_t, double);
	double getElement(uint32_t, uint32_t) const;
	void setRows(uint32_t);
	uint32_t getRows()const;
	void setColums(uint32_t);
	uint32_t getColums()const;

	~Matrix();

	Matrix& operator=(const Matrix&);
	Matrix& operator+=(const Matrix&);
	Matrix& operator-=(const Matrix&);
	Matrix& operator*=(const Matrix&);
	Matrix& operator/=(const Matrix&);
	Matrix operator+(const Matrix&);
	Matrix operator-(const Matrix&);
	Matrix operator*(const Matrix&);
	Matrix operator/(const Matrix&);

	bool operator==(const Matrix);
	bool operator!=(Matrix);
	
	Matrix operator*(const double);
	Matrix operator/(const double);

	friend std::istream& operator>>(std::istream&, Matrix&);
	friend std::ostream& operator<<(std::ostream&, const Matrix&);
};

#endif
