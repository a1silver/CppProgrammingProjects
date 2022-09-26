#ifndef MEDIA_H
#define MEDIA_H

class Media {
 public:
  Media();
  virtual ~Media();

  char* getTitle();
  int getYear();
  void setTitle(char titleIn[101]);
  void setYear(int yearIn);
 protected:
  char* title;
  int year;
};

#endif // MEDIA_H
