#include <iostream>
#include "Node.h"
#include "student.h"

using namespace std;

Node::Node(Student* studenttemp) {
  nextStudent = studenttemp;
  //added: initialize nextPointer
  nextPointer = nullptr;
}

Node* Node::getNext() {
  return nextPointer;
}

Student* Node::getStudent() {
  return nextStudent;
}

void Node::setNext(Node* nexttemp) {
  nextPointer = nexttemp;
}

Node::~Node() {
  cout << "Destructing Node" << endl;
  //added: delete nextStudent;
  delete nextStudent;
}