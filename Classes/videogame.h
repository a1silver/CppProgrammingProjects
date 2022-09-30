#include "media.h"

#ifndef VIDEOGAME_H
#define VIDEOGAME_H

class Videogame : public Media {
 public:
  Videogame();
  virtual ~Videogame();
  
  void setPublisher(char publisherIn[101]);
  void setRating(float ratingIn);
  void print();
 protected:
  char* publisher;
  float rating;
};

#endif // MEDIA_H
