#include <iostream>
#include <cstring>
#include "student.h"
#include "node.h"

using namespace std;

int main() {
    Node* current = NULL;

    cout << "Welcome to Student List, but with linked lists!  This is a demo to make sure all core files are working properly." << endl;

    Student* student1 = new Student();
    strcpy(student1->firstname, "Morgan");
    strcpy(student1->lastname, "Hinz");
    student1->id = 455152;
    student1->gpa = 4.143;
    Node* first = new Node(student1);
    
    Student* student2 = new Student();
    strcpy(student2->firstname, "Aaron");
    strcpy(student2->lastname, "Guo");
    student2->id = 419452;
    student2->gpa = 4.143;
    Node* second = new Node(student2);
    first->setNext(second);

    Student* student3 = new Student();
    strcpy(student3->firstname, "Joe");
    strcpy(student3->lastname, "Mama");
    student3->id = 123123;
    student3->gpa = 3.3;
    Node* third = new Node(student3);
    second->setNext(third);

    Student* student4 = new Student();
    strcpy(student4->firstname, "Jeff");
    strcpy(student4->lastname, "Smith");
    student4->id = 333444;
    student4->gpa = 2.71;
    Node* fourth = new Node(student4);
    third->setNext(fourth);

    Student* student5 = new Student();
    strcpy(student5->firstname, "Elon");
    strcpy(student5->lastname, "Musk");
    student5->id = 999999;
    student5->gpa = 4.2;
    Node* fifth = new Node(student5);
    fourth->setNext(fifth);

    current = first;
    
    while(current->getNext() != NULL) {
        cout << current->getStudent()->firstname << " " << current->getStudent()->lastname << ", " << current->getStudent()->id << ", " << current->getStudent()->gpa << endl;
        
        current = current->getNext();
    }
    
    // The while loop stops before the very last item in the list
    cout << current->getStudent()->firstname << " " << current->getStudent()->lastname << ", " << current->getStudent()->id << ", " << current->getStudent()->gpa << endl;

    return 0;
}