#include <cstring>
#include <iostream>
#include <map>
#include <vector>

#include "room.h"
#include "item.h"

using namespace std;

Room::Room(char *nameIn, char *descriptionIn)
{
  // Initialize fields!  Don't want those segmentation faults.
  requirements = new vector<Item *>();
  items = new vector<Item *>();
  exits = new map<char *, Room *>();
  name = nameIn;
  description = descriptionIn;
};

Room::~Room()
{
  // The room destructor is the worst
  for (auto it = requirements->begin(); it < requirements->end(); it++)
  {
    delete *it;
  }
  delete requirements;
  for (auto it = items->begin(); it < items->end(); it++)
  {
    delete *it;
  }
  delete items;
  map<char *, Room *>::iterator it = exits->begin(); // APPARENTLY THIS WORKS BUT A NORMAL FOR LOOP DOESN'T AAGHA
  for (auto it = exits->begin(); it != exits->end(); it++)
  {
    delete it->first;
    delete it->second;
  }
  delete exits;
  delete name;
  delete description;
}

void Room::addRequirement(Item *itemIn)
{
  // Add an item to a room that the user must have before entering
  for (auto it = requirements->begin(); it < requirements->end(); it++)
  {
    if ((*it)->equals(itemIn))
    {
      return;
    }
  }
  requirements->push_back(itemIn);
  return;
}

void Room::addItem(Item *itemIn)
{
  // Places an item in the room that can be picked up
  for (auto it = items->begin(); it < items->end(); it++)
  {
    if ((*it)->equals(itemIn))
    {
      return;
    }
  }
  items->push_back(itemIn);
  return;
}

void Room::setExit(char *directionIn, Room *roomIn)
{
  // Add an exit to the room
  if (exits->size() == 0)
  {
    exits->insert({directionIn, roomIn});
    return;
  }
  map<char *, Room *>::iterator it = exits->begin(); // APPARENTLY THIS WORKS BUT A NORMAL FOR LOOP DOESN'T AAGHA
  while (it != exits->end())
  {
    if (strcmp(it->first, directionIn) == 0)
    {
      return;
    }
    else
    {
      exits->insert({directionIn, roomIn});
      return;
    }
  }
}
