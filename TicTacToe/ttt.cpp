#include <iostream>
#include <cstring>
#include <ctype.h>

using namespace std;

// Move IDs
const int X_MOVE = 1;
const int O_MOVE = 2;
const int BLANK = 0;

// Method prototypes
void initBoard(int board[3][3]);
char getBoardChar(int move);
void printBoard(int board[3][3]);
void runTurn(int board[3][3], int player);
bool testWins(int board[3][3], int player);

int main() {
  // Scoring and board
  int board[3][3];
  int X_SCORE = 0;
  int O_SCORE = 0;
  int turn = 0;
  
  bool playing = true;
  cout << "Welcome to TicTacToe!  In this game, your goal is to try to achieve a three-in-a-row sequence of your own pieces.  We'll start by picking who goes first!  ";
  while (playing) {
    cout << "If you'd like X to go first, please type \"1.\"  If you'd like O to go first, please type \"2.\"  >>  ";
    cin.sync();
    char c;
    cin >> c;
    cout << endl;
    while (c != '1' && c != '2') {
      cin.sync();
      cout << "Please enter either \"1\" or \"2\":  >>  ";
      cin >> c;
    }
    
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
    
    cout << endl;
  
    initBoard(board);
    printBoard(board);
  
    while (true) {
      runTurn(board, turn);
      printBoard(board);
      if(testWins(board, turn)) {
        switch(turn) {
          case X_MOVE:
            X_SCORE++;
            cout << "Player X won this round! ";
            break;
          case O_MOVE:
            O_SCORE++;
            cout << "Player O won this round! ";
            break;
          default:
            break;
        }
        cout << "Player X has " << X_SCORE << " points and Player O has " << O_SCORE << " points." << endl;
        break;
      }
      // Swap Turns
      switch(turn) {
        case X_MOVE:
          turn = O_MOVE;
          break;
        case O_MOVE:
          turn = X_MOVE;
          break;
      }

      bool isBoardFull = true;
      for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
          if(board[i][j] == BLANK) {
            isBoardFull = false;
          }
        }
      }
      if(isBoardFull) {
        cout << "The game ended in a tie!" << endl;
        cout << "Player X has " << X_SCORE << " points and Player O has " << O_SCORE << " points." << endl;
        break;
      }
    }
    
    cout << "Would you like to play another game? (Y/N)" << endl;
    char ch;
    do {
      cin >> ch;
    } while (ch != 'Y' && ch != 'y' && ch != 'N' && ch != 'n');

    if(ch == 'N' || ch == 'n') {
      cout << "Thanks for playing!  The final score is below:" << endl;
      cout << "X: " << X_SCORE << "   O: " << O_SCORE << endl;
      playing = false;
    } else {
      cout << "Starting new game..." << endl;
      initBoard(board);
      turn = 0;
    }
  }

  return 0;
}

// Clears the board
void initBoard(int board[3][3]) {
  for(int i = 0; i < 3; i++) {
    for(int j = 0; j < 3; j++) {
      board[i][j] = BLANK;
    }
  }
}

// Get board cell character
char getBoardChar(int move) {
  switch(move) {
    case 0: // blank
      return ' ';
    case 1: // x move
      return 'X';
    case 2: // o move
      return 'O';
    default: // just in case
      return ' ';
  }
  return ' '; // also just in case
} 

// Print the board to the console
void printBoard(int board[3][3]) {
  cout << "Current Board: " << endl << "---------" << endl;
  cout << "  1 2 3" << endl;
  cout << "a " << getBoardChar(board[0][0]) << " " << getBoardChar(board[0][1]) << " " << getBoardChar(board[0][2]) << endl;
  cout << "b " << getBoardChar(board[1][0]) << " " << getBoardChar(board[1][1]) << " " << getBoardChar(board[1][2]) << endl;
  cout << "c " << getBoardChar(board[2][0]) << " " << getBoardChar(board[2][1]) << " " << getBoardChar(board[2][2]) << endl;
  cout << "" << endl;
}

// Run a turn.
void runTurn(int board[3][3], int turn) {
  bool isTaken = true; // retry the turn until a blank spot is chosen
  
  while(isTaken) {
    switch(turn) {
      case X_MOVE:
        cout << "Player X, please input the ROW (a, b, or c) of your chosen move: ";
        break;
      case O_MOVE:
        cout << "Player O, please input the ROW (a, b, or c) of your chosen move: ";
        break;
    }

    // ====> 
    cin.sync();
    char row;
    cin >> row;
    cout << endl;
    row = tolower(row);
    while (row != 'a' && row != 'b' && row != 'c') {
      cin.sync();
      cout << "\"" << row << "\" is not a valid row!  Please try again: ";
      cin >> row;
    }
    cout << endl;
    
    switch(turn) {
      case X_MOVE:
        cout << "Player X, please input the COLUMN (1, 2, or 3) of your chosen move: ";
        break;
      case O_MOVE:
        cout << "Player O, please input the COLUMN (1, 2, or 3) of your chosen move: ";
        break;
    }
  
    cin.sync(); // sync somehow fixes some issues with getting an int...
    int col;
    cin >> col;
    cout << col << endl;
    
    while (col != 1 && col != 2 && col != 3) {
      cin.sync();
      cin.ignore(1, '\n');
      cout << "\"" << col << "\" is not a valid column!  Please try again: ";
      cin >> col;
      cout << col << endl;
    }

    // The following code calculates the array pos for a given coordinate pair:
    int posX;
    int posY = col - 1;
    
    switch(row) {
      case 'a':
        posX = 0;
        break;
      case 'b':
        posX = 1;
        break;
      case 'c':
        posX = 2;
        break;
    }

    cout << "You are placing your piece in board position: " << posX << ", " << posY << endl;

    isTaken = board[posX][posY] != BLANK;

    if(isTaken) {
      cout << "That position is taken!" << endl;
    } else{
      board[posX][posY] = turn;
    }
    
  }
  
}

// Test wins for a player
bool testWins(int board[3][3], int player) {
  if(board[0][0] == player && board[0][1] == player && board[0][2] == player) { // top horizontal
    return true;
  }
  if(board[1][0] == player && board[1][1] == player && board[1][2] == player) { // center horizontal
    return true;
  }
  if(board[2][0] == player && board[2][1] == player && board[2][2] == player) { // bottom horizontal
    return true;
  }

  if(board[0][0] == player && board[1][0] == player && board[2][0] == player) { // left vertical
    return true;
  }
  if(board[0][1] == player && board[1][1] == player && board[2][1] == player) { // center vertical
    return true;
  }
  if(board[0][2] == player && board[1][2] == player && board[2][2] == player) { // right vertical
    return true;
  }

  if(board[0][0] == player && board[1][1] == player && board[2][2] == player) { // left->right diagonal
    return true;
  }
  if(board[0][2] == player && board[1][1] == player && board[2][0] == player) { // right->left diagonal
    return true;
  }
  return false;
}
