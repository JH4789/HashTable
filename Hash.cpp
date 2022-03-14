/*
Name: Jayden Huang
Date: 3/13/2022
Functionality: Hash Table of students with characteristics
*/
//Setup
#include "Node.h"
#include <fstream>
#include <iostream>
#include <math.h>
#include <cstring>
#include <iomanip>
#include <vector>
#include <iterator>
using namespace std;
//Class definition in main file
class studentinfo {
public:
  //Linked lists stored inside each class 
  int index;
  Node* head = NULL;
  int collisioncount = 0;
  void setIndex(int newindex) {
    index = newindex;
  }
  Node* getHead() {
    return head;
  }
  //Adds student and increases collision count, taken from Linked List Part 2
int addStudent(Node* prev, Node* current, Student* newstudent) {
  if(head == NULL) {
    head = new Node(newstudent);
    head->setNext(NULL);
    collisioncount ++;
    return collisioncount;
  }
  else if(current == NULL) {
    prev -> setNext(new Node(newstudent));
    prev->getNext()->setNext(NULL);
    collisioncount ++;
    return collisioncount;
  }
    //Recursion at the end if none satisfied
  else {
    return addStudent(current, current->getNext(), newstudent);
   }  
}
  //Deletes student, also taken from Linked List Part 2
  void delStudent(Node* prev, Node* current, int deletevalue) {
  if(head == NULL) {
    cout << "There is nothing here! Try adding some students first" << endl;
  }
  else if(deletevalue == current->getPointer()->getID()){
    if(current == head) {
      head = head->getNext();
      current->setNext(NULL);
      delete current;
      collisioncount--;
      return;
    }
    else {
      prev->setNext(current->getNext());
      current->setNext(NULL);
      delete current;
      collisioncount--;
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
int hashfunctiontwo(int studentidhash);
void printStudent(studentinfo hashtable[], int arraysize);
Student* generateRandom();
int main() {
  //Variable setup
  char commandinput[7];
  bool running = true;
  //Initializes two hash tables, one for initial other for rehashing
  studentinfo hashtable[100];
  studentinfo newhashtable[200];
  bool newhashmade = false;
  for(int i = 0; i < 100; i++) {
    hashtable[i].setIndex(i);
  }
  //Main loop
  while(running == true) {
    cout << "Enter ADD to add a student, enter PRINT to print all current students, enter DELETE to delete a student, entre RANDOM to add a random student, and enter QUIT to quit the program" << endl;
    cin >> commandinput;
    //Getting inputs 
    if(strcmp(commandinput, "ADD") == 0){
      //Initializes new student
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
      //Function to add doubles as return function to check for collision count
      if(hashtable[hashvalue].addStudent(testhead, testhead, newstudent) == 4 && newhashmade == false) {
	for(int i = 0 ; i < 100; i++) {
          Node* current = hashtable[i].getHead();
	  while(current != NULL) {
	    //Copies each element into the new hash table using a new hashing function
	    Student* copystudent = current->getPointer();
	    int newhash = hashfunctiontwo(copystudent->getID());
	    Node* newaddhead = newhashtable[newhash].getHead();
	    newhashtable[newhash].addStudent(newaddhead, newaddhead, copystudent);
	    current = current->getNext();
	  }
	}
	cout << "Rehashing complete!" << endl;
	newhashmade = true;
      }
    }
    //Print function takes arguments of array length, two cases for pre and post new table creation
    else if(strcmp(commandinput, "PRINT") == 0) {
      if(newhashmade == false) {
        printStudent(hashtable, 100);
      }
      else {
      printStudent(newhashtable, 200);
      }
    }
    //Calls generateRandom function and adds it to the array of classes
    else if (strcmp(commandinput, "RANDOM") == 0) {
      Student* newrandomstudent = generateRandom();
      if(newhashmade == false) {
	int randomhashmade = hashfunction(newrandomstudent->getID());
	Node* randomaddhead = hashtable[randomhashmade].getHead();
	hashtable[randomhashmade].addStudent(randomaddhead, randomaddhead, newrandomstudent);
      }
      else {
	int randomhash = hashfunctiontwo(newrandomstudent->getID());
	Node* randomhead = newhashtable[randomhash].getHead();
	newhashtable[randomhash].addStudent(randomhead, randomhead, newrandomstudent);
      }
    }
    //Calls the delete function inside the studentinfo class
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
      cout << "Please enter a valid input" << endl;
    }
  }
  
}
//Initial hash function 
int hashfunction(int studentidhash) {
  int posthash = studentidhash % 100;
  return posthash;
}
//Post table creation hash function
int hashfunctiontwo(int studentidhash) {
  int posthash = studentidhash*(studentidhash+3) % 200;
  return posthash;
}
//Prints with argument based on size of table
void printStudent(studentinfo hashtable[], int arraysize) {
  for(int i = 0; i < arraysize; i++) {
    Node* current = hashtable[i].getHead();
    while(current != NULL) {
      current->getPointer()->print();
      current = current->getNext();
    }
  }
}
//Creates a random student
Student* generateRandom(){
    //Written with help from Jeffrey Teh
    char* firstnameholder[100];
    char* lastnameholder[100];
    fstream firstNames;
    //Access first names through file
    firstNames.open("firstNames.txt");
    for(int i = 0; i<100; i++){
        char* firstName = new char[50];
        firstNames >> firstName;
        firstnameholder[i] = firstName;
    }
    fstream lastNames;
    //Opens txts to access info
    lastNames.open("lastNames.txt");
    for(int i = 0; i<100; i++){
        char* lastName = new char[50];
        lastNames >> lastName;
        lastnameholder[i] = lastName;
    }
    char* studentFirst = firstnameholder[rand() %100 + 1];
    char* studentLast = lastnameholder[rand() %100 + 1];
    int studentID = rand() %8999 + 1000;
    //To generate a random float, help from https://www.tutorialspoint.com/how-do-i-generate-random-floats-in-cplusplus
    //Range== [0,4.0]    
    float max = 4.0;
    float studentGPA = (float(rand())/float((RAND_MAX)) * max);
    studentGPA = roundf(studentGPA * 100) / 100;
    Student* temp2 = new Student();
    temp2->setID(studentID);
    temp2->setFirst(studentFirst);
    temp2->setLast(studentLast);
    temp2->setGPA(studentGPA);
    return temp2;
}
