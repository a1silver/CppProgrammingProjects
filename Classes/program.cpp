#include <iostream>
#include <iomanip>
#include <cstring>
#include <vector>
#include <ctype.h>

#include "media.h"
#include "videogame.h"

using namespace std;

const char ADD_CMD[] = "ADD";
const char SEARCH_CMD[] = "SEARCH";
const char DELETE_CMD[] = "DELETE";
const char QUIT_CMD[] = "QUIT";

const char VIDEOGAME_TYPE[] = "VIDEOGAME";
const char MUSIC_TYPE[] = "MUSIC";
const char MOVIE_TYPE[] = "MOVIE";

void addMedia(vector<Media *> *mediaList);
void searchMedia(vector<Media *> *mediaList);
void deleteMedia(vector<Media *> *mediaList);

// Main method
int main() {
  // Vector containing Media pointers
  vector<Media *> mediaList;

  // Set Float and Double Precision
  cout << fixed << setprecision(1);

  cout << "Media Database v1.0 by Morgan Hinz" << endl << endl;

  // Keeps track of the current command. 7 = longest cmd (6) + 1 (null char)
  char cmd[7];

  while (true) {
    cout << "> ";
    cin >> cmd;

    // Commands
    // add search delete quit
    if(strcmp(cmd, ADD_CMD) == 0) {
      addMedia(&mediaList);
    }
    if(strcmp(cmd, SEARCH_CMD) == 0) {
      
    }
    if(strcmp(cmd, DELETE_CMD) == 0) {

    }
    if(strcmp(cmd, QUIT_CMD) == 0) {
      break;
    }
  }
  
  return 0;
}

/*
  Adds a media object.  Asks for media type first.
  
  Video games will ask for: Title (char[]), year (int), publisher (char[]), rating (float)
  Music will ask for: Title (char[]), artist (char[]), year (int), duration minutes (float), publisher (char[])
  Movies will ask for: Title (char[]), director (char[]), year (int), duration minutes (float), rating (float)
 */
void addMedia(vector<Media *> *mediaList) {
  char typIn[10];

  // Media type. 0 = videogame, 1 = music, 2 = movie
  int typ = -1;
  
  // Get media type
  do {
    cout << "What type of media would you like to add?  Please enter either \"VIDEOGAME\", \"MUSIC\", or \"MOVIE\": ";
    cin >> typIn;
    cin.ignore();

    if(strcmp(typIn, VIDEOGAME_TYPE) == 0) {
      typ = 0;
      break;
    }
    if(strcmp(typIn, MUSIC_TYPE) == 0) {
      typ = 1;
      break;
    }
    if(strcmp(typIn, MOVIE_TYPE) == 0) {
      typ = 2;
      break;
    }
    
  } while (true);

  // Make the objects
  // Check for 0-length char arrays??
  switch (typ) {
  case 0: // Videogame
    {
      Videogame* obj = new Videogame();

      char title[101];
      cout << "Enter Title: ";
      cin.getline(title, 100, '\n');
      obj->setTitle(title);
    
      int year;
      cout << "Enter Year: ";
      cin >> year;
      cin.ignore();
      obj->setYear(year);
    
      char publisher[101];
      cout << "Enter Publisher: ";
      cin.getline(publisher, 100, '\n');
      obj->setPublisher(publisher);
    
      float rating;
      cout << "Enter Rating: ";
      cin >> rating;
      cin.ignore();
      obj->setRating(rating);

      obj->print();
    }
    break;
  case 1: // Music
    cout << "Adding music!" << endl;
    break;
  case 2: // Movie
    cout << "Adding a movie!" << endl;
    break;
  case -1:
  default:
    cout << "An unexpected error happened: An incorrect media type was supplied!" << endl;
    break;
  }
}

// when creating media objects:
// ===> title = new char[101];
// title is a char pointer.  we need to make enough space in memory for 101 characters (title + null char)
