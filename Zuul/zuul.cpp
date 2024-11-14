#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>

#include "item.h"
#include "room.h"

using namespace std;

// Exit directions
char EXIT_NORTH[] = "NORTH";
char EXIT_SOUTH[] = "SOUTH";
char EXIT_EAST[] = "EAST";
char EXIT_WEST[] = "WEST";

// look, take, drop, move, inventory, help, quit
const char CMD_LOOK[] = "LOOK";
const char CMD_TAKE[] = "TAKE";
const char CMD_GET[] = "GET";
const char CMD_DROP[] = "DROP";
const char CMD_MOVE[] = "MOVE";
const char CMD_GO[] = "GO";
const char CMD_INVT[] = "INVT";
const char CMD_HELP[] = "HELP";
const char CMD_QUIT[] = "QUIT";
const char CMD_EXIT[] = "EXIT";

// Method prototypes
void printRoom(Room *currentRoom);

int main()
{
  // Initializing items first
  // This is so much damn fun.
  // Galbraith if you're reading this please please please for the love of god let us use strings :(

  Item *flashlight = new Item((char*)"FLASHLIGHT", (char*)"A flashlight is needed to search the dark rooms.");
  Item *screwdriver = new Item((char*)"SCREWDRIVER", (char*)"Electricians used this item to open maintenance vents.");
  Item *dungeon1cKey = new Item((char*)"DUNGEON-1C-KEY", (char*)"This key grants access to the Dungeon 1C.");
  Item *rope = new Item((char*)"ROPE", (char*)"Ropes could be useful to cross large spaces or scale up tall things like cliffs!");
  Item *lint = new Item((char*)"LINTBALL", (char*)"Your ropes may be frayed, repair them by whipping them with some old lint!");
  Item *hammer = new Item((char*)"HAMMER", (char*)"Used along with the screwdriver!  Commonly used by electricians.");
  Item *turretSeKey = new Item((char*)"TURRET-SE-KEY", (char*)"This key grants access to the Southeast Turret.");
  Item *ironBar = new Item((char*)"IRONBAR", (char*)"You may need to pry open a window with this!");
  Item *turretNeKey = new Item((char*)"TURRET-NE-KEY", (char*)"This key grants access to the Northeast Turret.");
  Item *mat1 = new Item((char*)"MATTRESS-1", (char*)"Using a mattress could save your life in case you need to jump out of a window!");
  Item *mat2 = new Item((char*)"MATTRESS-2", (char*)"Using a mattress could save your life in case you need to jump out of a window!");

  // Initializing the rooms
  Room *darkHallway = new Room((char*)"Dark Hallway", (char*)"You emerge out of an awkward dream.  You ask yourself, \"Where am I?\"  As you slowly get your bearings, you notice you're in a disturbingly dark room.");
  Room *dungeon1b = new Room((char*)"Dungeon 1B", (char*)"You're in section 1B of the main dungeon.");
  Room *dungeon1a = new Room((char*)"Dungeon 1A", (char*)"You're in section 1A of the main dungeon.");
  Room *dungeon1 = new Room((char*)"Dungeon 1", (char*)"You're in the main dungeon.");
  Room *dungeon1d = new Room((char*)"Dungeon 1D", (char*)"You're in section 1D of the main dungeon.");
  Room *dungeon1e = new Room((char*)"Dungeon 1E", (char*)"You're in section 1E of the main dungeon.");
  Room *dungeon1c = new Room((char*)"Dungeon 1C", (char*)"You're in section 1C of the main dungeon.");
  Room *oldAirway = new Room((char*)"Old Airway", (char*)"You're in an old airway of the castle.  A great place for someone to hide.");
  Room *dungeon1f = new Room((char*)"Dungeon 1F", (char*)"You're in section 1F of the main dungeon.");
  Room *chasm = new Room((char*)"Chasm", (char*)"You're in the underground part of the castle and find an odd hole in the ground... could you possibly throw a rope to get across?");

  Room *rockShelfN = new Room((char*)"Rock Shelf North", (char*)"You're on Rock Shelf North");
  Room *rockShelfS = new Room((char*)"Rock Shelf South", (char*)"You're on Rock Shelf South");
  Room *rockShelfE = new Room((char*)"Rock Shelf East", (char*)"You're on Rock Shelf East");
  Room *rockShelfW = new Room((char*)"Rock Shelf West", (char*)"You're on Rock Shelf West");

  Room *barredWindowN1 = new Room((char*)"Barred Window N1", (char*)"You've found yourself in the castle's Barred Window N1...");
  Room *barredWindowN2 = new Room((char*)"Barred Window N2", (char*)"You've found yourself in the castle's Barred Window N2...");
  Room *barredWindowS1 = new Room((char*)"Barred Window S1", (char*)"You've found yourself in the castle's Barred Window S1...");
  Room *barredWindowS2 = new Room((char*)"Barred Window S2", (char*)"You've found yourself in the castle's Barred Window S2...");
  Room *barredWindowE = new Room((char*)"Barred Window E", (char*)"Congratulations, you successfully escaped the castle!  Thanks for playing.");

  Room *windowHallwayN = new Room((char*)"Window Hallway N", (char*)"You're in the castle's Window Hallway N.");
  Room *windowHallwayS = new Room((char*)"Window Hallway S", (char*)"You're in the castle's Window Hallway S.");
  Room *windowHallwayE1 = new Room((char*)"Window Hallway E1", (char*)"You're in the castle's Window Hallway E1.");
  Room *windowHallwayE2 = new Room((char*)"Window Hallway E2", (char*)"You're in the castle's Window Hallway E2.");

  Room *turretNE = new Room((char*)"Northeast Turret", (char*)"You're in the castle's Northeast Turret.");
  Room *turretSE = new Room((char*)"Southeast Turret", (char*)"You're in the castle's Southeast Turret.");

  // Set exits and items
  darkHallway->addItem(flashlight);
  darkHallway->setExit(EXIT_EAST, dungeon1);

  dungeon1b->setExit(EXIT_EAST, dungeon1c);
  dungeon1b->setExit(EXIT_SOUTH, dungeon1a);

  dungeon1a->addItem(screwdriver);
  dungeon1a->setExit(EXIT_NORTH, dungeon1b);
  dungeon1a->setExit(EXIT_SOUTH, dungeon1);

  dungeon1->setExit(EXIT_NORTH, dungeon1a);
  dungeon1->setExit(EXIT_SOUTH, dungeon1d);
  dungeon1->setExit(EXIT_EAST, oldAirway);
  dungeon1->setExit(EXIT_WEST, darkHallway);

  dungeon1d->addItem(dungeon1cKey);
  dungeon1d->setExit(EXIT_NORTH, dungeon1);
  dungeon1d->setExit(EXIT_SOUTH, dungeon1e);

  dungeon1e->setExit(EXIT_NORTH, dungeon1d);
  dungeon1e->setExit(EXIT_EAST, dungeon1f);

  dungeon1c->addItem(rope);
  dungeon1c->addRequirement(dungeon1cKey);
  dungeon1c->setExit(EXIT_WEST, dungeon1b);

  oldAirway->addItem(lint);
  oldAirway->addRequirement(screwdriver);
  oldAirway->addRequirement(hammer);
  oldAirway->setExit(EXIT_WEST, dungeon1);
  oldAirway->setExit(EXIT_EAST, rockShelfW);

  dungeon1f->addItem(hammer);
  dungeon1f->setExit(EXIT_WEST, dungeon1e);
  
  rockShelfN->addItem(ironBar);
  rockShelfN->setExit(EXIT_NORTH, windowHallwayN);
  rockShelfN->setExit(EXIT_SOUTH, chasm);
  
  rockShelfS->setExit(EXIT_NORTH, chasm);
  rockShelfS->setExit(EXIT_SOUTH, windowHallwayS);
  
  rockShelfE->addItem(turretNeKey);
  rockShelfE->setExit(EXIT_EAST, barredWindowE);
  rockShelfE->setExit(EXIT_WEST, chasm);
  
  rockShelfW->setExit(EXIT_EAST, chasm);
  rockShelfW->setExit(EXIT_WEST, oldAirway);

  chasm->addRequirement(rope);
  chasm->addRequirement(lint);
  chasm->setExit(EXIT_NORTH, rockShelfN);
  chasm->setExit(EXIT_SOUTH, rockShelfS);
  chasm->setExit(EXIT_EAST, rockShelfE);
  chasm->setExit(EXIT_WEST, rockShelfW);
  
  barredWindowN1->setExit(EXIT_EAST, windowHallwayN);
  
  barredWindowN2->setExit(EXIT_WEST, windowHallwayN);
  barredWindowN2->setExit(EXIT_EAST, turretNE);
  
  barredWindowS1->addItem(turretSeKey);
  barredWindowS1->setExit(EXIT_EAST, windowHallwayS);
  
  barredWindowS2->setExit(EXIT_WEST, windowHallwayS);
  barredWindowS2->setExit(EXIT_EAST, turretSE);
  
  barredWindowE->addRequirement(ironBar);
  barredWindowE->addRequirement(mat1);
  barredWindowE->addRequirement(mat2);
  
  windowHallwayN->setExit(EXIT_WEST, barredWindowN1);
  windowHallwayN->setExit(EXIT_EAST, barredWindowN2);
  windowHallwayN->setExit(EXIT_SOUTH, rockShelfN);
  
  windowHallwayS->setExit(EXIT_WEST, barredWindowS1);
  windowHallwayS->setExit(EXIT_EAST, barredWindowS2);
  windowHallwayS->setExit(EXIT_NORTH, rockShelfS);

  windowHallwayE1->addItem(mat1);
  windowHallwayE1->setExit(EXIT_NORTH, turretNE);
  
  windowHallwayE2->addItem(mat2);
  windowHallwayE2->setExit(EXIT_SOUTH, turretSE);

  turretNE->addRequirement(turretNeKey);
  turretNE->setExit(EXIT_WEST, barredWindowN2);
  turretNE->setExit(EXIT_SOUTH, windowHallwayE1);

  turretSE->addRequirement(turretSeKey);
  turretSE->setExit(EXIT_WEST, barredWindowS2);
  turretSE->setExit(EXIT_NORTH, windowHallwayE2);

  // Initializing variables
  Room *currentRoom = darkHallway;
  vector<Item *> *inventory = new vector<Item *>();

  // Time to actually start the game!

  // Print entry message
  cout << "Welcome to Escape the Castle, the epic sequel to Escape the Hotel, a Java Adventure Game." << endl << endl;
  cout << "If, at any point during the game you forget what commands to use, type \"HELP\" and you will be presented with the command list." << endl << endl;
  cout << "The goal of this game is to escape the castle using items that you find around the map!  Good luck." << endl;

  // Get commands forever until a quit command is sent
  while (true)
  {
    cout << "============================================================" << endl;

    // Print the room
    printRoom(currentRoom);

    // Get the command & arg
    cout << "> ";
    char command[101];
    cin >> command;
    for (int i = 0; i < strlen(command); i++) // ignore case
    {
      command[i] = toupper(command[i]);
    }

    cout << endl << "============================================================" << endl;

    char argument[101];

    // Check & run "commands"
    if (strcmp(command, CMD_LOOK) == 0)
    {
      // Dropping items
      if (strcmp(currentRoom->name, darkHallway->name) == 0)
      {
        if (find(inventory->begin(), inventory->end(), flashlight) != inventory->end()) // Player needs a flashlight to look around
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
            // Only display the first item so the player doesn't yoink them all straight away
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
        if (find(inventory->begin(), inventory->end(), flashlight) != inventory->end()) // Player needs a flashlight to look around
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
            // Only display the first item so the player doesn't yoink them all straight away
            cout << "I also found an item called \"" << currentRoom->items->at(0)->name << "\"..." << endl;
          }
        }
        else
        {
          cout << "It's too dark in here, I can't see!  A little bit of light might help.  I remember seeing a faint glimmer in that weird dark hallway I magically appeared in..." << endl;
        }
      }
    }
    else if (strcmp(command, CMD_TAKE) == 0 || strcmp(command, CMD_GET) == 0)
    {
      // Picking up items
      cout << "Enter the item name > ";
      cin >> argument;
      for (int i = 0; i < strlen(argument); i++) // ignore case
      {
        argument[i] = toupper(argument[i]);
      }
      
      cout << endl;

      int idx = 0;
      vector<Item *>::iterator it;
      bool found = false;

      for (it = currentRoom->items->begin(); it < currentRoom->items->end(); it++)
      {
        if (strcmp((*it)->name, argument) == 0)
        {
          inventory->push_back(currentRoom->items->at(idx));
          currentRoom->items->erase(currentRoom->items->begin() + idx);
          cout << "You picked up the \"" << argument << "\" that was in the room." << endl;
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
    else if (strcmp(command, CMD_DROP) == 0)
    {
      // Dropping items
      cout << "Enter the item name > ";
      cin >> argument;
      for (int i = 0; i < strlen(argument); i++) // ignore case
      {
        argument[i] = toupper(argument[i]);
      }

      cout << endl;

      int idx = 0;
      vector<Item *>::iterator it;
      for (it = inventory->begin(); it < inventory->end(); it++)
      {
        if (strcmp((*it)->name, argument) == 0)
        {
          if (find(currentRoom->requirements->begin(), currentRoom->requirements->end(), *it) != currentRoom->requirements->end()) // Current room has this item as a requirement
          {
            cout << "You can't drop this item here..." << endl;
          }
          else
          {
            currentRoom->items->push_back(inventory->at(idx));
            inventory->erase(inventory->begin() + idx);
            cout << "You dropped the \"" << argument << "\" into the room." << endl;
            cout << "Type \"INVT\" to view your inventory at any time." << endl;
          }
          break;
        }
        idx++;
      }
      cout << "You don't have that item..." << endl;
    }
    else if (strcmp(command, CMD_MOVE) == 0 || strcmp(command, CMD_GO) == 0)
    {
      // Moving around the map
      cout << "Enter the direction (" << currentRoom->getRoomListStr() << ") > ";
      cin >> argument;
      for (int i = 0; i < strlen(argument); i++) // ignore case
      {
        argument[i] = toupper(argument[i]);
      }

      cout << endl;

      bool found = false;
      map<char *, Room *>::iterator it = currentRoom->exits->begin(); // APPARENTLY THIS WORKS BUT A NORMAL FOR LOOP DOESN'T AAGHA
      for (auto it = currentRoom->exits->begin(); it != currentRoom->exits->end(); it++)
      {
        if (strcmp(it->first, argument) == 0)
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
          if (strcmp(currentRoom->name, barredWindowE->name) == 0) // The player is in the "winning" room
          {
            cout << currentRoom->description << endl;
            return 0;
          }
          else
          {
            cout << "You moved " << argument << " to the " << currentRoom->name << "." << endl;
            break;
          }
        }
      }
      if (!found)
      {
        // Tell the player they entered in the wrong input
        cout << "There isn't an exit there!" << endl;
      }
    }
    else if (strcmp(command, CMD_INVT) == 0)
    {
      // Display inventory or specific item info
      cout << "Enter an item name or NONE to view all > ";
      cin >> argument;
      for (int i = 0; i < strlen(argument); i++) // ignore case
      {
        argument[i] = toupper(argument[i]);
      }

      cout << endl;

      if (strcmp(argument, "NONE") == 0)
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
          if (strcmp((*it)->name, argument) == 0)
          {
            cout << (*it)->name << endl;
            cout << "   " << (*it)->description << endl;
            found = true;
            break;
          }
        }
        if (!found)
        {
          // Item doesn't exist
          cout << "You don't have that item in your inventory!" << endl;
        }
      }
    }
    else if (strcmp(command, CMD_HELP) == 0)
    {
      // Display the help menu
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
    else if (strcmp(command, CMD_QUIT) == 0)
    {
      // Quit command.  Send message and return exit code 0
      cout << "Thanks for playing!" << endl;
      return 0;
    }
    else
    {
      cout << "I didn't recognize that command...";
    }
    cout << endl;
  }

  return 0;
}

void printRoom(Room *currentRoom)
{
  // Print the room name, description, and tip
  cout << "Current Room: " << currentRoom->name << endl << endl;
  cout << currentRoom->description << endl << endl;
  cout << "What would you like to do?  Type \"HELP\" for you available commands." << endl;
}
