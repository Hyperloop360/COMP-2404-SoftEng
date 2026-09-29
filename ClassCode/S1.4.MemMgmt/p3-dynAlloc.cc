#include <iostream>
using namespace std;

#define MAX_ARRAY_SIZE 4

int main() {
  int *p1;

  p1 = new int;
  *p1 = 56;
  cout << "Value at p1: " << *p1 << endl;

  int *p2 = new int(87);
  cout << "Value at p2: " << *p2 << endl;

  delete p1;
  delete p2;

  int *p3 = new int[MAX_ARRAY_SIZE];

  for (int i = 0; i < MAX_ARRAY_SIZE; ++i)
    p3[i] = (i + 1) * 2;

  cout << "Array values: ";

  for (int i = 0; i < MAX_ARRAY_SIZE; ++i)
    cout << p3[i] << " ";

  cout << endl;

  delete[] p3;
  cout << "Deleted array" << endl;
  return 0;
}
