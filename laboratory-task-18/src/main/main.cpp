#include "../funcs/Library.hpp"

int main() {

    try {
        Library library;

        Book book1("Book 1", { "Author 1", "Author 2" }, 20.0, 5);
        Book book2("Book 2", { "Author 3" }, 15.0, 3);

        library.addBook(book1);
        library.addBook(book2);

        library.viewBooks();

        Book* foundBook = library.findBook("1");
        if (foundBook) {
            std::cout << "Found book: " << foundBook->getTitle() << std::endl;
        }
        else {
            std::cout << "Book not found" << std::endl;
        }

        library.removeBook("1");
        library.viewBooks();

        library.addAuthor("2", "Author 4");
        library.viewBooks();

        library.sortByBookID();
        library.viewBooks();

        library.sortByTitle();
        library.viewBooks();

        return 0;
    }
    catch (...)
    {

    }
}