#ifndef STUDENT_H
#define STUDENT_H

#include "Address.h"

class Student {
public:
  Student(string = "000000000", string = "Default name",
          string = "Default major", float = 0.0f, int = 0,
          string = "Default street", string = "Default city",
          string = "Default prov");
  ~Student();
  void print();

private:
  string number;
  string name;
  string majorPgm;
  float gpa;
  Address homeAddr;
};

#endif
