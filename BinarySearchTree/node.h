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

/*
    The Node struct represents a tree node.  It contains a left and right Node pointer and an integer holding the Node's data.
*/