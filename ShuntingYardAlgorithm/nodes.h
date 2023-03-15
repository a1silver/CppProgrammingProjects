#ifndef NODES_H
#define NODES_H

struct LLNode
{
    LLNode *next;
    char data;

    LLNode(char data);
};

struct TreeNode
{
    TreeNode *left;
    TreeNode *right;
    char data;

    TreeNode(char data);
    
    bool isOperator();
    bool isOperand();
};

#endif // NODES_H