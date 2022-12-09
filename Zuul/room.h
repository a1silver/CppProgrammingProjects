#ifndef ROOM_H
#define ROOM_H

#include "item.h"
#include <vector>
#include <map>

class Room {
 public:
  std::vector<Item*>* requirements;
  std::vector<Item*>* items;
  std::map<char*, Room*>* exits;

  char* name; // 50 and a null
  char* description; // 250 and a null
  
  Room();
  ~Room();

  void setNnD(char* nameIn, char* descriptionIn);
  void addRequirement(Item* itemIn);
  void addItem(Item* itemIn);
  void setExit(char directionIn[6], Room* roomIn);
};

#endif // ROOM_H
