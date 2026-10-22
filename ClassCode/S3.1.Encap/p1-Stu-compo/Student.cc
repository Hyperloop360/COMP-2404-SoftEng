#include <iomanip>
#include <iostream>
using namespace std;
#include <string>

#include "Student.h"

Student::Student(string s1, string s2, string s3, float g, int n, string str,
                 string city, string prov)
    : homeAddr(n, str, city, prov), number(s1), name(s2), majorPgm(s3), gpa(g) {
  /*
    number   = s1;
    name     = s2;
    majorPgm = s3;
    gpa      = g;
  */
  /* BAD
    homeAddr.number = n;
    homeAddr.street = str;
    homeAddr.city   = city;
    homeAddr.province = prov;
  */

  /* BAD
    Address tmpAddr(n,str,city,prov);
    homeAddr = tmpAddr;
  */

  cout << "-- Student ctor:  " << name << endl;
}

Student::~Student() { cout << "-- Student dtor:  " << name << endl; }

void Student::print() {
  cout << "Student:  " << number << "  " << left << setw(15) << name << " "
       << setw(15) << majorPgm << "   GPA: " << fixed << setprecision(2)
       << setw(5) << right << gpa << endl;
  homeAddr.print();
  cout << endl;
}
