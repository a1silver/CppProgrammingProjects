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
}

void LinkedList::append(Student *student)
{
    Node *newNode = new Node(student);
    newNode->setNext(nullptr);
    if (this->tail == nullptr)
    {
        this->head = newNode;
        this->tail = newNode;
    }
    else
    {
        this->tail->setNext(newNode);
        this->tail = newNode;
    }
    this->size++;
}

void LinkedList::prepend(Student *student)
{
    Node *newNode = new Node(student);
    newNode->setNext(this->head);
    this->head = newNode;
    if (this->tail == nullptr)
    {
        this->tail = this->head;
    }
    this->size++;
}

void LinkedList::insert(int index, Student *student)
{
    if (index == 0)
    {
        prepend(student);
    }
    else if (index >= size)
    {
        append(student);
    }
    else
    {
        Node *newNode = new Node(student);
        Node *current = this->head;
        for (int i = 0; i < index - 1; i++)
        {
            current = current->getNext();
        }
        newNode->setNext(current->getNext());
        current->setNext(newNode);
        this->size++;
    }
}

void LinkedList::remove(int index)
{
    if (index == 0)
    {
        Node *toDelete = this->head;
        head = this->head->getNext();
        delete toDelete;
        if (this->head == nullptr)
        {
            this->tail = nullptr;
        }
        this->size--;
    }
    else if (index >= size)
    {
        Node *current = this->head;
        for (int i = 0; i < this->size - 1; i++)
        {
            current = current->getNext();
        }
        Node *toDelete = current->getNext();
        current->setNext(nullptr);
        this->tail = current;
        delete toDelete;
        this->size--;
    }
    else
    {
        Node *current = this->head;
        for (int i = 0; i < index - 1; i++)
        {
            current = current->getNext();
        }
        Node *toDelete = current->getNext();
        current->setNext(current->getNext()->getNext());
        delete toDelete;
        // current->getNext() = current->getNext()->getNext();
        // delete toDelete;
        this->size--;
    }
}

Student *LinkedList::get(int index)
{
    Node *current = this->head;
    for (int i = 0; i < index; i++)
    {
        current = current->getNext();
    }
    return current->getStudent();
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

int LinkedList::getIndexOfId(int id)
{
    Node *current = this->head;
    for (int i = 0; i < this->size; i++)
    {
        if (current->getStudent()->id == id)
        {
            return i;
        }
        current = current->getNext();
    }
    return -1;
}

void LinkedList::getAverageGpa(Node *current, float *sum)
{
    if (current == nullptr)
    {
        return;
    }
    cout << "add current student to sum" << endl;
    (*sum) += current->getStudent()->gpa;
    cout << "recur" << endl;
    this->getAverageGpa(current->getNext(), sum);
}

float *LinkedList::getAverageGpa() // Return a pointer so we can delete it later
{
    cout << "create sum" << endl;
    float *sum = new float(0); // lmao fr I thought that setting this equal to zero would work (you have to do "new float(0)")
    cout << "get current" << endl;
    Node *current = this->head;
    cout << "start recursion" << endl;
    this->getAverageGpa(current, sum);
    cout << "average the sum" << endl;
    (*sum) /= this->getSize();
    // *sum = *sum / this->getSize();;
    cout << "return the sum" << endl;
    return sum;
}

/*
float LinkedList::getAverageGpa()
{
    float sum = 0;
    Node *current = this->head;
    for (int i = 0; i < this->size; i++)
    {
        // sum += current->getStudent()->gpa;
        if (current == nullptr)
        {
            break;
        }
        else
        {
            sum += current->getStudent()->gpa;
        }
        current = current->getNext();
    }
    return sum / this->size;
}
*/

void LinkedList::bubbleSort(Node *current)
{
    if (current == nullptr || current->getNext() == nullptr)
        return;

    if (current->getStudent()->id > current->getNext()->getStudent()->id)
    {
        Student *temp = current->getStudent();
        current->setStudent(current->getNext()->getStudent());
        current->getNext()->setStudent(temp);
        bubbleSort(this->getPrevious(current));
        /*
        On god, the one line above this comment took me THREE HOURS to figure out.  It exists because once we swap two nodes, the first node (now the smaller node) may still be smaller than the one before it.  Because of this, we have to run the bubbleSort() function on the new current's previous node.
        */
        // swap(head->getStudent(), head->getNext()->getStudent());
    }

    bubbleSort(current->getNext());
}

Node *LinkedList::getPrevious(Node *node)
{
    Node *current = this->head;
    for (int i = 0; i < this->size; i++)
    {
        if (current->getNext() == node)
        {
            return current;
        }
        current = current->getNext();
    }
    return nullptr;
}

void LinkedList::swap(Student *a, Student *b)
{
    Student temp;
    temp.id = a->id;
    strcpy(temp.firstname, a->firstname);
    strcpy(temp.lastname, a->lastname);
    // temp.firstname = a->firstname;
    // temp.lastname = a->lastname;
    temp.gpa = a->gpa;

    a->id = b->id;
    strcpy(a->firstname, b->firstname);
    strcpy(a->lastname, b->lastname);
    // a->firstname = b->firstname;
    // a->lastname = b->lastname;
    a->gpa = b->gpa;

    b->id = temp.id;
    strcpy(b->firstname, temp.firstname);
    strcpy(b->lastname, temp.lastname);
    // b->firstname = temp.firstname;
    // b->lastname = temp.lastname;
    b->gpa = temp.gpa;
}

void LinkedList::sortList()
{
    this->bubbleSort(this->head);
}

/*
void LinkedList::sortList()
{
    if (this->size == 0)
    {
        return;
    }

    bool swapped;
    Node *current;
    Node *last = nullptr;
    do
    {
        swapped = false;
        current = this->head;
        while (current->getNext() != last)
        {
            if (current->getStudent()->id > current->getNext()->getStudent()->id)
            {
                Student *temp = current->getStudent();
                current->setStudent(current->getNext()->getStudent());
                current->getNext()->setStudent(temp);
                swapped = true;
            }
            current = current->getNext();
        }
        last = current;
    } while (swapped);
}
*/

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
    current = current->getNext();
    this->printNode(current);
}

void LinkedList::printList()
{
    if (this->size == 0)
    {
        cout << "There aren't any students in the list!" << endl;
        return;
    }
    Node *current = this->head;
    this->printNode(current);
    cout << endl;
}

int LinkedList::getSize()
{
    return this->size;
}