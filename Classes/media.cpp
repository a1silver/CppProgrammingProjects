#include <cstring>

#include "media.h"

Media::Media() {
  title = new char[101];
  year = 1970;
}

Media::~Media() {
  delete title;
}

char* Media::getTitle() {
  return title;
}

int Media::getYear() {
  return year;
}

void Media::setTitle(char titleIn[101]) {
  strcpy(title, titleIn);
  delete titleIn;
}

void Media::setYear(int yearIn) {
  year = yearIn;
}
