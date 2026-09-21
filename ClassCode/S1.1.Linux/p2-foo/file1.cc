#include <iostream>
using namespace std;

void foo1(); // forward references
void foo2();

int main() {
  foo1();
  foo2();

  return 0;
}

void foo1() { cout << "Hello "; }
