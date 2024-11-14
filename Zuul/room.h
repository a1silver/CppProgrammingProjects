#ifndef ROOM_H
#define ROOM_H

#include "item.h"
#include <vector>
#include <map>

using namespace std;

class Room {
 public:
  vector<Item*> *requirements;
  vector<Item*> *items;
  map<char*, Room*> *exits;

  char *name; 
  char *description;
  
  Room(char* nameIn, char* descriptionIn);
  ~Room();

  void addRequirement(Item *itemIn);
  void addItem(Item *itemIn);
  void setExit(char *directionIn, Room *roomIn);
  char* getRoomListStr();
};

#endif // ROOM_H
