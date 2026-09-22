#include <iostream>
using namespace std;
#include "Date.h"
#include <string>

#define MAX_ARR_SIZE 3

int main() {
  cout << endl << "Declaring d4...";
  Date d4(22, 9, 2026);
  cout << "Printing d4...";
  d4.print();

  cout << endl << "Declaring d3...";
  Date d3(22, 9, 2026);
  cout << "Printing d3...";
  d3.print();

  cout << endl << "Declaring d2...";
  Date d2(22, 9, 2026);
  cout << "Printing d2...";
  d2.print();

  cout << endl << "Declaring d1...";
  Date d1(22, 9, 2026);
  cout << "Printing d1...";
  d1.print();

  Date dArray[MAX_ARR_SIZE];

  return 0;
}
