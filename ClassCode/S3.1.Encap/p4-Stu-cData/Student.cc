#include <iostream>
#include <iomanip>
using namespace std;
#include <string>

#include "Student.h"


Student::Student(string s1, string s2, string s3, float g) : number(s1)
{ 
  name     = s2;
  majorPgm = s3;
  gpa      = g;

  cout << "-- Student ctor:  " << name << endl;
}

Student::~Student()
{ 
  cout << "-- Student dtor:  " << name << endl;
}

void Student::print() const
{
  cout << "Student:  " << number << "  " << left << setw(15) << name << " "
                      << setw(15) << majorPgm << "   GPA: "
                      << fixed << setprecision(2) << setw(5) << right << gpa << endl;
}

