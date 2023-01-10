#include "node.h"

Node::Node(Student *student)
{
    this->next = nullptr;
    this->student = student;
}

Node::~Node()
{
    delete student;
}

Node *Node::getNext()
{
    return this->next;
}

void Node::setNext(Node *next)
{
    this->next = next;
}

Student *Node::getStudent()
{
    return this->student;
}
