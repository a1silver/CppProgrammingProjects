#ifndef NODE_H
#define NODE_H

#include "student.h"

class Node
{
public:
    Node(Student *student);            // Constructor
    ~Node();                           // Destructor
    Node *getNext();                   // Get the next node in the list
    void setNext(Node *next);          // Set the node pointer that this node points to
    Student *getStudent();             // Get the student contained in this node
    void setStudent(Student *student); // Set the student contained in this node (unused)
private:
    Node *next;       // Node pointer field
    Student *student; // Student pointer field
};

#endif // NODE_H
       /*
       This is the Node class!
       It represents a Node in the linked list.
       It contains a Student pointer and another Node pointer, which points to the next Node in the series.
       */