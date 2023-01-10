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
  void getAverageGpa(Node *current, float *sum);

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
  float *getAverageGpa();
  void sortList();
  void printList();
  int getSize();
};

#endif // LINKEDLIST_H
/*
This is the LinkedList class!
This class helps clean up operations done on a linked list.  It contains vital functions like sorting, appending, deleting, GPA averaging, and more.
Some of the utility functions like getPrevious(), swap(), bubbleSort(), and printNode() are private because they're used only by other public functions.
*/