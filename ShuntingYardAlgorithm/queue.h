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

#endif // QUEUE_H

/*
    This header contains an implementation for a Queue.  It is used to create an "output queue" for the Shunting Yard algorithm.

    A Queue follows the "first in / first out" or "last in / last out" rule, meaning that items will always be dequeued in the 
    same order as they were enqueued.
*/