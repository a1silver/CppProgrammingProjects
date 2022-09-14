#include <iostream>
#include <cstring>
#include <ctype.h>

using namespace std;

int main() {
  bool testing = true;

  cout << "This is a very simple palindrome tester! ";
  
  while (testing) {
    cout << "Please input up to 80 characters: ";
    char rawinput[81]; // allow for a null character to be written if the user inputs 80 characters!
    cin >> ws; // strip whitespace.
    cin.getline(rawinput, 80, '\n');

    char strippedinput[81];
    int isize = 0;
  
    for(int i = 0; i < 81; i++) {
      bool flag1 = isalpha(rawinput[i]);
      bool flag2 = rawinput[i] == '\0';
      if(flag1 || flag2) {
	strippedinput[isize] = rawinput[i];
	isize++;
      }
      if(flag2) {
	break;
      }
    }
    cout << isize << endl;
    char input[isize];
    char backwardsinput[isize];
  
    for(int i = 0; i < isize; i++) {
      input[i] = strippedinput[i];
    }
    for(int i = isize - 2, j = 0; i >= 0; i--, j++) {
      backwardsinput[j] = strippedinput[i];
    }
    backwardsinput[isize - 1] = '\0';

    for(int i = 0; i < strlen(input); i++) {
      cout << input[i];
    }
    cout << endl;
    for(int i = 0; i < strlen(backwardsinput); i++) {
      cout << backwardsinput[i];
    }
    cout << endl;

    int compareResult = strcmp(input, backwardsinput);

    if(compareResult == 0) {
      cout << "That phrase is a palindrome!" << endl;
    } else {
      cout << "That phrase is not a palindrome!" << endl;
    }

    cout << "Would you like to test another palindrome? (Y/N)" << endl;
    char ch;
    do {
      cin >> ch;
    } while (ch != 'Y' && ch != 'y' && ch != 'N' && ch != 'n');

    if(ch == 'N' || ch == 'n') {
      testing = false; // This will break out of the loop and terminate the application.
    }
  }
  
  return 0;
}
