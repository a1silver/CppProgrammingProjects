#ifndef NODES_H
#define NODES_H

struct LLNode
{
    LLNode(char data);
    LLNode *next;
    char data;
};

struct TreeNode
{
    TreeNode(char data);
    TreeNode *left;
    TreeNode *right;
    char data;
};

#endif // NODES_H