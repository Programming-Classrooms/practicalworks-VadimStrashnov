#ifndef PROFESSOR_HPP
#define PROFESSOR_HPP

#include "Person.hpp"

class Professor final: public Person
{
	char* department;
public:
	Professor();
	Professor(const char*, const char*);
	Professor(const Professor&);

	~Professor();

	void setDepartment(char*);
	char* getDepartment(char*);

	friend std::ostream& operator<<(std::ostream&, const Professor&);
	friend std::istream& operator>>(std::istream&, Professor&);

	void print(std::ostream&) const override;

};

#endif