#include <cstring>
#include <iostream>

#include "music.h"

using namespace std;

Music::Music() {
  title = new char[101];
  year = 1970;
  artist = new char[101];
  duration = 60;
  publisher = new char[101];
}

Music::~Music() {
  delete title;
  delete artist;
  delete publisher;
}

void Music::setArtist(char artistIn[101]) {
  strcpy(artist, artistIn);
}

void Music::setDuration(float durationIn) {
  duration = durationIn;
}

void Music::setPublisher(char publisherIn[101]) {
  strcpy(publisher, publisherIn);
}

void Music::print() {
  cout << "\"" << title << "\" by " << artist << " (" << duration << " minutes), published by " << publisher << " in " << year << endl;;
}
