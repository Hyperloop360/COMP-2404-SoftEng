#include <iostream>
using namespace std;

int main() {
  char c = 'H';
  int i = 42;

  int *iptr;

  cout << "sizes : " << sizeof(c) << " " << sizeof(i) << " " << sizeof(iptr)
       << endl;

  iptr = &i;

  cout << "addresses: " << &i << " " << &iptr << endl;
  cout << "values: " << i << " " << iptr << endl;

  cout << "two ways to i: " << i << " " << *iptr << endl;

  *iptr = 99;
  cout << "new value for i: " << i << " " << *iptr << endl;

  return 0;
}
