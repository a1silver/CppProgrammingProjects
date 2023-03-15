#include "nodes.h"

LLNode::LLNode(char data)
{
    this->next = nullptr;
    this->data = data;
}

TreeNode::TreeNode(char data)
{
    this->left = nullptr;
    this->right = nullptr;
    this->data = data;
}

bool TreeNode::isOperator()
{
    return (this->data == '+' || this->data == '-' || 
            this->data == '*' || this->data == '/' || 
            this->data == '%' || this->data == '^'
            );
}

bool TreeNode::isOperand()
{
    return !isOperator();
}