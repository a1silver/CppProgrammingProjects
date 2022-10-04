#include <iostream>
#include <iomanip>
#include <cstring>
#include <vector>
#include <ctype.h>

#include "media.h"
#include "videogame.h"
#include "music.h"
#include "movie.h"

using namespace std;

// Commands
const char ADD_CMD[] = "ADD";
const char SEARCH_CMD[] = "SEARCH";
const char DELETE_CMD[] = "DELETE";
const char QUIT_CMD[] = "QUIT";

// Media Types
const char VIDEOGAME_TYPE[] = "VIDEOGAME";
const char MUSIC_TYPE[] = "MUSIC";
const char MOVIE_TYPE[] = "MOVIE";

// Search filters
const char SEARCHBY_TITLE[] = "TITLE";
const char SEARCHBY_YEAR[] = "YEAR";

// Method prototypes
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
      searchMedia(&mediaList);
    }
    if(strcmp(cmd, DELETE_CMD) == 0) {
      // deleteMedia(&mediaList);
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

      mediaList->push_back(obj);
      
      cout << "New video game added! There are " << mediaList->size() << " entries in the database." << endl;
    }
    break;
  case 1: // Music
    {
      Music* obj = new Music();

      char title[101];
      cout << "Enter Title: ";
      cin.getline(title, 100, '\n');
      obj->setTitle(title);

      int year;
      cout << "Enter Year: ";
      cin >> year;
      cin.ignore();
      obj->setYear(year);

      char artist[101];
      cout << "Enter Artist: ";
      cin.getline(artist, 100, '\n');
      obj->setArtist(artist);

      float duration;
      cout << "Enter Duration in minutes: ";
      cin >> duration;
      cin.ignore();
      obj->setDuration(duration);

      char publisher[101];
      cout << "Enter Publisher: ";
      cin.getline(publisher, 100, '\n');
      obj->setPublisher(publisher);

      obj->print();

      mediaList->push_back(obj);
      
      cout << "New song added! There are " << mediaList->size() << " entries in the database." << endl;
    }
    break;
  case 2: // Movie
    {
      Movie* obj = new Movie();

      char title[101];
      cout << "Enter Title: ";
      cin.getline(title, 100, '\n');
      obj->setTitle(title);

      int year;
      cout << "Enter Year: ";
      cin >> year;
      cin.ignore();
      obj->setYear(year);

      char director[101];
      cout << "Enter Director: ";
      cin.getline(director, 100, '\n');
      obj->setDirector(director);

      float duration;
      cout << "Enter Duration in minutes: ";
      cin >> duration;
      cin.ignore();
      obj->setRating(duration);
      
      float rating;
      cout << "Enter Rating: ";
      cin >> rating;
      cin.ignore();
      obj->setRating(rating);

      obj->print();

      mediaList->push_back(obj);
      
      cout << "New movie added! There are " << mediaList->size() << " entries in the database." << endl;
    }
    break;

  case -1:
  default:
    cout << "An unexpected error happened: An incorrect media type was supplied!" << endl;
    break;
  }
}

void searchMedia(vector<Media *> *mediaList) {
  char typIn[10];

  // Search filter. 0 = by title, 1 = by year
  int typ = -1;
  
  // Get search filter
  do {
    cout << "What type of media would you like to add?  Please enter either \"TITLE\" or \"YEAR\": ";
    cin >> typIn;
    cin.ignore();

    if(strcmp(typIn, SEARCHBY_TITLE) == 0) {
      typ = 0;
      break;
    }
    if(strcmp(typIn, SEARCHBY_YEAR) == 0) {
      typ = 1;
      break;
    }
    
  } while (true);

  // Search the media database
  switch (typ) {
  case 0: // By title
    {
      cout << "Please enter the title you're searching for: ";
      char titleSearch[101];
      cin.getline(titleSearch, 100, '\n');

      int results = 0;
    
      vector<Media *>::iterator it;
      for(it = mediaList->begin(); it < mediaList->end(); it++) {
	if(strcmp((*it)->getTitle(), titleSearch) == 0) {
	  cout << " >> ";
	  (*it)->print();
	  results++;
	}
      }
      cout << "Found " << results << " results matching that title." << endl;
    }
    break;
  case 1: // By year
    {
      cout << "Please enter the year you're searching for: ";
      int yearSearch;
	cin >> yearSearch;
	cin.ignore();

      int results = 0;
    
      vector<Media *>::iterator it;
      for(it = mediaList->begin(); it < mediaList->end(); it++) {
	if((*it)->getYear() == yearSearch) {
	  cout << " >> ";
	  (*it)->print();
	  results++;
	}
      }
      cout << "Found " << results << " results matching that year." << endl;
    }
    break;
  case -1:
  default:
    cout << "An unexpected error happened: An incorrect search filter was supplied!" << endl;
    break;
  }
}

// when creating media objects:
// ===> title = new char[101];
// title is a char pointer.  we need to make enough space in memory for 101 characters (title + null char)
