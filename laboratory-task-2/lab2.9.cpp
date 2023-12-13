//Написать программу, которая для заданного натурального числа N находит, не превышающие это число дружественные


#include <iostream>
#include <exception>


void inputNumber(size_t& number)
{
  std::cout << " Write number: " << '\n';
  std::cin >> number;
}


int countSum(size_t number)
{
  size_t sum = 0;
  for (size_t i = 1; i < number; ++i)
  {
    if (number % i == 0)
    {
      sum += i;
    }
  }
  return sum;
}


void searchForFriendlyNumbers(size_t number)
{
  std::cout << " Your result: ";
  for (size_t i = 2; i < number; ++i)
  {
    for (size_t ally = 0; ally < i; ++ally)
    {
      if (countSum(i) == ally && countSum(ally) == i)
      {
        std::cout << ally << " & " << i << " ";
      }
    }
  }
}


void checkNumber(size_t& number)
{
  if (number < 1)
  {
    throw " Wrong number! ";
  }
  else
  {
    searchForFriendlyNumbers(number);
  }
}


int main()
{
  try
  {
  size_t number = 0;
  
  inputNumber(number);
  checkNumber(number);
  }
  catch (const char* msg)
  {
    std::cout << msg;
  }
  return 0;
}

