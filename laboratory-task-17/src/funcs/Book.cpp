#include "Book.hpp"

// Конструктор по умолчанию
Book::Book() {}

// Конструктор с параметрами
Book::Book(int32_t initudcNumber, const std::vector<Author>& initauthors, const std::string& inittitle, int32_t inityear)
    : udcNumber(initudcNumber), authors(initauthors), title(inittitle), year(inityear) {}

// Деструктор
Book::~Book() {}

// Геттеры
int32_t Book::getUdcNumber() const {
    return udcNumber;
}

std::vector<Author> Book::getAuthors() const {
    return authors;
}

std::string Book::getTitle() const {
    return title;
}

int32_t Book::getYear() const {
    return year;
}

// Сеттеры
void Book::setUdcNumber(int32_t udcNumber) {
    this->udcNumber = udcNumber;
}

void Book::setAuthors(const std::vector<Author>& authors) {
    this->authors = authors;
}

void Book::setTitle(const std::string& title) {
    this->title = title;
}

void Book::setYear(int32_t year) {
    this->year = year;
}

// Оператор присваивания
Book& Book::operator=(const Book& other) {
    if (this != &other) {
        udcNumber = other.udcNumber;
        authors = other.authors;
        title = other.title;
        year = other.year;
    }
    return *this;
}

// Оператор ввода
std::istream& operator>>(std::istream& is, Book& book) {
    is >> book.udcNumber;

    book.authors.clear();

    std::string line;
    while (std::getline(is, line)) {
        std::istringstream iss(line);
        Author author;

        if (iss >> author) {
            book.authors.push_back(author);
        }
    }
    is >> book.title >> book.year;
    return is;
}

// Оператор вывода
std::ostream& operator<<(std::ostream& os, const Book& book) {
    os << "UDC Number: " << book.udcNumber << "\n";
    os << "Authors:\n";
    for (const Author& author : book.authors) {
        os << author << "\n";
    }
    os << "Title: " << book.title << "\n";
    os << "Year: " << book.year << "\n";
    return os;
}
