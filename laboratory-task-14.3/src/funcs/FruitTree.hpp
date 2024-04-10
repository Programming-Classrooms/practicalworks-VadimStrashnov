#ifndef FRUITTREE_HPP
#define FRUITTREE_HPP
#include "Tree.hpp"


class FruitTree final : public Tree
{
private:
	double harvMass;
	size_t storageDuration;
public:
	FruitTree(std::string, size_t, treeTypes, double, size_t);
	FruitTree(const FruitTree&);
	FruitTree(const FruitTree&, double, size_t);
	~FruitTree() {}

	double getCropMass() const;
	size_t getStorageDration() const;

	void print() const override;
};
#endif // !FRUITTREE_HPP