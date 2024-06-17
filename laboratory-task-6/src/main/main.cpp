#include "../funcs/Functions.hpp"

int main()
{
	try {
		std::string line;
		std::ifstream fin("Numbers.txt");
		std::string delimiters{};
		int32_t* allNumbers = new int32_t[300]{};
		size_t sizeOfNumbers = 0;

		getDelimiters(delimiters, fin);
		getNumbers(fin, line, delimiters, allNumbers, sizeOfNumbers);

		std::ifstream finString("Strings.txt");
		std::string* allSurnames = new std::string[300]{};

		size_t sizeOfSurnames = 0;
		getDelimiters(delimiters, finString);
		getSurnames(finString, line, delimiters, allSurnames, sizeOfSurnames);

		Employee* employees = new Employee[sizeOfSurnames];
		fillingArrOfStruct(employees, allNumbers, allSurnames, sizeOfSurnames, sizeOfNumbers);
		std::cout << "Employees and number of children:\n";
		outputStruct(employees, sizeOfSurnames);

		menu(employees, sizeOfSurnames);
		std::cout << "Sorted struct:\n";
		outputStruct(employees, sizeOfSurnames);

		std::string lineForTxt = "result.txt";
		saveStructInText(lineForTxt, employees, sizeOfSurnames);

		std::string lineForBin = "result.bin";
		saveStructInBin(line, employees, sizeOfSurnames);
		std::ifstream finBin(lineForBin, std::ios::binary);

		Employee lastEmployee, firstEmployee;
		size_t pointerToLast = getPoiterLast(finBin, lastEmployee, firstEmployee);

		finBin.close();
		std::ofstream foutBin(lineForBin, std::ios::binary | std::ios::app);
		swapStringsInBin(foutBin, pointerToLast, lastEmployee, firstEmployee);
		foutBin.close();

		deleteArray(employees);
		deleteArray(allNumbers);
		deleteArray(allSurnames);
	}
	catch (const std::exception& e) {
		std::cout << e.what();
	}

	return 0;
}
