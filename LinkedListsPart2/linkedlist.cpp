#include <iostream>
#include <cstring>
#include "linkedlist.h"

using namespace std;

LinkedList::LinkedList()
{
    this->head = nullptr;
    this->tail = nullptr;
    this->size = 0;
}

LinkedList::~LinkedList()
{
    Node *current = head;
    while (current != nullptr)
    {
        Node *temp = current->getNext();
        delete current;
        current = temp;
    }
    delete tail;
}

void LinkedList::add(Node *current, Node *prev, Student *newS, bool isHead)
{
    if (current == nullptr && isHead) // Head doesn't exist
    {
        this->head = new Node(newS);
        this->size = 1;
        return;
    }
    // Node *prev = this->getPrevious(current);
    if (current->getNext() == nullptr) // still have to check to see if it goes before or after
    {
        if (newS->id < current->getStudent()->id)
        {
            Node *newN = new Node(newS);
            if (prev != nullptr)
                prev->setNext(newN);
            else
                this->head = newN;
            newN->setNext(current);
            this->size++;
            return;
        }
        else
        {
            current->setNext(new Node(newS));
            this->size++;
        }
        return;
    }
    if (newS->id < current->getStudent()->id)
    {
        Node *newN = new Node(newS);
        if (prev != nullptr)
            prev->setNext(newN);
        else
            this->head = newN;
        newN->setNext(current);
        this->size++;
        return;
    }
    else
    {
        this->add(current->getNext(), current, newS, false);
    }
}

void LinkedList::add(Student *newS)
{
    Node *current = this->head;
    this->add(current, nullptr, newS, true);
}

void LinkedList::remove(Node *current, Node *prev, int id)
{
    if (current == nullptr)
    {
        return;
    }

    if (current->getStudent()->id == id)
    {
        // Node *prev = this->getPrevious(current);
        Node *next = current->getNext();
        if (prev != nullptr && next != nullptr) // both prev and next are valid nodes
        {
            delete current;
            prev->setNext(next);
            this->size--;
            return;
        }
        else
        {
            if (prev == nullptr)
            {
                this->head = next;
                delete current;
                this->size--;
                return;
            }
            if (next == nullptr)
            {
                prev->setNext(nullptr);
                delete current;
                this->size--;
                return;
            }
        }
    }
    this->remove(current->getNext(), current, id);
}

void LinkedList::remove(int id)
{
    Node *current = this->head;
    return this->remove(current, nullptr, id);
}

bool LinkedList::idExists(int id)
{
    Node *current = this->head;
    for (int i = 0; i < this->size; i++)
    {
        if (current->getStudent()->id == id)
        {
            return true;
        }
        current = current->getNext();
    }
    return false;
}

void LinkedList::getAverageGpa(Node *current, float *sum)
{
    if (current == nullptr)
    {
        return;
    }
    (*sum) += current->getStudent()->gpa;
    this->getAverageGpa(current->getNext(), sum);
}

float *LinkedList::getAverageGpa() // Return a pointer so we can delete it later
{
    float *sum = new float(0); // lmao fr I thought that setting this equal to zero would work (you have to do "new float(0)")
    Node *current = this->head;
    this->getAverageGpa(current, sum);
    (*sum) /= this->getSize();
    // *sum = *sum / this->getSize();;
    return sum;
}

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

int LinkedList::getSize()
{
    return this->size;
}

Node *LinkedList::getHead()
{
    return this->head;
}
