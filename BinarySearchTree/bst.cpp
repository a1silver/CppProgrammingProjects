#include <iostream>
#include <iomanip>

#include "bst.h"

#define underline "\033[4m"
#define reset "\033[24m"

using namespace std;

BinarySearchTree::BinarySearchTree()
{
    this->root = nullptr;
    this->size = 0;
}

BinarySearchTree::~BinarySearchTree()
{
    // Recursively remove all nodes (a simple loop won't work)
    this->recursiveDestructor(this->root);
}

void BinarySearchTree::recursiveDestructor(Node *current)
{
    if (current == nullptr) // We're either at the end of the tree or the root doesn't exist
    {
        return;
    }

    // Get the left and right nodes
    Node *left = current->left;
    Node *right = current->right;

    delete current;

    // Recursively run the function on both the left and right child nodes
    recursiveDestructor(left);
    recursiveDestructor(right);
}

// Public wrapper function for adding a number to the tree
void BinarySearchTree::add(int data)
{
    if (this->root == nullptr) // If the root is null, create it
    {
        this->root = new Node(data);
        return;
    }
    this->add(this->root, data);
}

// Private recursive add function
Node *BinarySearchTree::add(Node *current, int data)
{
    if (current == nullptr) // We didn't find an appropriate place to add the value
    {
        return new Node(data);
    }

    // Insert data
    if (data > current->data)
    {
        // Insert right node data, if the data to be inserted is greater than current node data.

        // Process right nodes.
        current->right = add(current->right, data);
    }
    else if (data < current->data)
    {
        // Insert left node data, if the data to be inserted is smaller than current node data.

        // Process left nodes.
        current->left = add(current->left, data);
    }

    // Return 'current' node, after insertion.
    return current;
}

// Public wrapper function for removing a number from the tree
void BinarySearchTree::remove(int data)
{
    this->root = this->remove(this->root, data);
}

// Private recursive remove function
Node *BinarySearchTree::remove(Node *current, int value)
{
    if (current == nullptr) // The value wasn't found
    {
        return current;
    }
    if (value < current->data) // Move to the left
    {
        current->left = this->remove(current->left, value);
    }
    else if (value > current->data) // Move to the right
    {
        current->right = this->remove(current->right, value);
    }
    else
    {
        // Case 1: Node has no child
        if (current->left == nullptr && current->right == nullptr)
        {
            delete current;
            current = nullptr;
        }
        // Case 2: Node has one child
        else if (current->left == nullptr) // Case 2a: The right node exists
        {
            Node *temp = current;
            current = current->right;
            delete temp;
        }
        else if (current->right == nullptr) // Case 2b: The left node exists
        {
            Node *temp = current;
            current = current->left;
            delete temp;
        }
        // Case 3: Node has two children
        else
        {
            Node *temp = this->minValueNode(current->right); // Find the "lowest" child node of the current node
            current->data = temp->data;
            current->right = this->remove(current->right, temp->data);
        }
    }
    return current;
}

// Public wrapper function to find data in the tree
bool BinarySearchTree::search(int data)
{
    return this->search(this->root, data);
}

// Private recursive search function
bool BinarySearchTree::search(Node *current, int data)
{
    if (current == nullptr) // The value wasn't found
    {
        return false;
    }
    if (current->data == data) // We found the data
    {
        return true;
    }
    if (data < current->data) // Move to the left
    {
        return search(current->left, data);
    }
    else // Move to the right
    {
        return search(current->right, data);
    }
}

// Public wrapper function to display the entire tree
void BinarySearchTree::display()
{
    this->display(this->root, false, 0);
}

/*
    Private recursive display function

    Params:
     - Node *current: the current leaf
     - bool left: if the current leaf is a left node or a right node
     - int depth: how far the line should be indented
*/
void BinarySearchTree::display(Node *current, bool left, int depth)
{
    if (current == nullptr) // We're at the end of the list
    {
        return;
    }
    display(current->right, false, depth + 1); // First display the right subtree (at the top)

    cout << setw(depth * 5) << ""; // Set up correct formatting
    // Add "arrows" showing the parent-child nodes
    if (left)
    {
        cout << "\\";
    }
    else
    {
        if (current != this->root)
        {
            cout << "/";
        }
    }
    
    cout << underline << current->data << reset << endl; // Add a bit of underlining and print the data
    display(current->left, true, depth + 1); // Then display the left subtree (at the bottom)
}

// Find the "lowest" child node of the current node
Node *BinarySearchTree::minValueNode(Node *node)
{
    Node *current = node;
    while (current && current->left != nullptr)
    {
        current = current->left;
    }
    return current;
}
