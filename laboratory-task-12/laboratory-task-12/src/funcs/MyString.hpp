#ifndef MYSTRING_HPP
#define MYSTRING_HPP

#include <iostream>
#include <cstring>
#include <cctype>

class MyString
{
	size_t capacity;
	size_t size;
	char* arr;

public:
	MyString();
	MyString(size_t);
	MyString(const char*);
	MyString(const MyString&);
	~MyString();

	int32_t getSize()const;
	void setArray();
	void getArray();
	const char* getCstring() const;

	void toLowerCase();
	void toUpperCase();

	MyString& operator=(const MyString&);
	MyString& operator=(const char*&);
	MyString& operator+=(const MyString&);
	MyString& operator+=(const char*&);
	MyString operator+(MyString);
	char* operator+(char*);

	bool operator==(const MyString&);
	bool operator==(char* obj);
	bool operator!=(const MyString&);
	bool operator!=(char* obj);
	bool operator<(const MyString&);
	bool operator<(char* obj);
	char& operator[](int);

	friend std::istream& operator>>(std::istream&, MyString&);
	friend std::ostream& operator<<(std::ostream&, const MyString&);
};
#endif
