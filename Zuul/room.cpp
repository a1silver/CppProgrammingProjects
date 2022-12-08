#include <iostream>
#include <vector>
#include <map>

#include "room.h"
#include "item.h"

using namespace std;

Room::Room() {
  
};

Room::~Room() {
  for(vector<Item*>::iterator it = requirements->begin(); it < requirements->end(); it++) {
    delete *it;
  }
  delete requirements;
  for(vector<Item*>::iterator it = items->begin(); it < items->end(); it++) {
    delete *it;
  }
  delete items;
  for (auto entry : exits) {
    char* k = entry.first;
    Item* v = entry.second;
    delete k;
    delete v;
  }
  delete exits;
}
