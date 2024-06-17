#include "Library.hpp"

void Library::addBook(Book book) {
    books.push_back(book);
}

Book* Library::findBook(std::string ID) {
    for (Book& book : books) {
        if (book.getBookID() == ID) {
            return &book;
        }
    }
    return nullptr;
}

void Library::removeBook(std::string myBookID) {
    books.erase(std::remove_if(books.begin(), books.end(), [myBookID](Book book) { return book.getBookID() == myBookID; }), books.end());
}

void Library::viewBooks() {
    for (auto& book : books) {
        std::cout << "ID: " << book.getBookID() << ", Title: " << book.getTitle() << ", Authors: ";
        for (const auto& author : book.getAuthors()) {
            std::cout << author << " ";
        }
        std::cout << "Price: " << book.getPrice() << ", Count: " << book.getCount() << std::endl;
    }
}

void Library::addAuthor(std::string initBookID, std::string author) {
    for (auto& book : books) {
        if (book.getBookID() == initBookID) {
            book.addBookAuthor(author);
        }
    }
}

void Library::removeAuthor(std::string ID, std::string author) {
    for (auto& book : books) {
        if (book.getBookID() == ID) {
            book.getAuthors().erase(std::remove(book.getAuthors().begin(), book.getAuthors().end(), author), book.getAuthors().end());
            return;
        }
    }
}

void Library::sortByBookID() {
    std::sort(books.begin(), books.end(), [](Book left, Book right) { return left.getBookID() < right.getBookID(); });
}

void Library::sortByTitle() {
    std::sort(books.begin(), books.end(), [](Book left, Book right) { return left.getTitle() < right.getTitle(); });
}
