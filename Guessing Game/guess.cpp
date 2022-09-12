/*
This is a very simple guessing game.  The program generates a random number and you, the user, has to try to guess it in as little tries as possible.

Author: Morgan Hinz
Creation Date: 8 September 2022

Made for Mr. Galbraith's C++ class.

Rules of C++ for Mr. Galbraith:
  1. No global variables.
  2. Strings are NEVER allowed.  Cstrings and character arrays are fine.
  3. Include <iostream> and not stdio.
  4. Avoid using a mouse when possible.
 */

#include <iostream> // required to print to the console.

using namespace std; // standard library

/*
  The main function of the program.
 */
int main() {
  srand(time(NULL)); // Sets the random seed.

  bool playing = true;

  while(playing) {
    int randomNumber = rand() % 100 + 1; // Sets the number that the user has to guess.

    int guesses = 0; // Keeps track of the guesses made.

    cout << "Type a number: ";
    int guess; // Allocates an int for the user's guess. (changes over time)
    cin >> guess; // Read user input
    cout << endl;

    do { // Keep guessing until the guessed number is equal to the random chosen number.
      cin.ignore(1, '\n'); // Ignores the newline character
      ++guesses; // Increase guesses
      if (guess > randomNumber) {
	cout << "Your guess is greater than my number! (Guesses: " << guesses << ") Guess again." << endl;
	cin >> guess;
      } else if (guess < randomNumber) {
	cout << "Your guess is less than my number! (Guesses: " << guesses << ") Guess again." << endl;
	cin >> guess;
      }
    } while (guess != randomNumber);

    ++guesses;
  
    cout << "You guessed my number correctly!  It was " << randomNumber << ".  You guessed my number in " << guesses << " guesses." << endl;
    cout << "Would you like to play again? (Y/N)" << endl;
    char ch;
    do {
      cin >> ch;
    } while (ch != 'Y' && ch != 'y' && ch != 'N' && ch != 'n');

    if(ch == 'N' || ch == 'n') {
      playing = false;
    }
  
  }
  
  return 0;
}
