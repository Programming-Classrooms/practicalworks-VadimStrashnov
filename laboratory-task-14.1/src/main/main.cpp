#include "src/funcs/Student.hpp"
#include "src/funcs/Professor.hpp"
#include "src/funcs/Person.hpp"

void menu()
{
	size_t size = 0;

	while (size <= 0)
	{
		std::cout << "Enter size List = ";
		std::cin >> size;
	}

	size_t counter = 0;
	Person** arr = new Person* [size];

	int16_t op = 0;
	while (op != 5 && counter < size)
	{
		std::cout << "Enter Student - 1\n";
		std::cout << "Enter Professor - 2\n";
		std::cout << "Print List Student - 3\n";
		std::cout << "Print List Professor - 4\n";
		std::cout << "Exit - 5\n";
		std::cout << " Choice : ";
		std::cin >> op;
		switch (op)
		{

		case 1:
		{
			/* ���������� �������� � ������ */
			char* buffer = new char[2000];
			int32_t cource = 0;
			int32_t group = 0;
			std::cout << "Enter surname, name and patronym: ";
			std::cin.ignore();
			std::cin.getline(buffer, 2000);
			std::cout << "\nEnter cource: ";
			std::cin >> cource;
			std::cout << "\nEnter group: ";
			std::cin >> group;
			arr[counter++] = new Student(buffer, cource, group);
			delete buffer;
			break;
		}

		case 2:
		{
			/* ���������� ���������� � ������ */
			char buffer[2000];
			char buffer2[2000];
			std::cout << "Enter name and surname: ";
			std::cin.ignore();
			std::cin.getline(buffer, 2000);
			std::cout << "\nEnter name department: ";
			std::cin.getline(buffer2, 2000);
			arr[counter++] = new Professor(buffer, buffer2);
			break;
		}

		case 3:
		{
			/* ����� ������ ��������� */
			std::cout << "\n***************************\n" << "List Students :\n\n";
			bool check = false;
			for (size_t i = 0; i <= counter; ++i)
			{
				if (dynamic_cast<Student*>(arr[i])) {
					arr[i]->print(std::cout);
					std::cout << "\n\n";
					check = true;
				}
			}
			if (!check) {
				std::cout << " There are no students on the list \n";
			}
			std::cout << "\n***************************\n";
			break;
		}

		case 4:
		{
			/* ����� ������ ����������� */
			std::cout << "\n***************************\n" << "List Professors :\n\n";
			bool check = false;
			for (size_t i = 0; i <= counter; ++i) {
				if (dynamic_cast<Professor*>(arr[i])) {
					arr[i]->print(std::cout);
					std::cout << "\n\n";
					check = true;
				}
			}
			if (!check) {
				std::cout << " There are no professors on the list \n";
			}
			std::cout << "\n***************************\n";
			break;
		}
		default:
		{
			std::cout << " Select an available operation \n";
			break;
		}
		}
	}
	/* � ������ ������������ ������� */
	if (counter == size){
		std::cout << "\n****************\nYour list is full\n\n" << "Elements in List : \n*********************\n";
		for (size_t i = 0; i <= counter; ++i)
		{
			if (dynamic_cast<Student*>(arr[i])) {
				std::cout << " Student: \n";
				arr[i]->print(std::cout);
				std::cout << "\n\n";
			}
			else if (dynamic_cast<Professor*>(arr[i])) {
				std::cout << " Professor: \n";
				arr[i]->print(std::cout);
				std::cout << "\n\n";
			}
		}
	}
}

int main() 
{
	menu();
	return 0;
}