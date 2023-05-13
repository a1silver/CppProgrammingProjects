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