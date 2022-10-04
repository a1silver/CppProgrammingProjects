#include "media.h"

#ifndef MOVIE_H
#define MOVIE_H

class Movie : public Media {
 public:
  Movie();
  virtual ~Movie();

  void setDirector(char directorIn[101]);
  void setDuration(int durationIn);
  void setRating(float ratingIn);
  void print();
 protected:
  // artist duration publisher
  char* director;
  int duration;
  float rating;
};

#endif // MUSIC_H
