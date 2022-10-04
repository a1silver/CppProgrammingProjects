#include <cstring>

#include "media.h"

Media::Media() {
  
}

Media::~Media() {
  
}

void Media::print() {
  
}

char* Media::getTitle() {
  return title;
}

int Media::getYear() {
  return year;
}

void Media::setTitle(char titleIn[101]) {
  strcpy(title, titleIn);
}

void Media::setYear(int yearIn) {
  year = yearIn;
}
