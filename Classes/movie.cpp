#include <cstring>
#include <iostream>

#include "movie.h"

using namespace std;

Movie::Movie() {
  title = new char[101];
  year = 1970;
  director = new char[101];
  duration = 60;
  rating = 10.0;
}

Movie::~Movie() {
  delete title;
  delete director;
}

void Movie::setDirector(char directorIn[101]) {
  strcpy(director, directorIn);
}

void Movie::setDuration(int durationIn) {
  duration = durationIn;
}

void Movie::setRating(float ratingIn) {
  rating = ratingIn;
}

void Movie::print() {
  cout << "MOVIE: \"" << title << ",\" a " << year << " film directed by " << director << " (Duration: " << duration << " minutes).  Rated " << rating << " stars." << endl;
}


