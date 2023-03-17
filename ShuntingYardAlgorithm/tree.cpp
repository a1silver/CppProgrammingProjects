#include <iostream>
#include "tree.h"

using namespace std;

ExpressionTree::ExpressionTree()
{
    root = nullptr;
}

ExpressionTree::~ExpressionTree()
{
    delete root;
}

bool ExpressionTree::isEmpty()
{
    return (root == nullptr);
}

void ExpressionTree::setRoot(TreeNode<char> *newRoot)
{
    this->root = newRoot;
}

void ExpressionTree::infixTraversal(TreeNode<char> *node)
{
    if (node != nullptr)
    {
        if (node->isOperand())
        {
            cout << node->data << " ";
        }
        else
        {
            cout << "( ";
            infixTraversal(node->right);
            cout << node->data << " ";
            infixTraversal(node->left);
            cout << ") ";
        }
    }
}

void ExpressionTree::prefixTraversal(TreeNode<char> *node)
{
    if (node != nullptr)
    {
        if (node->isOperand())
        {
            cout << node->data << " ";
        }
        else
        {
            cout << node->data << " ";
            prefixTraversal(node->right);
            prefixTraversal(node->left);
        }
    }
}

void ExpressionTree::postfixTraversal(TreeNode<char> *node)
{
    if (node != nullptr)
    {
        postfixTraversal(node->right);
        postfixTraversal(node->left);
        cout << node->data << " ";
    }
}

void ExpressionTree::printInfix()
{
    infixTraversal(root);
    cout << endl;
}

void ExpressionTree::printPrefix()
{
    prefixTraversal(root);
    cout << endl;
}

void ExpressionTree::printPostfix()
{
    postfixTraversal(root);
    cout << endl;
}
