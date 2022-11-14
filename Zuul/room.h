#ifndef ROOM_H
#define ROOM_H

#include <map>
#include <vector>

using namespace std;

class ZuulRoom;

typedef map<char *, ZuulRoom *> Exits;

class ZuulRoom {
public:
  char* description;
  ZuulItem* requirement;
  ZuulPuzzle* puzzle;
  Exits* exits;
  Items* items;
  ZuulRoom(char descriptionIn[101]);
  ~ZuulRoom();

  void addExit(char directionIn[11], ZuulRoom *neighborIn);
  void addItem(ZuulItem *itemIn);
  void setRequirement(ZuulItem *requirementIn);
  void setPuzzle(ZuulPuzzle *puzzleIn);
  ZuulItem* getItemByName(char nameIn[51]);
  ZuulItem* getItemAt(int indexIn);
  void removeItemAt(int indexIn);
  void printFullDescription();
  void printExitString();
  ZuulRoom* getExit(char directionIn[11])
};

#ENDIF // ROOM_H
