#include <iostream>

#include "nodes.h"
#include "queue.h"

using namespace std;

Queue::Queue()
{
    this->head = nullptr;
    this->tail = nullptr;
}

Queue::~Queue()
{
    LLNode *current = this->head;
    while (current != nullptr)
    {
        LLNode *temp = current->next;
        delete current;
        current = temp;
    }
    cout << (this->tail == nullptr) << endl;
}

void Queue::enqueue(char data)
{
    LLNode *newNode = new LLNode(data);
    
    if (this->head == nullptr && this->tail == nullptr)
    {
        this->head = this->tail = newNode;
        return;
    }

    this->tail->next = newNode;
    this->tail = newNode;
}

char Queue::dequeue()
{
    LLNode *temp = this->head;
    if(this->head == nullptr)
    {
        return '\0';
    }
    if(this->head == this->tail)
    {
        this->head = this->tail = nullptr;
    }
    else
    {
        this->head = this->head->next;
    }
    char data = temp->data;
    delete temp;
    return data;
}

char Queue::peek()
{
    if (this->head == nullptr)
    {
        return '\0';
    }
    return this->head->data;
}

void Queue::display()
{
    LLNode *current = this->head;

    while (current != nullptr)
    {
        cout << current->data << " ";
        current = current->next;
    }

    cout << endl;
}