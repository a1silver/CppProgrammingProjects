#include <algorithm>
#include "room.h"
#include "zuul_types.h"

ZuulRoom::ZuulRoom(char descriptionIn[101], ZuulItem *requirementIn = NULL) {
  strcpy(description, descriptionIn);
  requirement = requirementIn;
}

ZuulRoom::~ZuulRoom() {
  delete description;
  delete requirement;
  delete puzzle;
  for(Exits::iterator it = exits->begin(); it < exits->end(); it++) {
    delete *it;
  }
  delete exits;
  for(Items::iterator it = items->begin(); it < items->end(); it++) {
    delete *it;
  }
  delete items;
}

void ZuulRoom::addExit(char directionIn[11], ZuulRoom *neighborIn) {
  exits.insert({directionIn, neighborIn});
}

void ZuulRoom::addItem(ZuulItem *itemIn) {
  items.push_back(itemIn);
}

void ZuulRoom::setRequirement(ZuulItem *requirementIn) {
  requirement = requirementIn;
}

void ZuulRoom::setPuzzle(ZuulPuzzle *puzzleIn) {
  puzzle = puzzleIn;
}

ZuulItem* ZuulRoom::getItemAt(int indexIn) {
  try {
    return items->at(idx);
  } catch (const out_of_range & ex) {
    return NULL;
  }
}

ZuulItem* ZuulRoom::getItemByName(char nameIn[51]) {
  Items::iterator it = find(items->begin(), items->end(), nameIn);

  if(it != items->cend()) {
    int idx = distance(items->begin(), it);
    try {
      return items->at(idx);
    } catch (const out_of_range & ex) {
      return NULL;
    }
  } else {
    return NULL;
  }
}

void ZuulRoom::removeItemAt(int indexIn) {
  try {
    delete items->at(indexIn);
    items->erase(items->begin() + indexIn);
  } catch (const out_of_range & ex) {
    return;
  }
}

void ZuulRoom::printExitString() {
  cout << "Exits:";
  for(Exits::iterator it = exits->begin(); it < exits->end(); it++) {
    cout << " " << it->first;
  }
  cout << endl;
}

void ZuulRoom::printFullDescription() {
  cout << "You are " << description << "." << endl;
  printExitString();
}

ZuulRoom* ZuulRoom::getExit(char directionIn[11]) {
  
}
