#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>
#include <string>
#include <numeric> 
#include <algorithm>

#include "../funcs/Train.hpp"

struct Student {
    std::string name;
    int32_t course = 0;
    std::string group;
};

int32_t sum(std::vector <int32_t> initArr)
{
	int32_t sum = 0;

	for (size_t i = 0; i < initArr.size(); ++i){
		sum += initArr[i];
	}
	return sum;
}

bool compareByName(const Student& a, const Student& b) {
    return a.name < b.name;
}

bool compareByCourseGroup(const Student& a, const Student& b) {
    if (a.course == b.course) {
        return a.group < b.group;
    }
    return a.course < b.course;
}

std::vector<std::vector<int>> deleteMaxElement(std::vector<std::vector<int>>& matrix, int32_t& rows, int32_t& cols) {
    // Поиск максимального элемента
    int maxElement = -2147483648;
    int maxRow = -1;
    int maxCol = -1;
    for (int32_t i = 0; i < matrix.size(); ++i) {
        for (int32_t j = 0; j < matrix[i].size(); ++j) {
            if (matrix[i][j] > maxElement) {
                maxElement = matrix[i][j];
                maxRow = i;
                maxCol = j;
            }
        }
    }

    // Проверка границ
    if (maxRow >= 0 && maxRow < matrix.size() && maxCol >= 0 && maxCol < matrix[maxRow].size()) {
        // Удаление строки и столбца максимального элемента
        matrix.erase(matrix.begin() + maxRow);
        for (int32_t i = 0; i < matrix.size(); ++i) {
            matrix[i].erase(matrix[i].begin() + maxCol);
        }
        rows = matrix.size();
        cols = matrix[0].size();
    }

    return matrix;
}

bool compareDepartureTime(const Train& train1, const Train& train2) {
    return train1.departureTime < train2.departureTime;
}

