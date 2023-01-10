#ifndef NODE_H
#define NODE_H

#include "student.h"

class Node
{
public:
    Node(Student *student);
    ~Node();
    Node *getNext();
    void setNext(Node *next);
    Student *getStudent();
    void setStudent(Student *student);

private:
    Node *next;
    Student *student;
};

#endif // NODE_H
/*
This is the Node class!  
It represents a Node in the linked list.  
It contains a Student pointer and another Node pointer, which points to the next Node in the series.
*/