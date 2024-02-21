#define _CRT_SECURE_NO_WARNINGS
#include "../fraction/Header.hpp"
#include <string.h>

int main()
{
	try 
	{
		Array a(5);
		Array b(5);
		std::cout << a;
		a = a + 3;
		std::cout << a;
		std::cout << b;
		a + b;
		std::cout << a;
	}
	catch(std::exception e)
	{
		std::cout << e.what();
	}

	return 0;
}