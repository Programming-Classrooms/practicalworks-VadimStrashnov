#define _CRT_SECURE_NO_WARNINGS
#include "../funcs/MyString.hpp"
#include <string.h>

int main()
{
	try {
		MyString a("fer");
		std::cout << a;
		a = "red";
		a += "der";
		a.toUpperCase();
		std::cout << a;
		a.toLowerCase();
		std::cout << a;
		std::cout << a[0] << '\n';
		std::cin >> a;
		a.toUpperCase();
		std::cout << a << '\n';
		MyString c;
		std::cout << c.getSize() << '\n';
		MyString b("FER");
		if (a == b) {
			std::cout << "Strings are equal\n";
		}
		else {
			std::cout << "Strings are not equal\n";
		}
		MyString left("gag");
		MyString right("faf");
		if (left < right) {
			std::cout << "Left is less\n";
		}
		else {
			std::cout << "Right is less\n";
		}
	}
	catch (std::invalid_argument& e) {
		std::cerr << e.what();
	}
	catch (std::exception& e) {
		std::cerr << e.what();
	}
	catch (std::out_of_range& e) {
		std::cerr << e.what();
	}
	return 0;
}
