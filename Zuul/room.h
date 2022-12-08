#ifndef ROOM_H
#define ROOM_H

#include "item.h"
#include <vector>
#include <map>

class Room {
 public:
  std::vector<Item*>* requirements;
  std::vector<Item*>* items;
  std::map<char*, Item*>* exits;

  char name[51]; // 50 and a null
  char description[101]; // 100 and a null
  
  Room();
  ~Room();
};

#endif // ROOM_H
