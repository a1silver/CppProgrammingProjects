#ifndef NODE_H
#define NODE_H

struct Node
{
    int data;
    Node *left;
    Node *right;
    Node(int data);
};

#endif // NODE_H