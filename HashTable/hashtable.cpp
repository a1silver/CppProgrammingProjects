#include <cstring>
#include <iostream>
#include <sstream>

#include "hashtable.h"
#include "types.h"

#define ll long long int

using namespace std;

HashTable::HashTable()
{
    this->capacity = 128;
    this->array = new Node *[this->capacity];
    for (int i = 0; i < this->capacity; i++)
    {
        this->array[i] = nullptr;
    }
}

HashTable::~HashTable()
{
    for (int i = 0; i < this->capacity; i++)
    {
        delete this->array[i];
    }
    delete[] this->array;
}

void HashTable::add(Student *student)
{
    int hash = this->hash(student->id);
    int chainSize = this->getChainSize(hash);

    Node *indexed = this->array[hash];

    Node *newNode = new Node();
    newNode->student = student;
    switch (chainSize)
    {
    case 0:
        this->array[hash] = newNode;
        break;
    case 1:
        indexed->next = newNode;
        break;
    case 2:
        indexed->next->next = newNode;
        break;
    case 3:
        indexed->next->next->next = newNode;
        break;
    default:
        this->resizeAndRehash();
        this->add(student);
    }
}

bool HashTable::remove(int id)
{
    int hash = this->hash(id);

    Node *prev = nullptr;
    Node *current = this->array[hash];
    bool first = true;

    while (current != nullptr)
    {
        if (current->student->id == id)
        {
            if (first)
            {
                delete current;
                this->array[hash] = nullptr;
                return true;
            }
            else
            {
                prev->next = nullptr;
                delete current;
                this->array[hash] = nullptr;
                return true;
            }
        }
        first = false;
        prev = current;
        current = current->next;
    }

    return false;
}

bool HashTable::idExists(int id)
{
    for (int i = 0; i < this->capacity; i++)
    {
        Node *current = this->array[i];
        while (current != nullptr)
        {
            if (current->student->id == id)
            {
                return true;
            }
            current = current->next;
        }
    }
    return false;
}

void HashTable::resizeAndRehash()
{
    // Store the prev size for later
    int prevSize = this->capacity;
    // Double the size
    this->capacity *= 2;

    // Create temporary array
    Node **tempArray = new Node *[this->capacity];
    // Copy all elements to the temporary array
    for (int i = 0; i < this->capacity; i++)
    {
        tempArray[i] = this->array[i];
    }
    // Clear the current array
    for (int i = 0; i < prevSize; i++)
    {
        this->array[i] = nullptr;
    }

    // Rehash and re-add all elements from the temp array to the new array
    for (int i = 0; i < this->capacity; i++)
    {
        Node *currentNode = tempArray[i];
        while(currentNode != nullptr)
        {
            Student *student = new Student();
            strcpy(student->fname, currentNode->student->fname);
            strcpy(student->lname, currentNode->student->lname);
            student->id = currentNode->student->id;
            student->gpa = currentNode->student->gpa;
            this->add(student);
            Node *temp = currentNode->next;
            delete currentNode;
            currentNode = temp;
        }
    }
    // Free temporary array memory
    delete[] tempArray;
}

/*
    Hash function adapted from https://www.geeksforgeeks.org/c-program-hashing-chaining/
*/
int HashTable::hash(int id)
{
    stringstream ss;
    ss << id;

    int bucketIndex;
    ll sum = 0, factor = 31;

    for (int i = 0; i < ss.str().size(); i++)
    {
        sum = ((sum % this->capacity) + ((int(ss.str()[i])) * factor) % this->capacity) % this->capacity;
        factor = ((factor % INT16_MAX) * (31 % INT16_MAX)) % INT16_MAX;
    }

    bucketIndex = sum;
    return bucketIndex;
}

int HashTable::getChainSize(int hash)
{
    Node *current = this->array[hash];
    int chainSize = 0;
    while (current != nullptr)
    {
        chainSize++;
        current = current->next;
    }
    return chainSize;
}

void HashTable::printList()
{
    for (int i = 0; i < this->capacity; i++)
    {
        Node *current = this->array[i];
        while (current != nullptr)
        {
            cout << current->student->fname << " " << current->student->lname << ", " << current->student->id << ", " << current->student->gpa << endl;
            current = current->next;
        }
    }
}