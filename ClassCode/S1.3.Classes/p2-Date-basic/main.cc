#include <iostream>
using namespace std;
#include <string>

#include "Date.h"
#define MAX_ARR_SIZE 3

int main() {
  cout << "Declaring d1...";
  Date d1(20, 9, 2026);

  cout << "Declaring d2...";
  Date d2;

  cout << endl;
  cout << "Declaring dArray..." << endl;
  Date dArray[MAX_ARR_SIZE];

  cout << "Printing d1...";
  d1.print();
  cout << "Printing d2...";
  d2.print();
  d2.setDate(3, 3, 1933);
  d2.print();

  dArray[0].setDate(1, 1, 1911);
  dArray[1].setDate(5, 5, 1955);

  for (int i = 0; i < MAX_ARR_SIZE; ++i)
    dArray[i].print();

  return 0;
}
