#include <iostream>
#include <sstream>

#include "hashtable.h"
#include "types.h"

#define ll long long int

using namespace std;

HashTable::HashTable()
{
    this->size = 128;
    this->array = new Node *[this->size];
    for (int i = 0; i < this->size; i++)
    {
        this->array[i] = nullptr;
    }
}

HashTable::~HashTable()
{
    for (int i = 0; i < this->size; i++)
    {
        delete this->array[i];
    }
    delete[] this->array;
}

void print(const char *c)
{
    cout << c << endl;
}

void HashTable::add(Student *student)
{
    print("hash");
    int hash = this->hash(student->id);
    print("get chain size");
    int chainSize = this->getChainSize(hash);

    print("get indexed");
    Node *indexed = this->array[hash];

    print("make new node");
    Node *newNode = new Node();
    print("set new node's student");
    newNode->student = student;
    switch (chainSize)
    {
    case 0:
        print("0 item - set index");
        this->array[hash] = newNode;
        break;
    case 1:
        print("1 item - set next");
        indexed->next = newNode;
        break;
    case 2:
        print("2 item - set next next");
        indexed->next->next = newNode;
        break;
    case 3:
        print("2 item - set next next next");
        indexed->next->next->next = newNode;
        break;
    default:
        print("rehash");
        this->resizeAndRehash();
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
    print("start");
    for (int i = 0; i < this->size; i++)
    {
        cout << "[iter " << i << "] get current" << endl;
        Node *current = this->array[i];
        cout << "[iter " << i << "] start while loop" << endl;
        while (current != nullptr)
        {
            cout << "[iter " << i << "] check id equality" << endl;
            if (current->student->id == id)
            {
                cout << "[iter " << i << "] found" << endl;
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
    int prevSize = this->size;
    // Double the size
    this->size *= 2;

    // Create temporary array
    Node **tempArray = new Node *[this->size];
    // Copy all elements to the temporary array
    for (int i = 0; i < this->size; i++)
    {
        tempArray[i] = this->array[i];
    }
    // Clear the current array
    for (int i = 0; i < prevSize; i++)
    {
        this->array[i] = nullptr;
    }

    // Rehash and re-add all elements from the temp array to the new array
    for (int i = 0; i < this->size; i++)
    {
        Node *current = tempArray[i];
        while (current != nullptr)
        {
            this->add(current->student);
            current = current->next;
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
        sum = ((sum % this->size) + ((int(ss.str()[i])) * factor) % this->size) % this->size;
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
    for (int i = 0; i < this->size; i++)
    {
        Node *current = this->array[i];
        while (current != nullptr)
        {
            cout << current->student->fname << " " << current->student->lname << ", " << current->student->id << ", " << current->student->gpa << endl;
            current = current->next;
        }
    }
}