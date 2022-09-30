#include <cstring>
#include <iostream>

#include "videogame.h"

using namespace std;

Videogame::Videogame() {
  title = new char[101];
  year = 1970;
  publisher = new char[101];
  rating = 10.0;
}

Videogame::~Videogame() {
  delete title;
  delete publisher;
}

void Videogame::setPublisher(char publisherIn[101]) {
  strcpy(publisher, publisherIn);
}

void Videogame::setRating(float ratingIn) {
  rating = ratingIn;
}

void Videogame::print() {
  cout << "\"" << title << "\" by " << publisher << ", published on " << year << " (Rating: " << rating << " stars)" << endl;
}
