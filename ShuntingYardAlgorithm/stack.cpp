#include <iostream>

#include "nodes.h"
#include "stack.h"

using namespace std;

Stack::Stack()
{
    top = nullptr;
}

bool Stack::isEmpty()
{
    return (top == nullptr);
}

void Stack::push(char data)
{
    LLNode *node = new LLNode(data);

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
        throw runtime_error("Stack is empty!");
    }

    char data = top->data;
    LLNode *temp = top;
    top = top->next;
    delete temp;
    return data;
}

char Stack::peek()
{
    if (isEmpty())
    {
        throw runtime_error("Stack is empty!");
    }

    return top->data;
}