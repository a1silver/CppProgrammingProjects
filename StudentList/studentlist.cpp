#include <iostream>
#include <cstring>
#include <vector>
#include <ctype.h>
#include "student.h"

using namespace std;

void readInStudent(vector<Student *> *students);
void printStudents(vector<Student *> *students);
void deleteStudent(vector<Student *> *students);
void formatCommand(char *cmd[]);

int main() {
  const char ADD_CMD[] = "ADD";
  const char PRINT_CMD[] = "PRINT";
  const char DELETE_CMD[] = "DELETE";
  const char QUIT_CMD[] = "QUIT";
  
  vector<Student *> students;

  char cmd[7];
  
  while(true) {
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
    if(strcmp(cmd, QUIT_CMD) == 0) {
      break;
    }
  }
  
  return 0;
}

void readInStudent(vector<Student *> *students) {
  Student student;
  
  cout << "Enter First Name: ";
  cin >> student.fname;
  cout << "Enter Last Name: ";
  cin >> student.lname;
  cout << "Enter Student ID: ";
  cin >> student.id;
  cout << "Enter Student GPA: ";
  cin >> student.gpa;

  students->push_back(&student);
  
  cout << "Student added!" << endl;
  
}

void printStudents(vector<Student *> *students) {
  for(vector<Student *>::itertor it = students->begin(); it != students->end(); it++) {
    Student *it;
    cout << it->fname << " " << it->lname << ", " << it->id << ", " << it->gpa << endl;
  }
}

void deleteStudent(vector<Student *> *students) {
  cout << "Deleting!" << endl;
}