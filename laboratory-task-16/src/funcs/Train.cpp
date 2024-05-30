#include "Train.hpp"
#include <iostream>

// Конструктор по умолчанию
Train::Train() : trainNumber(0), travelTime(0) {}

// Конструктор с параметрами
Train::Train(int32_t number, std::string dest, std::string type, std::string depTime, int32_t travel)
    : trainNumber(number), destination(dest), trainType(type), departureTime(depTime), travelTime(travel) {}

// Деструктор
Train::~Train() {}

// Геттеры
int32_t Train::getTrainNumber() const {
    return trainNumber;
}

std::string Train::getDestination() const {
    return destination;
}

std::string Train::getTrainType() const {
    return trainType;
}

std::string Train::getDepartureTime() const {
    return departureTime;
}

int32_t Train::getTravelTime() const {
    return travelTime;
}

// Сеттеры
void Train::setTrainNumber(int32_t number) {
    trainNumber = number;
}

void Train::setDestination(const std::string& dest) {
    destination = dest;
}

void Train::setTrainType(const std::string& type) {
    trainType = type;
}

void Train::setDepartureTime(const std::string& depTime) {
    departureTime = depTime;
}

void Train::setTravelTime(int32_t travel) {
    travelTime = travel;
}

// Оператор присваивания
Train& Train::operator=(const Train& other) {
    if (this == &other) {
        return *this;
    }

    trainNumber = other.trainNumber;
    destination = other.destination;
    trainType = other.trainType;
    departureTime = other.departureTime;
    travelTime = other.travelTime;

    return *this;
}

// Оператор ввода
std::istream& operator>>(std::istream& is, Train& train) {
    is >> train.trainNumber >> train.destination >> train.trainType >> train.departureTime >> train.travelTime;
    return is;
}

// Оператор вывода
std::ostream& operator<<(std::ostream& os, const Train& train) {
    os << "Train Number: " << train.trainNumber << '\n';
    os << "Destination: " << train.destination << '\n';
    os << "Train Type: " << train.trainType << '\n';
    os << "Departure Time: " << train.departureTime << '\n';
    os << "Travel Time: " << train.travelTime << '\n';
    return os;
}
