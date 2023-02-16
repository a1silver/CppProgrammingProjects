#ifndef TYPES_H
#define TYPES_H

#include <cstring>

using namespace std;

struct Student
{
    char fname[21];
    char lname[21];
    int id;
    float gpa;
    void print();
    int charLength() const
    {
        return strlen(this->fname) + strlen(this->lname) + sizeof(int) + sizeof(float) + 1;
    }
};

struct Node
{
    Node();
    ~Node();
    Student *student;
    Node *next;
};

#endif // TYPES_H