#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "Node.h"
#include "student.h"

class LinkedList
{
private:
  Node *head;                                                      // Head of the linked list
  int size;                                                        // Size of the linked list
  void printNode(Node *current);                                   // Recursive implentation of printing the list of students
  void getAverageGpa(Node *current, float *sum);                   // Recursive implentation of getting average gpa
  void add(Node *current, Node *prev, Student *newS, bool isHead); // Recursive implentation of adding a new student
  void remove(Node *current, Node *prev, int id);                  // Recursive implentation of removing a student by id

public:
  LinkedList();
  ~LinkedList();

  void add(Student *newS); // Wrapper function to add a new student
  void remove(int id);     // Wrapper function to remove a student by id
  bool idExists(int id);   // Return true if provided id exists, false otherwise
  float *getAverageGpa();  // Wrapper function to get average gpa
  void printList();        // Wrapper function to print list of students
  int getSize();           // Get linked list size
  Node *getHead();         // Public getter for this->head
};

#endif // LINKEDLIST_H
/*
This is the LinkedList class!
This class helps clean up operations done on a linked list.  It contains vital functions like sorting, appending, deleting, GPA averaging, and more.
The functions labeled as private are the implementations of their public wrapper function counterpart.  The public wrapper functions are for ease of use inside of main.cpp.
*/