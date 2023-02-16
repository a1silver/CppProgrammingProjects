#ifndef HASHTABLE_H
#define HASHTABLE_H

#include "types.h"

class HashTable
{
public:
    HashTable();
    ~HashTable();
    int hash(int id);
    void add(Student *student);
    bool remove(int id);
    void printList();
    bool exists(int id);
    Student *find(int id);
    int getSize() const
    {
        return this->elements;
    }
    int getCapacity() const
    {
        return this->capacity;
    };

private:
    int capacity;
    int elements;
    Node **array;
    int getChainSize(int hash);
    void resizeAndRehash();
};

#endif // HASHTABLE_H