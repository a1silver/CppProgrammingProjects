#include <cctype>
#include <cstring>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>

#include <stdlib.h>
#include <time.h>

#include "hashtable.h"
#include "types.h"

using namespace std;

// Const commands
const char ADD_CMD[] = "add";
const char PRINT_CMD[] = "print";
const char DELETE_CMD[] = "delete";
const char GEN_CMD[] = "gen";
const char QUIT_CMD[] = "quit";
const char EXIT_CMD[] = "exit";
const char HELP_CMD[] = "help";
const char HELP_ALL[] = "all";

// Function prototypes
void readInStudent(HashTable *hashtable);
void deleteStudent(HashTable *hashtable);
void generateStudents(HashTable *hashtable);
void help();

// Main method
int main()
{

    // LinkedList containing student pointers/nodes
    HashTable *hashtable = new HashTable();

    // Set Float and Double Precision
    cout << fixed;
    cout << setprecision(2);

    cout << "Student List Program w/ Linked Lists v1.0 by Morgan Hinz" << endl;

    // Keeps track of the current command
    char cmd[8];

    // Constantly get new commands until the user wants to quit.
    while (true)
    {
        cout << "> ";
        cin >> cmd;

        // This for loop takes care of ignoring any case sensitivity
        for (int i = 0; i < strlen(cmd); i++)
        {
            cmd[i] = tolower(cmd[i]);
        }

        // Commands
        if (strcmp(cmd, ADD_CMD) == 0)
        {
            readInStudent(hashtable);
        }
        if (strcmp(cmd, PRINT_CMD) == 0)
        {
            hashtable->printList();
        }
        if (strcmp(cmd, DELETE_CMD) == 0)
        {
            deleteStudent(hashtable);
        }
        if (strcmp(cmd, GEN_CMD) == 0)
        {
            generateStudents(hashtable);
        }
        if (strcmp(cmd, HELP_CMD) == 0)
        {
            help();
        }
        if (strcmp(cmd, QUIT_CMD) == 0)
        {
            cout << "Clearing up memory..." << endl;
            delete hashtable;
            cout << "Done!" << endl;
            break;
        }
        if (strcmp(cmd, EXIT_CMD) == 0)
        {
            cout << "Clearing up memory..." << endl;
            delete hashtable;
            cout << "Done!" << endl;
            break;
        }
    }

    return 0;
}

// Adds a student.  Asks for first/last name, ID and GPA
void readInStudent(HashTable *hashtable)
{
    Student *student = new Student();

    cout << " Enter First Name: ";
    cin >> student->fname;
    cout << " Enter Last Name: ";
    cin >> student->lname;
    cout << " Enter Student ID: ";
    cin >> student->id;
    cout << " Enter Student GPA: ";
    cin >> student->gpa;

    if (hashtable->idExists(student->id))
    {
        cout << " A student with id " << student->id << " already exists!" << endl;
        delete student;
        return;
    }

    cout << "add" << endl;
    hashtable->add(student);

    cout << " Student added!" << endl;
}

// Delete a student.  Asks for the ID to delete.  If the ID doesn't exist or the list size == 0 the function will return.
void deleteStudent(HashTable *hashtable)
{
    if (hashtable->getSize() == 0)
    {
        cout << " No students to delete!" << endl;
        return;
    }

    cout << " Enter ID to delete: ";
    int id;
    cin >> id;
    /*
    bool idExists = hashtable->idExists(id);

    if (!idExists)
    {
        cout << "Student with ID " << id << " not found!" << endl;
        return;
    }
    */

    if (hashtable->remove(id))
    {
        cout << " Student deleted!" << endl;
    }
    else
    {
        cout << " Failed to delete.  Either the ID doesn't exist or an internal error occurred." << endl;
    }
}

void generateStudents(HashTable *hashtable)
{
    cout << " How many students would you like to generate? ";
    int amount;
    cin >> amount;

    vector<char*> firstNames, lastNames;
    int firstNameCount = 0, lastNameCount = 0;

    ifstream firstNameFile("firstnames.txt");
    if(firstNameFile.is_open())
    {
        char temp[51];
        while(!firstNameFile.eof())
        {
            firstNameFile >> temp;
            firstNames.push_back(new char[51]);
            // firstNames[firstNameCount] = new char[51];
            strcpy(firstNames[firstNameCount], temp);
            firstNameCount++;
        }
        firstNameFile.close();
    }
    ifstream lastNameFile("lastnames.txt");
    if(lastNameFile.is_open())
    {
        char temp[51];
        while(!lastNameFile.eof())
        {
            lastNameFile >> temp;
            lastNames.push_back(new char[51]);
            // lastNames[lastNameCount] = new char[51];
            strcpy(lastNames[lastNameCount], temp);
            lastNameCount++;
        }
        lastNameFile.close();
    }

    srand(time(0));

    for(int i = 0; i < amount; i++)
    {
        Student *student = new Student();

        int randomNameIndex = rand() % 1000;
        strcpy(student->fname, firstNames[randomNameIndex]);

        randomNameIndex = rand() % 1000;
        strcpy(student->lname, lastNames[randomNameIndex]);

        int id = 0;
        while(true)
        {
            if(hashtable->idExists(id))
            {
                id++;
            } else {
                break;
            }
        }
        student->id = id;

        student->gpa = (float)rand() / ((float)RAND_MAX / 5.0f);

        hashtable->add(student);
    }
}

// Prints the help command & any command details for specified command
void help()
{
    cout << "Student List Help" << endl;
    cout << "Type \"ALL\" to view all commands." << endl;
    cout << "-----------------" << endl
         << "Command: ";

    char cmd[7];
    cin >> cmd;

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
    else if (strcmp(cmd, HELP_CMD) == 0)
    {
        cout << "Command: HELP" << endl;
        cout << "Show this message.";
    }
    else if (strcmp(cmd, QUIT_CMD) == 0)
    {
        cout << "Command: QUIT | EXIT" << endl;
        cout << "Quit the program.";
    }
    else if (strcmp(cmd, HELP_ALL) == 0)
    {
        cout << "Available commands: ADD, PRINT, DELETE, HELP, QUIT, EXIT" << endl;
        cout << "Type HELP + (COMMAND) to view help for a specific command.";
    }
    cout << endl;
}