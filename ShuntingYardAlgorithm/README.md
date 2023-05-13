Shunting Yard

 

Binary Expression Tree and Stack

                                                          

Why are we doing this?:  Trees are often used in computer science.  This program will also take advantage of a stack, which will be used to create the expression trees. Finally, we'll use a stack and queue for the Shunting Yard algorithm.

BUILD A STACK USING A LINKED LIST. You don't need a separate class for this, but you DO need the push(), pop(), and peek() functions.

BUILD A QUEUE USING A LINKED LIST. You don't need a separate class for this, but you DO need the enqueue() and dequeue() functions.

Both of these data structures are useful for the Shunting Yard algorithm.

You might need a similar stack for building your tree, too.

BUILD A BINARY TREE NODE CLASS WITH A LEFT AND RIGHT POINTER. (This is very similar to the Node class for linked list, except it has a data value, left pointer, and right pointer. If you want to combine the linked list node into the binary tree node, meaning it has a left, right, AND next, you may.)

For your reference:

https://en.wikipedia.org/wiki/Shunting-yard_algorithm

https://en.wikipedia.org/wiki/Binary_expression_tree

Overview:  Take a mathematical expression containing the four basic arithmetic expressions, power (represented as a carat, '^'), integer numbers (you are only required to parse single-digit numbers), and parentheses. Translate it into postfix notation.

Then take in the postfix notation and create an expression tree. Allow the user to output the expression as infix, prefix, or postfix notation using the expression tree. (Note: You MUST output from the expression tree for infix, postfix, and prefix, rather than just printing the user input for infix, or the shunting yard output for postfix. No shortcuts!)

Interface:  Your program should read a mathematical expression entered with infix notation, using spaces between each token. It will then output the postfix expression. You should then be able to output infix, prefix, or postfix notation, which is a recursive print from the expression tree.

Points: 

10 points creating a stack properly

5 points creating a queue properly

10 points for properly working shunting yard algorithm

10 points for creating the expression tree

5 points for correct output of prefix, infix, and postfix.

10 points for commenting. Seriously. 