#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "node.h"
#include "student.h"

class LinkedList
{
private:
  Node *head;
  Node *tail;
  int size;
  void bubbleSort(Node *current);
  void swap(Student *a, Student *b);
  Node *getPrevious(Node *node);
  void printNode(Node *current);

public:
  LinkedList();
  ~LinkedList();

  void append(Student *student);
  void prepend(Student *student);
  void insert(int index, Student *student);
  void remove(int index);
  Student *get(int index);
  bool idExists(int id);
  int getIndexOfId(int id);
  float getAverageGpa(); // fix average
  void sortList();
  void printList();
  int getSize();
};

#endif // LINKEDLIST_H