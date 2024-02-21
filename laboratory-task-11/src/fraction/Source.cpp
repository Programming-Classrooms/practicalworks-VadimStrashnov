#include "Header.hpp"

void Array::fillArray() {
    srand(time(NULL));
    for (int32_t i = 0; i < size; ++i) {
        arr[i] = rand() % 2 - 1;
    }
}

Array::Array(): size(10), arr(new int32_t [size])
{
  Array::fillArray();
}

Array::Array(int64_t size) : size(size), arr(new int32_t[size]) {
    std::cout << "constructor\n";
    if (size <= 0) {
        throw std::invalid_argument("wrong size\n");
    }
    Array::fillArray();
}

Array::Array(const Array& init) : size(init.size), arr(new int32_t[size]) {
    std::cout << "constructor of copy\n";
    for (int32_t i = 0; i < size; ++i) {
        arr[i] = init.arr[i];
    }
}

Array::~Array()
{
    std::cout << "destructor\n";
    delete[] arr;
}

Array& Array::operator=(const Array& right)
{
    if (this != &right) {
        delete[] arr;
        size = right.size;
        arr = new int32_t[size];
        for (int32_t i = 0; i < size; ++i) {
            arr[i] = right.arr[i];
        }

        return *this;
    }

}

int32_t Array::getSize() const
{
    return size;
}

void Array::setSize(int size)
{
    if (size <= 0) {
        throw std::invalid_argument("wrong size\n");
    }
}

int32_t& Array::operator[](int index)
{
    if (index < 0 || index >= size) {
        throw std::out_of_range("bad index\n");
    }

    return arr[index];
}

Array& Array::operator++()
{
    for (int32_t i = 0; i < size; i++)
    {
        ++arr[i];
    }

    return *this;
}

Array Array::operator++(int k)
{
    Array tmp(*this);
    for (int32_t i = 0; i < size; i++)
    {
        ++arr[i];
    }

    return tmp;
}

Array& Array::operator+(const Array& second)
{
    if (size != second.size)
    {
        std::cout << "Not correct size!";
    }
    else
    {
        for (int32_t i = 0; i < size; ++i)
        {
            arr[i] += second.arr[i];
        }
    }

    return *this;
}

Array Array::operator+(int32_t number)
{
    for (int32_t i = 0; i < size; ++i)
    {
        arr[i] += number;
    }

    return *this;
}

std::ostream& operator<<(std::ostream& out, const Array& right) {
    for (int32_t i = 0; i < right.size; ++i) {
        out << right.arr[i] << '\t';
    }
    out << '\n';

    return out;
}

void String::setSize(size_t size)
{
    if (size <= 0) {
        throw std::invalid_argument("wrong size\n");
    }
    this->size = size;
}

String::String(size_t size)
{
    this->size = size + 1;
    arr = new char[size + 1];
}

String::String() 
{ String(10); }

String::~String()
{
    delete[] arr;
}

void String::enterArray()
{
    std::cin.getline(arr, this->size);
    arr[this->size] = '\0';
}
void String::printArray()
{
    int i = 0;
    while (this->arr[i] != '\0')
    {
        std::cout << this->arr[i];
        i++;
    }
    std::cout << '\n';
}
String String::operator+(String obj)
{
    String newarray = String(obj.size + this->size - 2);
    int i = 0;
    for (; i < this->size - 1; i++)
    {
        newarray.arr[i] = this->arr[i];
    }
    for (int j = 0; j < obj.size - 1; j++)
    {
        newarray.arr[i + j] = obj.arr[j];
    }
    newarray.arr[newarray.size - 1] = '\0';
    return newarray;
}
bool String::operator==(String obj) {
    if (obj.size != this->size) return false;
    for (int i = 0; i < obj.size; i++)
    {
        if (obj.arr[i] != this->arr[i]) return false;
    }
    return true;
}
bool String::operator!=(String obj) {
    if (obj.size != this->size) return true;
    for (int i = 0; i < obj.size; i++)
    {
        if (obj.arr[i] != this->arr[i]) return true;
    }
    return false;
}