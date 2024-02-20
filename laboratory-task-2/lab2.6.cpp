/*  Написать программу, которая для заданного натурального числа
    выполняет разложение числа на простые множители 
*/


#include <iostream>
#include <exception>


void checkNumber(const int32_t number)
{
    if (number < 1){
        throw std::exception (" Wrong number!\n");
    }
}


void inputNumber(int32_t& number)
{
    std::cin >> number;
}


void findingPrimeFactors(int32_t& number, int32_t& divider)
{
    while ((number % divider) == 0 && number != divider){
        number /= divider;
        std::cout << divider << " * ";
    }
}


void findingTheLastPrimeFactor(int32_t& number, int32_t& divider)
{
    if (number == divider){
        number /= divider;
        std::cout << divider;
    }
}


void factoringNumIntoPrimeFactors(int32_t& number)
{
    for (int divider = 2; divider <= number; ++divider){
        findingPrimeFactors(number, divider);
        findingTheLastPrimeFactor(number, divider);
    }
}


int main()
{
    try{
        int32_t number = 0;

        std::cout << " Write element:\n";
        inputNumber(number);
        checkNumber(number);

        std::cout << " Your number:\n" << number << " = ";
        factoringNumIntoPrimeFactors(number);
    }
    catch (std::exception e){
        std::cout << e.what();
    }

    return 0;
}
