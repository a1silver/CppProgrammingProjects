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
