/*В целочисленной квадратной матрице nxn (3&lt;=n&lt;=101, n - нечетное) найти:
- найти сумму элементов нижнего правого треугольника;
- начиная с центра, обойти по спирали все элементы квадратной, выводя их в
порядке обхода. Обход выполнять по часовой стрелки, первый ход - вниз.*/


#include <iostream>


void chooseMtrxFieldWay(size_t& mode)
{
  std::cout << " choose elements ( press 1 ) or random elements ( press 2 ): " << '\n';
  std::cin >> mode;
}


void inputBorder(size_t& border)
{
  std::cout << " Input  " << '\n';
  std::cin >> border;
}


void random(size_t rows, size_t** mtr, size_t low_border, size_t high_border)
{
  for (size_t i = 0; i < rows; ++i)
  {
    for (size_t j = 0; j < rows; ++j)
    {
      mtr[i][j] = (rand() % (high_border - low_border)) + low_border;
    }
  }
  return;
}


void inputRows(size_t& rows)
{
  std::cout << " Write size of matrix: " << '\n';
  std::cin >> rows;
}


void checkRows(size_t rows)
{
  if (rows < 3  rows % 2 != 1)
  {
    throw " Wrong size! ";
  }
}


void createMtrx(size_t** mtr, size_t rows)
{
  for (size_t i = 0; i < rows; ++i)
  {
    mtr[i] = new size_t {0};
  }
}


void inputElement(size_t** mtr, size_t rows)
{
  std::cout << " Write elements of matrix: " << '\n';
  for (size_t i = 0; i < rows; ++i)
  {
    for (size_t j = 0; j < rows; ++j)
    {
      std::cin >> mtr[i][j];
    }
  }
}


void outputMtrx(size_t** mtr, size_t rows)
{
  std::cout << " Your matrix: " << '\n';
  for (size_t i = 0; i < rows; ++i)
  {
    for (size_t j = 0; j < rows; ++j)
    {
      std::cout << " " << mtr[i][j];
      if (j == rows - 1)
      {
        std::cout << '\n';
      }
    }
  }
}


size_t lowRightTriangleSum(size_t** mtr, size_t rows)
{
  size_t triangeSum = 0, counter = 1;
  std::cout << " Your sum: " << '\n';
  for (size_t i = 0; i < rows; ++i)
  {
    for (size_t j = rows - counter; j < rows; ++j)
    {
      triangeSum += mtr[i][j];
    }
    ++counter;
  }
  return triangeSum;
}


void outputSpiral(size_t** mtr, size_t rows)
{
  size_t counter = 0, mid = (rows - 1) / 2;
  std::cout << " Your numbers: " << '\n' << mtr[mid][mid] << " ";
  for (size_t i = 0; i < rows - 1; i += 2)
  {
    for (size_t j = 0; j <= i + 1; ++j)
    {
      std::cout << mtr[mid + (counter + 1)][mid - counter - j] << " ";
    }
    for (size_t k = 0; k <= i + 1; ++k)
    {
      std::cout << mtr[mid + counter - k][mid - (counter + 1)] << " ";
    }
    for (size_t f = 0; f <= i + 1; ++f)
    {
      std::cout << mtr[mid - (counter + 1)][mid - counter + f] << " ";
    }
    for (size_t g = 0; g <= i + 1; ++g)
    {
      std::cout << mtr[mid - counter + g][mid + (counter + 1)] << " ";
    }
    ++counter;
  }
}


void deleteMtrx(size_t** mtr, size_t rows)
{
  for (size_t i = 0; i < rows; ++i)
  {
    delete[] mtr[i];
  }
  delete [] mtr;
}


int main()
{
  try
  {
    size_t rows = 0, mode = 0, low_border = 0, high_border = 0;
    size_t** mtr = new size_t* { 0 };
    inputRows(rows);
    checkRows(rows);
    createMtrx(mtr, rows);
    chooseMtrxFieldWay(mode);
    switch (mode)
    {
    case 1:
      inputElement(mtr, rows);
      break;
    case 2:
      std::cout << " Write diapazon: " << '\n';
      std::cout << " Input Min " << '\n';
      inputBorder(low_border);
      std::cout << " Input Max " << '\n';
      inputBorder(high_border);
      if (low_border > high_border)
      {
        std::swap(low_border, high_border);
      }
      random(rows, mtr, low_border, high_border);
      break;
    default:
      throw " Wrong command! ";
      break;
    }
    outputMtrx(mtr, rows);
    
    //mission 1
    std::cout << lowRightTriangleSum(mtr, rows) << '\n';

    //mission 2
    outputSpiral(mtr, rows);
    deleteMtrx(mtr, rows);
  }
  catch (const char* msg)
  {
    std::cout << msg;
  }
}

