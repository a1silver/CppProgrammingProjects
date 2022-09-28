#include <iostream>
#include <iomanip>
#include <cstring>
#include <vector>
#include <ctype.h>

#include "media.h"

using namespace std;

int main() {
  Media* media = new Media();
  media->setTitle(new char[] {'B', 'r', 'e', 'a', 'k', 'i', 'n', 'g', ' ', 'B', 'a', 'd', '\0'});
  media->setYear(2020);
  cout << media->getTitle() << " - " << media->getYear() << endl;
  delete media;
  
  return 0;
}

// when creating media objects:
// ===> title = new char[101];
// title is a char pointer.  we need to make enough space in memory for 101 characters (title + null char)
