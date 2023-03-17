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

/*
    This function prompts the user to input an expression.
    The input should only contain numbers, operators, and spaces.
    The input should be 101 characters or less.
*/
Queue *inputExpression()
{
    cout << "Enter in your expression.  Numbers should be single digits only.  Separate each token with a space.  Expression shouldn't exceed 100 characters in length (including spaces)." << endl;
    cout << " >> ";
    cin.ignore();
    char expression[102];
    cin.getline(expression, 101, '\n');

    // Create the queue pointer.  This will be returned later for easier queue modification / manipulation.
    Queue *queue = new Queue();

    // Loop through the inputted expression
    for (int i = 0; i < 102; i++)
    {
        if (expression[i] == '\0') // If the current character is a null character, we're at the end...
        {
            // ... and then we break from the loop
            break;
        }
        // If the current character is a space...
        if (expression[i] == ' ')
        {
            // ... we don't need to include it in the expression.
            // We only want numbers and operators in our final expression queue.
            continue;
        }

        queue->enqueue(expression[i]);
    }

    // Return the queue pointer
    return queue;
}

/*
    This function takes care of performing the Shunting Yard Algorithm.

    The queue pointer created in the above function is passed in.
    The expression contained inside will be transformed into postfix notation and will be used by the next function to create an expression tree.
*/
void shuntingYardify(Queue *expression)
{
    // Create the output queue and operator stack
    Queue outputQueue;
    Stack operatorStack;

    // Continuously read tokens from the expression until it's empty
    while (!expression->isEmpty())
    {
        TreeNode<char> *node = new TreeNode<char>(expression->dequeue()); // We can take advantage of TreeNode::isOperator() and TreeNode::isNumber() here

        if (node->isNumber()) // If the current token is a number...
        {
            outputQueue.enqueue(node->data); // ... add it to the output queue
        }
        else if (node->isOperator()) // If the current token is an operator...
        {
            // The following while loop is what takes care of preserving the order of operations (PEMDAS)
            while (
                (operatorStack.peek() != '\0' && operatorStack.peek() != '(') // Something exists on the operator stack, AND the top of the operator stack isn't an open parentheses
                && 
                (precedence(operatorStack.peek()) >= precedence(node->data))) // The precedence of the top of the operator stack is greater than the precedence of the current token
            {
                outputQueue.enqueue(operatorStack.pop()); // Pop off the top of the operator stack and put it into the output queue
            }
            operatorStack.push(node->data); // Finally put the current token onto the operator stack
        }
        else if (node->data == '(') // The current token is an open parentheses
        {
            operatorStack.push(node->data); // Simply put the current token onto the operator stack
        }
        else if (node->data == ')') // The current token is a closing parentheses
        {
            while (operatorStack.peek() != '(') // Find operators & put them in the output queue until the top of the operator stack is an open parentheses
            {
                if (operatorStack.peek() == '\0') // The operator stack is empty before we've closed the parentheses
                {
                    throw runtime_error("Expression has one more more mismatched parentheses");
                }
                else
                {
                    outputQueue.enqueue(operatorStack.pop()); // Pop off the top of the operator stack and put it into the output queue
                }
            }
            if (operatorStack.peek() != '\0' && operatorStack.peek() == '(') // Ensure that the top of the operator stack is an open parentheses...
            {
                operatorStack.pop(); // ... and remove it from the operator stack
            }
        }
    }
    // Put all remaining operators on the operator stack into the output queue
    while (!operatorStack.isEmpty())
    {
        if (operatorStack.peek() == '(') // If there's still a parentheses in the operator stack...
        {
            // We have mismatched parentheses
            throw runtime_error("Expression has one more more mismatched parentheses");
        }
        else
        {
            outputQueue.enqueue(operatorStack.pop());
        }
    }
    // Make sure there's nothing left in the expression queue from earlier
    while (!expression->isEmpty())
    {
        expression->dequeue();
    }
    // Copy the entirety of the output queue into the expression queue from earlier
    while (!outputQueue.isEmpty())
    {
        expression->enqueue(outputQueue.dequeue());
    }
}

/*
    Construct the expression tree from the given postfix expression
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
    case '%':
        // Multiply and divide have middle priority
        return 2;
    case '^':
        // Exponents have highest priority
        return 3;
    default:
        return 0;
    }
}