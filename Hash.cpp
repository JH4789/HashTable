/*
Name: Jayden Huang
Date:
Functionality: Hash Table of students with characteristics
*/
//Setup
#include <iostream>
#include <cstring>
#include <iomanip>
#include <vector>
#include <iterator>
using namespace std;
//Struct definition
struct Node {
  Node* next;
  int value;
};
  
class studentinfo {
public:
  int index;
  Node* head = NULL;
  Node* tail = NULL;
  void setIndex(int newindex) {
    index = newindex;
  }
  Node* getHead() {
    return head;
  }
  void add(int newvalue) {
    if(head == NULL) {
      Node* newnode = new Node();
      newnode->value = newvalue;
      newnode->next = NULL;
      head = newnode;
      tail = newnode;
    }
    else {
    Node* newnode = new Node();
    newnode->value = newvalue;
    newnode->next = NULL;
    tail->next = newnode;
    tail = tail ->next;
   }
  }
};
//Function prototyping
int hashfunction(int studentidhash);
void addStudent(int newnumber, studentinfo newarray[100]);
void printStudent(vector <studentinfo*> &v);
void delStudent(vector <studentinfo*> &v);
int main() {
  //Variable setup
  char commandinput[7];
  bool running = true;
  studentinfo test[100];
  
  for(int i = 0; i < 100; i++) {
    test[i].setIndex(i);
  }
  addStudent(0, test);
  addStudent(100, test);
  cout << hashfunction(100) << endl;
  Node* testing = test[0].getHead();
  while(testing != NULL) {
    cout << testing->value;
    testing = testing->next;
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
void addStudent(int newnumber, studentinfo newarray[100]) {
  int bucketnumber = hashfunction(newnumber);
  newarray[bucketnumber].add(newnumber);
}
void printStudent(vector <studentinfo*> &v) {
  
}
void delStudent(vector <studentinfo*> &v) {
  
}
