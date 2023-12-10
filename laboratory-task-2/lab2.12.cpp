//Написать программу, которая на заданном отрезке [a,b] натурального ряда чисел находит все числа Армстронга


#include <iostream>
#include <cmath>


void min_input(int& min)
{
  std::cout << " Min: ";
  std::cin >> min;
}


void max_input(int& max)
{
  std::cout << " Max: ";
  std::cin >> max;
}


void natural_check(int& min, int& max)
{
  if (min < 1 || max < 1)
  {
    throw " Wrong diapazone! ";
  }
}


void diapazone_check(int& min, int& max)
{
  natural_check(min, max);
  if (min > max)
  {
    std::swap(min, max);
  }
}


void diapazone(int& min, int& max)
{
  std::cout << " Write diapazone: " << '\n';
  min_input(min);
  max_input(max);
  diapazone_check(min, max);
}


int count(int& number, int twin)
{
  int degree = 1;
  twin = number;
  while ( twin >= 10 )
  {
    twin = (float)twin / 10;
    ++degree;
  }
  return degree;
}


int sum_search( int twin, int number)
{
  int sum = 0;
  int degree = count(number, twin);
  int remainder = 0;
  twin = number;
  for (int index = 0; index < degree; ++index)
  {
    remainder = twin % 10;
    twin = ( twin - remainder ) / 10;
    sum += pow(remainder, degree);
    remainder = 0;
  }
  return sum;
}


void operation(int& min, int& max, int& twin)
{
  std::cout << " Your result: ";
  for (int number = min; number <= max; ++number)
  {
    twin = 0;
    int sum = sum_search(twin, number);;
    if (number == sum)
    {
      std::cout << number << " ";
    }
  }
}


int main()
{
  try 
  {
    int twin = 0;
    int min = 0, max = 0;
    diapazone(min, max);
    operation(min, max, twin);
  }
  catch (const char* msg)
  {
    std::cout << msg;
  }
  return 0;
}

