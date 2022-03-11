/*
Name: Jayden Huang
Date:
Functionality: Hash Table of students with characteristics
*/
//Setup
#include "Node.h"
#include <iostream>
#include <cstring>
#include <iomanip>
#include <vector>
#include <iterator>
using namespace std;
//Struct definition
  
class studentinfo {
public:
  int index;
  Node* head = NULL;
  int collisioncount = 0;
  void setIndex(int newindex) {
    index = newindex;
  }
  Node* getHead() {
    return head;
  }
  
void addStudent(Node* prev, Node* current, int newvalue) {
  //Function checks for an empty list and then places the new node based on the value of its ID
  if(head == NULL) {
    head = new Node(newvalue);
    head->setNext(NULL);
  }
  else if(current == NULL) {
    prev -> setNext(new Node(newvalue));
    prev->getNext()->setNext(NULL);
  }
    //Recursion at the end if none satisfied
  else {
    addStudent(current, current->getNext(), newvalue);
   }  
}
void delStudent(Node* prev, Node* current, int deletevalue) {
  if(head == NULL) {
    cout << "There is nothing here! Try adding some students first" << endl;
  }
  else if(deletevalue == current->getPointer()){
    if(current == head) {
      head = head->getNext();
      current->setNext(NULL);
      delete current;
      return;
    }
    else {
      prev->setNext(current->getNext());
      current->setNext(NULL);
      delete current;
      return;
    }
  }
  else {
    delStudent(current, current->getNext(), deletevalue);
  }
}

};
//Function prototyping
int hashfunction(int studentidhash);
//void addStudent(Node* & head, Node* prev, Node* current, int newvalue);
void printStudent(vector <studentinfo*> &v);
//void delStudent(int deletenumber, studentinfo newarray[], Node* head);
//void delStudent(Node* & head, Node* current, Node* prev, int deletevalue);
int main() {
  //Variable setup
  char commandinput[7];
  bool running = true;
  studentinfo hashtable[100];
  
  for(int i = 0; i < 100; i++) {
    hashtable[i].setIndex(i);
  }
  
  Node* testhead = hashtable[4].getHead();
  hashtable[4].addStudent(testhead, testhead, 4);
  Node* testhead1 = hashtable[4].getHead();
  hashtable[4].addStudent(testhead1, testhead1, 8);
  Node* newhead = hashtable[4].getHead();
  hashtable[4].delStudent(newhead, newhead, 4);
  Node* testing = hashtable[4].getHead();
  while(testing != NULL) {
    cout << testing->getPointer() << endl;
    testing = testing->getNext();
  }
  /*
  while(running == true) {
    cout << "Enter ADD to add a student, enter PRINT to print all current students, enter DELETE to delete a student, and enter QUIT to quit the program" << endl;
    cin >> commandinput;
    //Getting inputs 
    if(strcmp(commandinput, "ADD") == 0){
      addStudent(v);
    }
    else if(strcmp(commandinput, "PRINT") == 0) {
      printStudent(v);
    }
    else if(strcmp(commandinput, "DELETE") == 0){
      delStudent(v);
    }
    else if(strcmp(commandinput, "QUIT") == 0) {
      running = false;
    }
    else {
      cout << "Please enter a valid input";
    }
  }
  */
}
int hashfunction(int studentidhash) {
  int posthash = studentidhash % 100;
  return posthash;
}
void printStudent(vector <studentinfo*> &v) {
  
}
/*
void delStudent(int deletenumber, studentinfo newarray[], Node* head) {
  int posthash = hashfunction(deletenumber);
  Node* current = head;
  Node* prev = NULL;
  while(current != NULL) {
    if(current->value == deletenumber) {
      Node* temp = current;
      if(current == head->next) {
        head->next = NULL;
      }
      else if(current->next == NULL) {
	prev->next = NULL;
	break;
      }
      else {	
        prev->next = temp->next;
        return;
      }
    }
    else {
      prev = current;
      current = current->next;
    }  
  }
}
*/
