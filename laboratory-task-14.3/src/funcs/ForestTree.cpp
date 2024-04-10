#include "ForestTree.hpp"

ForestTree::ForestTree(
	std::string initTreeName,
	size_t initTreeAge,
	treeTypes initTreeType,
	double initWoodAmount): 
	Tree(initTreeName, initTreeAge, initTreeType),
	woodQuantity(initWoodAmount)
{}

ForestTree::ForestTree(const ForestTree& init):
	Tree(init),
	woodQuantity(init.woodQuantity)
{}

ForestTree::ForestTree(const ForestTree& init, double initWA):
	Tree(init),
	woodQuantity(initWA)
{}

double ForestTree::getWoodAmount() const
{
	return this->woodQuantity;
}

void ForestTree::print() const
{
	std::cout << "Forest Tree Name: " << name << '\n';
	std::cout << "Age: " << age << '\n';
	std::cout << "Quantity of wood: " << woodQuantity << '\n';
}