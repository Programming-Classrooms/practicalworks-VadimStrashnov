#define _CRT_SECURE_NO_WARNINGS
#include "Professor.hpp"

/* Конструктор по умолчанию */
Professor::Professor() :
	Person(),
	department(nullptr)
{}

/* Конструктор с параметрами */
Professor::Professor(const char* fullName, const char* objDepartment) :Person(fullName)
{
	this->department = new char[strlen(objDepartment) + 1];
	strcpy(department, objDepartment);
}

/* Конструктор копирования */
Professor::Professor(const Professor& rhs) :Person(rhs)
{
	if (rhs.department) {
		this->department = new char[strlen(rhs.department) + 1];
		strcpy(this->department, rhs.department);
	}
	else {
		this->department = nullptr;
	}
}

/* Деструктор */
Professor::~Professor()
{}

void Professor::setDepartment(char* arr)
{
	department = std::move(arr);
}

char* Professor::getDepartment(char* result)
{
	if (result == nullptr)
	{
		throw std::invalid_argument("Bad container.");
	}

	result[strlen(department)];

	for (size_t i = 0; i < strlen(department); ++i)
	{
		result[i] = department[i];
	}

	return result;
}

/* Перегрузка оператора вывода */
std::ostream& operator<<(std::ostream& out, const Professor& obj)
{
	obj.Person::print(out);
	out << '\n' << obj.department;

	return out;
}

/* Перегрузка оператора ввода */
std::istream& operator>>(std::istream& in, Professor& rhs)
{
	in >> *((Person*)&rhs);
	std::cout << "Write name of department:\n";
	char buffer[512];
	in >> buffer;

	if (rhs.department) {
		delete[] rhs.department;
		rhs.department = nullptr;
	}

	rhs.department = new char[strlen(buffer) + 1];
	strcpy(rhs.department, buffer);

	return in;
}

void Professor::print(std::ostream& out) const
{
	out << *this;
}