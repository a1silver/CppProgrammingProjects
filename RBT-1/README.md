Red-Black Tree

 

Create a Red-Black Tree

Why are we doing this?  Red-Black trees are a useful way of creating a binary search tree that balances itself (roughly).  Red-black trees have a certain set of properties:

1. A node is either red or black.
2. The root is black.
3. All leaves (NULL) are black.
4. Both children of every red node are black.
5. Every simple path from a given node to any of its descendant leaves contains the same number of black nodes.
 

Implementation:  Create an implementation of a red-black tree.  This tree should be able to handle numbers with up to three digits (1-999, whole numbers only). You do not have to deal with zero. Make sure that the tree always updates the red-black tree property no matter what you do to it!  The functions you should have are:

Add:  Enter a single number which gets inserted into the tree.  Update the tree. (40 points)

 

Read:  Read in a series of numbers from a file.  The file should have numbers separated by spaces in a single line.  Add each number sequentially, updating the tree properly after each one. (10 points)

Print:  Print out a representation of the tree.  It should have the number, red or black value, and parent as part of the print-out.  I would recommend creating a visual representation of the tree, as this will help with debugging. (10 points)

 

Total points: 60