#include <iostream>
using namespace std;
#include "Thing.h"
#include <cstdlib>

void func();

Thing t1(1, "first global");
Thing t2(2, "second global");

int main() {
  cout << endl << "In main..." << endl;

  Thing t3(3, "first local in main");

  cout << "Calling func()" << endl;
  func();
  cout << "Back from func()" << endl;

  cout << "Calling func() again" << endl;
  func();
  cout << "Back from func() again" << endl;

  static Thing t4(4, "local static in main");

  cout << "So long and thanks for all the fish" << endl << endl;

  return 0;
}

void func() {
  cout << "In func()" << endl;

  Thing t5(5, "first local in func");
  Thing t6(6, "second local in func");

  cout << "leaving func()" << endl;
}
