#include <iostream>
#include <iomanip>
#include <vector>

#include "rbt.h"

using namespace std;

// Terminal formatting codes
// Found on: https://stackoverflow.com/questions/2616906/how-do-i-output-coloured-text-to-a-linux-terminal
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

// Remove all the nodes in the tree
void RBT::recursiveDestructor(Node *current)
{
    if (current == this->nullNode)
    {
        return;
    }
    Node *left = current->left;
    Node *right = current->right;

    delete current;

    this->recursiveDestructor(left);
    this->recursiveDestructor(right);
}

// Add a node to the tree
void RBT::add(int data)
{
    Node *newNode = new Node(this->nullNode, data);

    // Find the node that the new node should be added to
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

// Runs through cases 3, 4, and 5 to maintain the properties of a Red-Black Tree
void RBT::fixAdd(Node *current)
{
    Node *uncle;
    while (current->parent->isRed()) // We don't need to fix insertion if the parent's color is black, as that wouldn't violate the RBT properties.
    {
        if (current->parent == current->parent->parent->right)
        {
            uncle = current->parent->parent->left;
            if (uncle->isRed()) // Case 3: Both the parent and the uncle of the current node is red
            {
                // Set the parent and uncle to black, and set the grandparent to red
                uncle->color = 'b';
                current->parent->color = 'b';
                current->parent->parent->color = 'r';
                current = current->parent->parent; // Used for checking to see if the current's grandparent is the root (at the end)
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
            uncle = current->parent->parent->right;

            if (uncle->isRed()) // Case 3: Both the parent and the uncle of the current node is red
            {
                // Set the parent and uncle to black, and set the grandparent to red
                uncle->color = 'b';
                current->parent->color = 'b';
                current->parent->parent->color = 'r';
                current = current->parent->parent; // Used for checking to see if the current's grandparent is the root (at the end)
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

/*
    Remove a node from the tree.

    Based off of https://www.programiz.com/dsa/red-black-tree's deletion and deletion fix algorithms.
*/
bool RBT::remove(int data)
{
    Node *foundNode = this->root;
    Node *toFix;
    Node *foundNodeOriginal;

    // Find the node that should be deleted
    while (foundNode != this->nullNode)
    {
        if (foundNode->data == data)
        {
            break;
        }

        if (foundNode->data <= data)
        {
            foundNode = foundNode->right;
        }
        else
        {
            foundNode = foundNode->left;
        }
    }

    if (foundNode == this->nullNode) // We didn't find the correct node
    {
        return false;
    }

    // Store the node that we want to delete and the color of that node for later use
    foundNodeOriginal = foundNode;
    char foundNodeOriginalColor = foundNodeOriginal->color;

    if (foundNode->left == this->nullNode) // The node to delete has one non-leaf child to the right
    {
        toFix = foundNode->right;
        this->transplant(foundNode, foundNode->right);
    }
    else if (foundNode->right == this->nullNode) // The node to delete has one non-leaf child to the left
    {
        toFix = foundNode->left;
        this->transplant(foundNode, foundNode->left);
    }
    else
    {
        foundNodeOriginal = this->getMinimum(foundNode->right); // Get the in-order successor (the smallest node of the found node's right subtree)
        foundNodeOriginalColor = foundNodeOriginal->color;      // Update the color of the minimum subtree
        toFix = foundNodeOriginal->right;                       // We now want to fix the right child of our minimum subtree

        if (foundNodeOriginal->parent == foundNode)
        {
            toFix->parent = foundNodeOriginal;
        }
        else
        {
            this->transplant(foundNodeOriginal, foundNodeOriginal->right);
            foundNodeOriginal->right = foundNode->right;
            foundNodeOriginal->right->parent = foundNodeOriginal;
        }

        this->transplant(foundNode, foundNodeOriginal);
        foundNodeOriginal->left = foundNode->left;
        foundNodeOriginal->left->parent = foundNodeOriginal;
        foundNodeOriginal->color = foundNode->color;
    }

    delete foundNode;

    if (foundNodeOriginalColor == 'b') // We only need to fix the Red-Black tree properties if we're removing a black node, removing red nodes doesn't violate the properties of a Red-Black tree
    {
        this->fixRemove(toFix);
    }
    return true;
}

/*
    Maintain the red-black tree properties after deletion.

    Based off of https://www.programiz.com/dsa/red-black-tree's deletion and deletion fix algorithms.
*/
void RBT::fixRemove(Node *toFix)
{
    Node *current;

    while (toFix != root && toFix->isBlack())
    {
        if (toFix == toFix->parent->left) // The node to fix is on the left side of its parent
        {
            current = toFix->parent->right; // Store the right sibling for easier use
            if (current->isRed())           // Case 1: The right child of the parent of our current node is red
            {
                current->color = 'b';
                toFix->parent->color = 'r';
                this->rotateLeft(toFix->parent);
                current = toFix->parent->right;
            }

            if (current->left->isBlack() && current->right->isBlack()) // Case 2: Both the right and the leftChild of our current node are BLACK
            {
                current->color = 'r';
                toFix = toFix->parent;
            }
            else
            {
                if (current->right->isBlack()) // Case 3: Only the right child of our current node is black
                {
                    current->left->color = 'b';
                    current->color = 'r';
                    this->rotateRight(current);
                    current = toFix->parent->right;
                }

                // Case 4: Only the right child of our current node is red
                current->color = toFix->parent->color;
                toFix->parent->color = 'b';
                current->right->color = 'b';
                this->rotateLeft(toFix->parent);
                toFix = this->root;
            }
        }
        else // Same as above but all uses of right and left are swapped (doing the same thing but the tree is mirrored)
        {
            current = toFix->parent->left;
            if (current->isRed())
            {
                current->color = 'b';
                toFix->parent->color = 'r';
                this->rotateRight(toFix->parent);
                current = toFix->parent->left;
            }

            if (current->right->isBlack() && current->right->isBlack())
            {
                current->color = 'r';
                toFix = toFix->parent;
            }
            else
            {
                if (current->left->isBlack())
                {
                    current->right->color = 'b';
                    current->color = 'r';
                    this->rotateLeft(current);
                    current = toFix->parent->left;
                }

                current->color = toFix->parent->color;
                toFix->parent->color = 'b';
                current->left->color = 'b';
                this->rotateRight(toFix->parent);
                toFix = this->root;
            }
        }
    }
    toFix->color = 'b'; // The node to fix should become black
}

/*
    Get the uncle of any node.
    Will return the node's parent's left node if the given node is on the right.
    Will return the node's parent's right node if the given node is on the left.
*/
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

// Rotate the subtrees of an origin node to the left
void RBT::rotateLeft(Node *origin)
{
    Node *right = origin->right;
    origin->right = right->left;
    if (right->left != this->nullNode)
    {
        right->left->parent = origin;
    }
    right->parent = origin->parent;
    if (origin->parent == nullptr) // We're at the top of the tree
    {
        this->root = right;
    }
    else if (origin == origin->parent->left) // Origin is to the right of the parent
    {
        origin->parent->left = right;
    }
    else
    {
        origin->parent->right = right;
    }
    right->left = origin;
    origin->parent = right;
}

// Rotate the substrees of an origin node to the right
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
    {
        origin->parent->right = left;
    }
    else
    {
        origin->parent->left = left;
    }
    left->right = origin;
    origin->parent = left;
}

// Replace the node being deleted with its successor or predecessor node while maintaining properties of the Red-Black Tree
void RBT::transplant(Node *toDelete, Node *replacement)
{
    if (toDelete->parent == nullptr) // We're at the top of the tree
    {
        this->root = replacement;
    }
    else if (toDelete == toDelete->parent->left)
    {
        toDelete->parent->left = replacement;
    }
    else
    {
        toDelete->parent->right = replacement;
    }
    replacement->parent = toDelete->parent;
}

// Get the "minimum" (predecessor) node of any node
Node *RBT::getMinimum(Node *origin)
{
    while (origin->left != this->nullNode)
    {
        origin = origin->left;
    }
    return origin;
}

/*
    Recursive helper function to display the tree
    The vector parameter is used to add lines that connect nodes at the same level in the tree to make visualization of the tree structure easier.
*/
void RBT::display(Node *current, vector<char> indent, bool left)
{
    if (current == this->nullNode) // We've reached the end of a subtree
    {
        return;
    }
    // Printing and updating the indentation
    for (vector<char>::iterator it = indent.begin(); it != indent.end(); it++)
    {
        cout << *it << "  ";
    }
    if (left)
    {
        indent.push_back(' ');
    }
    else
    {
        indent.push_back('|');
    }
    // Printing node value, position, and color
    cout << (current == this->root ? "T" : (left ? "L" : "R")) << "--->";
    cout << (current->isRed() ? red : "") << underline << current->data << reset << endl;
    // Display the subtrees
    display(current->right, indent, false);
    display(current->left, indent, true);
}

// Wrapper function to display the tree
void RBT::display()
{
    vector<char> indent;
    this->display(this->root, indent, false);
}

// Search for a value in the tree
bool RBT::search(int value)
{
    Node *current = this->root; // Start at the root
    while (true)
    {
        if (current == this->nullNode) // If we've reached a "null node," the value doesn't exist
        {
            return false;
        }
        if (current->data == value) // We've found the correct node
        {
            return true;
        }

        // Advance to the next node depending on if the value is less than or greater than the current node
        if (current->data > value)
        {
            current = current->left;
        }
        else
        {
            current = current->right;
        }
    }
}