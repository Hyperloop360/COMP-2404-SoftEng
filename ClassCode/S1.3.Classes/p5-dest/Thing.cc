#include <iostream>
using namespace std;
#include "Thing.h"
#include <string>

Thing::Thing(int i, string s) {
  id = i;
  location = s;
  cout << "-- constructor: " << id << " " << location << endl;
}

Thing::~Thing() { cout << "-- destructor: " << id << " " << location << endl; }
