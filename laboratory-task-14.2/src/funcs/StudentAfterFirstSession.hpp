#ifndef STUDENTAFTERFIRSTSESSION_HPP
#define STUDENTAFTERFIRSTSESSION_HPP

#include "Student.hpp"
#include <iostream>
#include <string>
#include <cstdint>

class StudentAfterFirst: public Student
{
protected:
    size_t marksOfFirst[4];

public:
    // ������������ � ����������
    StudentAfterFirst() = delete;
    StudentAfterFirst(std::string, size_t, size_t, size_t, size_t, size_t, size_t, size_t);
    StudentAfterFirst(const StudentAfterFirst&);
    ~StudentAfterFirst();

    // Set
    void setMarks(size_t, size_t, size_t, size_t);
    
    // Get
    void getMarks() const;
    
    // �����
    friend std::ostream& operator<<(std::ostream&, const StudentAfterFirst&);
    
    // ������� ���� �� ������ ������
    double Average() override;
};

#endif
