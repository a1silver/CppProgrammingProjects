#include <iomanip>
#include <iostream>
#include <sstream>

#include "types.h"

using namespace std;

void Student::print()
{
    stringstream ss;
    ss << this->fname << " " << this->lname << ", " << this->id << ", " << fixed << setprecision(2) << this->gpa;
    cout << ss.str();
}

Node::Node()
{
    this->student = nullptr;
    this->next = nullptr;
}

Node::~Node()
{
    delete this->student;
}