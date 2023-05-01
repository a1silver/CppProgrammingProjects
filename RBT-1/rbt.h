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
        void rotateLeft(Node *);
        void rotateRight(Node *);
        Node *getUncle(Node *);
        void display(Node *, vector<char>, bool);
    public:
        RBT();
        ~RBT();
        void add(int);
        void display();
};

#endif // RBT_H