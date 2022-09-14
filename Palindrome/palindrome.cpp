#include <iostream>
#include <cstring>

using namespace std;

int main() {
  cout << "This is a very simple palindrome tester!  Please input up to 80 characters:" << endl;
  char rawinput[80];
  cin >> ws;
  getline(cin, rawinput);
  cin.ignore(1, '\n');
  
  char input[80];
  strcpy(input, rawinput);
  puts(input);

  for(int i = 0; i < 80; ++i) {
    cout << input[i];
  }
  
  
  return 0;
}
