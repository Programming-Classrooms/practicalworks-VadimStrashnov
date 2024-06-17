#include "LinkedList.hpp"

void MyList::Clone(const MyList& right)
{
    First = new Node;
    First->info = right.First->info;
    Node* current = First;
    Node* otherCurrent = right.First->Next;

    while (otherCurrent != nullptr) {
        current->Next = new Node;
        current->Next->info = otherCurrent->info;
        current = current->Next;
        otherCurrent = otherCurrent->Next;
    }
}

bool MyList::is_empty()
{
	return First == nullptr;
}

MyList::MyList() : First(nullptr), Last(nullptr)
{

}

MyList::MyList(const MyList& right)
{
    if (right.First == nullptr) {
        First = nullptr;
    }
    else {
        this->Clone(right);
    }
}

MyList::~MyList()
{
    while (First != nullptr)
    {
        DeleteFromEnd();
    }
}

MyList MyList::operator=(MyList right)
{
    while (First != nullptr)
    {
        DeleteFromEnd();
    }
    this->Clone(right);
    return *this;
}

void MyList::insertToBegin(int32_t value)
{
    Node* current = new Node();
    current->info = value;

    if (is_empty()) {
        First = current;
        Last = current;
        return;
    }
    current->Next = First;
    First = current;
}

void MyList::insertToEnd(int32_t value)
{
    Node* current = new Node();
    current->info = value;

    if (is_empty()) {
        First = current;
        Last = current;
        return;
    }
    Last->Next = current;
    Last = current;
}

void MyList::DeleteFromBegin()
{
    if (is_empty())
        return;
    Node* current = First;
    First = current->Next;
    delete current;
}

void MyList::DeleteFromEnd()
{
    if (is_empty())
        return;
    if (First == Last)
        DeleteFromBegin();
        return;

    Node* current = First;

    while (current->Next != Last) {
        current = current->Next;
    }
    current->Next = nullptr;
    delete Last;
    Last = current;
}

void MyList::Delete(int32_t value)
{
    if (is_empty())
    {
        return;
    }
    
    if (First->info == value) {
        DeleteFromBegin();
        return;
    }
    else if (Last->info == value) {
        DeleteFromEnd();
        return;
    }

    Node* slow = First;
    Node* fast = First->Next;

    while (fast && fast->info != value) {
        fast = fast->Next;
        slow = slow->Next;
    }
    if (!fast) {
        std::cout << "Element" << value << "does not exist\n";
        return;
    }
    slow->Next = fast->Next;
    delete fast;
}

MyList::Node* MyList::SearchElem(int32_t value)
{
    Node* current = First;
    while (current && current->info != value) current = current->Next;
    return (current && current->info == value) ? current : nullptr;
}

MyList MyList::changeList()
{
    Node* current = First;
    size_t counter = 0;

    while (current != nullptr)
    {
        std::cout << "Write " << counter << "element:  ";
        std::cin >> current->info;
        current = current->Next;
        ++counter;
    }
    return *this;
}

void MyList::printList()
{
    Node* current = First;
    while (current != nullptr) {
        std::cout << current->info;
        current = current->Next;
    }
    std::cout << '\n';
    return;
}
