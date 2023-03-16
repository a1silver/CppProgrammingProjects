#ifndef TREE_H
#define TREE_H

#include "nodes.h"

class ExpressionTree {
    private:
        TreeNode<char>* root;

        void inorderTraversal(TreeNode<char>* node);
        void preorderTraversal(TreeNode<char>* node);
        void postorderTraversal(TreeNode<char>* node);

    public:
        ExpressionTree();

        bool isEmpty();
        void insert(char data);
        void setRoot(TreeNode<char> *newRoot);

        void printInorder();
        void printPreorder();
        void printPostorder();
};

#endif // TREE_H