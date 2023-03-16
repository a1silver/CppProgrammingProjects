#include <iostream>
#include <cstring>

#include "queue.h"
#include "stack.h"
#include "tree.h"

using namespace std;

// Commands
const char INPUT_CMD[] = "INPUT";
const char DISPLAY_CMD[] = "DISPLAY";
const char INFIX_DISPLAY_OPT[] = "INFIX";
const char PREFIX_DISPLAY_OPT[] = "PREFIX";
const char POSTFIX_DISPLAY_OPT[] = "POSTFIX";
const char CLEAR_CMD[] = "CLEAR";
const char QUIT_CMD[] = "QUIT";
const char EXIT_CMD[] = "EXIT";

// Function prototypes
Queue<char> *inputExpression();
void shuntingYardify(Queue<char> *expression);
void constructExpressionTree(Queue<char> *postfix, ExpressionTree *tree);
int precedence(char op);

int main()
{
    cout << "Shunting-Yard Algorithm Implementation by Morgan Hinz" << endl;

    ExpressionTree *tree = new ExpressionTree();

    char cmd[8];

    while (true)
    {
        cout << "-----------------------------------------------------" << endl;
        cout << "INPUT, DISPLAY, CLEAR or QUIT / EXIT" << endl;
        cout << " >> ";
        cin >> cmd;

        if (strcmp(cmd, INPUT_CMD) == 0)
        {
            if(!tree->isEmpty())
            {
                cout << "An expression has already been entered, please type \"CLEAR\" to clear the current expression." << endl;
            }
            else
            {
                Queue<char> *queue = inputExpression();
                shuntingYardify(queue);
                constructExpressionTree(queue, tree);
                delete queue;
            }
        }
        if (strcmp(cmd, DISPLAY_CMD) == 0)
        {
            cout << "You can display in either \"INFIX\", \"PREFIX\", or \"POSTFIX\" form." << endl;
            cout << " >> ";
            char opt[8];
            cin >> opt;

            if (strcmp(opt, INFIX_DISPLAY_OPT) == 0)
            {
                tree->printInorder();
            }
            if (strcmp(opt, PREFIX_DISPLAY_OPT) == 0)
            {
                tree->printPreorder();
            }
            if (strcmp(opt, POSTFIX_DISPLAY_OPT) == 0)
            {
                tree->printPostorder();
            }
        }
        if (strcmp(cmd, CLEAR_CMD) == 0)
        {
            delete tree;
            tree = new ExpressionTree();
            cout << "Expression cleared." << endl;
        }
        if (strcmp(cmd, EXIT_CMD) == 0 || strcmp(cmd, QUIT_CMD) == 0)
        {
            delete tree;
            break;
        }
    }

    return 0;
}

Queue<char> *inputExpression()
{
    cout << "Enter in your expression.  Numbers should be single digits only.  Separate each token with a space.  Expression shouldn't exceed 100 characters in length (including spaces).";
    cout << " >> ";

    char expression[101];
    cin >> expression;

    Queue<char> *queue = new Queue<char>();

    for(int i = 0; i < 101; i++)
    {
        if(expression[i] == '\0')
        {
            break;
        }

        queue->enqueue(expression[i]);
    }

    return queue;
}

void shuntingYardify(Queue<char> *expression)
{
    Queue<char> temp;
    Queue<char> *outputQueue = expression; // This line is simply to let the below code make more sense.
    Stack<char> *operatorStack;

    while (!expression->isEmpty())
    {
        temp.enqueue(expression->dequeue());
    }

    while (!temp.isEmpty())
    {
        TreeNode<char> token(temp.dequeue()); // We can take advantage of TreeNode's isOperand() and isOperator() this way
        
        if (token.isOperand())
        {
            outputQueue->enqueue(token.data);
        }
        else
        {
            if (token.data == ')')
            {
                while (operatorStack->peek() != '(')
                {
                    outputQueue->enqueue(operatorStack->pop());
                }
            }
            else
            {
                try {
                    if (precedence(operatorStack->peek()) > precedence(token.data))
                    {
                        outputQueue->enqueue(operatorStack->pop());
                        operatorStack->push(token.data);
                    }
                    else
                    {
                        operatorStack->push(token.data);
                    }
                }
                catch (runtime_error& ex)
                {
                    operatorStack->push(token.data);
                }
            }
        }
    }
}

void constructExpressionTree(Queue<char> *postfix, ExpressionTree *tree)
{
    Stack<TreeNode<char> *> stack;

    while (!postfix->isEmpty())
    {
        char symbol = postfix->dequeue();
        TreeNode<char> *node = new TreeNode<char>(symbol);

        if (node->isOperand())
        {
            stack.push(node);
        }
        else
        {
            node->right = stack.pop();
            node->left = stack.pop();
            stack.push(node);
        }
    }

    tree->setRoot(stack.pop());
}

int precedence(char op) {
    switch(op) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '^':
            return 3;
        default:
            return 0;
    }
}