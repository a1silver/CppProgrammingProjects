#include "media.h"

#ifndef MUSIC_H
#define MUSIC_H

class Music : public Media {
 public:
  Music();
  virtual ~Music();

  void setArtist(char artistIn[101]);
  void setDuration(float durationIn);
  void setPublisher(char publisherIn[101]);
  void print();
 protected:
  // artist duration publisher
  char* artist;
  float duration;
  char* publisher;
};

#endif // MUSIC_H
