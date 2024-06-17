#include "Functions.hpp"

bool checkFile(std::ifstream& file)
{
	if (!file.good()) {
		throw std::runtime_error("File isn't exist");
	}
	if (!file) {
		throw std::runtime_error("File is unopened!");
	}
	if (file.peek() == EOF) {
		file.close();
		throw std::runtime_error("File is empty!");
	}
	return true;
}

void deleteArray(Employee*& arr)
{
	delete[] arr;
}

void deleteArray(int32_t*& arr)
{
	delete[] arr;
}

void deleteArray(std::string*& arr)
{
	delete[] arr;
}

void getDelimiters(std::string& delimiters, std::ifstream& fin)
{
	if (checkFile(fin)) {
		std::getline(fin, delimiters);
		if (delimiters.size() == 0) {
			throw std::runtime_error("Delimiters are empty!");
		}
	}
}

bool isDigit(std::string word)
{
	size_t size = word.size();
	if (word[0] == '-' || isdigit(word[0])) {
		for (size_t i = 1; i < size; ++i) {
			if (!isdigit(word[i])) {
				return false;
			}
		}
		return true;
	}
	return false;
}

void transformStringForNumbers(const std::string line, int32_t* allNumbers, size_t& pos, std::string delimiters)
{
	std::string word;
	std::string::size_type begInd;
	pos = 0;

	begInd = line.find_first_not_of(delimiters);

	while (begInd != std::string::npos) {
		std::string::size_type endInd;
		endInd = line.find_first_of(" ", begInd);

		if (endInd == std::string::npos) {
			endInd = line.length();
		}

		word = line.substr(begInd, endInd - begInd);

		if (isDigit(word)) {
			allNumbers[pos] = stoi(word);
			++pos;
		}

		begInd = line.find_first_not_of(" ", endInd);
	}
}

bool isEven(int32_t n)
{
	return !(n & 1);
}

size_t chetNumber(int32_t* arr, size_t pos)
{
	size_t sum = 0;

	for (size_t i = 0; i < pos; ++i) {
		if (isEven(arr[i])) {
			++sum;
		}
	}

	return sum;
}

void sortNumbers(int32_t*& arr, size_t pos, int32_t*& copy)
{
	size_t j = 0;
	size_t k = 0;

	for (size_t i = 0; i < pos; ++i) {
		if (isEven(arr[i])) {
			copy[j] = arr[i];
			++j;
		}
		else {
			copy[k + chetNumber(arr, pos)] = arr[i];
			++k;
		}
	}
}

void getNumbers(std::ifstream& fin, std::string& line, std::string& delimiters, int32_t*& allNumbers, size_t& sizeOfNumbers)
{
	allNumbers[0] = INT_MIN;

	while (getline(fin, line)) {
		transformStringForNumbers(line, allNumbers, sizeOfNumbers, delimiters);
	}

	if (allNumbers[0] == INT_MIN) {
		throw std::runtime_error("No numbers!");
	}

	std::cout << "Primal array:\n";
	for (size_t i = 0; i < sizeOfNumbers; ++i) {
		std::cout << allNumbers[i] << ' ';
	}

	std::cout << '\n' << "Sorted array:\n";
	int32_t* copyArr = new int32_t[300]{};
	sortNumbers(allNumbers, sizeOfNumbers, copyArr);
	for (size_t i = 0; i < sizeOfNumbers; ++i) {
		std::cout << copyArr[i] << ' ';
	}
	std::cout << '\n';
	fin.close();
	line = {};
	delimiters = {};
	deleteArray(copyArr);
}

bool isSurname(std::string word)
{
	size_t size = word.size();

	if (word[0] == toupper(word[0]) && isalpha(word[0])) {
		for (size_t i = 1; i < size; ++i) {
			if (!isalpha(word[i]) || word[i] == toupper(word[i])) {
				return false;
			}
		}
		return true;
	}
	return false;
}

void transformStringForSurnames(const std::string line, std::string* allSurnames, size_t& pos, std::string delimiters)
{
	std::string word;
	std::string::size_type begInd;
	pos = 0;

	begInd = line.find_first_not_of(delimiters);

	while (begInd != std::string::npos) {
		std::string::size_type endInd;
		endInd = line.find_first_of(" ", begInd);

		if (endInd == std::string::npos) {
			endInd = line.length();
		}

		word = line.substr(begInd, endInd - begInd);

		if (isSurname(word)) {
			allSurnames[pos] = word;
			++pos;
		}

		begInd = line.find_first_not_of(" ", endInd);
	}
}

void insertionSort(std::string*& arr, size_t pos)
{
	for (size_t i = 1; i < pos; i++)
	{
		int32_t j = i - 1;

		while (j >= 0 && arr[j] > arr[j + 1])
		{
			std::swap(arr[j], arr[j + 1]);
			j--;
		}
	}
}

template<typename T>
void universalInsertionSort(T* arr, size_t pos, bool comp(T first, T second))
{
	for (size_t i = 1; i < pos; i++)
	{
		int32_t j = i - 1;

		while (j >= 0 && comp(arr[j], arr[j + 1]))
		{
			std::swap(arr[j], arr[j + 1]);
			j--;
		}
	}
}

