#ifndef ITEM_H
#define ITEM_H

struct Item {
  char* name; // 15 and a null;
  char* description; // 100 and a null;
  bool equals(Item* other);
};

#endif // ITEM_H
