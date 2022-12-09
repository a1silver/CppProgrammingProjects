#include <cstring>
#include "item.h"

bool Item::equals(Item* other) {
  return strcmp(name, other->name) == 0 && strcmp(description, other->description) == 0;
}
