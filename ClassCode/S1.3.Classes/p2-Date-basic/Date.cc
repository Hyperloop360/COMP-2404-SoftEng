#include <iomanip>
#include <iostream>
using namespace std;

#include "Date.h"

Date::Date() {
  cout << "in default ctor" << endl;
  day = month = year = 0;
}

Date::Date(int d, int m, int y) {
  cout << "in 3-param ctor" << endl;
  setDate(d, m, y);
}

void Date::setDate(int d, int m, int y) {
  year = ((y > 0) ? y : 0);
  month = ((m > 0 && m <= 12) ? m : 0);
  day = ((d > 0 && d <= lastDayInMonth(m, y)) ? d : 0);
}

void Date::print() {
  cout << setfill('0') << setw(4) << year << "-" << setfill('0') << setw(2)
       << month << "-" << setfill('0') << setw(2) << day << endl;
}

int Date::lastDayInMonth(int m, int y) {
  switch (m) {
  case 2:
    if (leapYear(y))
      return (29);
    else
      return 28;
  case 1:
  case 3:
  case 5:
  case 7:
  case 10:
  case 12:
    return 31;
  default:
    return 30;
  }
}

bool Date::leapYear(int y) {
  if (y % 400 == 0 || (y % 4 == 0 && y % 100 != 0))
    return true;
  else
    return false;
}
