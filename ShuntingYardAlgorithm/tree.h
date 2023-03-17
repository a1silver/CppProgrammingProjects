#ifndef TREE_H
#define TREE_H

#include "nodes.h"

class ExpressionTree {
    private:
        TreeNode<char>* root;

        void infixTraversal(TreeNode<char>* node);
        void prefixTraversal(TreeNode<char>* node);
        void postfixTraversal(TreeNode<char>* node);

    public:
        ExpressionTree();
        ~ExpressionTree();

        bool isEmpty();
        void setRoot(TreeNode<char> *newRoot);

        void printInfix();
        void printPrefix();
        void printPostfix();
};

#endif // TREE_H