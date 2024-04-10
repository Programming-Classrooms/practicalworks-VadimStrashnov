#include "Student.hpp"

/* ����������� �� ��������� */
Student::Student() :
	Person(),
	course(0),
	group(0)
{}

/* ����������� � ����������� */
Student::Student(const char* FullName, int32_t objCourse, int32_t objGroup) :
	Person(FullName),
	course(objCourse),
	group(objGroup)
{}

/* ����������� ����������� */
Student::Student(const Student& obj) :
	Person(obj),
	course(obj.course),
	group(obj.group)
{}

/* ���������� */
Student::~Student()
{}

void Student::SetCourse(int32_t number)
{
	course = number;
}

int Student::GetCourse()
{
	return course;
}

void Student::SetGroup(int32_t number)
{
	group = number;
}

int Student::GetGroup()
{
	return group;
}

/* ���������� ��������� ����� */
std::istream& operator>>(std::istream& in, Student& obj)
{
	in >> *((Person*)&obj);
	std::cout << "\nEnter course = ";
	in >> obj.course;
	std::cout << "\nEnter group = ";
	in >> obj.group;

	return in;
}

/* ���������� ��������� ������ */
std::ostream& operator<<(std::ostream& out, const Student& obj)
{
	obj.Person::print(out);
	out << "\nCourse: " << obj.course << "\nGroup: " << obj.group;

	return out;
}

void Student::print(std::ostream& out) const
{
	out << *this;
}
