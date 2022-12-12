#include <iostream>
#include <vector>
#include <cstring>

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

void printRoom(Room* currentRoom);
void dropItem(Room* currentRoom, vector<Item*>* inventory, int idx);

int main() {
  // Initializing items first

  // Flashlight
  cout << 1 << endl;
  char flashlightName[] = "FLASHLIGHT";
  char flashlightDescription[] = "This item is an imperative for finding other items!";
  Item* flashlight = new Item();
  strcpy(flashlight->name, flashlightName);
  strcpy(flashlight->description, flashlightDescription);

  // Screwdriver
  cout << 2 << endl;
  char screwdriverName[] = "SCREWDRIVER";
  char screwdriverDescription[] = "Electricians used this item to open maintenance vents.";
  Item* screwdriver = new Item();
  strcpy(screwdriver->name, screwdriverName);
  strcpy(screwdriver->description, screwdriverDescription);

  // Dungeon 1c Key
  cout << 3 << endl;
  char key1cName[] = "DUNGEON-1C-KEY";
  char key1cDescription[] = "This key grants access to the Dungeon 1C.";
  Item* dungeon1cKey = new Item();
  strcpy(dungeon1cKey->name, key1cName);
  strcpy(dungeon1cKey->description, key1cDescription);

  // Rope
  cout << 4 << endl;
  char ropeName[] = "ROPE";
  char ropeDescription[] = "Ropes could be useful to cross large spaces or scale up tall things like cliffs!";
  Item* rope = new Item();
  strcpy(rope->name, ropeName);
  strcpy(rope->description, ropeDescription);

  // Rope
  cout << 5 << endl;
  char lintName[] = "LINTBALL";
  char lintDescription[] = "Your ropes may be frayed, repair them by whipping them with some old lint!";
  Item* lint = new Item();
  strcpy(lint->name, lintName);
  strcpy(lint->description, lintDescription);

  // Hammer
  cout << 6 << endl;
  char hammerName[] = "HAMMER";
  char hammerDescription[] = "Used along with the screwdriver!  Commonly used by electricians.";
  Item* hammer = new Item();
  strcpy(hammer->name, hammerName);
  strcpy(hammer->description, hammerDescription);

  // Turret SE Key
  cout << 7 << endl;
  char turretSeKeyName[] = "TURRET-SE-KEY";
  char turretSeKeyDescription[] = "This key grants access to the Southeast Turret.";
  Item* turretSeKey = new Item();
  strcpy(turretSeKey->name, turretSeKeyName);
  strcpy(turretSeKey->description, turretSeKeyDescription);

  // Iron Bar
  cout << 8 << endl;
  char ironBarName[] = "IRONBAR";
  char ironBarDescription[] = "You may need to pry open a window with this!";
  Item* ironBar = new Item();
  strcpy(ironBar->name, ironBarName);
  strcpy(ironBar->description, ironBarDescription);

  // Turret NE Key
  cout << 9 << endl;
  char turretNeKeyName[] = "TURRET-NE-KEY";
  char turretNeKeyDescription[] = "This key grants access to the Northeast Turret.";
  Item* turretNeKey = new Item();
  strcpy(turretNeKey->name, turretNeKeyName);
  strcpy(turretNeKey->description, turretNeKeyDescription);

  // Mattress 1
  cout << 10 << endl;
  char mat1Name[] = "MATTRESS-1";
  char mat1Description[] = "Using a mattress could save your life in case you need to jump out of a window!";
  Item* mat1 = new Item();
  strcpy(mat1->name, mat1Name);
  strcpy(mat1->description, mat1Description);

  // Mattress 2
  cout << 11 << endl;
  char mat2Name[] = "MATTRESS-2";
  char mat2Description[] = "Using a mattress could save your life in case you need to jump out of a window!";
  Item* mat2 = new Item();
  strcpy(mat2->name, mat2Name);
  strcpy(mat2->description, mat2Description);


  // Initializing the rooms;
  Room* darkHallway = new Room();
  Room* dungeon1b = new Room();
  Room* dungeon1a = new Room();
  Room* dungeon1 = new Room();
  Room* dungeon1d = new Room();
  Room* dungeon1e = new Room();
  Room* dungeon1c = new Room();
  Room* oldAirway = new Room();
  Room* dungeon1f = new Room();
  Room* barredWindowN1 = new Room();
  Room* rockShelfW = new Room();
  Room* barredWindowS1 = new Room();
  Room* windowHallwayN = new Room();
  Room* rockShelfN = new Room();
  Room* chasm = new Room();
  Room* rockShelfS = new Room();
  Room* windowHallwayS = new Room();
  Room* barredWindowN2 = new Room();
  Room* rockShelfE = new Room();
  Room* barredWindowS2 = new Room();
  Room* turretNE = new Room();
  Room* windowHallwayE1 = new Room();
  Room* barredWindowE = new Room();
  Room* windowHallwayE2 = new Room();
  Room* turretSE = new Room();

  // Creating the rooms
  cout << 12 << endl;
  char darkHallwayName[] = "Dark Hallway";
  char darkHallwayDescription[] = "You emerge out of an awkward dream.  You ask yourself, \"Where am I?\"  As you slowly get your bearings, you notice you're in a disturbingly dark room.";
  darkHallway->setNnD(darkHallwayName, darkHallwayDescription);
  darkHallway->addItem(flashlight);
  darkHallway->setExit(EXIT_EAST, dungeon1);

  cout << 13 << endl;
  char dungeon1bName[] = "Dungeon 1B";
  cout << "13a" << endl;
  char dungeon1bDescription[] = "You're in section 1B of the main dungeon.";
  cout << "13b" << endl;
  dungeon1b->setNnD(dungeon1bName, dungeon1bDescription);
  cout << "13c" << endl;
  dungeon1b->setExit(EXIT_EAST, dungeon1c);
  cout << "13d" << endl;
  dungeon1b->setExit(EXIT_SOUTH, dungeon1a);
  cout << "13e" << endl;

  cout << 14 << endl;
  char dungeon1aName[] = "Dungeon 1A";
  char dungeon1aDescription[] = "You're in section 1A of the main dungeon.";
  dungeon1a->setNnD(dungeon1aName, dungeon1aDescription);
  dungeon1a->addItem(screwdriver);
  dungeon1a->setExit(EXIT_NORTH, dungeon1b);
  dungeon1a->setExit(EXIT_SOUTH, dungeon1);

  cout << 15 << endl;
  char dungeon1Name[] = "Dungeon 1";
  char dungeon1Description[] = "You're in the main dungeon.";
  dungeon1->setNnD(dungeon1Name, dungeon1Description);
  dungeon1->setExit(EXIT_NORTH, dungeon1a);
  dungeon1->setExit(EXIT_SOUTH, dungeon1d);
  dungeon1->setExit(EXIT_EAST, oldAirway);
  dungeon1->setExit(EXIT_WEST, darkHallway);

  cout << 16 << endl;
  char dungeon1dName[] = "Dungeon 1D";
  char dungeon1dDescription[] = "You're in section 1D of the main dungeon.";
  dungeon1d->setNnD(dungeon1dName, dungeon1dDescription);
  dungeon1d->addItem(dungeon1cKey);
  dungeon1d->setExit(EXIT_NORTH, dungeon1);
  dungeon1d->setExit(EXIT_SOUTH, dungeon1e);

  cout << 17 << endl;
  char dungeon1eName[] = "Dungeon 1E";
  char dungeon1eDescription[] = "You're in section 1E of the main dungeon.";
  dungeon1e->setNnD(dungeon1eName, dungeon1eDescription);
  dungeon1e->setExit(EXIT_NORTH, dungeon1d);
  dungeon1e->setExit(EXIT_EAST, dungeon1f);

  cout << 18 << endl;
  char dungeon1cName[] = "Dungeon 1C";
  char dungeon1cDescription[] = "You're in section 1C of the main dungeon.";
  dungeon1c->setNnD(dungeon1cName, dungeon1cDescription);
  dungeon1c->addItem(rope);
  dungeon1c->addRequirement(dungeon1cKey);
  dungeon1c->setExit(EXIT_WEST, dungeon1b);

  cout << 19 << endl;
  char oldAirwayName[] = "Old Airway";
  char oldAirwayDescription[] = "You're in an old airway of the castle.  A great place for someone to hide.";
  oldAirway->setNnD(oldAirwayName, oldAirwayDescription);
  oldAirway->addItem(lint);
  oldAirway->addRequirement(screwdriver);
  oldAirway->addRequirement(hammer);
  oldAirway->setExit(EXIT_WEST, dungeon1);
  oldAirway->setExit(EXIT_EAST, rockShelfW);

  cout << 20 << endl;
  char dungeon1fName[] = "Dungeon 1F";
  char dungeon1fDescription[] = "You're in section 1F of the main dungeon.";
  dungeon1f->setNnD(dungeon1fName, dungeon1fDescription);
  dungeon1f->addItem(hammer);
  dungeon1f->setExit(EXIT_WEST, dungeon1e);

  for(int i = 0; i < 4; i++) {
    char direction[6];
    switch(i) {
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
    int maxTitleSize = strlen(namePrefix) + 5 + 1; // name size + max direction size + null char
    int maxDescriptionSize = strlen(descriptionPrefix) + 5 + 1;
    char concatTitle[maxTitleSize];
    char concatDescription[maxDescriptionSize];
    strcpy(concatTitle, strcat(namePrefix, direction));
    strcpy(concatDescription, strcat(descriptionPrefix, direction));
    switch(i) {
      case 0:
        cout << 21 << endl;
        rockShelfN->setNnD(concatTitle, concatDescription);
        rockShelfN->addItem(ironBar);
        rockShelfN->setExit(EXIT_NORTH, windowHallwayN);
        rockShelfN->setExit(EXIT_SOUTH, chasm);
        break;
      case 1:
        cout << 22 << endl;
        rockShelfS->setNnD(concatTitle, concatDescription);
        rockShelfS->setExit(EXIT_NORTH, chasm);
        rockShelfS->setExit(EXIT_SOUTH, windowHallwayS);
        break;
      case 2:
        cout << 23 << endl;
        rockShelfE->setNnD(concatTitle, concatDescription);
        rockShelfE->addItem(turretNeKey);
        rockShelfE->setExit(EXIT_EAST, barredWindowE);
        rockShelfE->setExit(EXIT_WEST, chasm);
        break;
      case 3:
        cout << 24 << endl;
        rockShelfW->setNnD(concatTitle, concatDescription);
        rockShelfW->setExit(EXIT_EAST, chasm);
        rockShelfW->setExit(EXIT_WEST, oldAirway);
        break;
    }
  }

  cout << 25 << endl;
  char chasmName[] = "Chasm";
  char chasmDescription[] = "You're in the underground part of the castle and find an odd hole in the ground... could you possibly throw a rope to get across?";
  chasm->setNnD(chasmName, chasmDescription);
  chasm->addRequirement(rope);
  chasm->addRequirement(lint);
  chasm->setExit(EXIT_NORTH, rockShelfN);
  chasm->setExit(EXIT_SOUTH, rockShelfS);
  chasm->setExit(EXIT_EAST, rockShelfE);
  chasm->setExit(EXIT_WEST, rockShelfW);

  for(int i = 0; i < 5; i++) {
    char direction[5];
    switch(i) {
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
    switch(i) {
      case 0:
        cout << 26 << endl;
        barredWindowN1->setNnD(strcat(namePrefix, direction), strcat(strcat(descriptionPrefix, direction), descriptionSuffix));
        barredWindowN1->setExit(EXIT_EAST, windowHallwayN);
        break;
      case 1:
        cout << 27 << endl;
        barredWindowN2->setNnD(strcat(namePrefix, direction), strcat(strcat(descriptionPrefix, direction), descriptionSuffix));
        barredWindowN2->setExit(EXIT_WEST, windowHallwayN);
        barredWindowN2->setExit(EXIT_EAST, turretNE);
        break;
      case 2:
        cout << 28 << endl;
        barredWindowS1->setNnD(strcat(namePrefix, direction), strcat(strcat(descriptionPrefix, direction), descriptionSuffix));
        barredWindowS1->addItem(turretSeKey);
        barredWindowS1->setExit(EXIT_EAST, windowHallwayS);
        break;
      case 3:
        cout << 29 << endl;
        barredWindowS2->setNnD(strcat(namePrefix, direction), strcat(strcat(descriptionPrefix, direction), descriptionSuffix));
        barredWindowS2->setExit(EXIT_WEST, windowHallwayS);
        barredWindowS2->setExit(EXIT_EAST, turretSE);
        break;
      case 4:
        cout << 30 << endl;
        barredWindowE->setNnD(strcat(namePrefix, direction), strcat(strcat(descriptionPrefix, direction), descriptionSuffix));
        barredWindowE->addRequirement(ironBar);
        barredWindowE->addRequirement(mat1);
        barredWindowE->addRequirement(mat2);
        break;
    }
  }

  for(int i = 0; i < 4; i++) {
    char direction[5];
    switch(i) {
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
    switch(i) {
      case 0:
        cout << 31 << endl;
        windowHallwayN->setNnD(strcat(namePrefix, direction), strcat(strcat(descriptionPrefix, direction), descriptionSuffix));
        windowHallwayN->setExit(EXIT_WEST, barredWindowN1);
        windowHallwayN->setExit(EXIT_EAST, barredWindowN2);
        windowHallwayN->setExit(EXIT_SOUTH, rockShelfN);
        break;
      case 1:
        cout << 32 << endl;
        windowHallwayS->setNnD(strcat(namePrefix, direction), strcat(strcat(descriptionPrefix, direction), descriptionSuffix));
        windowHallwayN->setExit(EXIT_WEST, barredWindowS1);
        windowHallwayN->setExit(EXIT_EAST, barredWindowS2);
        windowHallwayN->setExit(EXIT_NORTH, rockShelfS);
        break;
      case 2:
        cout << 33 << endl;
        windowHallwayE1->setNnD(strcat(namePrefix, direction), strcat(strcat(descriptionPrefix, direction), descriptionSuffix));
        windowHallwayE1->addItem(mat1);
        windowHallwayE1->setExit(EXIT_NORTH, turretNE);
        break;
      case 3:
        cout << 34 << endl;
        windowHallwayE2->setNnD(strcat(namePrefix, direction), strcat(strcat(descriptionPrefix, direction), descriptionSuffix));
        windowHallwayE1->addItem(mat2);
        windowHallwayE1->setExit(EXIT_SOUTH, turretSE);
        break;
    }
  }

  cout << 35 << endl;
  char turretNeName[] = "Northeast Turret";
  char turretNeDescription[] = "You're in the castle's Northeast Turret.";
  turretNE->setNnD(turretNeName, turretNeDescription);
  turretNE->addRequirement(turretNeKey);
  turretNE->setExit(EXIT_WEST, barredWindowN2);
  turretNE->setExit(EXIT_SOUTH, windowHallwayE1);

  cout << 36 << endl;
  char turretSeName[] = "Southeast Turret";
  char turretSeDescription[] = "You're in the castle's Southeast Turret.";
  turretSE->setNnD(turretSeName, turretSeDescription);
  turretSE->addRequirement(turretSeKey);
  turretSE->setExit(EXIT_WEST, barredWindowS2);
  turretSE->setExit(EXIT_NORTH, windowHallwayE2);


  // Initializing variables
  Room* currentRoom = darkHallway;
  vector<Item*> inventory;
  cout << "Done initializing" << endl;

  while(true) {
    cout << "Enter your command > ";
    char cmd1[101];
    cin >> cmd1;
    cout << "Enter your command parameter > ";
    char cmd2[101];
    cin >> cmd2;
    cout << "Command 1: " << cmd1 << endl;
    cout << "Command 2: " << cmd2 << endl;
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

void printRoom(Room* currentRoom) {

}

void dropItem(Room* currentRoom, vector<Item*>* inventory, int idx) {

}
