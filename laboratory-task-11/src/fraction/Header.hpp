#ifndef HEADER_HPP
#define HEADER_HPP
#include <iostream>
#include <stdexcept>

class Array
{
private:
	int32_t size;
	int32_t* arr;
	void fillArray();
public:
	Array();
	Array(int64_t = 10);
	Array(const Array&);
	Array(Array&&);
	~Array();
	int32_t getSize() const;
	void setSize(int size);
	Array& operator=(const Array&);
	int32_t& operator[](int);
	Array& operator++();
	Array operator++(int k);
    Array& operator+(const Array&);
    Array operator+(int32_t);
	friend std::ostream& operator<<(std::ostream&, const Array&);
	friend std::istream& operator>>(std::istream&, Array&);
};

class String
{
	int32_t size;
	char* arr;

public:
	void setSize(size_t);
	String(size_t);
	String();
	~String();

	void enterArray();
	void printArray();
	String operator+(String);
	bool operator==(String);
	bool operator!=(String);
};
#endif
