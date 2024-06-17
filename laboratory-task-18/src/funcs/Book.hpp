#ifndef BOOK_HPP
#define BOOK_HPP

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

class Book {
protected:
    static int32_t IDcounter;
    std::string bookID;
    std::string title;
    std::vector<std::string> authors;
    double price;
    int32_t count;

public:
    Book();
    Book(const std::string&, const std::vector<std::string>&, double, int32_t);
    Book(const Book&);
    ~Book();

    std::string getBookID();
    std::string getTitle();
    std::vector<std::string> getAuthors();
    double getPrice();
    int32_t getCount();

    void setTitle(const std::string&);
    void setAuthors(std::vector<std::string>);
    void setPrice(const double&);
    void setCount(const int32_t&);

    void addBookAuthor(const std::string&);

    Book& operator=(const Book&);
    friend std::ostream& operator<<(std::ostream& os, const Book& book);
    friend std::istream& operator>>(std::istream& is, Book& book);
};

#endif
