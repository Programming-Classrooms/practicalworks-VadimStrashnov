#ifndef TREE_HPP
#define TREE_HPP
#include <iostream>
#include <string>


enum treeTypes
{
	Deciduous,
	Coniferous
};

class Tree
{
protected:
	std::string name;
	size_t age;
	treeTypes type;
public:
	Tree() = default;
	Tree(std::string, size_t, treeTypes);
	Tree(const Tree&);
	virtual ~Tree() {}

	std::string getTreeName() const;
	size_t getTreeAge() const;
	treeTypes getTreeType() const;

	virtual void print() const = 0;
};
#endif // TREE_HPP
