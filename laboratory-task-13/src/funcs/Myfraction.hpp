#ifndef MYFRACTION_HPP
#define MYFRACTION_HPP

#include <iostream>

class MyFraction
{
	int32_t num;
	int32_t den;

public:
	MyFraction();
	MyFraction(int32_t, int32_t);
	MyFraction(const MyFraction&);
	~MyFraction();

	void setNum(int32_t);
	void setDen(int32_t);
	int32_t getNum()const;
	int32_t getDen()const;

	int32_t NOD(int32_t, int32_t);
	void normalFraction();

	MyFraction& operator=(const MyFraction&);
	MyFraction& operator+=(const MyFraction&);
	MyFraction& operator-=(const MyFraction&);
	MyFraction& operator*=(const MyFraction&);
	MyFraction& operator/=(const MyFraction&);
	MyFraction operator+(const MyFraction&);
	MyFraction operator-(const MyFraction&);
	MyFraction operator*(const MyFraction&);
	MyFraction operator/(const MyFraction&);

	MyFraction& operator++();
	MyFraction& operator--();

	MyFraction operator-();
	MyFraction operator!();
	double operatordouble();

	bool operator==(const MyFraction);
	bool operator!=(MyFraction);
	bool operator<(MyFraction);
	bool operator>(MyFraction);
	bool operator<=(MyFraction);
	bool operator>=(MyFraction);

	friend std::istream& operator>>(std::istream&, MyFraction&);
	friend std::ostream& operator<<(std::ostream&, const MyFraction&);
};
#endif
