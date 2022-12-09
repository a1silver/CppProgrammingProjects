#include <cstring>
#include <iostream>
#include <map>
#include <vector>

#include "room.h"
#include "item.h"

using namespace std;

Room::Room() {
  requirements = new vector<Item*>();
  items = new vector<Item*>();
  exits = new map<char*, Room*>();
  name = new char[51];
  description = new char[251];
};

Room::~Room() {
  for(auto it = requirements->begin(); it < requirements->end(); it++) {
    delete *it;
  }
  delete requirements;
  for(auto it = items->begin(); it < items->end(); it++) {
    delete *it;
  }
  delete items;
  /*
  for (auto it = exits->begin(); it != exits->end(); it++) {
    delete it->first;
    delete it->second;
  }
  */
  map<char*, Room*>::iterator it = exits->begin(); // APPARENTLY THIS WORKS BUT A NORMAL FOR LOOP DOESN'T AAGHA
  while (it != exits->end()) {
    delete it->first;
    delete it->second;
  }
  delete exits;
}

void Room::setNnD(char nameIn[51], char descriptionIn[251]) {
  strcpy(name, nameIn);
  strcpy(description, descriptionIn);
}

void Room::addRequirement(Item* itemIn) {
  for(auto it = requirements->begin(); it < requirements->end(); it++) {
    if((*it)->equals(itemIn)) {
      return;
    }
  }
  requirements->push_back(itemIn);
  return;
}

void Room::addItem(Item* itemIn) {
  for(auto it = items->begin(); it < items->end(); it++) {
    if((*it)->equals(itemIn)) {
      return;
    }
  }
  items->push_back(itemIn);
  return;
}

void Room::setExit(char directionIn[6], Room* roomIn) {
  map<char*, Room*>::iterator it = exits->begin(); // APPARENTLY THIS WORKS BUT A NORMAL FOR LOOP DOESN'T AAGHA
  while (it != exits->end()) {
    if(strcmp(it->first, directionIn) == 0) {
      return;
    }
  }
  /*
  for(auto it = exits->begin(); it < exits->end(); it++) {
    if(strcmp(it.first, directionIn) == 0) {
      return;
    }
  }
  */
  exits->insert({directionIn, roomIn});
  return;
}
