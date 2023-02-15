#include "types.h"

Node::Node()
{
    this->student = nullptr;
    this->next = nullptr;
}

Node::~Node()
{
    delete this->student;
}