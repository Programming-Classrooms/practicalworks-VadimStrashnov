/*  В одномерном массиве, состоящем из п вещественных элементов, вычислить:
    - длину самой длинной цепочки попарно различных элементов, стоящих подряд;
    - сумму целых частей элементов массива, расположенных после последнего отрицательного
    элемента.
    Преобразовать массив таким образом, чтобы сначала располагались все элементы,
    отличающиеся от максимального не более чем на 20%, а потом — все остальные. Порядок
    следования элементов не изменять.
*/


#include <iostream>
#include <cmath>
#include <exception>


template <typename T>
void inputValue(T& value)
{
    std::cin >> value;
}


void writeElem(int32_t number, double arr[])
{
    for (int32_t i = 0; i < number; ++i){
        std::cin >> arr[i];
    }
}


void checkBorders(int32_t& lowBorder, int32_t& highBorder)
{
    if (lowBorder > highBorder){
        std::swap(lowBorder, highBorder);
    }
}


void randomElements(int32_t number, double  arr[], int32_t lowBorder, int32_t highBorder)
{
    for (size_t i = 0; i < number; ++i){
        arr[i] = lowBorder + rand() * (highBorder - lowBorder) / RAND_MAX;
    }
}


void menu(int32_t number, double  arr[], int32_t& lowBorder, int32_t& highBorder, int32_t mode)
{
    switch (mode){
    case 1:
        std::cout << " Write array elements:\n";
        writeElem(number, arr);
        break;
    case 2:
        std::cout << " Write diapazon:\n";
        std::cout << " Input Min:\n";
        inputValue(lowBorder);
        std::cout << " Input Max:\n";
        inputValue(highBorder);
        checkBorders(lowBorder, highBorder);
        randomElements(number, arr, lowBorder, highBorder);
        break;
    default:
        throw std::exception (" Wrong command!\n ");
        break;
    }
}


void primalArray(int32_t number, double arr[])
{
    for (int32_t i = 0; i < number; ++i){
        std::cout << arr[i] << " ";
    }
    std::cout << '\n';
}


double max(int32_t number, double arr[])
{
    double max = arr[0];

    for (int32_t i = 0; i < number; ++i){
        if (max < arr[i])
        {
            max = arr[i];
        }
    }

    return max;
}


int32_t countLength(int32_t number, double arr[])
{
    int32_t currentLength = 1;
    int32_t maxLength = 1;

    for (int32_t i = 1; i < number; ++i){
        if (arr[i] != arr[i - 1]){
            ++currentLength;
        }
        else{
            if (currentLength > maxLength){
                maxLength = currentLength;
            }
            currentLength = 1;
        }
    }

    if (currentLength > maxLength){
        maxLength = currentLength;
    }

    return maxLength;
}


int32_t negative(int32_t number, double arr[])
{
    int32_t lastNegative = -1;

    for (int32_t i = 0; i < number; ++i){
        if (arr[i] < 0){
            lastNegative = i;
        }
    }

    return lastNegative;
}


double sumAfterNegative(int32_t number, double arr[], int32_t lastnegative)
{
    double sum = 0;

    for (size_t i = lastnegative + 1; i < number; ++i){
        sum += floor(arr[i]);
    }

    return sum;
}


void conditionSumAfterNegative(int32_t number, double arr[])
{
    if (negative(number, arr) == number - 1){
        std::cout << " Summa does not exist!\n ";
    }

    else if (negative(number, arr) != -1){
        std::cout << " Summa after last negative: " << sumAfterNegative(number, arr, negative(number, arr)) << '\n';
    }

    else{
        std::cout << " No negative elements\n";
    }
}


void conditionSort(int32_t number, double arr[])
{
    int32_t count = 0;

    for (size_t i = 0; i <= number; ++i){
        int32_t count = 0;
        if (max(number, arr) >= 0){
            if (arr[i] >= max(number, arr) * 0.8){
                for (size_t j = i; j > count; --j){
                    std::swap(arr[j - 1], arr[j]);
                }
                ++count;
            }
        }
        else{
            if (arr[i] >= max(number, arr) * 1.2){
                for (size_t j = i; j > count; --j){
                    std::swap(arr[j - 1], arr[j]);
                }
                ++count;
            }
        }
    }
}


void completeArray(int32_t& number, double arr[])
{
    for (size_t i = 0; i < number; ++i){
        std::cout << arr[i] << " ";
    }
}


int main()
{
    try{
        int32_t number = 0;
        int32_t lowBorder = 0;
        int32_t highBorder = 0;
        int32_t mode = 0;
        double arr[1000] = { 0 };

        srand(time(NULL));
        std::cout << " Write number:\n";
        inputValue(number);
        if (number < 1){
            throw std::exception(" Wrong number!\n ");
        }
        else{
            std::cout << " choose elements ( press 1 ) or random elements ( press 2 )\n";
            inputValue(mode);
            menu(number, arr, lowBorder, highBorder, mode);
            std::cout << " Current array:\n ";
            primalArray(number, arr);

            std::cout << " The longest: " << countLength(number, arr) << '\n';

            conditionSumAfterNegative(number, arr);
            conditionSort(number, arr);

            std::cout << " Formed array:\n ";
            completeArray(number, arr);
        }
    }
    catch (std::exception e){
        std::cout << e.what();
    }

    return 0;
}