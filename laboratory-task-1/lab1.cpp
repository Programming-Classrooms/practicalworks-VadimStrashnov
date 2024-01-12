/*  Разработать консольное приложение для вычисления приближённого значения функции, 
    используя представление ее в виде ряда Тейлора.
    Вычисления заканчивать, когда очередное слагаемое окажется по модулю меньше заданного числа epsilon,
    где 0 < epsilon <= 10-k , k – натуральное число, k>1. Сравнить полученный результат со значением,
    вычисленным с помощью стандартных функций. Значение x и k ввести по запросу.
*/


#include <iostream>
#include <cmath>


void inputNumber(double& number)
{
  std::cout << " Write number: " << '\n';
  std::cin >> number;
}


void checkNumber(double number)
{
  if (number <= -1 || number > 1)
  {
    throw std::exception (" Wrong number! ");
  }
}


void inputAccuracy(size_t& accuracy)
{
  std::cout << " Write accuracy: " << '\n';
  std::cin >> accuracy;
}


void checkAccuracy(size_t accuracy)
{
  if (accuracy <= 1)
  {
    throw std::exception (" Wrong accuracy! ");
  }
}


void inputEpsilon(double& epsilon)
{
  std::cout << " Write epsilon: " << '\n';
  std::cin >> epsilon;
}


void checkEpsilon(double epsilon, size_t accuracy)
{
  if (epsilon <= 0 || epsilon >= pow(10, accuracy))
  {
    throw std::exception (" Wrong epsilon! ");
  }
}


double sum(double epsilon, double number)
{
  double sum = 0;
  double term = number;

  for (size_t i = 2; abs(term) > epsilon; ++i)
  {
    sum += term;
    term *= ( - 1 * number * (i - 1)) / i;
  }

  return sum;
}


int main()
{
  try
  {
    size_t accuracy = 0;
    double epsilon = 0;
    double number = 0;

    inputNumber(number);
    checkNumber(number);
    inputAccuracy(accuracy);
    checkAccuracy(accuracy);
    inputEpsilon(epsilon);
    checkEpsilon(epsilon, accuracy);

    std::cout << '\n' << log(number + 1) << " = " << sum(epsilon, number);
  }
  catch (std::exception e)
  {
    std::cout << e.what() << '\n';
  }

  return 0;
}
