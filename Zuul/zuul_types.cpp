#include <cstring>
#include <cctype>
#include "zuul_types.h"

using namespace std;

ZuulItem::ZuulItem(char nameIn[51], char descriptionIn[101]) {
  name = new char[51];
  description = new char[101];

  char tempName[51];
  for(int i = 0; i < 51; i++) {
    if(nameIn[i] == ' ') {
      tempName[i] = '-';
    } else {
      tempName[i] = tolower(nameIn[i]);
    }
    
    if(nameIn[i] == '\0') {
      break;
    }
  }
  
  strcpy(name, tempName);
  strcpy(description, descriptionIn);
}

ZuulItem::~ZuulItem() {
  delete name;
  delete description;
}

ZuulPuzzle::ZuulPuzzle(char nameIn[51], char descriptionIn[101], char solutionIn[11], ZuulItem* itemIn) {
  name = new char[51];
  description = new char[101];
  solution = new char[11];
  reward = itemIn;
  
  strcpy(name, nameIn);
  strcpy(description, descriptionIn);

  char tempSolution[11];
  for(int i = 0; i < 11; i++) {
    if(solutionIn[i] == ' ') {
      tempSolution[i] = '-';
    }
    if(solutionIn[i] == '\0') {
      break;
    }
  }
  strcpy(solution, tempSolution);
}

ZuulPuzzle::~ZuulPuzzle() {
  delete name;
  delete solution;
  delete description;
  delete reward;
}
