#include <iostream>
void number_input(size_t& number)
{
  std::cout << " Write number: " << '\n';
  std::cin >> number;
}
int number_sum(size_t number)
{
  size_t sum = 0;
  for (size_t index = 1; index < number; ++index)
  {
    if (number % index == 0)
    {
      sum += index;
    }
  }
  return sum;
}
void allies_search(size_t number)
{
  std::cout << " Your result: ";
  for (size_t index = 2; index < number; ++index)
  {
    for (size_t ally = 0; ally < index; ++ally)
    {
      if (number_sum(index) == ally && number_sum(ally) == index)
      {
        std::cout << ally << " & " << index << " ";
      }
    }
  }
}
void number_check(size_t& number)
{
  if (number < 1)
  {
    std::cout << " Wrong number! " << '\n';
  }
  else
  {
    allies_search(number);
  }
}
int main()
{
  size_t number = 0;
  number_input(number);
  number_check(number);
  return 0;
}
