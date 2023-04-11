#ifndef NODE_H
#define NODE_H

struct Node {
    Node(int);

    int data;

    Node *parent;
    Node *left;
    Node *right;
    
    int color;
};

#endif // NODE_H