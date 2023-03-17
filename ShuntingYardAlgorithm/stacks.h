#ifndef STACK_H
#define STACK_H

#include "nodes.h"

class Stack
{
private:
    LLNode<char> *top;

public:
    Stack();
    ~Stack();

    bool isEmpty();
    void push(char data);
    char pop();
    char peek();
};

class ExpressionStack
{
private:
    LLNode<TreeNode<char> *> *top;

public:
    ExpressionStack();
    ~ExpressionStack();

    bool isEmpty();
    void push(TreeNode<char> *data);
    TreeNode<char> *pop();
    TreeNode<char> *peek();
};

#endif // STACK_H

/*
    This header file contains two stacks.  The first stack is a generic stack that is used by the 
    actual Shunting Yard algorithm, and the second is a stack that is used when forming a binary 
    expression tree. The first stack deals with linked list nodes that contain chars, and the 
    second stack deals with tree nodes that contain chars (for the expression tree).
*/