#include "Tree.hpp"

Tree::Tree(
	std::string initName,
	size_t initAge,
	treeTypes initType):
	age(initAge),
	type(initType)
{
	if (initName.length() == 0) {
		throw std::runtime_error("Tree name is empty!\n");
	}
	name = initName;
}

Tree::Tree(const Tree& obj):
	name(obj.name),
	age(obj.age),
	type(obj.type)
{}

std::string Tree::getTreeName() const
{
	return name;
}

size_t Tree::getTreeAge() const
{
	return age;
}

treeTypes Tree::getTreeType() const
{
	return type;
}