void getSurnames(std::ifstream& fin, std::string& line, std::string& delimiters, std::string*& allSurnames, size_t& size)
{
	size_t pos = 0;

	while (getline(fin, line)) {
		transformStringForSurnames(line, allSurnames, pos, delimiters);
	}

	if (allSurnames[0] == "") {
		throw std::runtime_error("No surnames!");
	}

	std::cout << "Primal Surnames:\n";
	for (size_t i = 0; i < pos; ++i) {
		std::cout << allSurnames[i] << ' ';
	}

	std::cout << '\n' << "Sorted Surnames:\n";
	insertionSort(allSurnames, pos);
	for (size_t i = 0; i < pos; ++i) {
		std::cout << allSurnames[i] << ' ';
	}
	std::cout << '\n';

	size = pos;
	fin.close();
	line = {};
	delimiters = {};
}

size_t inputChildren(std::string messege)
{
	size_t count = 0;
	do {
		std::cout << "Please enter a count of children for " << messege << '\n';
		std::cin >> count;
	} while (count > 9);
	return count;
}

void fillingArrOfStruct(Employee* arrOfStruct, int32_t* arrOfChildren, std::string* arrOfSurnames, size_t sizeOfSurnames, size_t sizeOfChildren)
{
	bool flag;
	size_t j = 0;
	for (size_t i = 0; i < sizeOfSurnames; ++i)
	{
		flag = false;
		arrOfStruct[i].surname = arrOfSurnames[i];
		for (; j < sizeOfChildren; ++j) {
			if (arrOfChildren[j] < 10 && arrOfChildren[j] >= 0) {
				flag = true;
				arrOfStruct[i].children = arrOfChildren[j];
				++j;
				break;
			}
		}
		if (!flag) {
			arrOfStruct[i].children = inputChildren(arrOfStruct[i].surname);
		}
	}
}

void outputStruct(Employee* arr, size_t size)
{
	for (size_t i = 0; i < size; ++i) {
		std::cout << arr[i].surname << ' ' << arr[i].children << '\n';
	}
}

bool compareEmployees(Employee emp1, Employee emp2) {
	if (emp1.surname != emp2.surname) {
		if (emp1.surname > emp2.surname) {
			return true;
		}
		else {
			return false;
		}
	}
	else {
		if (emp1.surname > emp2.surname) {
			return true;
		}
		else {
			return false;
		}
	}
}

int compareEmployeesForQsort(const void* emp1, const void* emp2)
{
	Employee* employee1 = (Employee*)emp1;
	Employee* employee2 = (Employee*)emp2;

	if (employee1->surname != employee2->surname) {
		return employee1->surname > employee2->surname ? -1 : 1;
	}
	else {
		return employee1->children > employee2->children ? -1 : 1;
	}
}

void menu(Employee* arr, size_t size)
{
	size_t mode = 0;

	do {
		std::cout << "Enter method of sort: Insertion sort (press 1) or algorithm (press 2):\n";
		std::cin >> mode;
	} while (mode > 2);
	switch (mode) {
	case 1:
		universalInsertionSort(arr, size, compareEmployees);
		break;
	case 2:
		static_cast <int32_t> (size);
		std::qsort(arr, size, sizeof(Employee), compareEmployeesForQsort);
		break;
	default:
		throw std::runtime_error("Wrong command!\n");
	}
}

void saveStructInText(std::string line, Employee* arr, size_t size)
{
	std::ofstream fout(line);
	if (fout.is_open()) {
		for (size_t i = 0; i < size; ++i) {
			fout << arr[i].surname << " " << arr[i].children << '\n';
		}
		std::cout << "Text was already saved!";
		fout.close();
	}
}

void saveStructInBin(std::string line, Employee* arr, size_t size)
{
	std::ofstream fout(line, std::ios::binary);
	if (fout.is_open()) {
		for (size_t i = 0; i < size; ++i) {
			fout.write(reinterpret_cast<char*>(&arr[i]), sizeof(Employee));
		}
		std::cout << "\nBin was already saved!";
		fout.close();
	}
}

size_t getPoiterLast(std::ifstream& fin, struct Employee& employeeLast, struct Employee& employeeFirst)
{
	size_t pointerToLast = 0;

	fin.read(reinterpret_cast<char*>(&employeeFirst), sizeof(Employee));
	while (fin.read(reinterpret_cast<char*>(&employeeLast), sizeof(Employee))) {
		pointerToLast = fin.tellg();
	}

	return pointerToLast;
}

void swapStringsInBin(std::ofstream& fout, size_t pointerToLast, struct Employee employeeLast, struct Employee employeeFirst)
{
	fout.seekp(0);
	fout.write(reinterpret_cast<char*>(&employeeLast), sizeof(employeeLast));
	fout.seekp(pointerToLast - sizeof(employeeLast));
	fout.write(reinterpret_cast<char*>(&employeeFirst), sizeof(employeeFirst));
}