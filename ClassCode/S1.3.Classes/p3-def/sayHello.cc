#include <iostream>
using namespace std;

#include <string>

void sayHello(string);

int main() {
  sayHello("world");

  return 0;
}

void sayHello(string who) { cout << "Hello " << who << endl; }
