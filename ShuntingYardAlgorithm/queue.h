#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
#include "nodes.h"

using namespace std;

template <class T>
class Queue
{
    private:
        LLNode<T>* front;
        LLNode<T>* rear;
    public:
        Queue();
        ~Queue();
        
        bool isEmpty();
        void enqueue(T data);
        T dequeue();
        T peek();
};


// Implementations

template <class T>
Queue<T>::Queue()
{
    front = nullptr;
    rear = nullptr;
}

template <class T>
Queue<T>::~Queue()
{
    LLNode<T> *current = front;
    while (current != nullptr)
    {
        LLNode<T> *temp = current->next;
        delete current;
        current = temp;
    }
    front = nullptr;
    rear = nullptr;
}

template <class T>
bool Queue<T>::isEmpty()
{
    return (front == nullptr && rear == nullptr);
}

template <class T>
void Queue<T>::enqueue(T data)
{
    LLNode<T> *node = new LLNode<T>(data);

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

template <class T>
T Queue<T>::dequeue()
{
    if (isEmpty())
    {
        throw runtime_error("Queue is empty!");
    }

    T data = front->data;
    LLNode<T> *temp = front;

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

template <class T>
T Queue<T>::peek()
{
    if (isEmpty())
    {
        throw runtime_error("Queue is empty!");
    }

    return front->data;
}

#endif // QUEUE_H