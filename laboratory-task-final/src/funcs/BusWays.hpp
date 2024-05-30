#ifndef BUSWAYS_HPP
#define BUSWAYS_HPP

#include<iostream>
#include <string>

class BusRoute
{
private:
// Поля класса
    int32_t numOfWay = 0;
    std::string driver;
    int32_t numOfBus = 0;
    std::string brandOfBus;
public:
// Конструкторы
    BusRoute() = default;
    BusRoute(int32_t, std::string, int32_t, std::string);
    BusRoute(const BusRoute&);

// Оператор присваивания
    void operator=(const BusRoute& right);

// Геттеры
    int32_t getNumOfRoute();
    std::string getDriver();
    int32_t getNumOfBus();
    std::string getBrand();

// Сеттеры
    void setNumOfRoute(const int32_t&);
    void setDriver(const std::string&);
    void setNumOfBus(const int32_t&);
    void setBrand(const std::string&);

// Операторы ввода и вывода
    friend std::ostream& operator<<(std::ostream&, const BusRoute&);
    friend std::istream& operator>>(std::istream&, BusRoute&);
};

#endif //BUSWAYS_HPP
