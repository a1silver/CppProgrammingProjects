#ifndef STUDENT_H
#define STUDENT_H

struct Student
{
    int id;
    char firstname[20];
    char lastname[20];
    float gpa;
};

#endif // STUDENT_H
/*
This is the Student class!
It represents a Student.  All Student objects are contained inside a Node object. 
A Student object contains:
 - An ID number (integer)
 - A first name (char[])
 - A last name (char[])
 - A GPA (float)
*/