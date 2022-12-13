#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>

#include "item.h"
#include "room.h"

using namespace std;

char EXIT_NORTH[] = "NORTH";
char EXIT_SOUTH[] = "SOUTH";
char EXIT_EAST[] = "EAST";
char EXIT_WEST[] = "WEST";

const char DIR_NORTH_FULL[] = "North";
const char DIR_SOUTH_FULL[] = "South";
const char DIR_EAST_FULL[] = "East";
const char DIR_WEST_FULL[] = "West";
const char DIR_NORTH[] = "N";
const char DIR_SOUTH[] = "S";
const char DIR_NORTH_1[] = "N1";
const char DIR_NORTH_2[] = "N2";
const char DIR_SOUTH_1[] = "S1";
const char DIR_SOUTH_2[] = "S2";
const char DIR_EAST[] = "E";
const char DIR_EAST_1[] = "E1";
const char DIR_EAST_2[] = "E2";

// look, take, drop, move, inventory, help, quit
const char CMD_LOOK[] = "LOOK";
const char CMD_TAKE[] = "TAKE";
const char CMD_DROP[] = "DROP";
const char CMD_MOVE[] = "MOVE";
const char CMD_INVT[] = "INVT";
const char CMD_HELP[] = "HELP";
const char CMD_QUIT[] = "QUIT";
const char CMD_NULL[] = "NONE";

void printRoom(Room *currentRoom);
void look(Room *currentRoom);
void dropItem(Room *currentRoom, vector<Item *> *inventory, int idx);

