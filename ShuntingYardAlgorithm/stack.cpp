#include <iostream>

#include "nodes.h"
#include "stack.h"

using namespace std;

Stack::Stack()
{
    this->head = nullptr;
}

Stack::~Stack()
{
    LLNode *current = this->head;
    while (current != nullptr)
    {
        LLNode *temp = current->next;
        delete current;
        current = temp;
    }
}

void Stack::push(char data)
{
    LLNode *oldHead = this->head;
    this->head = new LLNode(data);
    this->head->next = oldHead;
}

char Stack::pop()
{
    LLNode *top = this->head;
    this->head = top->next;
    char data = top->data;
    delete top;
    return data;
}

char Stack::peek()
{
    return this->head->data;
}

void Stack::display()
{
    LLNode *current = this->head;

    while (current != nullptr)
    {
        cout << current->data << " ";
        current = current->next;
    }

    cout << endl;
}