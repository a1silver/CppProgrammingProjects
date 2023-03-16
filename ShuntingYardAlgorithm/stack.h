#ifndef STACK_H
#define STACK_H

#include "nodes.h"

template <class T>
class Stack
{
private:
    LLNode<T> *top;

public:
    Stack() ~Stack();

    bool isEmpty();
    void push(T data);
    T pop();
    T peek();
};

// Implementations

template <class T>
Stack<T>::Stack()
{
    top = nullptr;
}

template <class T>
Stack<T>::~Stack()
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

template <class T>
bool Stack<T>::isEmpty()
{
    return (top == nullptr);
}

template <class T>
void Stack<T>::push(T data)
{
    LLNode<T> *node = new LLNode<T>(data);

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

template <class T>
T Stack<T>::pop()
{
    if (isEmpty())
    {
        throw runtime_error("Stack is empty!");
    }

    char data = top->data;
    LLNode<T> *temp = top;
    top = top->next;
    delete temp;
    return data;
}

template <class T>
T Stack<T>::peek()
{
    if (isEmpty())
    {
        throw runtime_error("Stack is empty!");
    }

    return top->data;
}

#endif // STACK_H