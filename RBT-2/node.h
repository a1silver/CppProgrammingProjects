#ifndef NODE_H
#define NODE_H
struct Node {
    Node();
    Node(Node *, int);

    bool isRed();
    bool isBlack();

    int data;

    Node *parent;
    Node *left;
    Node *right;
    
    char color; // 'r' is red, 'b' is black
};

#endif // NODE_H

/*
    This header file contains the definition for the Node struct.

    The Node struct represents a Node object.  A Node contains a left child, right child, parent node, a data value, and a color (red or black).
*/