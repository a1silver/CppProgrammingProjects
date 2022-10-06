#include <iostream>
#include "zuul_types.h"

using namespace std;

int main() {
  char name[] = "Test ITEM";
  char description[] = "This is a test item!";
  ZuulItem* item = new ZuulItem(name, description);
  cout << item->name << " " << item->description << endl;
  delete item;
  cout << &name << " " << &description << endl;
  return 0;
}
