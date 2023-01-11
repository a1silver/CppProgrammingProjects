#pragma once
#include <iostream>
#include "student.h"

using namespace std;

class Node {
 public:
  Node(Student*); // node constructor
  Node* getNext(); // get next node pointer
  Student* getStudent(); // get student pointer
  void setNext(Node*); // set next corresponding node pointer
  ~Node(); // node destructor

  Student* nextStudent;
  Node* nextPointer;
};