#include <iostream>
#include <iomanip>
#include <vector>

#include "rbt.h"

using namespace std;

#define underline "\033[4m"
#define red "\033[31m"
#define reset "\033[0m"

RBT::RBT()
{
    this->nullNode = new Node();
    this->root = this->nullNode;
    this->size = 0;
}

RBT::~RBT()
{
    this->recursiveDestructor(this->root);
}

void RBT::recursiveDestructor(Node *current)
{
    if(current == this->nullNode) {
        return;
    }
    Node *left = current->left;
    Node *right = current->right;

    delete current;

    this->recursiveDestructor(left);
    this->recursiveDestructor(right);
}

void RBT::add(int data)
{
    Node *newNode = new Node(this->nullNode, data);

    Node *addTo = nullptr;
    Node *current = this->root;
    while (current != this->nullNode)
    {
        addTo = current;
        if (newNode->data > current->data)
        {
            current = current->right;
        }
        else
        {
            current = current->left;
        }
    }

    newNode->parent = addTo;
    if (addTo == nullptr) // Case 1 part a: The root is null
    {
        this->root = newNode;
    }
    else if (newNode->data > addTo->data)
    {
        addTo->right = newNode;
    }
    else
    {
        addTo->left = newNode;
    }

    // Case 1 part b: The root is null
    if (newNode->parent == nullptr)
    {
        newNode->color = 'b'; // Simply set the new node's color to black
        return;
    }
    /*
    Case 2: The node's parent is black.
    This only applies to nodes in the second level of the tree.
    If the new node's parent's parent is null, then the new node's parent is the root of the tree, and the root shouldn't have a parent node.
    */
    if (newNode->parent->parent == nullptr)
    {
        return;
    }

    // Handle the rest of the cases in a separate function.
    this->fixAdd(newNode);
}

void RBT::fixAdd(Node *current)
{
    Node *uncle = this->getUncle(current);
    bool isUncleOnLeft = (uncle == current->parent->parent->left);
    while (current->parent->isRed()) // We don't need to fix insertion if the parent's color is red, as that wouldn't violate the RBT properties.
    {
        if (isUncleOnLeft)
        {
            if (uncle->isRed()) // Case 3: Both the parent and the uncle of the current node is red
            {
                // Set the parent and uncle to black, and set the grandparent to red
                uncle->color = 'b';
                current->parent->color = 'b';
                current->parent->parent->color = 'r';

                current = current->parent->parent; // Used for checking to see if the current's grandparent is the root (at the end);
            }
            else // Case 4: The uncle is black.  Parent is left and node is right OR parent is right and node is left
            {
                if (current == current->parent->left) // Current is the left child
                {
                    // Set up a tree rotation through the current node's parent
                    current = current->parent;
                    this->rotateRight(current);
                }
                // Case 5: The uncle is black.  Parent is left and node is left OR parent is right and node is right
                // Swap the parent and the grandparent colors
                current->parent->color = 'b';
                current->parent->parent->color = 'r';
                // Set up a tree rotation through current node's grandparent
                this->rotateLeft(current->parent->parent);
            }
        }
        else
        {
            if (uncle->isRed()) // Case 3: Both the parent and the uncle of the current node is red
            {
                // Set the parent and uncle to black, and set the grandparent to red
                uncle->color = 'b';
                current->parent->color = 'b';
                current->parent->parent->color = 'r';

                current = current->parent->parent; // Used for checking to see if the current's grandparent is the root (at the end);
            }
            else // Case 4: The uncle is black.  Parent is left and node is right OR parent is right and node is left
            {
                if (current == current->parent->right) // Current is the left child
                {
                    // Set up a tree rotation through the current node's parent
                    current = current->parent;
                    this->rotateLeft(current);
                }
                // Case 5: The uncle is black.  Parent is left and node is left OR parent is right and node is right
                // Swap the parent and the grandparent colors
                current->parent->color = 'b';
                current->parent->parent->color = 'r';
                // Set up a tree rotation through current node's grandparent
                this->rotateRight(current->parent->parent);
            }
        }
        if (current == this->root)
        {
            break;
        }
    }
    this->root->color = 'b';
}

Node *RBT::getUncle(Node *node)
{
    if (node->parent == node->parent->parent->right)
    {
        return node->parent->parent->left;
    }
    else
    {
        return node->parent->parent->right;
    }
}

void RBT::rotateLeft(Node *origin)
{
    Node *right = origin->right;
    origin->right = right->left;

    if (right->left != this->nullNode)
    {
        right->left->parent = origin;
    }

    right->parent = origin->parent;

    if (origin->parent == nullptr)
    {
        this->root = right;
    }
    else if (origin == origin->parent->left)
    { // Origin is to the left of the parent
        origin->parent->left = right;
    }
    else
    {
        origin->parent->right = right;
    }

    right->left = origin;
    origin->parent = right;
}

void RBT::rotateRight(Node *origin)
{
    Node *left = origin->left;
    origin->left = left->right;

    if (left->right != this->nullNode)
    {
        left->right->parent = origin;
    }

    left->parent = origin->parent;

    if (origin->parent == nullptr)
    {
        this->root = left;
    }
    else if (origin == origin->parent->right)
    { // Origin is to the right of the parent
        origin->parent->right = left;
    }
    else
    {
        origin->parent->left = left;
    }

    left->right = origin;
    origin->parent = left;
}

/*
void RBT::display(Node *current, bool left, int depth)
{
    if (current == nullptr) // We're at the end of the list
    {
        return;
    }
    display(current->right, false, depth + 1); // First display the right subtree (at the top)

    if (current != this->nullNode)
    {
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

        cout << underline << (current->isRed() ? red : "") << current->data << reset << endl; // Add a bit of underlining and print the data
    }

    display(current->left, true, depth + 1); // Then display the left subtree (at the bottom)
}
*/
void RBT::display(Node *current, vector<char> indent, bool left, int depth) {
    if (current == this->nullNode) { // We've reached the end of a subtree
        return;
    }
    vector<char>::iterator it;
    for(it = indent.begin(); it != indent.end(); it++) {
        cout << *it << "  ";
    }
    if(left) {
        indent.push_back(' ');
    } else {
        indent.push_back('|');
    }
    // cout << setw(depth * 3);
    cout << (current == this->root ? "T" : (left ? "L" : "R")) << "--->";
    cout << (current->isRed() ? red : "") << underline << current->data << reset << endl;
    display(current->left, indent, false, depth + 1);
    display(current->right, indent, true, depth + 1);
}

void RBT::display()
{
    vector<char> indent;
    this->display(this->root, indent, false, 0);
}