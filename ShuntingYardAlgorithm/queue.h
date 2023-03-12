#ifndef QUEUE_H
#define QUEUE_H

#include "nodes.h"

class Queue
{
public:
    Queue();
    ~Queue();
    void enqueue(char data);
    char dequeue();
    char peek();
    void display();

private:
    LLNode *head;
    LLNode *tail;
};

#endif // QUEUE_H