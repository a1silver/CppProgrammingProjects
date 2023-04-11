#include "node.h"

Node::Node(int data) {
    this->data = data;
    this->parent = nullptr;
    this->left = nullptr;
    this->right = nullptr;
    this->color = 0; // 0 is black, 1 is red
}