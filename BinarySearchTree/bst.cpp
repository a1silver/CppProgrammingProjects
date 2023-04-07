#include <iostream>
#include <iomanip>

#include "bst.h"

using namespace std;

BST::BST()
{
    this->root = nullptr;
    this->size = 0;
}

BST::~BST()
{
    this->recursiveDestructor(this->root);
}

void BST::recursiveDestructor(Node *current)
{
    if (current == nullptr)
    {
        return;
    }
    Node *left = current->left;
    Node *right = current->right;
    delete current;
    if (left != nullptr)
    {
        recursiveDestructor(left);
    }
    if (right != nullptr)
    {
        recursiveDestructor(right);
    }
}

void BST::add(int data)
{
    if (this->root == nullptr)
    {
        this->root = new Node(data);
        return;
    }
    this->add(this->root, data);
}

Node *BST::add(Node *current, int data)
{
    if (current == nullptr)
    {
        return new Node(data);
    }
    // Insert data.
    if (data > current->data)
    {
        // Insert right node data, if the 'value'
        // to be inserted is greater than 'current' node data.

        // Process right nodes.
        current->right = add(current->right, data);
    }
    else if (data < current->data)
    {
        // Insert left node data, if the 'value'
        // to be inserted is smaller than 'current' node data.

        // Process left nodes.
        current->left = add(current->left, data);
    }

    // Return 'current' node, after insertion.
    return current;
}

void BST::remove(int data)
{
    this->root = this->remove(this->root, data);
}

Node* BST::remove(Node* current, int value) {
    if (current == NULL) {
        return current;
    }
    if (value < current->data) {
        current->left = this->remove(current->left, value);
    }
    else if (value > current->data) {
        current->right = this->remove(current->right, value);
    }
    else {
        // Case 1: Node has no child
        if (current->left == NULL && current->right == NULL) {
            delete current;
            current = NULL;
        }
        // Case 2: Node has one child
        else if (current->left == NULL) {
            Node* temp = current;
            current = current->right;
            delete temp;
        }
        else if (current->right == NULL) {
            Node* temp = current;
            current = current->left;
            delete temp;
        }
        // Case 3: Node has two children
        else {
            Node* temp = this->minValueNode(current->right);
            current->data = temp->data;
            current->right = this->remove(current->right, temp->data);
        }
    }
    return current;
}

bool BST::search(int data) {
    return this->search(this->root, data);
}

bool BST::search(Node* current, int data) {
    if (current == NULL) {
        return false;
    }
    if (current->data == data) {
        return true;
    }
    if (data < current->data) {
        return search(current->left, data);
    }
    else {
        return search(current->right, data);
    }
}

void BST::display()
{
    this->display(this->root, 0);
}

void BST::display(Node *current, int depth)
{
    if (current == nullptr)
    {
        return;
    }
    display(current->right, depth + 1);
    cout << setw(depth * 5) << "";
    cout << current->data << endl;
    display(current->left, depth + 1);
}

Node *BST::minValueNode(Node *node)
{
    Node *current = node;
    while (current && current->left != NULL)
    {
        current = current->left;
    }
    return current;
}
