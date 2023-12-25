#include <iostream>
#include <cmath>
#include <exception>


template <typename T>
void inputValue(T& value)
{
    std::cin >> value;
}


void checkNumber(const double number)
{
    if (number <= -1 || number > 1){
        throw " Wrong number! ";
    }
}


void checkAccuracy(const size_t accuracy)
{
    if (accuracy <= 1){
        throw " Wrong accuracy! ";
    }
}


void checkEpsilon(const double epsilon, const size_t accuracy)
{
    if (epsilon <= 0 || epsilon >= pow(10, accuracy)){
        throw " Wrong epsilon! ";
    }
}


double sum(double epsilon, double number)
{
    double sum = 0, term = number;
    for (size_t i = 2; abs(term) > epsilon; ++i){
        sum += term;
        term *= (-1 * number * (i - 1)) / i;
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

        std::cout << " Write number:\n";
        inputValue(number);
        checkNumber(number);
        std::cout << " Write accuracy:\n";
        inputValue(accuracy);
        checkAccuracy(accuracy);
        std::cout << " Write epsilon:\n";
        inputValue(epsilon);
        checkEpsilon(epsilon, accuracy);
        std::cout << sum(epsilon, number) << '\n' << log(number + 1) << " = " << sum(epsilon, number);
    }
    catch (const char* msg)
    {
        std::cout << msg;
    }
}
