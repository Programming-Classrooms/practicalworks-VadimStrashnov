#ifndef STUDENT_HPP
#define STUDENT_HPP

#include "Person.hpp"

class Student final: public Person
{
	int32_t course;
	int32_t group;
public:
	// ������������ 
	Student();
	Student(const char*, int32_t, int32_t);
	Student(const Student&);

	// ���������� 
	~Student();

	void SetCourse(int32_t);
	void SetGroup(int32_t);

	int GetCourse();
	int GetGroup();

	friend std::istream& operator>>(std::istream&, Student&);
	friend std::ostream& operator<<(std::ostream&, const Student&);
	void print(std::ostream&) const override;
};

#endif