#include "node.h"

Node::Node(Student* student) {
    this->student = student;
}

Node::~Node() {
    delete student;
}

Node* Node::getNext() {
    return this->next;
}

void Node::setNext(Node* next) {
    this->next = next;
}

Student* Node::getStudent() {
    return this->student;
}

void Node::setStudent(Student* student) {
    this->student = student;
}