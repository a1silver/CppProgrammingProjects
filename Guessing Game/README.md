# Guessing Game (Assignment)

Interface

The computer will pick a random number between 0 and 100, inclusive. The user will guess a number,

and the computer will tell you if it is too high, too low, or correct. If it is correct, it will display how

many guesses it took you, and ask if you want to play again.


Implementation

Create a variable which will hold the random number and use rand() to create it. (5 points) Note that

you need to use srand() to set the random seed first. I would use time (so the line would be

“srand(time(NULL));”) Use cout to print things out to the command line. (5 points) Use cin to read

in a line. (5 points)

Compare the input to the random number. (5 points) If the guess is correct, print out the number of

guesses (use a variable to keep track) and ask if they want to play again. (5 points) If so, restart the game. (5

points) (You can use y/n for the answer.)

Comments! (5 points)

At the top of your program, after your heading comment, put in the three rules for the C++ class. If you're not sure what the answer is, you should actually read the previous modules like you were supposed to. (5 points)

Total: 40 points