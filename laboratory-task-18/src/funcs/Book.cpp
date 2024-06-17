#include "Book.hpp"

int32_t Book::IDcounter = 0;

Book::Book() : bookID(""), title(""), authors({}), price(0.0), count(0) {}

Book::Book(const std::string& title, const std::vector<std::string>& authors, double price, int32_t count)
    : bookID(std::to_string(++IDcounter)), title(title), authors(authors), price(price), count(count) {}

Book::Book(const Book& other) {
    bookID = other.bookID;
    title = other.title;
    authors = other.authors;
    price = other.price;
    count = other.count;
}

Book::~Book() {}

std::string Book::getBookID()
{
    return bookID;
}

std::string Book::getTitle()
{
    return title;
}

std::vector<std::string> Book::getAuthors()
{
    return authors;
}

double Book::getPrice()
{
    return price;
}

int32_t Book::getCount()
{
    return count;
}

void Book::setTitle(const std::string& line)
{
    title = line;
}

void Book::setAuthors(std::vector<std::string> initAuthors)
{
    authors = initAuthors;
}

void Book::setPrice(const double& num)
{
    price = num;
}

void Book::setCount(const int32_t& num )
{
    count = num;
}

void Book::addBookAuthor(const std::string& initAuthor)
{
    this->authors.push_back(initAuthor);
}

Book& Book::operator=(const Book& other) {
    if (this != &other) {
        bookID = other.bookID;
        title = other.title;
        authors = other.authors;
        price = other.price;
        count = other.count;
    }
    return *this;
}

std::ostream& operator<<(std::ostream& out, const Book& book) {
    out << "ID: " << book.bookID << ", Title: " << book.title << ", Authors: ";
    for (const auto& author : book.authors) {
        out << author << ", ";
    }
    out << "Price: " << book.price << ", Count: " << book.count;
    return out;
}

std::istream& operator>>(std::istream& in, Book& book) {
    in >> book.bookID >> book.title;
    int authorCount;
    in >> authorCount;
    book.authors.resize(authorCount);
    for (int i = 0; i < authorCount; ++i) {
        in >> book.authors[i];
    }
    in >> book.price >> book.count;
    return in;
}
