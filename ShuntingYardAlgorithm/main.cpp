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

    ExpressionTree *tree = new ExpressionTree(); // This takes care of storing the completed expression tree

    char cmd[8];

    while (true)
    {
        cout << "-----------------------------------------------------" << endl;
        cout << "INPUT, DISPLAY, CLEAR or QUIT / EXIT" << endl;
        cout << " >> ";
        cin >> cmd; // Get the command

        if (strcmp(cmd, INPUT_CMD) == 0) // Input command (get an expression from the user)
        {
            if (!tree->isEmpty()) // The tree's root node is not null, that means the tree currently contains an expression
            {
                // Prompt the user to clear the current command
                cout << "An expression has already been entered, please type \"CLEAR\" to clear the current expression." << endl;
            }
            else
            {
                // Create a temporary queue pointer from a user-inputted expression
                // (This has to be a pointer so we can manually de-allocate pointers created by this object)
                Queue *queue = inputExpression();
                try
                {
                    shuntingYardify(queue);               // First, perform the shunting yard algorithm on the provided expression
                    constructExpressionTree(queue, tree); // Next, transform the same queue (now containing a postfix expression) into a binary tree
                    cout << "Done." << endl;
                }
                catch (runtime_error &ex) // The only time this will be used (currently) is when the expression contains one or more mismatched parentheses
                {
                    cout << ex.what() << endl;
                }
                delete queue;
            }
        }
        if (strcmp(cmd, DISPLAY_CMD) == 0) // Display command (display the current expression in either infix, prefix, or postfix notation)
        {
            if (tree->isEmpty()) // The tree's root node is null, that means the tree does not currently contain an expression
            {
                cout << "There is no current expression!" << endl;
            }
            else
            {
                // Prompt the user to choose to display the current expression in either infix, prefix, or postfix notation
                cout << "You can display in either \"INFIX\", \"PREFIX\", or \"POSTFIX\" form." << endl;
                cout << " >> ";
                char opt[8];
                cin >> opt;

                if (strcmp(opt, INFIX_DISPLAY_OPT) == 0)
                {
                    tree->printInfix(); // Start the recursive printing for infix notation
                }
                if (strcmp(opt, PREFIX_DISPLAY_OPT) == 0)
                {
                    tree->printPrefix(); // Start the recursive printing for prefix notation
                }
                if (strcmp(opt, POSTFIX_DISPLAY_OPT) == 0)
                {
                    tree->printPostfix(); // Start the recursive printing for postfix notation
                }
            }
        }
        if (strcmp(cmd, CLEAR_CMD) == 0)
        {
            // Delete the current expression tree and set the variable to a new instance
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

/*
    Construc
*/
void constructExpressionTree(Queue *postfix, ExpressionTree *tree)
{
    ExpressionStack stack; /*
                               This stack contains pointers that will be transferred to the expression tree,
                               so we don't want to create a dynamically allocated object here (and then have to delete it)
                           */

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

/*
    Get the precedence (PEMDAS) of a given operator
*/
int precedence(char op)
{
    switch (op)
    {
    case '+':
    case '-':
        // Add and subtract have lowest priority
        return 1;
    case '*':
    case '/':
        // Multiply and divide have middle priority
        return 2;
    case '^':
        // Exponents have highest priority
        return 3;
    default:
        return 0;
    }
}