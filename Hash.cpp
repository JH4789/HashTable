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
  
void addStudent(Node* prev, Node* current, Student* newstudent) {
  //Function checks for an empty list and then places the new node based on the value of its ID
  if(head == NULL) {
    head = new Node(newstudent);
    head->setNext(NULL);
  }
  else if(current == NULL) {
    prev -> setNext(new Node(newstudent));
    prev->getNext()->setNext(NULL);
  }
    //Recursion at the end if none satisfied
  else {
    addStudent(current, current->getNext(), newstudent);
   }  
}
  void delStudent(Node* prev, Node* current, int deletevalue) {
  if(head == NULL) {
    cout << "There is nothing here! Try adding some students first" << endl;
  }
  else if(deletevalue == current->getPointer()->getID()){
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
void printStudent(studentinfo hashtable[], int arraysize);
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
  while(running == true) {
    cout << "Enter ADD to add a student, enter PRINT to print all current students, enter DELETE to delete a student, and enter QUIT to quit the program" << endl;
    cin >> commandinput;
    //Getting inputs 
    if(strcmp(commandinput, "ADD") == 0){
      Student* newstudent = new Student();
      int newid;
      float newgpa;
      char firstname[100];
      char lastname[100];
      cout << "Please enter the student ID of the student you want to add" << endl;
      cin >> newid;
      newstudent->setID(newid);
      cout << "Please enter the first name of the student you want to add" << endl;
      cin >> firstname;
      newstudent->setFirst(firstname);

      cout << "Please enter the last name of the student you want to add" << endl;
      cin >> lastname;
      newstudent->setLast(lastname);
      cout << "Please enter the GPA of the student you want to add" << endl;
      cin >> newgpa;
      newstudent->setGPA(newgpa);
      
      int hashvalue = hashfunction(newid);
      Node* testhead = hashtable[hashvalue].getHead();
      hashtable[hashvalue].addStudent(testhead, testhead, newstudent);
  
    }
    else if(strcmp(commandinput, "PRINT") == 0) {
      printStudent(hashtable, 100);
    }
    else if(strcmp(commandinput, "DELETE") == 0){
      int delvalue;
      cout << "Please enter the student ID of the student you want to delete" << endl;
      cin >> delvalue;
      int hashdelvalue = hashfunction(delvalue);
      Node* deltesthead = hashtable[hashdelvalue].getHead();
      hashtable[hashdelvalue].delStudent(deltesthead, deltesthead, delvalue);
    }
    else if(strcmp(commandinput, "QUIT") == 0) {
      running = false;
    }
    else {
      cout << "Please enter a valid input";
    }
  }
  
}
int hashfunction(int studentidhash) {
  int posthash = studentidhash % 100;
  return posthash;
}
void printStudent(studentinfo hashtable[], int arraysize) {
  for(int i = 0; i < arraysize; i++) {
    Node* current = hashtable[i].getHead();
    while(current != NULL) {
      cout << current->getPointer() << endl;
      current = current->getNext();
    }
  }
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