int main()
{
	try {
        setlocale(LC_ALL, "Russian");

        std::vector<int32_t> numbers;
        int32_t input;

        std::cout << "Write numbers (press 0 to comlete):" << std::endl;
        while (true) {
            std::cin >> input;
            if (input == 0) {
                break;
            }
            numbers.push_back(input);
        }

        // ����� �����
        int32_t sum = 0;
        for (int32_t num : numbers) {
            sum += num;
        }
        std::cout << "Summa: " << sum << std::endl;

        // ����� ���������� �����
        int32_t totalNumbers = numbers.size();
        std::cout << "Number of numbers: " << totalNumbers << std::endl;

        // ���������� �����, ������ ���������
        int32_t targetNumber = 5; // ������: ���� ����� 5
        int32_t countTarget = std::count(numbers.begin(), numbers.end(), targetNumber);
        std::cout << "Numbers = " << targetNumber << ": " << countTarget << std::endl;

        // ���������� �����, ������� ��� �������� �����
        int32_t n = 10; // ������: ���� ����� ������ 10
        int32_t countGreaterThanN = std::count_if(numbers.begin(), numbers.end(), [n](int32_t num) { return num > n; });
        std::cout << "Numbers > " << n << ": " << countGreaterThanN << std::endl;

        // ������ ���� ����� ������� ��������������
        int32_t average = sum / totalNumbers;
        std::replace_if(numbers.begin(), numbers.end(), [](int32_t num) { return num == 0; }, average);

        // ���������� � ������� �������� ������� ����� ���� ����� �� ��������� ���������
        std::for_each(numbers.begin(), numbers.end(), [sum](int32_t& num) { num += sum; });

        // ������ �����, ������ ������� ���� ������ �����, �� �������� ������������� � ������������ ��������
        int32_t maxNum = *std::max_element(numbers.begin(), numbers.end());
        int32_t minNum = *std::min_element(numbers.begin(), numbers.end());
        std::replace_if(numbers.begin(), numbers.end(), [](int32_t num) { return abs(num) % 2 == 0; }, maxNum - minNum);

        // �������� �� ������������������ ���� ������ �� ������ �����, ����� ������� �� ���
        std::vector<int32_t> uniqueNumbers;
        std::copy_if(numbers.begin(), numbers.end(), std::back_inserter(uniqueNumbers), [&uniqueNumbers](int32_t num) {
            return std::find(uniqueNumbers.begin(), uniqueNumbers.end(), abs(num)) == uniqueNumbers.end();
            });

        // ����� �����������
        std::cout << "Changed vector:" << std::endl;
        for (int32_t num : numbers) {
            std::cout << num << " ";
        }
        std::cout << std::endl;


        // 3 �������

        std::vector<std::string> words;

        // ������ ������ ���� �� ���������� �����
        std::ifstream file("Words.txt");
        std::string word;
        while (file >> word) {
            words.push_back(word);
        }
        file.close();

        // ���������� ������
        std::sort(words.begin(), words.end());

        // ������ ���������������� ������
        std::cout << "Sorted list of words:\n";
        for (const auto& initWord : words) {
            std::cout << initWord << " ";
        }
        std::cout << std::endl;

        // ������ ��������� ������, ������������ �� �������� �����
        char startLetter = 'q';
        std::cout << "Words begin from " << startLetter << ":\n";
        for_each(words.begin(), words.end(), [startLetter](const std::string& w) {
            if (w.front() == startLetter) {
                std::cout << w << " ";
            }
            });
        std::cout << std::endl;

        // �������� ��������� ������ �� �������� �����
        char letterToDelete = 'u';
        words.erase(std::remove_if(words.begin(), words.end(), [letterToDelete](const std::string& w) {
            return w.front() == letterToDelete;
            }), words.end());

        // ������ ������ ����� �������� ���������
        std::cout << "List after delete words begin " << letterToDelete << ":\n";
        for (const auto& initWord : words) {
            std::cout << initWord << " ";
        }
        std::cout << std::endl;


        // 4 �������

        int32_t rows = 0, cols = 0;

        std::cout << "Enter the number of rows: ";
        std::cin >> rows;

        std::cout << "Enter the number of columns: ";
        std::cin >> cols;

        int32_t lower_bound = 0, upper_bound = 0;

        std::cout << "Enter the lower bound for the elements: ";
        std::cin >> lower_bound;

        std::cout << "Enter the upper bound for the elements: ";
        std::cin >> upper_bound;

        std::vector<std::vector<int32_t>> matrix(rows, std::vector<int32_t>(cols));

        // Fill the matrix with random values
        for (int32_t i = 0; i < rows; ++i) {
            for (int32_t j = 0; j < cols; ++j) {
                matrix[i][j] = rand() % (upper_bound - lower_bound + 1) + lower_bound;
            }
        }

        // Find the maximum element in the matrix
        int32_t max_element = matrix[0][0];
        int32_t max_row = 0, max_col = 0;

        for (int32_t i = 0; i < rows; ++i) {
            for (int32_t j = 0; j < cols; ++j) {
                if (matrix[i][j] > max_element) {
                    max_element = matrix[i][j];
                    max_row = i;
                    max_col = j;
                }
            }
        }

        for (int32_t i = 0; i < rows; ++i) {
            for (int32_t j = 0; j < cols; ++j) {
                std::cout << matrix[i][j] << " ";
            }
            std::cout << std::endl;
        }

        deleteMaxElement(matrix, rows, cols);

        for (int32_t i = 0; i < rows; ++i) {
            for (int32_t j = 0; j < cols; ++j) {
                std::cout << matrix[i][j] << " ";
            }

            std::cout << std::endl;
        }

        // Сортировка по сумме элементов в каждой строке
        for (int32_t i = 0; i < rows; ++i) {
            for (int32_t j = i + 1; j < rows; ++j) {
                int32_t sum_i = 0, sum_j = 0;

                for (int32_t k = 0; k < cols; ++k) {
                    sum_i += matrix[i][k];
                    sum_j += matrix[j][k];
                }

                if (sum_i > sum_j) {
                    std::swap(matrix[i], matrix[j]);
                }
            }
        }

       

        // Вывод изменённой матрицы
        std::cout << "Modified Matrix:" << std::endl;

        for (int32_t i = 0; i < rows; ++i) {
            for (int32_t j = 0; j < cols; ++j) {
                std::cout << matrix[i][j] << " ";
            }

            std::cout << std::endl;
        }


        // 5 �������

        std::ifstream inputFile("Students.txt");
        std::ofstream outputByName("Fio.txt");
        std::ofstream outputByCourseGroup("Groups.txt");

        std::vector<Student> students;

        // ������ ������ �� �����
        while (!inputFile.eof()) {
            Student student;
            inputFile >> student.name >> student.course >> student.group;
            students.push_back(student);
        }

        // ���������� �� ��������
        std::sort(students.begin(), students.end(), compareByName);

        // ������ � ���� Fio.txt
        for (const auto& student : students) {
            outputByName << student.name << " " << student.course << " " << student.group << std::endl;
        }

        // ���������� �� ������ � �������
        std::sort(students.begin(), students.end(), compareByCourseGroup);

        // ������ � ���� Groups.txt
        for (const auto& student : students) {
            outputByCourseGroup << student.name << " " << student.course << " " << student.group << std::endl;
        }

        inputFile.close();
        outputByName.close();
        outputByCourseGroup.close();


        // 6 ������� 

        std::ifstream inputTrains("Trains.txt");
        if (!inputTrains.is_open()) {
           throw std::invalid_argument("File not open");
        }

        std::vector<Train> trains;

        // ���������� ������ �� ����� � ������ trains
        int32_t number;
        std::string dest, type, depTime;
        int32_t travel;
        while (inputFile >> number >> dest >> type >> depTime >> travel) {
            trains.emplace_back(Train(number, dest, type, depTime, travel));
        }

        // �������������� ������� �� ������� �����������
        std::sort(trains.begin(), trains.end(), compareDepartureTime);

        // ����� ���������� ��� ���� �������
        for (const auto& train : trains) {
            std::cout << "Train Number: " << train.trainNumber << ", Place of ariving: " << train.destination << ", Type of train: " << train.trainType << ", time of arriving: " << train.departureTime << ", Time in travel: " << train.travelTime << " hours" << std::endl;
        }

        inputFile.close();

        return 0;
	}
	catch (const std::invalid_argument& a)
	{
        std::cout << a.what();
	}
}