#define _CRT_SECURE_NO_WARNINGS
#include "Person.hpp"

/* Конструктор по умолчанию */
Person::Person() :name(nullptr)
{}

/* Конструктор с параметрами */
Person::Person(const char* fullName)
{
	this->name = new char[strlen(fullName) + 1];
	strcpy(this->name, fullName);
}

/* Конструктор копирования */
Person::Person(const Person& rhs)
{
	if (rhs.name) {
		this->name = new char[strlen(rhs.name) + 1];
		strcpy(this->name, rhs.name);
	}
	else {
		this->name = nullptr;
	}
}

/* Деструктор */
Person::~Person()
{
	delete[] this->name;
}


char* Person::GetName(char* result)
{
	if (result == nullptr)
	{
		throw std::invalid_argument("Bad container.");
	}
	result[strlen(name)];
	for (size_t i = 0; i < strlen(name); ++i)
	{
		result[i] = name[i];
	}

	return result;
}

void Person::SetName(char* arr)
{
	name = std::move(arr);
}

std::istream& operator>>(std::istream& in, Person& obj)
{
	std::cout << "Write Surname\n";
	char buffer[512];
	in >> buffer;

	std::cout << "Write Name\n";
	char buffer2[512];
	in >> buffer2;

	std::cout << "Write Patronymic\n";
	char buffer3[512];
	in >> buffer;

	if (obj.name) {
		delete[] obj.name;
		obj.name = nullptr;
	}

	obj.name = new char[strlen(buffer) + strlen(buffer2) + strlen(buffer3) + 1];
	strcpy(obj.name, buffer);
	strcat(obj.name, " ");
	strcat(obj.name, buffer2);
	strcat(obj.name, " ");
	strcat(obj.name, buffer3);

	return in;
}

std::ostream& operator<<(std::ostream& out, const Person& obj)
{
	if (strlen(obj.name) > 0)
	{
		out << obj.name;
	}

	return out;
}

void Person::print(std::ostream& out) const
{
	out << *this;
}
