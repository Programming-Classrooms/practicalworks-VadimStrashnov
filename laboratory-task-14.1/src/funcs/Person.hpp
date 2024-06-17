#ifndef PERSON_HPP
#define PERSON_HPP

#include <iostream>
#include <cstring>
#include <string>
#include <assert.h>

class Person
{
protected:
	char* name;
public:
	Person();
	Person(const char*);
	Person(const Person&);

	virtual ~Person();

	void SetName(char*);
	char* GetName(char*);

	friend std::istream& operator >>(std::istream&, Person&);
	friend std::ostream& operator <<(std::ostream&, const Person&);
	virtual void print(std::ostream&)const;
};

#endif
