#include "queue.h"

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