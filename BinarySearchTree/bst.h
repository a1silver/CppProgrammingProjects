#ifndef BST_H
#define BST_H

#include "node.h"

class BST
{
public:
    BST();
    ~BST();
    void add(int data);
    void remove(int data);
    bool search(int data);
    void display();

private:
    Node *root;
    int size;
    Node *add(Node *current, int data);
    Node *remove(Node *current, int data);
    bool search(Node *current, int data);
    void display(Node *current, int depth);
    Node *minValueNode(Node *current);
    void recursiveDestructor(Node *current);
};

#endif // BST_H