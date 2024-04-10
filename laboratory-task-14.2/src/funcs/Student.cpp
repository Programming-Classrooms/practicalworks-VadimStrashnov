#include "Student.hpp"

int32_t Student::counter = 0;

Student::Student(std::string n, size_t c, size_t g, size_t r) : name(n), course(c), group(g), studBookNum(r), ID(++counter) {}

Student::Student(const Student& s) : Student(s.name, s.course, s.group, s.studBookNum) {}

Student::~Student() {}

void Student::setName(std::string s)
{
    this->name = s;
}

void Student::setCourse(size_t c)
{
    this->course = c;
}

void Student::setGroup(size_t g)
{
    this->group = g;
}

std::string Student::getName() const
{
    return name;
}

size_t Student::getCourse() const
{
    return course;
}

size_t Student::getGroup() const
{
    return group;
}

size_t Student::getRecordNumber() const
{
    return studBookNum;
}

size_t Student::getId() const
{
    return ID;
}

std::ostream& operator<<(std::ostream& out, const Student& s)
{
    out << "Name: " << s.name << '\n'
        << "Course: " << s.course << '\n'
        << "Group: " << s.group << '\n'
        << "Record number: " << s.studBookNum << '\n'
        << "ID: " << s.ID << '\n';
    return out;
}
