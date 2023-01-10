#include <iostream>
#include <iomanip>
#include <cstring>
#include <vector>
#include <algorithm>
#include <ctype.h>
#include "student.h"
#include "node.h"
#include "linkedlist.h"

using namespace std;

// Const commands
const char ADD_CMD[] = "ADD";
const char PRINT_CMD[] = "PRINT";
const char DELETE_CMD[] = "DELETE";
const char QUIT_CMD[] = "QUIT";
const char AVERAGE_CMD[] = "AVERAGE";
const char HELP_CMD[] = "HELP";
const char HELP_ALL[] = "ALL";

void readInStudent(LinkedList *studentList);
void deleteStudent(LinkedList *studentList);
void averageStudents(LinkedList *studentList);
void sortStudents(LinkedList *studentList);
void help();

// Main method
int main()
{

    // Vector containing student pointers
    LinkedList *studentList = new LinkedList();

    // Set Float and Double Precision
    cout << fixed;
    cout << setprecision(2);

    cout << "Student List Program w/ Linked Lists v1.0 by Morgan Hinz" << endl;

    // Keeps track of the current command
    char cmd[8];

    while (true)
    {
        cout << "> ";
        cin >> cmd;

        // commands
        if (strcmp(cmd, ADD_CMD) == 0)
        {
            readInStudent(studentList);
        }
        if (strcmp(cmd, PRINT_CMD) == 0)
        {
            studentList->printList();
        }
        if (strcmp(cmd, DELETE_CMD) == 0)
        {
            deleteStudent(studentList);
        }
        if (strcmp(cmd, AVERAGE_CMD) == 0)
        {
            averageStudents(studentList);
        }
        if (strcmp(cmd, HELP_CMD) == 0)
        {
            help();
        }
        if (strcmp(cmd, QUIT_CMD) == 0)
        {
            delete studentList;
            break;
        }
    }

    return 0;
}

// Adds a student.  Asks for first/last name, ID and GPA
void readInStudent(LinkedList *studentList)
{
    Student *student = new Student();

    cout << "Enter First Name: ";
    cin >> student->firstname;
    cout << "Enter Last Name: ";
    cin >> student->lastname;
    cout << "Enter Student ID: ";
    cin >> student->id;
    cout << "Enter Student GPA: ";
    cin >> student->gpa;

    if (studentList->idExists(student->id))
    {
        cout << "A student with id " << student->id << " already exists!" << endl;
        return;
    }

    studentList->append(student);
    studentList->sortList();

    cout << "Student added!" << endl;
}

// Delete a student by ID
void deleteStudent(LinkedList *studentList)
{
    if (studentList->getSize() == 0)
    {
        cout << "No students to delete!" << endl;
        return;
    }

    cout << "Enter ID to delete: ";
    int id;
    cin >> id;
    cout << "got ID" << endl;
    int indexOfId = studentList->getIndexOfId(id);
    cout << "got index" << endl;

    if (indexOfId == -1)
    {
        cout << "Student with ID " << id << " not found!" << endl;
        return;
    }

    studentList->remove(indexOfId);
    cout << "removed" << endl;
    studentList->sortList();
    cout << "sorted" << endl;

    cout << " Deleted!" << endl;
}

void averageStudents(LinkedList *studentList) {
    if (studentList->getSize() == 0)
    {
        cout << "No students to average!" << endl;
        return;
    }
    cout << "The average GPA of all " << studentList->getSize() << " students is " << studentList->getAverageGpa() << "!" << endl;
}

void help()
{
    // add, print, delete, clear, help, quit

    cout << "Student List Help" << endl;
    cout << "Type \"ALL\" to view all commands." << endl;
    cout << "-----------------" << endl
         << "Command: ";

    char cmd[7];
    cin >> cmd;
    // add print delete quit average help
    if (strcmp(cmd, ADD_CMD) == 0)
    {
        cout << "Command: ADD" << endl;
        cout << "Add a student to the list.";
    }
    else if (strcmp(cmd, PRINT_CMD) == 0)
    {
        cout << "Command: PRINT" << endl;
        cout << "Print all of the students in the list.";
    }
    else if (strcmp(cmd, DELETE_CMD) == 0)
    {
        cout << "Command: DELETE" << endl;
        cout << "Find and delete a student by ID.";
    }
    else if (strcmp(cmd, AVERAGE_CMD) == 0)
    {
        cout << "Command: AVERAGE" << endl;
        cout << "Get the average GPA of all students.";
    }
    else if (strcmp(cmd, HELP_CMD) == 0)
    {
        cout << "Command: HELP" << endl;
        cout << "Show this message.";
    }
    else if (strcmp(cmd, QUIT_CMD) == 0)
    {
        cout << "Command: QUIT" << endl;
        cout << "Quit the program.";
    }
    else if (strcmp(cmd, HELP_ALL) == 0)
    {
        cout << "Available commands: ADD, PRINT, DELETE, AVERAGE, HELP, QUIT" << endl;
        cout << "Type HELP + (COMMAND) to view help for a specific command.";
    }
    cout << endl;
}
