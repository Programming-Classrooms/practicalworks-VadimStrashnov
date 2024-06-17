#include "src/funcs/TreeContainer.hpp"
#include <iomanip>
#include <fstream>

bool checkFile(std::ifstream& file, std::string path)
{
	if (!file.good()) {
		std::string mes = "File not found! Path: ";
		mes.append(path);
		throw std::invalid_argument(mes);
	}
	if (!file) {
		std::string mes = "File is bad! Path: ";
		mes.append(path);
		throw std::ios_base::failure(mes);
	}
	if (file.peek() == EOF) {
		std::string mes = "File is empti! Path: ";
		mes.append(path);
		throw std::runtime_error(mes);
	}
	return true;
}


int main()
{
	TreesContainer trees;
	std::string pathToFile = "src/ForTxt/ListOfTrees.txt";
	std::ifstream fin(pathToFile);

	if (checkFile(fin, pathToFile)) {
		fin >> trees;
	}
	trees.print();
	std::cout << "Number Of Deciduous Trees: " << trees.countingByTreeType(treeTypes::Deciduous) << '\n';
	trees.sortTreesVector();
	trees.print();
}
