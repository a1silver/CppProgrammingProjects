Hash Table

Create a hash table and a random student generator                                        

Why are we doing this?  Hash Tables are efficient ways to access data.  If you have a good hash function, it can be efficient to store information in one of these.

Implementation:  Start from your student list program, meaning you need ADD, PRINT, DELETE, and QUIT. Change the way the students are stored; use a hash table. You should create a hash function using the student data which attempts to spread out data evenly through the table. It can be something you make up, or you may use a pre-existing hash formula. The hash table should start with at least 100 slots (of an array, not a vector).  It should be able to deal with collisions in a valid way. We will be using chaining, which means each entry is actually a linked list. (10 points) If you get more than 3 collisions when you are chaining (so you add, or would add, a fourth node to a single chain), create a table to have at least double the number of slots, then rehash your students into the new table.  (Your hash should alter based on the size of the table, by the way, and it should spread out the data as you resize the table.  Make it so.)  (10 points)

In addition to adding students manually to the hash table, create a random student generator.  You should have a file with a list of first names and a file with a list of last names.  Your student list program should be able to randomly generate new students by grabbing a random student first and last name from the corresponding files, incrementing the id number, adding a random GPA (much like real life), and adding it in.  Make sure you have a command that allows you to specify how many students to generate and add.  This will make debugging your project MUCH easier.  (10 points)

Comment. (5 points)

Total Points: 35