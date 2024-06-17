/*  Вычислить значение определенного интеграла с аналитически заданной подынтегральной
    функцией с заданной точностью eps
    А) по формуле левых прямоугольников;
    Б) по формуле правых прямоугольников;
    В) по формуле средних прямоугольников;
    Г) по формуле трапеций;
    Д) по формуле Симпсона (параболических трапеций).

    Формула средних прямоугольников:
    ∫f(x)dx ≈ h*[f(x 1 )+ f(x 2 )+…+ f(x n )], где h=(b-a)/n, f(x i )=a+i*h-h/2,

    где n–число точек деления отрезка [a, b]. Для вычисления первого приближения можно взять
    n=4. Чтобы оценить точность, с которой вычислено значение интеграла, необходимо найти второе
    приближение. Для этого можно увеличить n в два раза. Если s 1 и s 2 – два соседних приближения и |s 1
    – s 2 |&lt;eps, то точность считается достигнутой и s 2 принимается за искомое значение интеграла. В
    противном случае надо положить s 1 = s 2 и удвоить число точек деления отрезка [a, b]. После этого
    вычисляется новое значение s 2 . Процесс удвоения n и вычисления s 2 надо продолжать до тех пор,
    пока модуль разности s 1 и s 2 не станет меньше eps. Остальные формулы посмотреть самим.

    Разработать функции, реализующие методы вычислений интеграла, входными параметрами
    которых должны быть функция для вычисления значения подынтегрального выражения, пределы
    интегрирования и точность вычислений. Головная программа должна вывести результат вычислений
    для записанных в задании интегралов по заданным формулам и значение n, при котором достигнута
    заданная точность. Для проверки вычислений в таблице приведены значения интегралов.
*/


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
    throw std::exception (" Wrong epsilon!\n");
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
  catch (std::exception e) {
    std::cout << e.what();
  }

  return 0;
}
