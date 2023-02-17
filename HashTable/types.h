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
/*
    This header file contains the two most important data types used by the program.

    The `Student` struct represents a student.  It contains a first & last name, ID, and GPA.  
    It also contains a helper function for printing the student, and a function for getting the character width of the student.  
    That function is only used for formatted printing.

    The `Node` struct represents a node in a linked list.  
    It contains a Student object pointer and a Node object pointer (pointing to the next Node in a linked list).
*/