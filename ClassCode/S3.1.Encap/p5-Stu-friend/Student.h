#ifndef STUDENT_H
#define STUDENT_H

#include "Address.h"

class Student
{
  friend void where(Student&);

  public:
    Student(string="000000000", string="Default name", string="Default major", float=0.0f,
            int=0, string="Default street", string="Default city", string="Default province");
    ~Student();
    void print() const;
    void moveTo(string,string);

  private:
    const string number;
    string  name;
    string  majorPgm;
    float   gpa;
    Address homeAddr;
};

#endif
