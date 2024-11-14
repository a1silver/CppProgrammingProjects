#ifndef ITEM_H
#define ITEM_H

class Item {
  public:
   char *name;
   char *description;
   Item(char *nameIn, char *descriptionIn);
   ~Item();
   bool equals(Item* other);
};

#endif // ITEM_H
