#ifndef TYPES_H
#define TYPES_H

struct Student
{
    char fname[21];
    char lname[21];
    int id;
    float gpa;
};

struct Node
{
    Node();
    ~Node();
    Student *student;
    Node *next;
};

#endif // TYPES_H