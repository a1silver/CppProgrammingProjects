#ifndef ITEM_H
#define ITEM_H

class Item {
  public:
   char* name; // 15 and a null;
   char* description; // 100 and a null;
   Item();
   ~Item();
   bool equals(Item* other);
};

#endif // ITEM_H
