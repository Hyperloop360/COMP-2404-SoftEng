#include <iostream>
using namespace std;
#include "Date.h"
#include <string>

#define MAX_ARR_SIZE 3

int main() {
  cout << "Statically allocated array of Date Objects" << endl;
  Date arr1[MAX_ARR_SIZE];

  arr1[0].setDate(1, 1, 1911);
  arr1[1].setDate(2, 2, 1922);
  arr1[0].print();
  arr1[1].print();

  cout << "Statically allocated array of Date Object pointers" << endl;
  Date *arr2[MAX_ARR_SIZE];
  Date *dt1 = new Date(3, 3, 1933);

  arr2[0] = dt1;
  arr2[1] = new Date(4, 4, 1933);
  arr2[0]->print();
  arr2[1]->print();

  delete arr2[0];
  delete arr2[1];

  cout << "Dynamically allocated array of Date Objects" << endl;
  Date *arr3;
  arr3 = new Date[MAX_ARR_SIZE];
}
