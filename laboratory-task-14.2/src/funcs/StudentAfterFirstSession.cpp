#include "StudentAfterFirstSession.hpp"

StudentAfterFirst::StudentAfterFirst(std::string initName, size_t initCourse, size_t initgroup, size_t initStudBook, size_t mark1, size_t mark2, size_t mark3, size_t mark4) : Student(initName, initCourse, initgroup, initStudBook)
{
    marksOfFirst[0] = mark1;
    marksOfFirst[1] = mark2;
    marksOfFirst[2] = mark3;
    marksOfFirst[3] = mark4;
}
StudentAfterFirst::StudentAfterFirst(const StudentAfterFirst& obj) : Student(obj.name, obj.course, obj.group, obj.studBookNum)
{
    for (size_t i = 0; i < 4; ++i)
    {
        marksOfFirst[i] = obj.marksOfFirst[i];
    }
}

StudentAfterFirst::~StudentAfterFirst() {}

void StudentAfterFirst::setMarks(size_t mark1, size_t mark2, size_t mark3, size_t mark4)
{
    marksOfFirst[0] = mark1;
    marksOfFirst[1] = mark2;
    marksOfFirst[2] = mark3;
    marksOfFirst[3] = mark4;
}

void StudentAfterFirst::getMarks() const
{
    for (size_t i = 0; i < 4; ++i)
    {
        std::cout << marksOfFirst[i] << '\n';
    }
}

double StudentAfterFirst::Average()
{
    double res = 0;
    for (size_t i = 0; i < 4; ++i)
    {
        res += marksOfFirst[i];
    }
    res = (static_cast<double>(res) / 4);

    return res;
}

std::ostream& operator<<(std::ostream& out, const StudentAfterFirst& obj)
{
    out << obj.name << '\n'
        << "Course: " << obj.course << '\n'
        << "Group: " << obj.group << '\n'
        << "Record number: " << obj.studBookNum << '\n'
        << "ID: " << obj.ID << '\n';
    for (size_t i = 0; i < 4; ++i)
    {
        out << obj.marksOfFirst[i] << '\n';
    }

    return out;
}