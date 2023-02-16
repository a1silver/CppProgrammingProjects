#include <cstring>
#include <iomanip>
#include <iostream>
#include <sstream>

#include "hashtable.h"
#include "types.h"

#define ll long long int

using namespace std;

HashTable::HashTable()
{
    this->capacity = 128;
    this->elements = 0;
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
        this->elements++;
        break;
    case 1:
        indexed->next = newNode;
        this->elements++;
        break;
    case 2:
        indexed->next->next = newNode;
        this->elements++;
        break;
    case 3:
        indexed->next->next->next = newNode;
        this->elements++;
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
                this->elements--;
                return true;
            }
            else
            {
                prev->next = nullptr;
                delete current;
                this->array[hash] = nullptr;
                this->elements--;
                return true;
            }
        }
        first = false;
        prev = current;
        current = current->next;
    }

    return false;
}

bool HashTable::exists(int id)
{
    int hash = this->hash(id);
    Node *current = this->array[hash];
    while (current != nullptr)
    {
        if (current->student->id == id)
        {
            return true;
        }
        current = current->next;
    }
    return false;
}

Student *HashTable::find(int id)
{
    int hash = this->hash(id);
    Node *current = this->array[hash];
    while (current != nullptr)
    {
        if (current->student->id == id)
        {
            return current->student;
        }
        current = current->next;
    }
    return nullptr;
}

void HashTable::resizeAndRehash()
{
    /*
    // Store the prev size for later
    int prevSize = this->capacity;
    // Double the size
    this->capacity *= 2;

    // Create temporary array
    Node **tempArray = new Node *[prevSize];
    // Copy all elements to the temporary array
    for (int i = 0; i < this->capacity; i++)
    {
        if(i < prevSize)
        {
            tempArray[i] = this->array[i];
        }
        this->array[i] = nullptr;
    }
    // delete[] this->array;
    this->array = new Node *[this->capacity];
    for (int i = 0; i < this->capacity; i++)
    {
        this->array[i] = nullptr;
    }

    // Rehash and re-add all elements from the temp array to the new array
    for (int i = 0; i < prevSize; i++)
    {
        Node *currentNode = tempArray[i];
        while (currentNode != nullptr)
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
    // delete[] tempArray;
    for (int i = 0; i < prevSize; i++)
    {
        tempArray[i] = nullptr;
    }
    delete[] tempArray;
    */
    this->elements = 0;
    int oldCapacity = this->capacity;
    Node **temp = this->array;

    this->capacity *= 2;
    this->array = new Node *[this->capacity];

    for (int i = 0; i < this->capacity; i++)
    {
        this->array[i] = nullptr;
    }
    for (int i = 0; i < oldCapacity; i++)
    {
        Node *current = temp[i];
        while (current != nullptr)
        {
            Student *student = new Student();
            strcpy(student->fname, current->student->fname);
            strcpy(student->lname, current->student->lname);
            student->id = current->student->id;
            student->gpa = current->student->gpa;
            this->add(student);
            current = current->next;
        }
    }
    delete[] temp;
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
    int maxCols = 3;
    int entryWidth = 45 + sizeof(int) * 2 + sizeof(float) * 2 + 1;
    // entryWidth /= 2;
    int col = 1;
    for (int i = 0; i < this->capacity; i++)
    {
        Node *current = this->array[i];
        while (current != nullptr)
        {
            cout << setw(entryWidth) << left;
            current->student->print();
            col++;
            if (col > maxCols)
            {
                col = 1;
                cout << endl;
            }
            current = current->next;
        }
    }
    cout << endl;
}