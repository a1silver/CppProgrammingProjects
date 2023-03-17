#include <iostream>
#include <cstring>

#include "queue.h"
#include "stacks.h"
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
Queue *inputExpression();
void shuntingYardify(Queue *expression);
void constructExpressionTree(Queue *postfix, ExpressionTree *tree);
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
            if (!tree->isEmpty())
            {
                cout << "An expression has already been entered, please type \"CLEAR\" to clear the current expression." << endl;
            }
            else
            {
                Queue *queue = inputExpression();
                try
                {
                    shuntingYardify(queue);
                    constructExpressionTree(queue, tree);
                    cout << "Done." << endl;
                }
                catch (runtime_error &ex)
                {
                    cout << ex.what() << endl;
                }
                delete queue;
            }
        }
        if (strcmp(cmd, DISPLAY_CMD) == 0)
        {
            if (tree->isEmpty())
            {
                cout << "There is no current expression!" << endl;
            }
            else
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

        cout << endl;
    }

    return 0;
}

Queue *inputExpression()
{
    cout << "Enter in your expression.  Numbers should be single digits only.  Separate each token with a space.  Expression shouldn't exceed 100 characters in length (including spaces).";
    cout << " >> ";

    cin.ignore();

    char expression[101];
    cin.getline(expression, 101, '\n');

    Queue *queue = new Queue();

    for (int i = 0; i < 101; i++)
    {
        if (expression[i] == '\0')
        {
            break;
        }
        if (expression[i] == ' ')
        {
            continue;
        }

        queue->enqueue(expression[i]);
    }

    return queue;
}

void shuntingYardify(Queue *expression)
{
    Queue outputQueue;
    Stack operatorStack;

    while (!expression->isEmpty())
    {
        TreeNode<char> *node = new TreeNode<char>(expression->dequeue());

        if (node->data >= '0' && node->data <= '9')
        {
            outputQueue.enqueue(node->data);
        }
        else if (node->isOperator())
        {
            while (
                (operatorStack.peek() != '(') && (precedence(operatorStack.peek()) >= precedence(node->data)))
            {
                outputQueue.enqueue(operatorStack.pop());
            }
            operatorStack.push(node->data);
        }
        else if (node->data == '(')
        {
            operatorStack.push(node->data);
        }
        else if (node->data == ')')
        {
            while (operatorStack.peek() != '(')
            {
                if (operatorStack.peek() == '\0') // The operator stack is empty before we've closed the parentheses
                {
                    throw runtime_error("Expression has one more more mismatched parentheses");
                }
                else
                {
                    outputQueue.enqueue(operatorStack.pop());
                }
            }
            if (operatorStack.peek() == '(')
            {
                operatorStack.pop();
            }
        }
    }
    while (!operatorStack.isEmpty())
    {
        if (operatorStack.peek() == '(')
        {
            throw runtime_error("Expression has one more more mismatched parentheses");
        }
        else
        {
            outputQueue.enqueue(operatorStack.pop());
        }
    }
    while (!expression->isEmpty())
    {
        expression->dequeue();
    }
    while (!outputQueue.isEmpty())
    {
        expression->enqueue(outputQueue.dequeue());
    }
}

void constructExpressionTree(Queue *postfix, ExpressionTree *tree)
{
    ExpressionStack stack; // This stack contains pointers so we don't want to create a dynamically allocated object here

    while (!postfix->isEmpty())
    {
        TreeNode<char> *node = new TreeNode<char>(postfix->dequeue());

        if (node->isOperand())
        {
            stack.push(node);
        }
        else
        {
            TreeNode<char> *leftChild = stack.pop();
            TreeNode<char> *rightChild = stack.pop();
            node->left = leftChild;
            node->right = rightChild;
            stack.push(node);
        }
    }
    tree->setRoot(stack.pop());
}

int precedence(char op)
{
    switch (op)
    {
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