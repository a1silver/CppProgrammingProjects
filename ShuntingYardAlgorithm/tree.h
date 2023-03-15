#ifndef TREE_H
#define TREE_H

#include "nodes.h"

class Tree {
    private:
        TreeNode* root;

        void inorderTraversal(TreeNode* node);
        void preorderTraversal(TreeNode* node);
        void postorderTraversal(TreeNode* node);

    public:
        Tree();

        bool isEmpty();
        void insert(char data);
        bool search(char data);        

        void printInorder();
        void printPreorder();
        void printPostorder();
};

#endif // TREE_H