#ifndef ARRAY_H
#define ARRAY_H

#include "Date.h"

#define MAX_ARR_SIZE 64

class Array {
public:
  Array();
  ~Array();
  void add(Date *);
  void print();

private:
  Date *elements[MAX_ARR_SIZE];
  int size; // number of elements
};

#endif
