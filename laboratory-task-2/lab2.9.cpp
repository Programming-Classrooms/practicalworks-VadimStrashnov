/*  Написать программу, которая для заданного натурального числа N находит,
    не превышающие это число дружественные числа
*/


#include <iostream>
#include <exception>


void inputNumber(size_t& number)
{
    std::cin >> number;
}


int countSum(const size_t number)
{
    size_t sum = 0;
    for (size_t i = 1; i < number; ++i) {
        if (number % i == 0) {
            sum += i;
        }
    }
    return sum;
}


void searchForFriendlyNumbers(const size_t number)
{
    for (size_t i = 2; i < number; ++i) {
        for (size_t ally = 0; ally < i; ++ally) {
            if (countSum(i) == ally && countSum(ally) == i) {
                std::cout << ally << " & " << i << " ";
            }
        }
    }
}


void checkNumber(const size_t number)
{
    if (number < 1) {
        throw " Wrong number!\n";
    }
    else {
        std::cout << " Your result:\n";
        searchForFriendlyNumbers(number);
    }
}


int main()
{
    try {
        size_t number = 0;

        std::cout << " Write number:\n";
        inputNumber(number);
        checkNumber(number);
    }
    catch (const char* msg) {
        std::cout << msg;
    }
    
    return 0;
}
