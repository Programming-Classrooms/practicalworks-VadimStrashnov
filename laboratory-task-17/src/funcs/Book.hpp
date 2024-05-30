#ifndef BOOK_HPP
#define BOOK_HPP

#include <vector>
#include <string>
#include <iostream>
#include "Author.hpp"
#include <sstream>

class Book {
public:
    int32_t udcNumber;
    std::vector<Author> authors;
    std::string title;
    int32_t year;

    // Конструкторы
    Book();
    Book(int32_t udcNumber, const std::vector<Author>& authors, const std::string& title, int32_t year);

    // Деструктор
    ~Book();

    // Геттеры
    int32_t getUdcNumber() const;
    std::vector<Author> getAuthors() const;
    std::string getTitle() const;
    int32_t getYear() const;

    // Сеттеры
    void setUdcNumber(int32_t udcNumber);
    void setAuthors(const std::vector<Author>& authors);
    void setTitle(const std::string& title);
    void setYear(int32_t year);

    // Оператор присваивания
    Book& operator=(const Book& other);

    // Оператор ввода
    friend std::istream& operator>>(std::istream& is, Book& book);

    // Оператор вывода
    friend std::ostream& operator<<(std::ostream& os, const Book& book);


};

#endif  // BOOK_HPP
