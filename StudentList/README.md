Student List
 

The Idea

This assignment is all about structs and pointers.

 

Create a struct.  It will have a first name (character array), a last name (character array), a number for the student id (int), and decimal for GPA (float).

 

Your program should have a vector of struct pointers passed by reference, or a vector pointer (which will point to a vector of struct pointers). (20 points)

 

Your program will allow you to read in students, print them out, and delete them.  Each of these functions should be in a different method.

 

When you type in: ADD

You should create a new entry for a student.  After you type in add, the program should prompt for first name, last name, student id, and GPA.  That student should then be added to the vector of students (well, student pointers!). (20 points)

 

When you type in: PRINT

Your program should print out all the students currently stored.  For example:

 

Jason Galbraith, 487329, 5.00

John Elstad, 903826, 3.25

Kevin Jin, 468921, 0.12

 

The GPA should be shown to two decimal places. I recommend looking up how iterators work; regular for loops do not work with vectors. (20 points)

 

When you type in: DELETE

Prompt the user for the student id number to delete, and remove that struct from the vector. Be sure to delete the data. (20 points)

 

By the way, your program should finish with a "QUIT" command.

 

Comment this thing. (10 points)