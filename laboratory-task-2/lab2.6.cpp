//Написать программу, которая для заданного натурального числа  выполняет разложение числа на простые множители


#include <iostream>
#include <exception>


void checkNumber(int32_t& number)
{
  if (number < 1)
  {
    throw " Wrong number!\n";
  }
}


void inputNumber(int32_t& number)
{
  std::cout << " Write element:\n";
  std::cin >> number;
}


void findingPrimeFactors(int32_t& number, int32_t& div)
{
  while ((number % divider) == 0 && number != divider)
  {
    number /= divider;
    std::cout << divider << " * ";
  }
}


void findingTheLastPrimeFactor(int32_t& number, int32_t& div)
{
  if (number == divider)
  {
    number /= divider;
    std::cout << divider;
  }
}


void forizataction(int32_t& number)
{
  for (int divider = 2; divider <= number; ++divider)
  {
    findingPrimeFactors(number, divider);
    findingTheLastPrimeFactor(number, divider);
  }
}


int main()
{
  try
  {
    int32_t number = 0;

    inputNumber(number);
    checkNumber(number);
    std::cout << " Your number:\n" << number << " = ";
    factorization(number);
  }
  catch (const char* msg)
  {
    std::cout << msg;
  }
  return 0;
}
