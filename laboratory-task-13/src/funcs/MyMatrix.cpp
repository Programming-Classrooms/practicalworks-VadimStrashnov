#include "MyMatrix.hpp"

Matrix::Matrix(uint32_t rows, uint32_t colums) : rows(rows), colums(colums) {
    double** data = new double* [rows];
    for (int i = 0; i < rows; ++i) {
        data[i] = new double[colums];
        for (size_t j = 0; j < colums; ++j)
        {
            data[i][j] = 0;
        }
    }
    arr = data;
}

Matrix::Matrix(const Matrix& rhs)
{
    rows = rhs.rows;
    colums = rhs.colums;
    arr = new double* [rows];

    for (size_t i = 0; i < rows; ++i) {
        arr[i] = new double[colums];
    }
    for (size_t i = 0; i < rows; ++i) {
        for (size_t j = 0; j < colums; ++j)
        {
            arr[i][j] = rhs.arr[i][j];
        }
    }
}


void Matrix::setElement(uint32_t row, uint32_t col, double value) {
    if (row >= 0 && row < rows && col >= 0 && col < colums) {
        arr[row][col] = value;
    }
    else {
       throw std::logic_error ("Invalid index\n");
    }
}

double Matrix::getElement(uint32_t row, uint32_t col) const
{
    if (row >= 0 && row < rows && col >= 0 && col < colums) {
        return arr[row][col];
    }
    else {
        throw std::invalid_argument(" No Element! ");
    }
}

void Matrix::setRows(uint32_t num)
{
    rows = num;
    arr[rows][colums];
}

uint32_t Matrix::getRows() const
{
    return rows;
}

void Matrix::setColums(uint32_t num)
{
    colums = num;
    arr[rows][colums];
}

uint32_t Matrix::getColums() const
{
    return colums;
}


Matrix::~Matrix() {
    for (int i = 0; i < rows; ++i)
    {
        delete[] arr[i];
    }
    delete[] arr;
}

Matrix& Matrix::operator=(const Matrix& right)
{
    if (this == &right)
    {
        rows = right.rows;
        colums = right.colums;
        arr[right.rows][right.colums];
        for (uint32_t i = 0; i < right.rows; ++i)
        {
            for (uint32_t j = 0; j < right.colums; ++j)
            {
                arr[i][j] = right.arr[i][j];
            }
        }
    }
    else
    {
       throw std::invalid_argument(" The same matrix! ");
    }
}

Matrix& Matrix::operator+=(const Matrix& right)
{
    if (rows == right.rows && colums == right.colums)
    {
        for (uint32_t i = 0; i < right.rows; ++i)
        {
            for (uint32_t j = 0; j < right.colums; ++j)
            {
                arr[i][j] += right.arr[i][j];
            }
        }
    }
    else
    {
        throw std::invalid_argument(" Wrong size");
    }
}

Matrix& Matrix::operator-=(const Matrix& right)
{
    if (rows == right.rows && colums == right.colums)
    {
        for (uint32_t i = 0; i < right.rows; ++i)
        {
            for (uint32_t j = 0; j < right.colums; ++j)
            {
                arr[i][j] -= right.arr[i][j];
            }
        }
    }
    else
    {
       throw std::invalid_argument(" Wrong size");
    }
}

Matrix& Matrix::operator*=(const Matrix& right)
{
    if (rows == right.colums)
    {
        Matrix result(rows, right.colums);

        for (uint32_t i = 0; i < rows; ++i)
        {
            for (uint32_t j = 0; j < right.colums; ++j)
            {
                for (uint32_t k = 0; k < right.colums; ++k)
                {
                    result.arr[i][j] = arr[i][k] * right.arr[k][j];
                }
            }
        }

        return result;
    }
    else
    {
        throw std::invalid_argument(" Wrong size");
    }
}

Matrix& Matrix::operator/=(const Matrix& right)
{
    if (rows == right.rows && colums == right.colums)
    {
        for (uint32_t i = 0; i < right.rows; ++i)
        {
            for (uint32_t j = 0; j < right.colums; ++j)
            {
                if (right.arr[i][j] != 0)
                {
                    arr[i][j] *= right.arr[i][j];
                }
            }
        }
    }
    else
    {
        throw std::invalid_argument(" Wrong size!");
    }
}

