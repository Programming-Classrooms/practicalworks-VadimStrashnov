#ifndef STUDENT_HPP
#define STUDENT_HPP

#include <iostream>
#include <string>

class Student
{
protected:
    const int32_t ID;
    static int32_t counter;
    std::string name;
    size_t course;
    size_t group;
    const size_t studBookNum;
public:
    Student() = delete;
    Student(std::string, size_t, size_t, size_t);
    Student(const Student&);
    ~Student();

    // сеттеры
    void setName(std::string);
    void setCourse(size_t);
    void setGroup(size_t);
    // геттеры
    std::string getName() const;
    size_t getCourse() const;
    size_t getGroup() const;
    size_t getRecordNumber() const;
    size_t getId() const;

    // вывод
    friend std::ostream& operator<<(std::ostream&, const Student&);

    // подсчёт среднего арифметического
    virtual double Average() = 0;
};

#endif
