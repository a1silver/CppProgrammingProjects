/*
  This is not part of the TicTacToe assignment.  This is testing passing by reference vs passing by value.
 */
#include <iostream>
#include <cstring>
#include <ctype.h>

using namespace std;

float pow(float & a, int x);

int main() {
  float number = 6;
  int power = 4;
  int nonRefVal = pow(number, power);

  cout << "Passed by value: " << nonRefVal << endl;
  cout << "Passed by reference: " << number << endl;

  return 0;
}

float pow(float & a, int x) {
  float ans = a;
  for(int i = 0; i < x - 1; i++) {
    ans *= a;
  }
  a = ans;
  return ans;
}
