#ifndef RBT_H
#define RBT_H

#include <vector>
#include "node.h"

using namespace std;

class RBT {
    private:
        Node *root;
        Node *nullNode;
        int size;
        void recursiveDestructor(Node *);
        void fixAdd(Node *);
        void fixRemove(Node *);
        void rotateLeft(Node *);
        void rotateRight(Node *);
        Node *getUncle(Node *);
        void transplant(Node *, Node *);
        Node *getMinimum(Node *);
        void display(Node *, vector<char>, bool);
    public:
        RBT();
        ~RBT();
        void add(int);
        bool remove(int);
        void display();
        bool search(int);
};

#endif // RBT_H