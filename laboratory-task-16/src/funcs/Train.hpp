#ifndef TRAIN_HPP
#define TRAIN_HPP

#include <string>
#include <iostream>

class Train {
public:
    int32_t trainNumber;
    std::string destination;
    std::string trainType;
    std::string departureTime;
    int32_t travelTime;

    // Конструкторы
    Train();
    Train(int32_t number, std::string dest, std::string type, std::string depTime, int32_t travel);

    // Деструктор
    ~Train();

    // Геттеры
    int32_t getTrainNumber() const;
    std::string getDestination() const;
    std::string getTrainType() const;
    std::string getDepartureTime() const;
    int32_t getTravelTime() const;

    // Сеттеры
    void setTrainNumber(int32_t number);
    void setDestination(const std::string& dest);
    void setTrainType(const std::string& type);
    void setDepartureTime(const std::string& depTime);
    void setTravelTime(int32_t travel);

    // Оператор присваивания
    Train& operator=(const Train& other);

    // Оператор ввода
    friend std::istream& operator>>(std::istream& is, Train& train);

    // Оператор вывода
    friend std::ostream& operator<<(std::ostream& os, const Train& train);
};

#endif  // TRAIN_HPP
