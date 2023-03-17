#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
#include "nodes.h"

using namespace std;

class Queue
{
    private:
        LLNode<char>* front;
        LLNode<char>* rear;
    public:
        Queue();
        ~Queue();
        
        bool isEmpty();
        void enqueue(char data);
        char dequeue();
        char peek();
};


// Implementations

Queue::Queue()
{
    front = nullptr;
    rear = nullptr;
}

Queue::~Queue()
{
    LLNode<char> *current = front;
    while (current != nullptr)
    {
        LLNode<char> *temp = current->next;
        delete current;
        current = temp;
    }
    front = nullptr;
    rear = nullptr;
}

bool Queue::isEmpty()
{
    return (front == nullptr && rear == nullptr);
}

void Queue::enqueue(char data)
{
    LLNode<char> *node = new LLNode<char>(data);

    if (isEmpty())
    {
        this->front = rear = node;
    }
    else
    {
        rear->next = node;
        rear = node;
    }
}

char Queue::dequeue()
{
    if (front == nullptr)
    {
        return '\0';
    }

    char data = front->data;
    LLNode<char> *temp = front;

    if (front == rear)
    {
        front = rear = nullptr;
    }
    else
    {
        front = front->next;
    }

    delete temp;
    return data;
}

char Queue::peek()
{
    if (isEmpty())
    {
        return '\0';
    }

    return front->data;
}

#endif // QUEUE_H