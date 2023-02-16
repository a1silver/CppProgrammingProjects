#include <charconv>
#include <cstring>
#include <iomanip>
#include <iostream>

#include "hashtable.h"
#include "types.h"

/*
    See "int HashTable::hash(int id)"

    The purpose of this #define macro is to make a shorthand for a "long long int," which is a 64-bit integer in C++.
*/
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

/*
    Add a new student to the hash table
*/
void HashTable::add(Student *student)
{
    int hash = this->hash(student->id); // Get the hash of the provided student
    int chainSize = this->getChainSize(hash); // Get the chain size of the node at the calculated hash index

    Node *indexed = this->array[hash];

    Node *newNode = new Node();
    newNode->student = student;
    
    // Determine where the new node goes based on the calculated chain size
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
        // If the chain size is greater than three, we'll rehash everything and then add the student afterwards
        this->resizeAndRehash();
        this->add(student);
    }
}

/*
    Remove a student by ID
*/
bool HashTable::remove(int id)
{
    // Hash the given ID
    int hash = this->hash(id);

    // We have to keep track of both the previous and the current nodes
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
                prev->next = nullptr; // Make sure the previous node isn't pointing to invalid memory
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

/*
    Checks to see if a student with the given ID exists in the hash table.
*/
bool HashTable::exists(int id)
{
    
    int hash = this->hash(id); // Hash the given ID
    Node *current = this->array[hash]; // Get the node at the calculated hash index
    
    // Check all of the chains to see if the ID given is present.
    while (current != nullptr)
    {
        if (current->student->id == id) // The given ID is present in the hash table
        {
            return true;
        }
        current = current->next;
    }
    return false;
}

/*
    Find a student by ID.  Smiliar to HashTable::exists() but it returns the current student instead.
*/
Student *HashTable::find(int id)
{
    int hash = this->hash(id); // Hash the given ID
    Node *current = this->array[hash]; // Get the node at the calculated hash index
    
    // Check all of the chains to see if the ID given is present.
    while (current != nullptr)
    {
        if (current->student->id == id) // The given ID is present in the hash table
        {
            return current->student;
        }
        current = current->next;
    }
    return nullptr;
}

/*
    Resizes the element array and rehashes everything
*/
void HashTable::resizeAndRehash()
{
    this->elements = 0; // Setting the amount of elements to 0 fixes many weird bugs
    int oldCapacity = this->capacity;
    Node **temp = this->array; // Store everything in a temporary array

    this->capacity *= 2; // Double the capacity
    this->array = new Node *[this->capacity]; // Set the element array to a new array of double its previous capacity

    // Fill the new element array with null pointers
    for (int i = 0; i < this->capacity; i++)
    {
        this->array[i] = nullptr;
    }
    
    // Iterate through the temporary array and rehash every single element into the new array
    for (int i = 0; i < oldCapacity; i++)
    {
        Node *current = temp[i];
        while (current != nullptr)
        {
            /*
                Make a true copy of the current element's student.  
                If we don't, the student pointer will be deleted when freeing the memory used by the temporary array.
            */
            Student *student = new Student();
            strcpy(student->fname, current->student->fname);
            strcpy(student->lname, current->student->lname);
            student->id = current->student->id;
            student->gpa = current->student->gpa;
            this->add(student);
            current = current->next;
        }
    }
    delete[] temp; // Free the memory used by the temporary array
}

/*
    Hash function adapted from https://www.geeksforgeeks.org/c-program-hashing-chaining/
*/
int HashTable::hash(int id)
{
    // == (START) Convert ID to a char array =================================================
    char idArray[15 + sizeof(char) + 1]; /*
                                            Create a char array to store the converted ID
                                            Size is 16 (amount of digits in a signed integer) + 1 (for a null char)
                                         */
    for(int i = 0; i < 15 + sizeof(char); i++) // Fill with null characters so strlen() works properly
    {
        idArray[i] = '\0';
    }
    to_chars(idArray, idArray + 15, id); // Use the charconv header (New in C++ 17) to convert the ID to a char array
    // == (END) Convert ID to a char array ===================================================
    
    /*
        Essay time!  I remember from Java Programming last year that we could use other sources to help us with our 
        code, as long as we could explain it.  So here goes!

        The following code is an implementation of the "Polynomial Rolling Hash" algorithm.  What this means is that 
        the given string (char array) is treated like a polynomial, and each character in the string is a coefficient 
        of said polynomial.  The final hash is calculated with a fixed base being plugged in to our "polynomial."  
        In this case, it's 31.

        The variable called "factor" is our base.  It starts at 31 and is updated for each iteration of the hash function 
        to be the result of the modulus of the current value of "factor" with the maximum value of a signed integer 
        (16 bits - INT16_MAX), multiplied by the constant value of 31, modulo INT16_MAX.

        The variable called "sum" is the running sum of the polynomial as it's evaluated.  In each iteration of the hash 
        function, the hash value of the next character is calculated by multiplying its ASCII representation by the current
        value of "factor," and then adding that result to the current value of "sum."

        The final hash value is then taken as the modulo of the final value of sum with the capacity of our hash table.
        The "% this->capacity" part of the calculation ensures that the hash value is within the range of our hash table
        capacity.
    */
    ll sum = 0, factor = 31; /*
                                We're using a "long long int" here because of the 
                                    possibility of an overflow when dealing with large integers
                             */

    for (int i = 0; i < strlen(idArray); i++)
    {
        sum = ((sum % this->capacity) + ((int(idArray[i])) * factor) % this->capacity) % this->capacity;
        factor = ((factor % INT16_MAX) * (31 % INT16_MAX)) % INT16_MAX;
    }

    return sum;
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