#ifndef LINKEDLIST_HPP
#define LINKEDLIST_HPP

#include <iostream>
#include <exception>

class MyList
{
	struct Node
	{
		int32_t info;
		Node* Next;
	};
	Node* First;
	Node* Last;
public:
	MyList();
	MyList(const MyList&);
	~MyList();

	bool is_empty();
	void Clone(const MyList&);
	MyList operator=(MyList);
	void insertToBegin(int32_t);
	void insertToEnd(int32_t);
	void DeleteFromBegin();
	void DeleteFromEnd();
	void Delete(int32_t);
	Node* SearchElem(int32_t value);
	MyList changeList();
	void printList();
};


#endif