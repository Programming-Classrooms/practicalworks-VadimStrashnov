/*  Написать программу, которая на заданном отрезке[a, b] натурального ряда чисел
    находит все числа Армстронга 
*/


#include <iostream>
#include <cmath>
#include <exception>


void inputBorder(int32_t& border)
{
    std::cin >> border;
}


void checkNatural(int32_t min, int32_t max)
{
    if (min < 1 || max < 1){
        throw std::exception (" Wrong diapazone!\n");
    }
}


void checkRange(int32_t& min, int32_t& max)
{
    checkNatural(min, max);
    if (min > max){
        std::swap(min, max);
    }
}


int32_t countDegree(int32_t number, int32_t twin)
{
    int32_t degree = 1;
    twin = number;

    while (twin >= 10){
        twin = (float)twin / 10;
        ++degree;
    }

    return degree;
}


int32_t countSum(int32_t twin, int32_t number)
{
    int32_t sum = 0;
    int32_t degree = countDegree(number, twin);
    int32_t remainder = 0;
    twin = number;

    for (int32_t i = 0; i < degree; ++i){
        remainder = twin % 10;
        twin = (twin - remainder) / 10;
        sum += pow(remainder, degree);
        remainder = 0;
    }

    return sum;
}


void searchArmstrongNumbers(int32_t min, int32_t max)
{
    int32_t twin = 0;

    for (int32_t number = min; number <= max; ++number){
        twin = 0;
        int32_t sum = countSum(twin, number);
        if (number == sum){
            std::cout << number << " ";
        }
    }
}


int main()
{
    try
    {
        int32_t min = 0;
        int32_t max = 0;

        std::cout << " Write diapazone:\n";
        std::cout << " Min:\n";
        inputBorder(min);
        std::cout << " Max:\n";
        inputBorder(max);
        checkRange(min, max);

        std::cout << " Your result:\n";
        searchArmstrongNumbers(min, max);
    }
    catch (std::exception e)
    {
        std::cout << e.what();
    }

    return 0;
}
