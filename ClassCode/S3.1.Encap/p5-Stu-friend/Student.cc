#include <iostream>
#include <iomanip>
using namespace std;
#include <string>

#include "Student.h"


Student::Student(string s1, string s2, string s3, float g,
                 int n, string s, string c, string p) 
    : number(s1), name(s2), majorPgm(s3), gpa(g), homeAddr(n,s,c,p)
{ 
  cout << "-- Student ctor:  " << name << endl;
}

Student::~Student()
{ 
  cout << "-- Student dtor:  " << name << endl;
}

void Student::moveTo(string c, string p)
{
  homeAddr.city     = c;
  homeAddr.province = p;
}

void Student::print() const  
{
  cout<<"Student:  " << number << "  " << left << setw(15) << name << " "
                     << setw(15) << majorPgm << "   GPA: "
                     << fixed << setprecision(2) << setw(5) << right << gpa << endl;
  homeAddr.print();
  cout<<endl;
}

