#include <iostream>
#include <cstring>
#include <ctype.h>
#include "data.h"

using namespace std;

const int X_MOVE = 1;
const int O_MOVE = 2;
const int BLANK = 0;

int board[9];
int X_SCORE = 0;
int O_SCORE = 0;

int turn = 0;

void initBoard();
void printBoard();

int main() {
  cout << "Welcome to TicTacToe!  In this game, your goal is to try to achieve a three-in-a-row sequence of your own pieces.  We'll start by picking who goes first!  If you'd like X to go first, please type \"1.\"  If you'd like O to go first, please type \"2.\"  >>  ";
  cin.sync();
  char c;
  cin >> c;
  cout << endl;
  while (c != '1' && c != '2') {
    cin.sync();
    cout << "Please enter either \"1\" or \"2\":  >>  ";
    cin >> c;
  }
  
  cout << endl;
  
  switch(c) {
  case '1':
    turn = 1;
    cout << "The first player will be X!" << endl;
    break;
  case '2':
    turn = 2;
    cout << "The first player will be O!" << endl;
    break;
  }

  initBoard();
  printBoard();

  return 0;
}

void initBoard() {
  for(int i = 0; i < 9; i++) {
    board[i] = BLANK;
  }
}

void printBoard() {
  cout << "  1 2 3" << endl;
  cout << "a " << board[0] << " " << board[1] << " " << board[2] << endl;
  cout << "b " << board[3] << " " << board[4] << " " << board[5] << endl;
  cout << "c " << board[6] << " " << board[7] << " " << board[8] << endl;
}
