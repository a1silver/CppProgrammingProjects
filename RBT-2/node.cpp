#include "node.h"

Node::Node() {
    this->data = 0;
    this->parent = nullptr;
    this->left = nullptr;
    this->right = nullptr;
    this->color = 'b';
}

Node::Node(Node *nullNode, int data) {
    this->data = data;
    this->parent = nullptr;
    this->left = nullNode;
    this->right = nullNode;
    this->color = 'r'; // 'r' is red, 'b' is black
}

bool Node::isBlack() {
    return this->color == 'b';
}

bool Node::isRed() {
    return !this->isBlack();
}