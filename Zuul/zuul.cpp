#include <iostream>
#include "zuul_types.h"

using namespace std;

int main() {
  char name[] = "Test ITEM";
  char description[] = "This is a test item!";
  ZuulItem* item = new ZuulItem(name, description);
  cout << item->name << " " << item->description << endl;
  char name1[] = "Test Room";
  char description1[] = "Test Room Description";
  char solution[] = "123456";
  ZuulPuzzle* room = new ZuulPuzzle(name1, description1, solution, item);
  cout << room->name << " " << room->description << " " << room->solution << " " << room->reward->name << " " << room->reward->description << endl;
  return 0;
}
