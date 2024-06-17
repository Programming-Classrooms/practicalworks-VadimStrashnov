#define _CRT_SECURE_NO_WARNINGS

#include "MyString.hpp"

MyString::MyString()
{
    arr = nullptr;
    size = 0;
    capacity = 0;
}

MyString::MyString(size_t initsize)
{
    if (initsize == 0){
        size = 0;
        capacity = 1;
        arr[size] = '\0';
    }
    else{
        this->size = initsize;
        capacity = size * 2;
        arr[capacity];
        arr[++size] = '\0';
    }
}

MyString::MyString(const char* string) {
    if (strlen(string) == 0) {
        throw std::invalid_argument("Wrong value of size");
    }

    size = strlen(string);
    capacity = size * 2;
    arr = new char[capacity];
    strcpy(arr, string);
}

MyString::MyString(const MyString& secondObject)
{
    capacity = secondObject.capacity;
    size = secondObject.size;
    arr = new char[size + 1];
    for (int32_t i = 0; i < size; ++i) {
        arr[i] = secondObject.arr[i];
    }
    arr[size] = '\0';
}

MyString::~MyString()
{
    delete[] arr;
}

int32_t MyString::getSize() const
{
    return size;
}

const char* MyString::getCstring() const
{
    char* result = new char[capacity];
    for (size_t i = 0; i < size + 1; ++i) {
        result[i] = arr[i];
    }
    return result;
}

void MyString::setArray()
{
    std::cin.getline(arr, this->size);
    arr[this->size] = '\0';
}

void MyString::getArray()
{
    size_t i = 0;
    while (arr[i] != '\0'){
        std::cout << arr[i];
        i++;
    }
    std::cout << '\n';
}

MyString& MyString::operator=(const MyString& right) {
    if (this != &right) {
        delete[] arr;
        capacity = right.capacity;
        size = right.size;
        arr = new char[capacity];
        strcpy(arr, right.arr);
    }
    else{
        std::invalid_argument("The same string!");
    }
    return *this;
}

void MyString::toLowerCase() {
    for (size_t i = 0; i < size; ++i) {
        arr[i] = tolower(arr[i]);
    }
}

void MyString::toUpperCase() {
    for (size_t i = 0; i < size; ++i) {
        arr[i] = (char)toupper(arr[i]);
    }
}


MyString& MyString::operator=(const char*& right) {
    if (&arr == &right) {
        return *this;
    }
    else {
        delete[] arr;
        size = strlen(right);
        capacity = size * 2;
        arr = new char[capacity];
        strcpy(arr, right);
        return *this;
    }
}

MyString& MyString::operator+=(const MyString& right) {
    char* temp = arr;
    size += right.size;
    char* copy = new char[size + 1];
    strcpy(copy, temp);
    strcat(copy, right.arr);
    delete[] temp;
    arr = copy;
    return *this;
}

MyString& MyString::operator+=(const char*& right) {
    char* temp = arr;
    size += strlen(right);
    char* copy = new char[size + 1];
    strcpy(copy, temp);
    strcat(copy, right);
    delete[] temp;
    arr = copy;

    return *this;
}

MyString MyString::operator+(MyString obj)
{
    MyString sum;

    int32_t iter = 0;
    for (int32_t i = 0; i < this->size; ++i) {
        sum.arr[iter] = this->arr[i];
        ++iter;
    }
    for (int32_t i = 0; i < obj.size; ++i) {
        sum.arr[iter] = obj.arr[i];
        ++iter;
    }

    sum.size = iter;

    return sum;
}

char* MyString::operator+(char* cstring)
{
    char* sum = nullptr;

    int32_t iter = 0;
    for (int32_t i = 0; i < this->size; ++i) {
        sum[iter] = this->arr[i];
        ++iter;
    }
    for (int32_t i = 0; i < strlen(cstring); ++i) {
        sum[iter] = cstring[i];
        ++iter;
    }

    return sum;
}

bool MyString::operator==(const MyString& obj) {
    if (obj.size != this->size && obj.capacity != this->capacity){
        return false;
    }
    for (int i = 0; i < obj.size; i++){
        if (obj.arr[i] != this->arr[i]) return false;
    }
    return true;
}

bool MyString::operator==(char* obj) {
    if (strlen(obj) != this->size) return false;
    for (int i = 0; i < strlen(obj); i++)
    {
        if (obj[i] != this->arr[i]) return false;
    }
    return true;
}

bool MyString::operator<(const MyString& obj)
{
    if (strcmp(arr, obj.arr) == 0)
    {
        return true;
    }
    return false;
}

bool MyString::operator<(char* obj)
{
    if (strcmp(arr, obj) == 0)
    {
        return true;
    }
    return false;
}

bool MyString::operator!=(const MyString& obj) {
    if (obj.size != this->size && obj.capacity != this->capacity) return true;
    for (int i = 0; i < obj.size; i++)
    {
        if (obj.arr[i] != this->arr[i]) return true;
    }
    return false;
}

bool MyString::operator!=(char* obj) {
    if (strlen(obj) != this->size) return true;
    for (int i = 0; i < strlen(obj); i++)
    {
        if (obj[i] != this->arr[i]) return true;
    }
    return false;
}

char& MyString::operator[](int index) {
	if (index < 0 || index >= size) {
		throw::std::out_of_range("Wrong index\n");
	}
	return arr[index];
}

std::istream& operator>>(std::istream& in, MyString& right)
{
    char temp[80];
    in.get(temp, 80);
    if (in)
        right = temp;
    while (in && in.get() != '\n')
        continue;
    right.size = strlen(right.arr);
    right.capacity = right.size * 2;
    right.arr[right.capacity];
    return in;
}

std::ostream& operator<<(std::ostream& out, const MyString& right)
{
    for (int32_t i = 0; i < right.size; ++i)
    {
        out << right.arr[i];
    }
    return out;
}
