#include "FruitTree.hpp"

FruitTree::FruitTree(
	std::string initTreeName,
	size_t initTreeAge,
	treeTypes initTreeType,
	double initCropMass,
	size_t initStorageDuration):
	Tree(initTreeName, initTreeAge, initTreeType),
	harvMass(initCropMass),
	storageDuration(initStorageDuration)
{}

FruitTree::FruitTree(const FruitTree& init) :
	Tree(init), harvMass(init.harvMass), storageDuration(init.storageDuration)
{}

FruitTree::FruitTree(
	const FruitTree& init,
	double initCropMass,
	size_t initStorageDuration
) : Tree(init), harvMass(initCropMass), storageDuration(initStorageDuration)
{}

double FruitTree::getCropMass() const
{
	return harvMass;
}

size_t FruitTree::getStorageDration() const
{
	return storageDuration;
}

void FruitTree::print() const
{
	std::cout << "Fruit tree: " << name << '\n';
	std::cout << "Age: " << age << '\n';
	std::cout << "Harvest mass of this tree: " << harvMass << '\n';
	std::cout << "Storage duration: " << storageDuration << " days" << '\n';
}