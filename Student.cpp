#include "Student.h"
#include <cstring>
//Largely based off of Student List, nothing much to see here
void Student::setID(int newid) {
  id = newid;
}
void Student::setFirst(char* newfirstname) {
  firstname = new char[100];
  strcpy(firstname, newfirstname);
}
void Student::setLast(char* newlastname) {
  lastname = new char[100];
  strcpy(lastname, newlastname);
}
void Student::setGPA(float newgpa) {
  gpa = newgpa;
}
int Student::getID() {
  return id;
}
float Student::getGPA() {
  return gpa;
}
void Student::print() {
  cout << "The student's first name is " << firstname << endl;
  cout << "The student's last name is " << lastname << endl;
  cout << "The student's id is " << id << endl;
  cout << "The student's GPA is " << gpa << endl;
}
