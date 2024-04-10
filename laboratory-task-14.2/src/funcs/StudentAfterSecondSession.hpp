#ifndef STUDENTAFTERSECONDSESSION_HPP
#define STUDENTAFTERSECONDSESSION_HPP

#include "StudentAfterFirstSession.hpp"

class StudentAfterSecond : public StudentAfterFirst
{
protected:
    size_t marksOfSecond[5];

public:
    // ������������ � ����������
    StudentAfterSecond() = delete;
    StudentAfterSecond(const StudentAfterFirst&, size_t, size_t, size_t, size_t, size_t);
    StudentAfterSecond(const StudentAfterFirst&, const StudentAfterSecond&);
    ~StudentAfterSecond();

    // Set
    void setMarks(size_t, size_t, size_t, size_t, size_t);

    // Get
    void getMarks() const;

    // �����
    friend std::ostream& operator<<(std::ostream&, const StudentAfterSecond&);

    // ������� ���� �� ���
    double Average() override;
};

#endif