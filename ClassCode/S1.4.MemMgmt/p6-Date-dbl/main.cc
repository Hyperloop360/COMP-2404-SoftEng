#include <iostream>
using namespace std;
#include "Date.h"
#include <string>

#define MAX_ARR 5

void initDate(int, int, int, Date **);

int main() {
  Date *someDates[MAX_ARR];
  Date *tmpDate;

  initDate(1922, 2, 2, &tmpDate);
  someDates[0] = tmpDate;
  cout << "Initialized: ";
  tmpDate->print();

  initDate(1988, 8, 8, &tmpDate);
  someDates[1] = tmpDate;
  cout << "Initialized: ";
  someDates[1]->print();

  initDate(1977, 7, 7, &someDates[2]);
  cout << "Initialied: ";
  someDates[2]->print();

  initDate(1955, 5, 5, someDates + 3);
  cout << "Initialied: ";
  someDates[3]->print();

  cout << endl << "Deallocating dates..." << endl;

  for (int i = 0; i < 4; ++i)
    delete someDates[i];

  return 0;
}

void initDate(int y, int m, int d, Date **dt) { *dt = new Date(d, m, y); }
