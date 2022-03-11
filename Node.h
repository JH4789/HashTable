#ifndef NODEHEADER
#define NODEHEADER
#include <iostream>
using namespace std;
class Node{
 public:
  Node(int newvalue);
  ~Node();
  int getPointer();
  void setNext(Node* next);
  Node* getNext();
 private:
  //Needs to hold a Student pointer for code to work
  int value;
  Node* next; 
};

#endif
