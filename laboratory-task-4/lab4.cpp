/*В целочисленной квадратной матрице nxn (3&lt;=n&lt;=101, n - нечетное) найти:
- найти сумму элементов нижнего правого треугольника;
- начиная с центра, обойти по спирали все элементы квадратной, выводя их в
порядке обхода. Обход выполнять по часовой стрелки, первый ход - вниз.*/


#include <iostream>
#include <iomanip>
#include <exception>


void chooseMtrxFieldWay(size_t& mode)
{
  std::cout << " choose elements ( press 1 ) or random elements ( press 2 ):\n";
  std::cin.getline (mode, 10);
}


void inputBorder(int32_t& border)
{
  std::cin >> border;
}


void checkBorders(int32_t low_border, int32_t high_border)
{
  if (low_border > high_border)
      {
        std::swap(low_border, high_border);
      }
}


void random(int32_t rows, int32_t** mtrx, int32_t low_border, int32_t high_border)
{
  for (size_t i = 0; i < rows; ++i)
  {
    for (size_t j = 0; j < rows; ++j)
    {
      mtrx[i][j] = (rand() % (high_border - low_border)) + low_border;
    }
  }
  return;
}


void inputRows(int32_t& rows)
{
  std::cout << " Write size of matrix:\n";
  std::cin >> rows;
}


void checkRows(int32_t rows)
{
  if (rows < 3  rows % 2 != 1)
  {
    throw " Wrong size!\n";
  }
}


void createMtrx(int32_t**& mtrx, int32_t rows)
{
  mtrx = new int32_t* [rows];
  for (int32_t i = 0; i < rows; ++i)
  {
    mtrx[i] = new int32_t [rows];
  }
}


void inputElement(int32_t** mtrx, int32_t rows)
{
  std::cout << " Write elements of matrix:\n";
  for (int32_t i = 0; i < rows; ++i)
  {
    for (int32_t j = 0; j < rows; ++j)
    {
      std::cin >> mtrx[i][j];
    }
  }
}


void menu (int32_t rows, int32_t** mtrx, int32_t& low_border, int32_t& high_border, int32_t mode)
{
  switch (mode)
    {
    case 1:
      inputElement(mtrx, rows);
      break;
    case 2:
      std::cout << " Write range:\n";
      std::cout << " Input Min\n";
      inputBorder(low_border);
      std::cout << " Input Max:\n";
      inputBorder(high_border);
      checkBorders(low_border, high_border);
      random(rows, mtrx, low_border, high_border);
      break;
    default:
      throw " Wrong command!\n";
      break;
    }
}


void outputMtrx(int32_t** mtrx, int32_t rows)
{
  std::cout << " Your matrix:\n";
  for (size_t i = 0; i < rows; ++i)
  {
    for (size_t j = 0; j < rows; ++j)
    {
      std::cout << std::setw(7) << mtrx[i][j];
      if (j == rows - 1)
      {
        std::cout << '\n';
      }
    }
  }
}


int32_t lowRightTriangleSum(int32_t** mtrx, int32_t rows)
{
  int32_t triangeSum = 0, counter = 1;
  std::cout << " Your sum:\n";
  for (size_t i = 0; i < rows; ++i)
  {
    for (size_t j = rows - counter; j < rows; ++j)
    {
      triangeSum += mtrx[i][j];
    }
    ++counter;
  }
  return triangeSum;
}


void outputSpiral(int32_t** mtrx, int32_t rows)
{
  int32_t counter = 0, mid = (rows - 1) / 2;
  std::cout << " Your numbers:\n" << mtrx[mid][mid] << " ";
  for (int32_t i = 0; i < rows - 1; i += 2)
  {
    for (size_t j = 0; j <= i + 1; ++j)
    {
      std::cout << mtrx[mid + (counter + 1)][mid - counter - j] << " ";
    }
    for (size_t j = 0; j <= i + 1; ++j)
    {
      std::cout << mtrx[mid + counter - j][mid - (counter + 1)] << " ";
    }
    for (size_t j = 0; j <= i + 1; ++j)
    {
      std::cout << mtrx[mid - (counter + 1)][mid - counter + j] << " ";
    }
    for (size_t j = 0; j <= i + 1; ++j)
    {
      std::cout << mtrx[mid - counter + j][mid + (counter + 1)] << " ";
    }
    ++counter;
  }
}


void deleteMtrx(int32_t**& mtrx, int32_t rows)
{
  for (size_t i = 0; i < rows; ++i)
  {
    delete[] mtrx[i];
  }
  delete [] mtrx;
}


int main()
{
  try
  {
    int32_t rows = 0;
    int32_t mode = 0;
    int32_t low_border = 0;
    int32_t high_border = 0;
    int32_t** mtrx = nullptr;
    
    inputRows(rows);
    checkRows(rows);
    createMtrx(mtrx, rows);
    chooseMtrxFieldWay(mode);
    menu (rows, mtrx, low_border, high_border, mode);
    outputMtrx(mtrx, rows);
    
    //mission 1
    std::cout << lowRightTriangleSum(mtrx, rows) << '\n';

    //mission 2
    outputSpiral(mtrx, rows);
    deleteMtrx(mtrx, rows);
  }
  catch (const char* msg)
  {
    std::cout << msg;
    deleteMtrx(mtrx, rows);
  }
  return 0;
}
