#ifndef STUDENTHEADER
#define STUDENTHEADER
#include <iostream>

using namespace std;
//Used for testing purposes
class Student{
public:
  void setID(int newid);
  void print();
  void setFirst(char* newfirstname);
  void setLast(char* newlastname);
  void setGPA(float newgpa);
  int getID();
  float getGPA();
private:
  int id;
  char* firstname;
  char* lastname;
  float gpa;
};

#endif
