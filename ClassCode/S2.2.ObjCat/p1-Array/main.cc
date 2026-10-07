#include <iostream>
using namespace std;

#include "Array.h"
#include "Date.h"

int main() {
  Array arr;
  Date *d;

  d = new Date(1, 1, 1911);
  arr.add(d);

  d = new Date(2, 2, 1922);
  arr.add(d);

  arr.add(new Date(3, 3, 1933));
  arr.add(new Date(4, 4, 1944));

  arr.print();

  return 0;
}