Matrix Matrix::operator+(const Matrix& right)
{
    Matrix result(rows, colums);

    if (rows == right.rows && colums == right.colums)
    {
        for (uint32_t i = 0; i < right.rows; ++i)
        {
            for (uint32_t j = 0; j < right.colums; ++j)
            {
                   result.arr[i][j] = arr[i][j] + right.arr[i][j];
            }
        }
        return result;
    }
    else
    {
       throw std::invalid_argument(" Wrong size!");
    }
}

Matrix Matrix::operator-(const Matrix& right)
{
    Matrix result(rows, colums);

    if (rows == right.rows && colums == right.colums)
    {
        for (uint32_t i = 0; i < right.rows; ++i)
        {
            for (uint32_t j = 0; j < right.colums; ++j)
            {
                    result.arr[i][j] = arr[i][j] - right.arr[i][j];
            }
        }
        return result;
    }
    else
    {
       throw std::invalid_argument(" Wrong size!");
    }
}

Matrix Matrix::operator*(const Matrix& right)
{
    Matrix result(rows, colums);

    if (rows == right.rows && colums == right.colums)
    {
        for (uint32_t i = 0; i < right.rows; ++i)
        {
            for (uint32_t j = 0; j < right.colums; ++j)
            {
                for (uint32_t k = 0; k < right.colums; ++k)
                {
                    result.arr[i][j] = arr[i][k] * right.arr[k][j];
                }
            }
        }

        return result;
    }
    else
    {
        throw std::invalid_argument(" Wrong size!");
    }
}

Matrix Matrix::operator/(const Matrix& right)
{
    Matrix result(rows, colums);

    if (rows == right.rows && colums == right.colums)
    {
        for (uint32_t i = 0; i < right.rows; ++i)
        {
            for (uint32_t j = 0; j < right.colums; ++j)
            {
                if (right.arr[i][j] != 0)
                {
                    result.arr[i][j] = arr[i][j] / right.arr[i][j];
                }
            }
        }
        return result;
    }
    else
    {
        throw std::logic_error(" Wrong number!");
    }
}

bool Matrix::operator==(const Matrix right)
{
    if (rows == right.rows && colums == right.colums)
    {
        for (uint32_t i = 0; i < right.rows; ++i)
        {
            for (uint32_t j = 0; j < right.colums; ++j)
            {
                if (arr[i][j] != right.arr[i][j])
                {
                    return false;
                }
                
            }
        }
        return true;
    }
    else
    {
        return false;
    }
}

bool Matrix::operator!=(const Matrix right)
{
    return !(*this == right);
}

Matrix Matrix::operator*(const double num)
{
    Matrix result(rows, colums);

    for (uint32_t i = 0; i < rows; ++i)
    {
        for (uint32_t j = 0; j < colums; ++j)
        {
            result.arr[i][j] = arr[i][j] * num;
        }
    }

    return result;
}

Matrix Matrix::operator/(const double num)
{
    if (num != 0)
    {
        Matrix result(rows, colums);

        for (uint32_t i = 0; i < rows; ++i)
        {
            for (uint32_t j = 0; j < colums; ++j)
            {
                result.arr[i][j] = arr[i][j] / num;
            }
        }

        return result;
    }
    else
    {
       throw std::logic_error(" Wrong number!");
    }
}

std::istream& operator>>(std::istream& in, Matrix& right)
{
    std::cout << "Write number of rows\n";
    in >> right.rows;
    std::cout << "Write number of colums\n";
    in >> right.colums;

    for (uint32_t i = 0; i < right.rows; ++i)
    {
        for (uint32_t j = 0; j < right.colums; ++j)
        {
            std::cout << "Write element [" << i << " ] [" << j << " ]:\n";
            in >> right.arr[i][j];
        }
    }

    return in;
}

std::ostream& operator<<(std::ostream& out, const Matrix& right)
{
    for (uint32_t i = 0; i < right.rows; ++i)
    {
        for (uint32_t j = 0; j < right.colums; ++j)
        {
            out << right.arr[i][j] << " ";
        }
        out << '\n';
    }

    return out;
}