int main()
{
  // Initializing items first

  // Flashlight
  char flashlightName[] = "FLASHLIGHT";
  char flashlightDescription[] = "This item is an imperative for finding other items!";
  Item *flashlight = new Item();
  strcpy(flashlight->name, flashlightName);
  strcpy(flashlight->description, flashlightDescription);

  // Screwdriver
  char screwdriverName[] = "SCREWDRIVER";
  char screwdriverDescription[] = "Electricians used this item to open maintenance vents.";
  Item *screwdriver = new Item();
  strcpy(screwdriver->name, screwdriverName);
  strcpy(screwdriver->description, screwdriverDescription);

  // Dungeon 1c Key
  char key1cName[] = "DUNGEON-1C-KEY";
  char key1cDescription[] = "This key grants access to the Dungeon 1C.";
  Item *dungeon1cKey = new Item();
  strcpy(dungeon1cKey->name, key1cName);
  strcpy(dungeon1cKey->description, key1cDescription);

  // Rope
  char ropeName[] = "ROPE";
  char ropeDescription[] = "Ropes could be useful to cross large spaces or scale up tall things like cliffs!";
  Item *rope = new Item();
  strcpy(rope->name, ropeName);
  strcpy(rope->description, ropeDescription);

  // Rope
  char lintName[] = "LINTBALL";
  char lintDescription[] = "Your ropes may be frayed, repair them by whipping them with some old lint!";
  Item *lint = new Item();
  strcpy(lint->name, lintName);
  strcpy(lint->description, lintDescription);

  // Hammer
  char hammerName[] = "HAMMER";
  char hammerDescription[] = "Used along with the screwdriver!  Commonly used by electricians.";
  Item *hammer = new Item();
  strcpy(hammer->name, hammerName);
  strcpy(hammer->description, hammerDescription);

  // Turret SE Key
  char turretSeKeyName[] = "TURRET-SE-KEY";
  char turretSeKeyDescription[] = "This key grants access to the Southeast Turret.";
  Item *turretSeKey = new Item();
  strcpy(turretSeKey->name, turretSeKeyName);
  strcpy(turretSeKey->description, turretSeKeyDescription);

  // Iron Bar
  char ironBarName[] = "IRONBAR";
  char ironBarDescription[] = "You may need to pry open a window with this!";
  Item *ironBar = new Item();
  strcpy(ironBar->name, ironBarName);
  strcpy(ironBar->description, ironBarDescription);

  // Turret NE Key
  char turretNeKeyName[] = "TURRET-NE-KEY";
  char turretNeKeyDescription[] = "This key grants access to the Northeast Turret.";
  Item *turretNeKey = new Item();
  strcpy(turretNeKey->name, turretNeKeyName);
  strcpy(turretNeKey->description, turretNeKeyDescription);

  // Mattress 1
  char mat1Name[] = "MATTRESS-1";
  char mat1Description[] = "Using a mattress could save your life in case you need to jump out of a window!";
  Item *mat1 = new Item();
  strcpy(mat1->name, mat1Name);
  strcpy(mat1->description, mat1Description);

  // Mattress 2
  char mat2Name[] = "MATTRESS-2";
  char mat2Description[] = "Using a mattress could save your life in case you need to jump out of a window!";
  Item *mat2 = new Item();
  strcpy(mat2->name, mat2Name);
  strcpy(mat2->description, mat2Description);

  // Initializing the rooms;
  Room *darkHallway = new Room();
  Room *dungeon1b = new Room();
  Room *dungeon1a = new Room();
  Room *dungeon1 = new Room();
  Room *dungeon1d = new Room();
  Room *dungeon1e = new Room();
  Room *dungeon1c = new Room();
  Room *oldAirway = new Room();
  Room *dungeon1f = new Room();
  Room *barredWindowN1 = new Room();
  Room *rockShelfW = new Room();
  Room *barredWindowS1 = new Room();
  Room *windowHallwayN = new Room();
  Room *rockShelfN = new Room();
  Room *chasm = new Room();
  Room *rockShelfS = new Room();
  Room *windowHallwayS = new Room();
  Room *barredWindowN2 = new Room();
  Room *rockShelfE = new Room();
  Room *barredWindowS2 = new Room();
  Room *turretNE = new Room();
  Room *windowHallwayE1 = new Room();
  Room *barredWindowE = new Room();
  Room *windowHallwayE2 = new Room();
  Room *turretSE = new Room();

  // Creating the rooms
  char darkHallwayName[] = "Dark Hallway";
  char darkHallwayDescription[] = "You emerge out of an awkward dream.  You ask yourself, \"Where am I?\"  As you slowly get your bearings, you notice you're in a disturbingly dark room.";
  darkHallway->setNnD(darkHallwayName, darkHallwayDescription);
  darkHallway->addItem(flashlight);
  darkHallway->setExit(EXIT_EAST, dungeon1);

  char dungeon1bName[] = "Dungeon 1B";
  char dungeon1bDescription[] = "You're in section 1B of the main dungeon.";
  dungeon1b->setNnD(dungeon1bName, dungeon1bDescription);
  dungeon1b->setExit(EXIT_EAST, dungeon1c);
  dungeon1b->setExit(EXIT_SOUTH, dungeon1a);

  char dungeon1aName[] = "Dungeon 1A";
  char dungeon1aDescription[] = "You're in section 1A of the main dungeon.";
  dungeon1a->setNnD(dungeon1aName, dungeon1aDescription);
  dungeon1a->addItem(screwdriver);
  dungeon1a->setExit(EXIT_NORTH, dungeon1b);
  dungeon1a->setExit(EXIT_SOUTH, dungeon1);

  char dungeon1Name[] = "Dungeon 1";
  char dungeon1Description[] = "You're in the main dungeon.";
  dungeon1->setNnD(dungeon1Name, dungeon1Description);
  dungeon1->setExit(EXIT_NORTH, dungeon1a);
  dungeon1->setExit(EXIT_SOUTH, dungeon1d);
  dungeon1->setExit(EXIT_EAST, oldAirway);
  dungeon1->setExit(EXIT_WEST, darkHallway);

  char dungeon1dName[] = "Dungeon 1D";
  char dungeon1dDescription[] = "You're in section 1D of the main dungeon.";
  dungeon1d->setNnD(dungeon1dName, dungeon1dDescription);
  dungeon1d->addItem(dungeon1cKey);
  dungeon1d->setExit(EXIT_NORTH, dungeon1);
  dungeon1d->setExit(EXIT_SOUTH, dungeon1e);

  char dungeon1eName[] = "Dungeon 1E";
  char dungeon1eDescription[] = "You're in section 1E of the main dungeon.";
  dungeon1e->setNnD(dungeon1eName, dungeon1eDescription);
  dungeon1e->setExit(EXIT_NORTH, dungeon1d);
  dungeon1e->setExit(EXIT_EAST, dungeon1f);

  char dungeon1cName[] = "Dungeon 1C";
  char dungeon1cDescription[] = "You're in section 1C of the main dungeon.";
  dungeon1c->setNnD(dungeon1cName, dungeon1cDescription);
  dungeon1c->addItem(rope);
  dungeon1c->addRequirement(dungeon1cKey);
  dungeon1c->setExit(EXIT_WEST, dungeon1b);

  char oldAirwayName[] = "Old Airway";
  char oldAirwayDescription[] = "You're in an old airway of the castle.  A great place for someone to hide.";
  oldAirway->setNnD(oldAirwayName, oldAirwayDescription);
  oldAirway->addItem(lint);
  oldAirway->addRequirement(screwdriver);
  oldAirway->addRequirement(hammer);
  oldAirway->setExit(EXIT_WEST, dungeon1);
  oldAirway->setExit(EXIT_EAST, rockShelfW);

  char dungeon1fName[] = "Dungeon 1F";
  char dungeon1fDescription[] = "You're in section 1F of the main dungeon.";
  dungeon1f->setNnD(dungeon1fName, dungeon1fDescription);
  dungeon1f->addItem(hammer);
  dungeon1f->setExit(EXIT_WEST, dungeon1e);

  for (int i = 0; i < 4; i++)
  {
    char direction[6];
    switch (i)
    {
    case 0:
      strcpy(direction, DIR_NORTH_FULL);
      break;
    case 1:
      strcpy(direction, DIR_SOUTH_FULL);
      break;
    case 2:
      strcpy(direction, DIR_EAST_FULL);
      break;
    case 3:
      strcpy(direction, DIR_WEST_FULL);
      break;
    }
    char namePrefix[] = "Rock Shelf ";
    char descriptionPrefix[] = "You're on Rock Shelf ";
    switch (i)
    {
    case 0:
      rockShelfN->setNnD(strcat(namePrefix, direction), strcat(descriptionPrefix, direction));
      rockShelfN->addItem(ironBar);
      rockShelfN->setExit(EXIT_NORTH, windowHallwayN);
      rockShelfN->setExit(EXIT_SOUTH, chasm);
      break;
    case 1:
      rockShelfS->setNnD(strcat(namePrefix, direction), strcat(descriptionPrefix, direction));
      rockShelfS->setExit(EXIT_NORTH, chasm);
      rockShelfS->setExit(EXIT_SOUTH, windowHallwayS);
      break;
    case 2:
      rockShelfE->setNnD(strcat(namePrefix, direction), strcat(descriptionPrefix, direction));
      rockShelfE->addItem(turretNeKey);
      rockShelfE->setExit(EXIT_EAST, barredWindowE);
      rockShelfE->setExit(EXIT_WEST, chasm);
      break;
    case 3:
      rockShelfW->setNnD(strcat(namePrefix, direction), strcat(descriptionPrefix, direction));
      rockShelfW->setExit(EXIT_EAST, chasm);
      rockShelfW->setExit(EXIT_WEST, oldAirway);
      break;
    }
  }

  char chasmName[] = "Chasm";
  char chasmDescription[] = "You're in the underground part of the castle and find an odd hole in the ground... could you possibly throw a rope to get across?";
  chasm->setNnD(chasmName, chasmDescription);
  chasm->addRequirement(rope);
  chasm->addRequirement(lint);
  chasm->setExit(EXIT_NORTH, rockShelfN);
  chasm->setExit(EXIT_SOUTH, rockShelfS);
  chasm->setExit(EXIT_EAST, rockShelfE);
  chasm->setExit(EXIT_WEST, rockShelfW);

  for (int i = 0; i < 5; i++)
  {
    char direction[5];
    switch (i)
    {
    case 0:
      strcpy(direction, DIR_NORTH_1);
      break;
    case 1:
      strcpy(direction, DIR_NORTH_2);
      break;
    case 2:
      strcpy(direction, DIR_SOUTH_1);
      break;
    case 3:
      strcpy(direction, DIR_SOUTH_2);
      break;
    case 4:
      strcpy(direction, DIR_EAST);
      break;
    }
    char namePrefix[] = "Barred Window ";
    char descriptionPrefix[] = "You've found yourself in the castle's Barred Window ";
    char descriptionSuffix[] = "...";
    char finalRoomDescription[] = "Congratulations, you successfully escaped the castle!  Thanks for playing.";
    switch (i)
    {
    case 0:
      barredWindowN1->setNnD(strcat(namePrefix, direction), strcat(strcat(descriptionPrefix, direction), descriptionSuffix));
      barredWindowN1->setExit(EXIT_EAST, windowHallwayN);
      break;
    case 1:
      barredWindowN2->setNnD(strcat(namePrefix, direction), strcat(strcat(descriptionPrefix, direction), descriptionSuffix));
      barredWindowN2->setExit(EXIT_WEST, windowHallwayN);
      barredWindowN2->setExit(EXIT_EAST, turretNE);
      break;
    case 2:
      barredWindowS1->setNnD(strcat(namePrefix, direction), strcat(strcat(descriptionPrefix, direction), descriptionSuffix));
      barredWindowS1->addItem(turretSeKey);
      barredWindowS1->setExit(EXIT_EAST, windowHallwayS);
      break;
    case 3:
      barredWindowS2->setNnD(strcat(namePrefix, direction), strcat(strcat(descriptionPrefix, direction), descriptionSuffix));
      barredWindowS2->setExit(EXIT_WEST, windowHallwayS);
      barredWindowS2->setExit(EXIT_EAST, turretSE);
      break;
    case 4:
      barredWindowE->setNnD(strcat(namePrefix, direction), finalRoomDescription);
      barredWindowE->addRequirement(ironBar);
      barredWindowE->addRequirement(mat1);
      barredWindowE->addRequirement(mat2);
      break;
    }
  }

  for (int i = 0; i < 4; i++)
  {
    char direction[5];
    switch (i)
    {
    case 0:
      strcpy(direction, DIR_NORTH);
      break;
    case 1:
      strcpy(direction, DIR_SOUTH);
      break;
    case 2:
      strcpy(direction, DIR_EAST_1);
      break;
    case 3:
      strcpy(direction, DIR_EAST_2);
      break;
    }
    char namePrefix[] = "Window Hallway ";
    char descriptionPrefix[] = "You're in the castle's window hallway ";
    char descriptionSuffix[] = ".";
    switch (i)
    {
    case 0:
      windowHallwayN->setNnD(strcat(namePrefix, direction), strcat(strcat(descriptionPrefix, direction), descriptionSuffix));
      windowHallwayN->setExit(EXIT_WEST, barredWindowN1);
      windowHallwayN->setExit(EXIT_EAST, barredWindowN2);
      windowHallwayN->setExit(EXIT_SOUTH, rockShelfN);
      break;
    case 1:
      windowHallwayS->setNnD(strcat(namePrefix, direction), strcat(strcat(descriptionPrefix, direction), descriptionSuffix));
      windowHallwayS->setExit(EXIT_WEST, barredWindowS1);
      windowHallwayS->setExit(EXIT_EAST, barredWindowS2);
      windowHallwayS->setExit(EXIT_NORTH, rockShelfS);
      break;
    case 2:
      windowHallwayE1->setNnD(strcat(namePrefix, direction), strcat(strcat(descriptionPrefix, direction), descriptionSuffix));
      windowHallwayE1->addItem(mat1);
      windowHallwayE1->setExit(EXIT_NORTH, turretNE);
      break;
    case 3:
      windowHallwayE2->setNnD(strcat(namePrefix, direction), strcat(strcat(descriptionPrefix, direction), descriptionSuffix));
      windowHallwayE2->addItem(mat2);
      windowHallwayE2->setExit(EXIT_SOUTH, turretSE);
      break;
    }
  }

  char turretNeName[] = "Northeast Turret";
  char turretNeDescription[] = "You're in the castle's Northeast Turret.";
  turretNE->setNnD(turretNeName, turretNeDescription);
  turretNE->addRequirement(turretNeKey);
  turretNE->setExit(EXIT_WEST, barredWindowN2);
  turretNE->setExit(EXIT_SOUTH, windowHallwayE1);

  char turretSeName[] = "Southeast Turret";
  char turretSeDescription[] = "You're in the castle's Southeast Turret.";
  turretSE->setNnD(turretSeName, turretSeDescription);
  turretSE->addRequirement(turretSeKey);
  turretSE->setExit(EXIT_WEST, barredWindowS2);
  turretSE->setExit(EXIT_NORTH, windowHallwayE2);

  // Initializing variables
  Room *currentRoom = darkHallway;
  vector<Item *> *inventory = new vector<Item *>();

  cout << "Welcome to Escape the Castle, the epic sequel to Escape the Hotel, a Java Adventure Game." << endl;
  cout << "If, at any point during the game you forget what commands to use, type \"HELP\" and you will be presented with the command list." << endl;
  cout << "The goal of this game is to escape the castle using items that you find around the map!  Good luck." << endl
       << endl;

  while (true)
  {
    printRoom(currentRoom);
    cout << "Enter your command > ";
    char cmd1[101];
    cin >> cmd1;
    char cmd2[101];

    if (strcmp(cmd1, CMD_LOOK) == 0)
    {
      if (strcmp(currentRoom->name, darkHallwayName) == 0)
      {
        if (find(inventory->begin(), inventory->end(), flashlight) != inventory->end())
        {
          cout << "There are " << currentRoom->exits->size() << " ways to exit this room: " << endl;
          map<char *, Room *>::iterator it = currentRoom->exits->begin(); // APPARENTLY THIS WORKS BUT A NORMAL FOR LOOP DOESN'T AAGHA
          for (auto it = currentRoom->exits->begin(); it != currentRoom->exits->end(); it++)
          {
            cout << "   " << it->first;
          }
          cout << endl;
          if (currentRoom->items->size() > 0)
          {
            cout << "I also found an item called \"" << currentRoom->items->at(0)->name << "\"..." << endl;
          }
        }
        else
        {
          cout << "It's pretty hard to see, but I think I spotted a FLASHLIGHT in the corner!  Be careful, it might be covered in cobwebs." << endl;
        }
      }
      else
      {
        if (find(inventory->begin(), inventory->end(), flashlight) != inventory->end())
        {
          cout << "There are " << currentRoom->exits->size() << " ways to exit this room: " << endl;
          map<char *, Room *>::iterator it = currentRoom->exits->begin(); // APPARENTLY THIS WORKS BUT A NORMAL FOR LOOP DOESN'T AAGHA
          for (auto it = currentRoom->exits->begin(); it != currentRoom->exits->end(); it++)
          {
            cout << "   " << it->first;
          }
          cout << endl;
          if (currentRoom->items->size() > 0)
          {
            cout << "I also found an item called \"" << currentRoom->items->at(0)->name << "\"..." << endl;
          }
        }
        else
        {
          cout << "It's too dark in here, I can't see!  A little bit of light might help.  I remember seeing a faint glimmer in that weird dark hallway I magically appeared in..." << endl;
        }
      }
    }
    if (strcmp(cmd1, CMD_TAKE) == 0)
    {
      cout << "Enter your command parameter > ";
      cin >> cmd2;
      cout << endl;

      int idx = 0;
      vector<Item *>::iterator it;
      bool found = false;
      for (it = currentRoom->items->begin(); it < currentRoom->items->end(); it++)
      {
        if (strcmp((*it)->name, cmd2) == 0)
        {
          inventory->push_back(currentRoom->items->at(idx));
          currentRoom->items->erase(currentRoom->items->begin() + idx);
          cout << "You picked up the \"" << cmd2 << "\" that was in the room." << endl;
          cout << "Type \"INVT\" to view your inventory at any time." << endl;
          found = true;
          break;
        }
        idx++;
      }
      if (!found)
      {
        cout << "I couldn't find that item anywhere..." << endl;
      }
    }
    if (strcmp(cmd1, CMD_DROP) == 0)
    {
      cout << "Enter your command parameter > ";
      cin >> cmd2;
      cout << endl;

      int idx = 0;
      vector<Item *>::iterator it;
      for (it = inventory->begin(); it < inventory->end(); it++)
      {
        if (strcmp((*it)->name, cmd2) == 0)
        {
          currentRoom->items->push_back(inventory->at(idx));
          inventory->erase(inventory->begin() + idx);
          cout << "You dropped the \"" << cmd2 << "\" into the room." << endl;
          cout << "Type \"INVT\" to view your inventory at any time." << endl;
        }
        idx++;
      }
    }
    if (strcmp(cmd1, CMD_MOVE) == 0)
    {
      cout << "Enter your command parameter > ";
      cin >> cmd2;
      cout << endl;

      bool found = false;
      map<char *, Room *>::iterator it = currentRoom->exits->begin(); // APPARENTLY THIS WORKS BUT A NORMAL FOR LOOP DOESN'T AAGHA
      for (auto it = currentRoom->exits->begin(); it != currentRoom->exits->end(); it++)
      {
        if (strcmp(it->first, cmd2) == 0)
        {
          bool missing = false;
          found = true;
          vector<Item *>::iterator it1;
          for (it1 = it->second->requirements->begin(); it1 < it->second->requirements->end(); it1++)
          {
            if (find(inventory->begin(), inventory->end(), *it1) == inventory->end())
            {
              // Player does not have requirement
              cout << "You need a " << (*it1)->name << " to enter that room!" << endl;
              missing = true;
              break;
            }
          }
          if (missing)
          {
            continue;
          }
          currentRoom = it->second;
          if (strcmp(currentRoom->name, barredWindowE->name) == 0)
          {
            cout << currentRoom->description << endl;
            return 0;
          }
          else
          {
            cout << "You moved " << cmd2 << " to the " << currentRoom->name << "." << endl;
            break;
          }
        }
      }
      if (!found)
      {
        cout << "There isn't an exit there!" << endl;
      }
    }
    if (strcmp(cmd1, CMD_INVT) == 0)
    {
      cout << "Enter your command parameter > ";
      cin >> cmd2;
      cout << endl;

      if (strcmp(cmd2, CMD_NULL) == 0)
      {
        vector<Item *>::iterator it;
        cout << "Your Items:" << endl;
        for (it = inventory->begin(); it < inventory->end(); it++)
        {
          cout << "   " << (*it)->name;
        }
        cout << endl;
      }
      else
      {
        bool found = false;
        vector<Item *>::iterator it;
        for (it = inventory->begin(); it < inventory->end(); it++)
        {
          if (strcmp((*it)->name, cmd2) == 0)
          {
            cout << (*it)->name << endl;
            cout << "   " << (*it)->description << endl;
            found = true;
            break;
          }
        }
        if (!found)
        {
          cout << "You don't have that item in your inventory!" << endl;
        }
      }
    }
    if (strcmp(cmd1, CMD_HELP) == 0)
    {
      cout << endl;
      cout << "Escape the Castle - Help" << endl;
      cout << "Square bracket arguments [] are required; angle bracket arguments <> are optional." << endl;
      cout << "To leave an optional argument blank, simply type \"NONE\"." << endl
           << endl;
      cout << "LOOK                 Look around the room for exits and items.  You need the flashlight item to run this command.  This item is found at the very start of the game." << endl;
      cout << "TAKE [item_name]     Take items from the room.  Your inventory has unlimited space." << endl;
      cout << "DROP [item_name]     Drop items from your inventory into the current room that you're in.  You can't drop items into a room if said item is that room's requirement." << endl;
      cout << "MOVE [direction]     Move from room to room.  Some rooms may require that you have a certain item in your inventory in order to enter." << endl;
      cout << "INVT <item_name>     View all of the items that you have, or view a specific item and it's description." << endl;
      cout << "HELP                 View this message." << endl;
      cout << "QUIT                 Exit the game at any time." << endl;
    }
    if (strcmp(cmd1, CMD_QUIT) == 0)
    {
      cout << "Thanks for playing!" << endl;
      return 0;
    }
    cout << endl;

    /*
    char cmd[55];
    cin.getline(cmd, 54, '\n');
    char cmd1[5];
    char cmd2[51];
    std::vector<char*> v;
    int count = 0;
    char* chars_array = strtok(cmd, " ");
    while (chars_array) {
      if(count > 0) {
        strcpy(cmd2, strcat(cmd2, chars_array));
      } else {
        strcpy(cmd1, chars_array);
      }
      chars_array = strtok(NULL, " ");
      // std::cout << chars_array << endl;
      count++;
    }
    if(strlen(cmd1) > 4) {
      cout << "\"" << cmd1 << "\" is not a valid command!" << endl;
      continue;
    }
    cout << "Command 1: " << cmd1 << endl;
    cout << "Command 2: " << cmd2 << endl;
    */
  }

  return 0;
}

void printRoom(Room *currentRoom)
{
  cout << "Current Room: " << currentRoom->name << endl;
  cout << currentRoom->description << endl;
  cout << "What would you like to do?  Type \"HELP\" for you available commands." << endl;
}

void look(Room *currentRoom, vector<Item *> *inventory)
{
}

void dropItem(Room *currentRoom, vector<Item *> *inventory, int idx)
{
}
