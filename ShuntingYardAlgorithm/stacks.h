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

// Implementations

Stack::Stack()
{
    top = nullptr;
}

Stack::~Stack()
{
    LLNode<char> *current = top;
    while (current != nullptr)
    {
        LLNode<char> *temp = current->next;
        delete current;
        current = temp;
    }
    top = nullptr;
}

bool Stack::isEmpty()
{
    return (top == nullptr);
}

void Stack::push(char data)
{
    LLNode<char> *node = new LLNode<char>(data);

    if (isEmpty())
    {
        top = node;
    }
    else
    {
        node->next = top;
        top = node;
    }
}

char Stack::pop()
{
    if (isEmpty())
    {
        return '\0';
    }

    char data = top->data;
    LLNode<char> *temp = top;
    top = top->next;
    delete temp;
    return data;
}

char Stack::peek()
{
    if (isEmpty())
    {
        return '\0';
    }
    return top->data;
}

// =================================================================
// ExpressionStack
// =================================================================

ExpressionStack::ExpressionStack()
{
    top = nullptr;
}

ExpressionStack::~ExpressionStack()
{
    LLNode<TreeNode<char> *> *current = top;
    while (current != nullptr)
    {
        LLNode<TreeNode<char> *> *temp = current->next;
        delete current;
        current = temp;
    }
    top = nullptr;
}

bool ExpressionStack::isEmpty()
{
    return (top == nullptr);
}

void ExpressionStack::push(TreeNode<char> *data)
{
    LLNode<TreeNode<char> *> *node = new LLNode<TreeNode<char> *>(data);

    if (isEmpty())
    {
        top = node;
    }
    else
    {
        node->next = top;
        top = node;
    }
}

TreeNode<char> *ExpressionStack::pop()
{
    if (isEmpty())
    {
        return nullptr;
    }

    TreeNode<char> *data = top->data;
    LLNode<TreeNode<char> *> *temp = top;
    top = top->next;
    delete temp;
    return data;
}

TreeNode<char> *ExpressionStack::peek()
{
    if (isEmpty())
    {
        return nullptr;
    }
    return top->data;
}

#endif // STACK_H