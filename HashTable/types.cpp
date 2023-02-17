#include <cstdio>
#include <iomanip>
#include <iostream>

#include "types.h"

using namespace std;

void Student::print()
{
    char output[251];
    sprintf(output, "%s %s, %d, %.2f", this->fname, this->lname, this->id, this->gpa);
    cout << output;
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