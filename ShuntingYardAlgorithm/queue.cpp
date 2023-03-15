#include <iostream>

#include "nodes.h"
#include "queue.h"

using namespace std;

Queue::Queue()
{
    front = nullptr;
    rear = nullptr;
}

bool Queue::isEmpty()
{
    return (front == nullptr && rear == nullptr);
}

void Queue::enqueue(char data)
{
    LLNode *node = new LLNode(data);

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
    if (isEmpty())
    {
        throw runtime_error("Queue is empty!");
    }

    char data = front->data;
    LLNode *temp = front;

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
        throw runtime_error("Queue is empty!");
    }

    return front->data;
}