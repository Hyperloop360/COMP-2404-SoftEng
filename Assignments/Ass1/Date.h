#ifndef DATE_H
#define DATE_H

/*
 * Class: Date
 * Purpose: Represents a calendar date with year, month, and day,
 *          and provides functionality to validate, print, and compare dates.
 * Members:
 *   - day: integer representing the day
 *   - month: integer representing the month
 *   - year: integer representing the year
 *   - lastDayInMonth(int, int): helper function to get the last day of a month
 *   - leapYear(int): helper function to check for a leap year
 */

class Date {
public:
  // Date();
  Date(int = 0, int = 0, int = 2000);
  void setDate(int, int, int);
  void print();
  bool lessThan(Date &d);

private:
  int day;
  int month;
  int year;
  int lastDayInMonth(int, int);
  bool leapYear(int);
};

#endif
