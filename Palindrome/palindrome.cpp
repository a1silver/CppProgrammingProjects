/*
  This program tests phrases to see if they are palindromes.
  The program asks you to input max. 80 characters.  Everything except for null chars and letters will be stripped.

  Author: Morgan Hinz
  Creation Date: 14 September 2022

  Made for Mr. Galbraith's C++ class.
 */
#include <iostream>
#include <cstring>
#include <ctype.h>

using namespace std;

int main() {
  bool testing = true; // we are still checking palindromes
  
  cout << "This is a very simple palindrome tester! ";
  
  while (testing) { // keep testing for a palindrome
    cout << "Please input up to 80 characters: ";
    char rawinput[81]; // allow for a null character to be written if the user inputs 80 characters!
    
    cin.getline(rawinput, 80, '\n'); // get 80 characters

    char strippedinput[81]; // prepare for formatting the input
    int isize = 0; // actual input size when ignoring everything but '\0' and alpha characters.
  
    for(int i = 0; i < 81; i++) {
      bool flag1 = isalpha(rawinput[i]); // is the character an alpha character
      bool flag2 = rawinput[i] == '\0'; // does the character terminate the string
      if(flag1 || flag2) {
	strippedinput[isize] = tolower(rawinput[i]); // insert the lowercase letter into the formatted array
	isize++;
      }
      if(flag2) {
	break; // if the character was a null character we don't need to continue
      }
    }
    
    char input[isize]; // regular input
    char backwardsinput[isize]; // reversed input
  
    for(int i = 0; i < isize; i++) {
      input[i] = strippedinput[i]; // kinda redundant...
    }
    for(int i = isize - 2, j = 0; i >= 0; i--, j++) { // this for loop reverses all of the characters
      backwardsinput[j] = strippedinput[i];
    }
    backwardsinput[isize - 1] = '\0'; // instead of inserting the null char at the beginning, we have to do it at the end.

    int compareResult = strcmp(input, backwardsinput); // when this == 0, the phrase is a palindrome

    if(compareResult == 0) {
      cout << "That phrase is a palindrome!" << endl;
    } else {
      cout << "That phrase is not a palindrome!" << endl;
    }

    cout << "Would you like to test another palindrome? (Y/N)" << endl;
    char ch;
    do {
      cin >> ch;
    } while (ch != 'Y' && ch != 'y' && ch != 'N' && ch != 'n'); // do-while is required here so that the application doesn't immediately terminate because "ch" contains a random bit of memory. :(

    if(ch == 'N' || ch == 'n') {
      testing = false; // This will break out of the loop and terminate the application.
    }
  }
  
  return 0;
}
