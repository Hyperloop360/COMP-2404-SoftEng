#ifndef DATE_H
#define DATE_H

class Date {
public:
  Date();
  Date(int, int, int);
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
