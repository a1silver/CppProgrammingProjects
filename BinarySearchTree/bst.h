#ifndef BST_H
#define BST_H

#include "node.h"

class BinarySearchTree
{
public:
    BinarySearchTree();
    ~BinarySearchTree();
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
    void display(Node *current, bool left, int depth);
    Node *minValueNode(Node *current);
    void recursiveDestructor(Node *current);
};

#endif // BST_H

/*
    The BinarySearchTree class provides functionality to recreate a binary search tree.

    A binary search tree is a data structure that allows for quick access to data.  
    The left node is always less than its parent, and the right node is always greater than its parent.
*/