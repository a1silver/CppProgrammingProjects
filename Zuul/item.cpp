#include <cstring>
#include "item.h"

Item::Item() {
  // Initialize fields. lol.
  name = new char[16];
  description = new char[101];
}

Item::~Item() {
  // Make sure to delete any fields that are pointers.
  delete name;
  delete description;
}

bool Item::equals(Item* other) {
  // Never used?
  return strcmp(name, other->name) == 0 && strcmp(description, other->description) == 0;
}
