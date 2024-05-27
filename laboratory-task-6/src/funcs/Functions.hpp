#ifndef FUNCTIONS_HPP
#define FUNCTIONS_HPP
#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
#include <stdexcept>
#include <exception>
#include <climits>


struct Employee
{
	std::string surname{};
	size_t children{};
};

bool checkFile(std::ifstream&);
void deleteArray(Employee*&);
void deleteArray(int32_t*&);
void deleteArray(std::string*&);
void getDelimiters(std::string&, std::ifstream&);
bool isDigit(std::string);
void transformStringForNumbers(const std::string, int32_t*, size_t&, std::string);
bool isEven(int32_t);
size_t chetNumber(int32_t*, size_t);
void sortNumbers(int32_t*&, size_t, int32_t*&);
void getNumbers(std::ifstream&, std::string&, std::string&, int32_t*&, size_t&);
bool isSurname(std::string);
void transformStringForSurnames(const std::string, std::string*, size_t&, std::string);
void insertionSort(std::string*&, size_t);
template<typename T>
void universalInsertionSort(T*, size_t, bool comp(T first, T second));
void getSurnames(std::ifstream&, std::string&, std::string&, std::string*&, size_t&);
size_t inputChildren(std::string);
void fillingArrOfStruct(Employee*, int32_t*, std::string*, size_t, size_t);
void outputStruct(Employee*, size_t);
bool compareEmployees(Employee, Employee);
int compareEmployeesForQsort(const void*, const void*);
void menu(Employee*, size_t);
void saveStructInText(std::string, Employee*, size_t);
void saveStructInBin(std::string, Employee*, size_t);
size_t getPoiterLast(std::ifstream&, struct Employee&, struct Employee&);
void swapStringsInBin(std::ofstream&, size_t, struct Employee, struct Employee);

#endif