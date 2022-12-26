#ifndef NODE_H
#define NODE_H

#include "student.h"

class Node {
    public:
        Node(Student* student);
        ~Node();
        Node* getNext();
        void setNext(Node* next);
        Student* getStudent();
        void setStudent(Student* student);
    private:
        Node* next;
        Student* student;
};

#endif // NODE_H