# Palindrome (Assignment)

NOTE: BE VERY CAREFUL ABOUT NULL CHARACTERS AT THE END OF CSTRINGS.

The Idea

Create a program that will read in a series of characters; only read in 80 characters at most.  Remove all spaces and punctuation.  (20 points)  Check to see if the input is the same backwards as it is forwards. If it is a palindrome (the same backwards and forwards), print “Palindrome”.  If not, print “Not a palindrome.” (20 points) Make sure that you make all of the letters the same case before comparing! You may include numbers, but nothing beyond alphanumeric characters.

A quick note about Macs vs. other machines. Some Macs automatically include cstring; make sure you do this manually, anyway, since we often test your code on Windows and Linux devices.

One other thing; if you are accidentally not allocating enough space, it is entirely possible that you will accidentally wander into memory that isn't part of your character arrays, especially when printing. C++ doesn't mind this, because it assumes you know what you're doing. (Do you need some explosives? Here you go! I assume you know what you're doing...) It does NOT check to see if you go off the end of an array, which means that you can assign ten characters to a five character array, merrily writing over whatever the next five spots in memory are after the end of your array. This means that you can have code that does not throw an error even after you've technically made one, but it breaks on a later line of code trying to access other memory, possibly even seeming like a random error.

 

DO NOT USE STRINGS FOR THIS PROJECT. You should use character arrays/cstrings.

You may use the <cstring> library, including strcmp, strlen, strcpy.

 

Example:

A dog, a plan, a canal: pagoda.

Palindrome.

 

This is not a palindrome.

Not a palindrome.



Implementation

Read in from cin into a character array.  Don’t forget to remove punctuation and spaces!  You probably want to create a second character array, and put all the characters in backwards.  Compare the two arrays, and see if they are the same.

There are a number of ways to implement this, so I’m going to leave the implementation details to you.

Comments? Comments! (5 points)

Total: 45 points