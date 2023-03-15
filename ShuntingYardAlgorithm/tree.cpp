#include <iostream>
#include "tree.h"

using namespace std;

Tree::Tree()
{
    root = nullptr;
}

bool Tree::isEmpty()
{
    return (root == nullptr);
}

void Tree::insert(char data)
{
    TreeNode *node = new TreeNode(data);

    if (isEmpty())
    {
        root = node;
    }
    else
    {
        TreeNode *current = root;
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

void Tree::inorderTraversal(TreeNode *node)
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
            inorderTraversal(node->left);
            cout << node->data << " ";
            inorderTraversal(node->right);
            cout << ") ";
        }
    }
}

void Tree::preorderTraversal(TreeNode *node)
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
            preorderTraversal(node->left);
            preorderTraversal(node->right);
        }
    }
}

void Tree::postorderTraversal(TreeNode *node)
{
    if (node != nullptr)
    {
        postorderTraversal(node->left);
        postorderTraversal(node->right);
        cout << node->data << " ";
    }
}

void Tree::printInorder()
{
    inorderTraversal(root);
    cout << endl;
}

void Tree::printPreorder()
{
    preorderTraversal(root);
    cout << endl;
}

void Tree::printPostorder()
{
    postorderTraversal(root);
    cout << endl;
}
