#include <iostream>
#include <algorithm>
#include <fstream>
#include <unordered_map>
#include <set>

#include "../funcs/Book.hpp"

bool compareAuthorsByLastName(const Author& a, const Author& b) {
    return a.lastName < b.lastName;
}

bool compareBooksByTitle(const Book& a, const Book& b) {
    return a.title < b.title;
}

int main()
{
    //====================== 2 ������� ==========================

    std::vector<Book> library;

    // ��������� ���������� � ������ �� �����
    std::ifstream fin("DATA.txt");
    if (!fin.is_open()) {
        std::cerr << "Error opening file." << std::endl;
        return 1;
    }

    int32_t udcNumber, year;
    std::string lastName, firstName, middleName, title;

    while (fin >> udcNumber >> lastName >> firstName >> middleName >> title >> year) {
        Author author = { lastName, firstName, middleName };
        Book book = { udcNumber, {author}, title, year };
        library.push_back(book);
    }

    fin.close();

    // ��������� ����� �� ��������
    std::sort(library.begin(), library.end(), compareBooksByTitle);

    // ���������� �����
    // ������ ���������� ����� � ����� �������
    Author newAuthor = { "Smith", "John", "Doe" };
    Book newBook = { 12345, {newAuthor}, "New Book", 2022 };
    library.push_back(newBook);

    // �������� �����
    // ������ �������� ����� �� ��������
    std::string bookToDelete = "Some Book";
    auto it = std::find_if(library.begin(), library.end(), [bookToDelete](const Book& b) {
        return b.title == bookToDelete;
        });
    if (it != library.end()) {
        library.erase(it);
    }

    // ����� ���� �� ��������
    std::string searchTitle = "New Book";
    auto foundBook = std::find_if(library.begin(), library.end(), [searchTitle](const Book& b) {
        return b.title == searchTitle;
        });
    if (foundBook != library.end()) {
        std::cout << "Book found: " << foundBook->title << std::endl;
    }
    else {
        std::cout << "Book not found." << std::endl;
    }

    // ����� ���� �� ������
    std::string searchAuthorLastName = "Doe";
    for (const auto& book : library) {
        auto authorFound = std::find_if(book.authors.begin(), book.authors.end(), [searchAuthorLastName](const Author& a) {
            return a.lastName == searchAuthorLastName;
            });
        if (authorFound != book.authors.end()) {
            std::cout << "Book by author found: " << book.title << std::endl;
        }
    }

    // ���������� � �������� ������ ��������� �����
    // ������ ���������� ������ � ������ ����� � ����������
    Author additionalAuthor = { "Brown", "Alice", "Mary" };
    library[0].authors.push_back(additionalAuthor);

    // ������ �������� ������ �� ������ ����� � ����������
    std::string authorToDelete = "Doe";
    auto bookWithAuthor = std::find_if(library.begin(), library.end(), [authorToDelete](const Book& b) {
        auto authorFound = std::find_if(b.authors.begin(), b.authors.end(), [authorToDelete](const Author& a) {
            return a.lastName == authorToDelete;
            });
        return authorFound != b.authors.end();
        });

    if (bookWithAuthor != library.end()) {
        auto authorToDeleteIt = std::remove_if(bookWithAuthor->authors.begin(), bookWithAuthor->authors.end(), [authorToDelete](const Author& a) {
            return a.lastName == authorToDelete;
            });
        bookWithAuthor->authors.erase(authorToDeleteIt, bookWithAuthor->authors.end());
    }


    //==================== 3 ������� =============================

    std::ifstream inputFile("For3.txt");
    if (!inputFile.is_open()) {
        std::cerr << "Error opening file." << std::endl;
        return 1;
    }

    std::unordered_map<std::string, int32_t> wordCount;
    std::set<std::string> uniqueWords;
    std::string word;

    while (inputFile >> word) {
        // �������� ����� � ������� ��������
        for (char& c : word) {
            c = std::tolower(c);
        }
        // ������� ����� ����������
        word.erase(std::remove_if(word.begin(), word.end(), ispunct), word.end());

        // ��������� ����� � ���������� ������
        uniqueWords.insert(word);

        // ����������� ������� ��� ����� �����
        wordCount[word]++;
    }

    inputFile.close();

    // ������� ������ ���� ����
    std::cout << "List of all words in txt:" << std::endl;
    for (const auto& w : uniqueWords) {
        std::cout << w << std::endl;
    }

    // ������� ���������� ��������� ������� �����
    std::cout << "Number of arriving of every word from txt:" << std::endl;
    for (const auto& pair : wordCount) {
        std::cout << pair.first << ": " << pair.second << std::endl;
    }


    //============================= 4 ������� =====================================

    std::set<std::string> fisherman1 = { "Losos", "Forel", "Okyn" };
    std::set<std::string> fisherman2 = { "Forel", "Karas", "Yorsh" };
    std::set<std::string> fisherman3 = { "Losos", "Karas", "Yorsh" };

    // ������� ��������� ����� ��� ������� ������
    std::set<std::string> allFish;
    std::set_union(fisherman1.begin(), fisherman1.end(), fisherman2.begin(), fisherman2.end(), std::inserter(allFish, allFish.begin()));
    std::set_union(allFish.begin(), allFish.end(), fisherman3.begin(), fisherman3.end(), std::inserter(allFish, allFish.begin()));

    // ������� ���� ��� � ������� ������
    std::cout << "Types of fish of every fisher:" << std::endl;
    std::cout << "Fisher 1: ";
    for (const auto& fish : fisherman1) {
        std::cout << fish << " ";
    }
    std::cout << std::endl;

    std::cout << "Fisher 2: ";
    for (const auto& fish : fisherman2) {
        std::cout << fish << " ";
    }
    std::cout << std::endl;

    std::cout << "Fisher 3: ";
    for (const auto& fish : fisherman3) {
        std::cout << fish << " ";
    }
    std::cout << std::endl;

    // ������� ����, ����������� ���� �� ����� �������
    std::set<std::string> caughtFish;
    std::set_union(fisherman1.begin(), fisherman1.end(), fisherman2.begin(), fisherman2.end(), std::inserter(caughtFish, caughtFish.begin()));
    std::set_union(caughtFish.begin(), caughtFish.end(), fisherman3.begin(), fisherman3.end(), std::inserter(caughtFish, caughtFish.begin()));

    std::cout << "\n Fish, that caught by one of the fishers:" << std::endl;
    for (const auto& fish : caughtFish) {
        std::cout << fish << " ";
    }
    std::cout << std::endl;

    // ������� ����, ������� ���� � �����, �� �� ������ � ����
    std::set<std::string> allFishInLake = { "Losos", "Forel", "Okyn", "Karas", "Yorsh" };

    std::set<std::string> notCaughtFish;
    std::set_difference(allFishInLake.begin(), allFishInLake.end(), caughtFish.begin(), caughtFish.end(), std::inserter(notCaughtFish, notCaughtFish.begin()));

    std::cout << "\nFish, that not in lists:\n";
    for (const auto& fish : notCaughtFish) {
        std::cout << fish << " ";
    }
    std::cout << std::endl;

    return 0;
}