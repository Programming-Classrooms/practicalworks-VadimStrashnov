/*В одномерном массиве, состоящем из п вещественных элементов, вычислить:
- длину самой длинной цепочки попарно различных элементов, стоящих подряд;
- сумму целых частей элементов массива, расположенных после последнего отрицательного 
элемента.
Преобразовать массив таким образом, чтобы сначала располагались все элементы, 
отличающиеся от максимального не более чем на 20%, а потом — все остальные. Порядок 
следования элементов не изменять.*/


#include <iostream>
#include <cmath>


void inputNumber(int& number) 
{
  std::cout << " Write number: " << '\n';
  std::cin >> number;
}


void writeElem(int number, double arr[])
{
  for (int i = 0; i < number; i++)
  {
    std::cin >> arr[i];
  }
}


void inputMode(int& mode)
{
  std::cout << " choose elements ( press 1 ) or random elements ( press 2 ) " << '\n';
  std::cin >> mode;
}


void inputBorder(int& border)
{
  std::cout << " Input min " << '\n';
  std::cin >> border;
}


void randomElements(int number, double  arr[], int lowBorder, int highBorder)
{
  for (size_t i = 0; i < number; ++i)
  {
    arr[i] = lowBorder + rand() * (highBorder - lowBorder) / RAND_MAX;
  }
}


void primalArray(int number, double arr[])
{
  std::cout << " Current array: ";
  for (int index = 0; index < number; ++index)
  {
    std::cout << arr[index] << " ";
  }
  std::cout << '\n';
}


double max(int number, double arr[])
{
  double max = arr[0];
  for (int i = 0; i < number; ++i)
  {
    if (max < arr[i])
    {
      max = arr[i];
    }
  }
  return max;
}


int countLength(int number, double arr[])
{
  int currentLength = 1;
  int maxLength = 1;
  for (int i = 1; i < number; ++i)
  {
    if (arr[i] != arr[i - 1])
    {
      ++currentLength;
    }
    else
    {
      if (currentLength > maxLength)
      {
        maxLength = currentLength;
      }
      currentLength = 1;
    }
  }
  if (currentLength > maxLength)
  {
    maxLength = currentLength;
  }
  return maxLength;
}


int negative(int number, double arr[])
{
  int lastNegative = -1;
  for (int i = 0; i < number; ++i)
  {
    if (arr[i] < 0)
    {
      lastNegative = i;
    }
  }
  return lastNegative;
}


double sumAfterNegative(int number, double arr[], int lastnegative)
{
  double sum = 0;
  for (int index = lastnegative + 1; index < number; ++index)
  {
    sum += floor(arr[index]);
  }
  return sum;
}


void conditionSumAfterNegative(int number, double arr[])
{
  if (negative(number, arr) != -1)
  {
    std::cout << " Summa after last negative: " << sumAfterNegative(number, arr, negative(number, arr)) << '\n';
  }
  else
  {
    std::cout << " No negative elements " << '\n';
  }
}


void conditionSort(int number, double arr[])
{
  int count = 0;
  for (int i = 0; i <= number; ++i)
  {
    int count = 0;
    if (max(number, arr) >= 0)
    {
      if (arr[i] >= max(number, arr) * 0.8)
      {
        for (int j = i; j > count; --j)
        {
          std::swap(arr[j - 1], arr[j]);
        }
        ++count;
      }
    }
    else
    {
      if (arr[i] >= max(number, arr) * 1.2)
      {
        for (int j = i; j > count; --j)
        {
          std::swap(arr[j - 1], arr[j]);
        }
        ++count;
      }
    }
  }
}


void completeArray(int& number, double arr[])
{
  std::cout << " Formed array: ";
  for (int index = 0; index < number; ++index)
  {
    std::cout << arr[index] << " ";
  }
}


int main()
{
  int number = 0, mode = 0, highBorder = 0, lowBorder = 0;
  double arr[1000] = { 0 };
  srand(time(0));
  inputNumber(number);
  if (number < 1)
  {
    std::cout << " Uncorrect number " << '\n';
  }
  else
  {
    inputMode(mode);
    switch (mode)
    { 
    case 1:
      std::cout << " Write array elements: " << '\n';
      writeElem(number, arr);
      break;
    case 2:
      std::cout << " Write diapazon: " << '\n';
      inputBorder(lowBorder);
      inputBorder(highBorder);
      if (lowBorder > highBorder)
      {
        std::swap(lowBorder, highBorder);
      }
        randomElements(number, arr, lowBorder, highBorder);

      break;
    default:
      std::cout << " Wrong command " << '\n';
      return false;
      break;
    }
    primalArray(number, arr);

    std::cout << " The longest: " << countLength(number, arr) << '\n';

    conditionSumAfterNegative(number, arr);

    conditionSort(number, arr);
    completeArray(number, arr);
  }
  return 0;
}

