#include <iostream>
#include "queue.h"
#include "stack.h"

using namespace std;

int main()
{
    Queue *q = new Queue();
    q->enqueue('1');
    q->enqueue('2');
    q->enqueue('3');
    q->display();
    q->dequeue();
    q->display();
    delete q;

    Stack *s = new Stack();
    s->push('1');
    s->push('2');
    s->push('3');
    s->display();
    s->pop();
    s->display();
    delete s;
        

    return 0;
}