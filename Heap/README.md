Heap

 

Take a look at binary trees:

https://en.wikipedia.org/wiki/Binary_treeLinks to an external site.

and heaps:

https://en.wikipedia.org/wiki/Heap_(data_structure)Links to an external site.

 

Create a program that creates a heap.  (A binary tree where every node is larger than its child, which is called a max heap.) You should be able to enter a series of numbers (up to 100 numbers will be stored) OR enter a filename, which contains a space-separated list of numbers (with a range between 1 and 1000 for each number, and yes, this means your program should be able to handle both input methods). DO NOT ADD NUMBERS THEN ATTEMPT TO SORT; THEY SHOULD BE ADDED ONE AT A TIME.

The heap should also be able to remove the largest element from the heap (the root), adding it to the output (print the value to the console). Finally, create another "remove all" function, which calls your remove function continuously (sending each largest number to the output over and over) until you have removed all of the numbers from the heap. The output will be from largest to smallest, since this is a max heap.

Implementation:

When adding a single number, it should get added in the next available slot in the array, or the bottom row's rightmost empty slot if thinking as a tree. After that, you check your parent to see if you are larger than it, and if so, then swap with your parent. Recursively move up the tree until your parent is larger than you or you've reached the root.

When removing a single number, output the root's value to the console. Move the last available slot in the array (or bottom row's rightmost child as a tree) to the root (and reduce your table size by one). After that, check your left and right child to see if at least one of them is larger, and if so, swap with the larger one. Recursively move down the tree until you are smaller than both children, or you've reached a leaf.

Finally, you have a visual way to display your tree when it is full. There should be an obvious way to see the parent-child relationship for each node, as well as each value. (This will help you greatly in debugging your code.) One way I often recommend to people to display the tree is sideways, using tabs. Thus, if I need to represent the tree resulting from a heap with numbers 100, 99, 98, 97, 96, 95, 94 (not in order), it could result in:

        95

    96

        94

100

        97

    99

        98

(Note that I tab over an extra time at each level; the root is 100, while it's left child is 99 and right child is 96.)

A last word: no vectors, but instead implement this ADT as an array, rather than a series of tree nodes. Assuming you start at index 1 (instead of 0), you can find your left child at (index * 2) and your right child at (index * 2 + 1), while your parent is (floor(index / 2)).

 

Numbers are entered into the heap correctly (both from file and from command line):  10 points

Numbers are removed from the heap correctly (both individually and removing everything):  10 points

You have a way to visually represent the tree. 5 points

Comments. Really? I have to keep putting this on here? 5 points

 

Total: 30 points