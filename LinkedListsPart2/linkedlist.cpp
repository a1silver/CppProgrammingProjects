#include <iostream>
#include <cstring>
#include "linkedlist.h"

using namespace std;

LinkedList::LinkedList() // Constructor
{
    this->head = nullptr;
    this->size = 0;
}

LinkedList::~LinkedList() // Destructor
{
    Node *current = head;
    // Loop through all students delete one by one.  Keep track of the next element.
    while (current != nullptr)
    {
        Node *temp = current->getNext();
        delete current;
        current = temp;
    }
}

// Recursively add a student & sort IDs by least to greatest
void LinkedList::add(Node *current, Node *prev, Student *newS, bool isHead)
{
    if (current == nullptr && isHead) // Head doesn't exist, list size = 0
    {
        this->head = new Node(newS);
        this->size = 1;
        return;
    }
    if (current->getNext() == nullptr) // We're at the last element of the list
    {                                  // still have to check to see if it goes before or after
        // The student to add should go before our current node
        if (newS->id < current->getStudent()->id)
        {
            Node *newN = new Node(newS);
            if (prev != nullptr)
                prev->setNext(newN);
            else
                this->head = newN;
            newN->setNext(current);
            this->size++;
        }
        // The student to add should go after our current node
        else
        {
            current->setNext(new Node(newS));
            this->size++;
        }
        return;
    }
    if (newS->id < current->getStudent()->id) // This is the same as above but it's ran if we're not at the end of the list
    {                                         // The student to add should go before our current node
        Node *newN = new Node(newS);
        if (prev != nullptr)
            prev->setNext(newN);
        else
            this->head = newN;
        newN->setNext(current);
        this->size++;
        return;
    }
    else // The student to add should go after our current node.
    {    // All we have to do is run add() on the current node's next.
        this->add(current->getNext(), current, newS, false);
    }
}

// Wrapper function for add()
void LinkedList::add(Student *newS)
{
    Node *current = this->head;
    this->add(current, nullptr, newS, true);
}

// Recursively delete a node by student ID
void LinkedList::remove(Node *current, Node *prev, int id)
{
    if (current == nullptr) // We're at the end of the list
    {
        return;
    }

    if (current->getStudent()->id == id) // We found our target ID
    {
        Node *next = current->getNext();
        if (prev != nullptr && next != nullptr) // both prev and next are valid nodes
        {
            delete current;
            prev->setNext(next);
            this->size--;
        }
        else // Either prev or next is null (or both)
        {
            if (prev == nullptr) // Prev would only we null if we're at the head of the list (theoretically)
            {
                this->head = next;
                delete current;
                this->size--;
            }
            if (next == nullptr) // We're at the end of the list (theoretically)
            {
                prev->setNext(nullptr);
                delete current;
                this->size--;
            }
        }
        return;
    }
    // Run the function again on the current node's next if we haven't found our target ID
    this->remove(current->getNext(), current, id);
}

// Wrapper function for remove()
void LinkedList::remove(int id)
{
    Node *current = this->head;
    return this->remove(current, nullptr, id);
}

// Returns true if a student with the given ID is in the list.  Otherwise returns false.
bool LinkedList::idExists(int id)
{
    Node *current = this->head;
    while (current != nullptr)
    {
        if (current->getStudent()->id == id)
        {
            return true;
        }
        current = current->getNext();
    }
    return false;
}

// Recursively goes through all students and updates a float pointer with the sum of all GPAs
void LinkedList::getAverageGpa(Node *current, float *sum)
{
    if (current == nullptr)
    {
        return;
    }
    (*sum) += current->getStudent()->gpa; // Dereference pointer & then update its value
    this->getAverageGpa(current->getNext(), sum); // Run function again on current node's next and pass in the float ptr
}

// Wrapper function for getAverageGpa()
float *LinkedList::getAverageGpa() // Return a pointer so we can delete it later
{
    float *sum = new float(0); // lmao fr I thought that setting this equal to zero would work (you have to do "new float(0)")
    Node *current = this->head;
    this->getAverageGpa(current, sum);
    (*sum) /= this->size; // Dereference pointer & then update its value
    return sum; // Return a pointer to the average gpa
}

// Recursively print out all nodes in the list
void LinkedList::printNode(Node *current)
{
    if (current == nullptr)
    {
        return;
    }
    cout << current->getStudent()->firstname << " ";
    cout << current->getStudent()->lastname << ", ";
    cout << current->getStudent()->id << ", ";
    cout << current->getStudent()->gpa << endl;
    this->printNode(current->getNext());
}

// Wrapper function for printNode()
void LinkedList::printList()
{
    if (this->size == 0)
    {
        cout << "There aren't any students in the list!" << endl;
        return;
    }
    Node *current = this->head;
    this->printNode(this->head);
    cout << endl;
}

// Getter for list size
int LinkedList::getSize()
{
    return this->size;
}

// Getter for list head
Node *LinkedList::getHead()
{
    return this->head;
}
