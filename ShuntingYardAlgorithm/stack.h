#ifndef STACK_H
#define STACK_H

#include "nodes.h"

class Stack
{
private:
    LLNode *top;

public:
    Stack();

    bool isEmpty();
    void push(char data);
    char pop();
    char peek();
};

#endif // STACK_H