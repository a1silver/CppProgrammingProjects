#include <iostream>
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
const char QUIT_CMD[] = "QUIT";
const char EXIT_CMD[] = "EXIT";

// Function prototypes
Queue<char> *inputExpression();
void displayInfix(Tree *tree);
void displayPrefix(Tree *tree);
void displayPostfix(Tree *tree);

int main()
{
    cout << "Shunting-Yard Algorithm Implementation by Morgan Hinz" << endl;
    cout << "-----------------------------------------------------" << endl;

    return 0;
}