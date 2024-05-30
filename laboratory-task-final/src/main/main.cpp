#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <map>
#include <set>

#include "src/funcs/BusWays.hpp"

// Компараторы для std::sort
bool compareByNumBus(BusRoute& a, BusRoute& b)
{
    return a.getNumOfBus() < b.getNumOfBus();
}

bool compareByNumRoute(BusRoute& a, BusRoute& b)
{
    return a.getNumOfRoute() < b.getNumOfRoute();
}

// Функция проверки файла
void checkFile(std::ifstream& file)
{
    if (!file.good())
    {
        throw std::logic_error("File don't exist!\n");
    }

    if (!file)
    {
        throw std::logic_error("File not opened!\n");
    }

    if (file.peek() == EOF)
    {
        throw std::logic_error("File is empty!\n");
    }
}

// Функция чтения файла
void readFile(const std::ifstream& file, std::vector<BusRoute>& busRoutes)
{
    std::string line;
    while(getline(file, line))
    {
        {
            std::vector<std::string> data;
            size_t pos = 0;
            std::string temp;

            while(pos = line.find(',') != std::string::npos)
            {
                temp = line.substr(0, pos);
                data.push_back(temp);
                line.erase(0, pos + 1);
            }

            data.push_back(line);

            int32_t initNumOfWay = std::stoi(data[0]);
            std::string initDriver = data[1];
            int32_t initNumOfBus = std::stoi(data[0]);
            std::string initBrandOfBus = data[3];
            
            BusRoute route(initNumOfWay, initDriver, initNumOfBus, initBrandOfBus) ;
            busRoutes.push_back(route);
        }
    }
}

// Функция вывода вектора маршрутов автобуса
void writeBusRoutes(const std::vector<BusRoute>& busRoutes)
{
    for (const auto& route : busRoutes)
    {
        std::cout << route;
    }
}

int main()
{
    try 
    {
        //1 задание

        std::ifstream fin("Routes.txt");
        std::vector<BusRoute> busRoutes;

        checkFile(fin);
        readFile(fin, busRoutes);

        std::sort(busRoutes.begin(), busRoutes.end(), compareByNumBus);
        writeBusRoutes(busRoutes);

        std::sort(busRoutes.begin(), busRoutes.end(), compareByNumRoute);
        writeBusRoutes(busRoutes);


        // 2 Задание (4, 5)

        // 4c

        std::map<int32_t, BusRoute> mapRoutes;

        for(const auto& route : busRoutes)
        {
            int32_t number = route.getNumOfRoute();
            std::pair<int32_t, BusRoute> pair {number, route};
            mapRoutes.insert(pair);
        }

        int32_t numOfRoute = 0;

        std::cout << "Write Number of Route:\n";
        std::cin >> numOfRoute;

        std::cout<< "List of drivers on this route: \n";
        for(const auto& pair : mapRoutes)
        {
            if (pair.first == numOfRoute)
            {
                std::cout << pair.second.getDriver() << ' ';
            }
        }
        std::cout << '\n';

        // 4a

        std::set<int32_t> setOfRoutes;
        for(const auto& route : busRoutes)
        {
            int32_t numRoute = route.getNumOfRoute();
            setOfRoutes.insert(numRoute);
        }

        std::cout<< "List of routes: \n";
        for(const auto& number : setOfRoutes)
        {
            std::cout << number << " ";
        }
        std::cout << '\n';

        // Смена автобуса (5c)

        int32_t busNum

        std::cout << "Write number of bus:\n";
        std::cin >> busNum;

         for(const auto& route : busRoutes)
        {
            if(route.getNumOfBus() == busNum)
            {
                int32_t newNum = 0;
                std::string newBrand;

                std::cout << "New bus number:" << "\n";
                std::cin >> newNum;
                std::cout << "New bus brand:" << "\n";
                std::cin >> newBrand;

                if (newNum <= 0)
                {
                    throw std::invalid_argument("Wrong number of bus!\n");
                }
                
                if (newBrand == "")
                {
                    throw std::invalid_argument("Wrong brand of bus!\n");
                }

                route.setNumOfBus(newNum);
                std::cout << "Number Changed!\n";
                route.setBrand(newNum);
                std::cout << "Brand Changed!\n";
            }
        }

        //3 задание (6)

        std::string name;

        std::cout << "Write Driver:\n";
        std::cin >> name;

        std::cout << "Number of Route:\n"
        for(const auto& route : busRoutes)
        {
            if(route.getDriver == name)
            {
                std::cout << route.getNumOfRoute() << "\n";
            }
        }

        return 0;
    }
    catch(const std::logic_error& a)
    {
        std::cout << a.what();
    }
    catch(const std::invalid_argument& a)
    {
        std::cout << a.what();
    }
}
