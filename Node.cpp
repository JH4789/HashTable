#include "Node.h"
//Functions to iterate through a linked list
Node::Node(int newvalue) {
  value = newvalue;
  next = NULL;
}
Node::~Node() {
  next = NULL;
}
int Node::getPointer() {
  return value;
}
void Node::setNext(Node* newnext) {
  next = newnext;
}
Node* Node::getNext() {
  return next;
}
