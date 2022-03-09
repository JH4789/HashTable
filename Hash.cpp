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
  int collisioncount = 0;
  void setIndex(int newindex) {
    index = newindex;
  }
  Node* getHead() {
    return head;
  }
  void addstudent(int newvalue) {
    collisioncount ++;
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
    tail = tail->next;
   }
  }
  
};
//Function prototyping
int hashfunction(int studentidhash);
void addStudent(int newnumber, studentinfo newarray[]);
void printStudent(vector <studentinfo*> &v);
void delStudent(int deletenumber, studentinfo newarray[]);
int main() {
  //Variable setup
  char commandinput[7];
  bool running = true;
  studentinfo hashtable[100];
  
  for(int i = 0; i < 100; i++) {
    hashtable[i]= new studentinfo();
    hashtable[i].setIndex(i);
  }
  addStudent(0, hashtable);
  addStudent(100, hashtable);
  addStudent(200, hashtable);
  addStudent(300, hashtable);
  addStudent(4, hashtable);
  delStudent(4, hashtable);
  addStudent(5000, hashtable);
  delStudent(100, hashtable);
  delStudent(200, hashtable);
  Node* testing = hashtable[0].getHead();
  while(testing != NULL) {
    cout << testing->value << endl;
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
void addStudent(int newnumber, studentinfo newarray[]) {
  int bucketnumber = hashfunction(newnumber);
  newarray[bucketnumber].addstudent(newnumber);
}
void printStudent(vector <studentinfo*> &v) {
  
}
void delStudent(int deletenumber, studentinfo newarray[]) {
  int posthash = hashfunction(deletenumber);
  Node* current = newarray[posthash].getHead();
  Node* prev = NULL;
  while(current != NULL) {
    if(current->value == deletenumber) {
      Node* temp = current;
      if(current->next == NULL) {
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
