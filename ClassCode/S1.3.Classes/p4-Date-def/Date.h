#ifndef DATE_H
#define DATE_H

class Date {
public:
  // Date();
  Date(int = 0, int = 0, int = 2000);
  void setDate(int, int, int);
  void print();

private:
  int day;
  int month;
  int year;
  int lastDayInMonth(int, int);
  bool leapYear(int);
};

#endif
