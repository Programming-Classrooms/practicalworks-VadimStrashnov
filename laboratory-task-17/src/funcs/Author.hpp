#ifndef AUTHOR_HPP
#define AUTHOR_HPP

#include <string>
#include <iostream>

class Author {
public:
    std::string lastName;
    std::string firstName;
    std::string middleName;

    // Конструкторы
    Author();
    Author(const std::string&, const std::string&, const std::string&);

    // Деструктор
    ~Author();

    // Геттеры
    std::string getLastName() const;
    std::string getFirstName() const;
    std::string getMiddleName() const;

    // Сеттеры
    void setLastName(const std::string& lastName);
    void setFirstName(const std::string& firstName);
    void setMiddleName(const std::string& middleName);

    // Оператор присваивания
    Author& operator=(const Author& other);

    // Оператор ввода
    friend std::istream& operator>>(std::istream& is, Author& author);

    // Оператор вывода
    friend std::ostream& operator<<(std::ostream& os, const Author& author);
};

#endif  // AUTHOR_HPP
