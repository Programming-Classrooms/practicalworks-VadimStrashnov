#include "Myfraction.hpp"

MyFraction::MyFraction():
	num(0),
	den(1)
{
}

MyFraction::MyFraction(int32_t firstKoef, int32_t secondKoef)
{
	num = firstKoef;
	den = secondKoef;
	this->normalFraction();
}

MyFraction::MyFraction(const MyFraction& secondObject)
{
	num = secondObject.num;
	den = secondObject.den;
	this->normalFraction();
}

MyFraction::~MyFraction()
{
}

void MyFraction::setNum(int32_t number)
{
	num = number;
}

void MyFraction::setDen(int32_t number)
{
	den = number;
}

int32_t MyFraction::getNum() const
{
	return num;
}

int32_t MyFraction::getDen() const
{
	return den;
}

int32_t MyFraction::NOD(int32_t initNum, int32_t initDen)
{
	int32_t numCopy = initNum;
	int32_t denCopy = initDen;

	if (numCopy < 0)
	{
		numCopy *= -1;
	}
	while (numCopy != denCopy) {
		if (numCopy > denCopy) {
			numCopy = numCopy - denCopy;
		}
		else {
			denCopy = denCopy - numCopy;
		}
	}
	return numCopy;
}

void MyFraction::normalFraction()
{
	if (den == 0)
	{
		throw std::invalid_argument(" Wrong denominator!");
	}
	if (den < 0)
	{
		den *= -1;
		num *= -1;
	}
	if (this->NOD(num, den) != 1)
	{
		num /= this->NOD(num, den);
		den /= this->NOD(num, den);
	}
}

MyFraction& MyFraction::operator=(const MyFraction& right)
{
	num = right.num;
	den = right.den;
	return *this;
}

MyFraction& MyFraction::operator+=(const MyFraction& right)
{
	num = num * right.den + right.num * den;
	den *= right.den;
	this->normalFraction();
	return *this;
}

MyFraction& MyFraction::operator-=(const MyFraction& right)
{
	num -= num * right.den - right.num * den;
	den *= right.den;
	this->normalFraction();
	return *this;
}

MyFraction& MyFraction::operator*=(const MyFraction& right)
{
	num *= right.num;
	den *= right.den;
	this->normalFraction();
	return *this;
}

MyFraction& MyFraction::operator/=(const MyFraction& right)
{
	if (right.num != 0)
	{
		num *= right.den;
		den *= right.num;
		this->normalFraction();
	}
	else
	{
		throw std::invalid_argument (" Wrong fraction!");
	}
	return *this;
}

MyFraction MyFraction::operator+(const MyFraction& right)
{
	MyFraction res(num * right.den + right.num * den, den * right.den);
	res.normalFraction();
	return res;
}

MyFraction MyFraction::operator-(const MyFraction& right)
{
	MyFraction res(num * right.den - right.num * den, den * right.den);
	res.normalFraction();
	return res;
}

MyFraction MyFraction::operator*(const MyFraction& right)
{
	MyFraction res(num * right.num, den * right.den);
	res.normalFraction();
	return res;
}

MyFraction MyFraction::operator/(const MyFraction& right)
{
	if (right.num != 0)
	{
		MyFraction res(num * right.den, den * right.num);
		res.normalFraction();
		return res;
	}
	else
	{
		throw std::invalid_argument(" Wrong denominator!");
	}
	return *this;
}

MyFraction& MyFraction::operator++()
{
	++num;
	this->normalFraction();
	return *this;
}

MyFraction& MyFraction::operator--()
{
	--num;
	this->normalFraction();
	return *this;
}

MyFraction MyFraction::operator-()
{
	num *= -1;
	this->normalFraction();
	return *this;
}

MyFraction MyFraction::operator!()
{
	if (num != 0)
	{
		int32_t number = 0;
		number = den;
		den = num;
		num = number;
		this->normalFraction();
	}
	else
	{
		throw std::invalid_argument(" Wrong fraction!");
	}
	return *this;
}

bool MyFraction::operator==(const MyFraction right) 
{
	return (num == right.num && den == right.den) ? true:false ;
}

bool MyFraction::operator!=(MyFraction right)
{
	return (num == right.num && den == right.den) ? false : true;
}

bool MyFraction::operator<(MyFraction right)
{
	double num1 = num / den;
	double num2 = right.num / right.den;
	if (num1 < num2)
	{
		return true;
	}
	return false;
}

bool MyFraction::operator>(MyFraction right)
{
	double num1 = num / den;
	double num2 = right.num / right.den;
	if (num1 > num2)
	{
		return true;
	}
	return false;
}

bool MyFraction::operator<=(MyFraction right)
{
	double num1 = num / den;
	double num2 = right.num / right.den;
	if (num1 <= num2)
	{
		return true;
	}
	return false;
}

bool MyFraction::operator>=(MyFraction right)
{
	double num1 = num / den;
	double num2 = right.num / right.den;
	if (num1 >= num2)
	{
		return true;
	}
	return false;
}

double MyFraction::operatordouble() 
{
	return static_cast <double> (num) / den;
}

std::istream& operator>>(std::istream& in, MyFraction& right)
{
	in >> right.num;
	in >> right.den;
	right.normalFraction();
	return in;
}

std::ostream& operator<<(std::ostream& out, const MyFraction& right)
{
	out << right.num << " / " << right.den;

	return out;
}
