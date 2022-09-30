#include <cstring>

#include "media.h"

Media::Media() {
  
}

Media::~Media() {
  
}

void Media::print() {
  
}

void Media::setTitle(char titleIn[101]) {
  strcpy(title, titleIn);
}

void Media::setYear(int yearIn) {
  year = yearIn;
}
