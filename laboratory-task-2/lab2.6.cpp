//Написать программу, которая для заданного натурального числа  выполняет разложение числа на простые множители

#include <iostream>


void number_check(int& number)
{
  if (number < 1)
  {
    throw " Wrong number! ";
  }
}


void number_input(int& number)
{
  std::cout << " Write element: ";
  std::cin >> number;
}


void div_op1(int& number, int& div)
{
  while ((number % div) == 0 && number != div)
  {
    number /= div;
    std::cout << div << " * ";
  }
}


void div_op2(int& number, int& div)
{
  if (number == div)
  {
    number /= div;
    std::cout << div;
  }
}


void operation(int& number)
{
  for (int div = 2; div <= number; ++div)
  {
    div_op1(number, div);
    div_op2(number, div);
  }
}


int main()
{
  try
  {
    int number = 0;
    number_input(number);
    number_check(number);
    std::cout << " Your number: " << number << " = ";
    operation(number);
  }
  catch (const char* msg)
  {
    std::cout << msg;
  }
  return 0;
}

