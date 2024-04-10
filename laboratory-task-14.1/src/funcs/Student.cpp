#include "Student.hpp"

/* Конструктор по умолчанию */
Student::Student() :
	Person(),
	course(0),
	group(0)
{}

/* Конструктор с параметрами */
Student::Student(const char* FullName, int32_t objCourse, int32_t objGroup) :
	Person(FullName),
	course(objCourse),
	group(objGroup)
{}

/* Конструктор копирования */
Student::Student(const Student& obj) :
	Person(obj),
	course(obj.course),
	group(obj.group)
{}

/* Деструктор */
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

/* Перегрузка оператора ввода */
std::istream& operator>>(std::istream& in, Student& obj)
{
	in >> *((Person*)&obj);
	std::cout << "\nEnter course = ";
	in >> obj.course;
	std::cout << "\nEnter group = ";
	in >> obj.group;

	return in;
}

/* Перегрзука оператора вывода */
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
