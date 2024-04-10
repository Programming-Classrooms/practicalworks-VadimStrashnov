#include "StudentAfterSecondSession.hpp"

StudentAfterSecond::StudentAfterSecond(const StudentAfterFirst& initObj, size_t mark1, size_t mark2, size_t mark3, size_t mark4, size_t mark5) : StudentAfterFirst(initObj)
{
    marksOfSecond[0] = mark1;
    marksOfSecond[1] = mark2;
    marksOfSecond[2] = mark3;
    marksOfSecond[3] = mark4;
    marksOfSecond[4] = mark5;
}
StudentAfterSecond::StudentAfterSecond(const StudentAfterFirst& obj, const StudentAfterSecond& extendedObj) : StudentAfterFirst(obj)
{
    for (size_t i = 0; i < 5; ++i)
    {
        marksOfSecond[i] = extendedObj.marksOfSecond[i];
    }
}

StudentAfterSecond::~StudentAfterSecond() {}

void StudentAfterSecond::setMarks(size_t mark1, size_t mark2, size_t mark3, size_t mark4, size_t mark5)
{
    marksOfSecond[0] = mark1;
    marksOfSecond[1] = mark2;
    marksOfSecond[2] = mark3;
    marksOfSecond[3] = mark4;
    marksOfSecond[4] = mark5;
}

void StudentAfterSecond::getMarks() const
{
    for (size_t i = 0; i < 5; ++i)
    {
        std::cout << marksOfSecond[i] << '\n';
    }
}

double StudentAfterSecond::Average()
{
    double res = 0;
    for (size_t i = 0; i < 4; ++i)
    {
        res += marksOfFirst[i];
    }
    for (size_t i = 0; i < 5; ++i)
    {
        res += marksOfSecond[i];
    }
    return static_cast<double>(res) / 9;
}

std::ostream& operator<<(std::ostream& out, const StudentAfterSecond& s)
{
    out << s.name << '\n'
        << "course: " << s.course << '\n'
        << "group: " << s.group << '\n'
        << "record number: " << s.studBookNum << '\n'
        << "Id: " << s.ID << '\n';
    for (size_t i = 0; i < 4; ++i)
    {
        out << s.marksOfFirst[i] << ' ';
    }
    for (size_t i = 0; i < 5; ++i)
    {
        out << s.marksOfSecond[i] << ' ';
    }
    out << '\n';
    return out;
}