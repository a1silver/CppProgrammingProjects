#ifndef NODES_H
#define NODES_H

template <class T>
struct LLNode
{
    LLNode *next;
    T data;

    LLNode(T data);
};

template <class T>
struct TreeNode
{
    TreeNode *left;
    TreeNode *right;
    T data;

    TreeNode(T data);
    
    bool isOperator();
    bool isOperand();
    bool isNumber();
};


// Implementations

template <class T>
LLNode<T>::LLNode(T data)
{
    this->next = nullptr;
    this->data = data;
}

template <class T>
TreeNode<T>::TreeNode(T data)
{
    this->left = nullptr;
    this->right = nullptr;
    this->data = data;
}

template <class T>
bool TreeNode<T>::isOperator()
{
    return (this->data == '+' || this->data == '-' || 
            this->data == '*' || this->data == '/' || 
            this->data == '%' || this->data == '^'
            );
}

template <class T>
bool TreeNode<T>::isOperand()
{
    return !isOperator();
}

template <class T>
bool TreeNode<T>::isNumber()
{
    return node->data >= '0' && node->data <= '9';
}

#endif // NODES_H