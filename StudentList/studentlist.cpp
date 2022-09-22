#include <iostream>
#include <iomanip>
#include <cstring>
#include <vector>
#include <algorithm>
#include <ctype.h>
#include "student.h"

using namespace std;

// Const commands
const char ADD_CMD[] = "ADD";
const char PRINT_CMD[] = "PRINT";
const char DELETE_CMD[] = "DELETE";
const char CLEAR_CMD[] = "CLEAR";
const char QUIT_CMD[] = "QUIT";
const char HELP_CMD[] = "HELP";
const char HELP_ALL[] = "ALL";

void readInStudent(vector<Student *> *students);
void printStudents(vector<Student *> *students);
void deleteStudent(vector<Student *> *students);
void clearStudents(vector<Student *> *students);
void formatCommand(char *cmd[]);
void help();

// Main method
int main() {

  // Vector containing student pointers
  vector<Student *> students;
  
  // Set Float and Double Precision
  cout << fixed;
  cout << setprecision(2);

  cout << "Student List Program v1.0 by Morgan Hinz" << endl;

  // Keeps track of the current command
  char cmd[7];

  while(true) {
    cout << "> ";
    cin >> cmd;
    
    // commands
    if(strcmp(cmd, ADD_CMD) == 0) {
      readInStudent(&students);
    }
    if(strcmp(cmd, PRINT_CMD) == 0) {
      printStudents(&students);
    }
    if(strcmp(cmd, DELETE_CMD) == 0) {
      deleteStudent(&students);
    }
    if(strcmp(cmd, CLEAR_CMD) == 0) {
      clearStudents(&students);
    }
    if(strcmp(cmd, HELP_CMD) == 0) {
      help();
    }
    if(strcmp(cmd, QUIT_CMD) == 0) {
      break;
    }
  }
  
  return 0;
}

// Adds a student.  Asks for first/last name, ID and GPA
void readInStudent(vector<Student *> *students) {
  Student* student = new Student();
  
  cout << "Enter First Name: ";
  cin >> student->fname;
  cout << "Enter Last Name: ";
  cin >> student->lname;
  cout << "Enter Student ID: ";
  cin >> student->id;
  cout << "Enter Student GPA: ";
  cin >> student->gpa;

  vector<Student *>::iterator it;
  for(it = students->begin(); it < students->end(); it++) {
    if((*it)->id == student->id) { // Check to see if that ID already exists
      cout << "A student with id " << student->id << " already exists!" << endl << endl;
      return;
    }
  }
  
  students->push_back(student);

  cout << "Student added!" << endl << endl;
  
}

// Prints out every student entry
void printStudents(vector<Student *> *students) {
  vector<Student *>::iterator it;
  for(it = students->begin(); it < students->end(); it++) {
    cout << (*it)->fname << " " << (*it)->lname << ", " << (*it)->id << ", " << (*it)->gpa << endl;
  }
  cout << endl;
}

// Delete a student by ID
void deleteStudent(vector<Student *> *students) {
  cout << "Enter ID to delete: ";
  int id;
  cin >> id;

  bool found = false;
  int index = 0;
  vector<Student *>::iterator it;
  for(it = students->begin(); it < students->end(); it++) {
    if((*it)->id == id) {
      found = true;
      cout << "Student found! Deleting...";
      delete *it; // first clear the memory location
      students->erase(students->begin() + index); // remove object from the vector
      break;
    }
    index++;
  }

  if(!found) {
    cout << "Student with ID " << id << " not found!" << endl << endl;
    return;
  }
  
  cout << " Deleted!" << endl << endl;
  
}

// Clear the entire list of students
void clearStudents(vector<Student *> *students) {
  vector<Student *>::iterator it;
  for(it = students->begin(); it < students->end(); it++) {
    delete *it;
  }

  int len = students->size();
  students->clear();
  cout << len << " students removed!" << endl << endl;
}

void help() {
  // add, print, delete, clear, help, quit

  cout << "Student List Help" << endl;
  cout << "Type \"ALL\" to view all commands." << endl;
  cout << "-----------------" << endl << "Command: ";
  
  char cmd[7];
  cin >> cmd;
  
  if(strcmp(cmd, ADD_CMD) == 0) {
    cout << "Command: ADD" << endl;
    cout << "Add a student to the list.";
  } else if(strcmp(cmd, PRINT_CMD) == 0) {
    cout << "Command: PRINT" << endl;
    cout << "Print all of the students in the list.";
  } else if(strcmp(cmd, DELETE_CMD) == 0) {
    cout << "Command: DELETE" << endl;
    cout << "Find and delete a student by ID.";
  } else if(strcmp(cmd, CLEAR_CMD) == 0) {
    cout << "Command: CLEAR" << endl;
    cout << "Clear the entire list of students.";
  } else if(strcmp(cmd, HELP_CMD) == 0) {
    cout << "Command: HELP" << endl;
    cout << "Show this message.";
  } else if(strcmp(cmd, QUIT_CMD) == 0) {
    cout << "Command: QUIT" << endl;
    cout << "Quit the program.";
  } else if(strcmp(cmd, HELP_ALL) == 0) {
    cout << "Available commands: ADD, PRINT, DELETE, CLEAR, HELP, QUIT" << endl;
    cout << "Type HELP + (COMMAND) to view help for a specific command.";
  }
  cout << endl << endl;
}
