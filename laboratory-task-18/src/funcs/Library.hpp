#ifndef LIBRARY_HPP
#define LIBRARY_HPP

#include "Book.hpp"

class Library : public Book
{
private:
    std::vector<Book> books;

public:

    void addBook(Book);
    Book* findBook(std::string);
    void removeBook(std::string);
    void viewBooks();
    void addAuthor(std::string, std::string);
    void removeAuthor(std::string, std::string);
    void sortByBookID();
    void sortByTitle();

};

#endif
