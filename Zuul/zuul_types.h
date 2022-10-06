#ifndef ZUUL_TYPES_H
#define ZUUL_TYPES_H

#include <cctype>

using namespace std;

struct ZuulItem {
  char* name;
  char* description;
  ZuulItem(char nameIn[51], char descriptionIn[101]);
  ~ZuulItem();
};

#endif // ZUUL_TYPES_H
