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

void ExpressionTree::insert(char data)
{
    TreeNode<char> *node = new TreeNode<char>(data);

    if (isEmpty())
    {
        root = node;
    }
    else
    {
        TreeNode<char> *current = root;
        while (true)
        {
            if (data < current->data)
            {
                if (current->left == nullptr)
                {
                    current->left = node;
                    break;
                }
                else
                {
                    current = current->left;
                }
            }
            else
            {
                if (current->right == nullptr)
                {
                    current->right = node;
                    break;
                }
                else
                {
                    current = current->right;
                }
            }
        }
    }
}

void ExpressionTree::setRoot(TreeNode<char> *newRoot)
{
    this->root = newRoot;
}

void ExpressionTree::inorderTraversal(TreeNode<char> *node)
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
            inorderTraversal(node->right);
            cout << node->data << " ";
            inorderTraversal(node->left);
            cout << ") ";
        }
    }
}

void ExpressionTree::preorderTraversal(TreeNode<char> *node)
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
            preorderTraversal(node->right);
            preorderTraversal(node->left);
        }
    }
}

void ExpressionTree::postorderTraversal(TreeNode<char> *node)
{
    if (node != nullptr)
    {
        postorderTraversal(node->right);
        postorderTraversal(node->left);
        cout << node->data << " ";
    }
}

void ExpressionTree::printInorder()
{
    inorderTraversal(root);
    cout << endl;
}

void ExpressionTree::printPreorder()
{
    preorderTraversal(root);
    cout << endl;
}

void ExpressionTree::printPostorder()
{
    postorderTraversal(root);
    cout << endl;
}
