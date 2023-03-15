#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
#include "nodes.h"

using namespace std;

class Queue
{
    private:
        LLNode* front;
        LLNode* rear;
    public:
        Queue();
        bool isEmpty();
        void enqueue(char data);
        char dequeue();
        char peek();
};

#endif // QUEUE_H