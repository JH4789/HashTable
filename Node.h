#ifndef NODEHEADER
#define NODEHEADER
#include <iostream>
#include "Student.h"
using namespace std;
class Node{
 public:
  Node(Student*);
  ~Node();
  Student* getPointer();
  void setNext(Node*);
  Node* getNext();
 private:
  //Needs to hold a Student pointer for code to work
  Student* student;
  Node* next; 
};

#endif
