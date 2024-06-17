#include "Author.hpp"

// Конструктор по умолчанию
Author::Author() {}

// Конструктор с параметрами
Author::Author(const std::string& initlastName, const std::string& initfirstName, const std::string& initmiddleName)
    : lastName(initlastName), firstName(initfirstName), middleName(initmiddleName) {}

// Деструктор
Author::~Author() {}

// Геттеры
std::string Author::getLastName() const {
    return lastName;
}

std::string Author::getFirstName() const {
    return firstName;
}

std::string Author::getMiddleName() const {
    return middleName;
}

// Сеттеры
void Author::setLastName(const std::string& lastName) {
    this->lastName = lastName;
}

void Author::setFirstName(const std::string& firstName) {
    this->firstName = firstName;
}

void Author::setMiddleName(const std::string& middleName) {
    this->middleName = middleName;
}

// Оператор присваивания
Author& Author::operator=(const Author& other) {
    if (this != &other) {
        lastName = other.lastName;
        firstName = other.firstName;
        middleName = other.middleName;
    }
    return *this;
}

// Оператор ввода
std::istream& operator>>(std::istream& is, Author& author) {
    is >> author.lastName >> author.firstName >> author.middleName;
    return is;
}

// Оператор вывода
std::ostream& operator<<(std::ostream& os, const Author& author) {
    os << author.lastName << " " << author.firstName << " " << author.middleName;
    return os;
}
