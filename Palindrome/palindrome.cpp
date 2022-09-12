#include <iostream>
#include <cstring>

using namespace std;

int main(int argc, char *argv[]) {
  cout << "Arg count: " << argc - 1 << endl; // subtract 1 to account for the filename
  
  if(argc == 1) { // Use cin to read input.
    
  } else { // Use the argv to read input.
    int len = strlen(argv[1]);
    char str[len];
    strcpy(str, "");
    strcat(str, argv[1]);

    // palindrome stuff
    
  }
}
