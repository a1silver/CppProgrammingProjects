#include <cstring>
#include "item.h"

Item::Item() {
  name = new char[16];
  description = new char[101];
}

Item::~Item() {
  delete name;
  delete description;
}

bool Item::equals(Item* other) {
  return strcmp(name, other->name) == 0 && strcmp(description, other->description) == 0;
}
