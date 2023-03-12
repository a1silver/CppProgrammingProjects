#ifndef STACK_H
#define STACK_H

#include "nodes.h"

class Stack
{
public:
    Stack();
    ~Stack();
    void push(char data);
    char pop();
    char peek();
    void display();

private:
    LLNode *head;
};

#endif // STACK_H