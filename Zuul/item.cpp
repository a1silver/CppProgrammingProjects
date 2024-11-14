#include <cstring>
#include "item.h"

Item::Item(char *nameIn, char *descriptionIn) {
  // Initialize fields. lol.
  this->name = new char[257]; // 256 characters + null
  this->description = new char[257]; // 256 characters + null

  strncpy(name, nameIn, 256);
  name[256] = '\0'; // Ensure null termination
  strncpy(description, descriptionIn, 256);
  description[256] = '\0'; // Ensure null termination
}

Item::~Item() {
  // Make sure to delete any fields that are pointers.
  delete this->name;
  delete this->description;
}

bool Item::equals(Item* other) {
  // Never used?
  return strcmp(this->name, other->name) == 0 && strcmp(this->description, other->description) == 0;
}
