#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "Node.h"
#include "student.h"

class LinkedList
{
private:
  Node *head;
  int size;
  void printNode(Node *current);
  void getAverageGpa(Node *current, float *sum);
  void add(Node *current, Node *prev, Student *newS, bool isHead);
  void remove(Node *current, Node *prev, int id);

public:
  LinkedList();
  ~LinkedList();

  void add(Student *newS);
  void remove(int id);
  bool idExists(int id);
  float *getAverageGpa();
  void printList();
  int getSize();
  Node *getHead();
};

#endif // LINKEDLIST_H
/*
This is the LinkedList class!
This class helps clean up operations done on a linked list.  It contains vital functions like sorting, appending, deleting, GPA averaging, and more.
Some of the utility functions like getPrevious(), swap(), bubbleSort(), and printNode() are private because they're used only by other public functions.
*/