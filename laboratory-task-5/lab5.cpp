//Пример #12 на фото


#include <exception>
#include <iostream>
#include <cmath>


void inputEpsilon(double& eps)
{
  std::cout << " Write epsilon:\n";
  std::cin >> eps;
}


void checkEpsilon(const double eps, const  double lowborder, const  double highborder)
{
  if (eps <= lowborder || eps >= highborder)
  {
    throw " Wrong epsilon!\n";
  }
}


double step(const double lowborder, const double highborder, const size_t counter)
{
  double step = (highborder - lowborder) / counter;
  return step;
}


double theFirstFunction(const double number)
{
  double result = sin(number * 0.4) * pow(number, 0.23);
  return result;
}


double theSecondFunction(const double number)
{
  double result = exp(-1 * pow(number, 2)) * pow(sin(0.4 * number), 2) / (pow(number, 2) + 3.5);
  return result;
}


double theThirdFunction(const double number)
{
  double result = exp(1.1 * number / (pow(number, 2) + 1)) / (pow(number, 2) + 1.1);
  return result;
}


double formulaTheAverageRectangle(const double eps, const double lowborder, const double highborder, double (*function)(double))
{
  size_t counter = 4;
  double sumOfIntegrals = 0;
  double lastSumOfIntegrals = -1;
  double h = 0;
  double x = 0;
  while (fabs(sumOfIntegrals - lastSumOfIntegrals) >= eps) {
    lastSumOfIntegrals = sumOfIntegrals;
    sumOfIntegrals = 0;
    counter *= 2;
    h = step(lowborder, highborder, counter);
    for (size_t i = 1; i < counter; ++i) {
      x = lowborder + i * h - h / 2;
      sumOfIntegrals += h * function(x);
    }
  }
  return sumOfIntegrals;
}


double formulaTheAverageTrapezoid(const double eps, const  double lowborder, const double highborder, double (*function)(double))
{
  double sumOfIntegrals = 0;
  double lastSumOfIntegrals = -1;
  size_t counter = 4;
  while (fabs(sumOfIntegrals - lastSumOfIntegrals) >= eps){
    counter *= 2;
    double h = step(lowborder, highborder, counter);
    lastSumOfIntegrals = sumOfIntegrals;
    sumOfIntegrals = h * (function(lowborder) + function(highborder)) / 2;
    for (double i = h; i < highborder; i += h){
      sumOfIntegrals += h * function(i);
    }
  }
  return sumOfIntegrals;
}


int main()
{
  try{
    double eps = 0;
    double lowborder = 0;
    double highborder = 1;

    inputEpsilon(eps);
    checkEpsilon(eps, lowborder, highborder);
    std::cout << " First result:\n" << formulaTheAverageRectangle(eps, lowborder, highborder, theFirstFunction) << '\n' << formulaTheAverageTrapezoid(eps, lowborder, highborder, theFirstFunction) << '\n';
    std::cout << " Second result:\n" << formulaTheAverageRectangle(eps, lowborder, highborder, theSecondFunction) << '\n' << formulaTheAverageTrapezoid(eps, lowborder, highborder, theSecondFunction) << '\n';
    std::cout << " Third result:\n" << formulaTheAverageRectangle(eps, lowborder, highborder, theThirdFunction) << '\n' << formulaTheAverageTrapezoid(eps, lowborder, highborder, theThirdFunction) << '\n';
  }
  catch (const char* msg){
    std::cout << msg;
  }
  return 0;
}
