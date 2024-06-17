#include "src/funcs/Student.hpp"
#include "src/funcs/StudentAfterFirstSession.hpp"
#include "src/funcs/StudentAfterSecondSession.hpp"

int main()

{
	std::cout << '\n';
	StudentAfterFirst obj1("Ber", 4, 6552, 52334324, 1, 2 ,3, 4);
	std::cout << obj1 << '\n';
	obj1.getMarks();
	std::cout << '\n';
	StudentAfterSecond obj2(obj1, 5, 6, 7, 8, 9);
	std::cout << obj2 << "Average mark after a year: " << obj2.Average() << '\n' << "Marks of second session:\n";
	obj2.getMarks();
	std::cout << '\n';
	return 0;
}
