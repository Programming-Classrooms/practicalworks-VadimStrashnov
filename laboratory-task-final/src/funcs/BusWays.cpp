#include "BusWays.hpp"

BusRoute::BusRoute(int32_t initRoute, std::string initDriver, int32_t initNumOfBus, std::string initBrand):
numOfWay(initRoute),
driver(initDriver),
numOfBus(initNumOfBus),
brandOfBus(initBrand)
{
}

BusRoute::BusRoute(const BusRoute& right)
{
    numOfWay = right.numOfWay;
    driver = right.driver;
    numOfBus = right.numOfBus;
    brandOfBus = right.brandOfBus;
}

void BusRoute::operator=(const BusRoute& right)
{
    //if(this == right&)
    //{
    //    throw std::logic_error("The same Bus Number");
    //}

    numOfWay = right.numOfWay;
    driver = right.driver;
    numOfBus = right.numOfBus;
    brandOfBus = right.brandOfBus;
}

int32_t BusRoute::getNumOfRoute()
{
    return this->numOfWay;
}

std::string BusRoute::getDriver()
{
    return this->driver;
}

int32_t BusRoute::getNumOfBus()
{
    return this->numOfBus;
}
std::string BusRoute::getBrand()
{
    return this->brandOfBus;
}

void BusRoute::setNumOfRoute(const int32_t& num)
{
    this->numOfWay = num;
}

void BusRoute::setDriver(const std::string& string)
{
    this->driver = string;
}

void BusRoute::setNumOfBus(const int32_t& num)
{
    this->numOfBus = num;
}

void BusRoute::setBrand(const std::string& string)
{
    this->brandOfBus = string;
}

std::ostream& operator<<(std::ostream& out, const BusRoute& right)
{
    out << right.numOfWay << ' ' << right.driver << ' ' << right.numOfBus << ' ' << right.brandOfBus << '\n';
}

std::istream& operator>>(std::istream& in, BusRoute& right)
{
    std::cout << "Write number of route: ";
    in >> right.numOfWay;
    std::cout << '\n';
    std::cout << "Write driver: ";
    in >> right.driver;
    std::cout << '\n';
    std::cout << "Write number of bus: ";
    in >> right.numOfBus;
    std::cout << '\n';
    std::cout << "Write brand: ";
    in >> right.brandOfBus;
    std::cout << '\n';
}
