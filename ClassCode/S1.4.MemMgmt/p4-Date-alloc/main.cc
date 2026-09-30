#include <iostream>
using namespace std;
#include "Date.h"
#include <string>

#define MAX_ARR_SIZE 3

int main() {
  cout << "Allocating single objects..." << endl;
  Date *d1 = new Date;
  Date *d2 = new Date(28, 9);

  cout << endl << "Printing d1: ";
  d1->print();
  cout << "Printing d2: ";
  d2->print();

  cout << endl << "Allocating array of objects..." << endl;
  Date *arr = new Date[MAX_ARR_SIZE];

  arr[0].setDate(11, 11, 2011);
  arr[1].setDate(12, 12, 2012);

  cout << endl << "Printing arr[0]:  ";
  arr[0].print();
  cout << endl << "Printing arr[1]:  ";
  arr[1].print();

  cout << endl << "Deallocating single objects...  " << endl;
  delete d1;
  delete d2;

  cout << endl << "Deallocating array...  " << endl;
  delete[] arr;

  return 0;
}
