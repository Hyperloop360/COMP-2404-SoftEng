// Date.cc  --  CLASS SOURCE FILE
#include <iostream>
#include "Date.h"          // include the HEADER, never another .cc file!
using namespace std;

// static data member initialization belongs in the source file.
int Date::liveCount = 0;

// Scope resolution operator (Date::) says "this function is a member
// of Date". Without it we'd be defining a brand-new GLOBAL function.
// NOTE: default arguments are NOT repeated here.
Date::Date(int d, int m, int y) : day(d), month(m), year(y) {
    ++liveCount;
    cout << "    [Date ctor  " << day << "/" << month << "/" << year << "]\n";
}

Date::~Date() {
    --liveCount;
    cout << "    [Date dtor  " << day << "/" << month << "/" << year << "]\n";
}

int  Date::getDay()   const { return day; }
int  Date::getMonth() const { return month; }
int  Date::getYear()  const { return year; }
void Date::print()    const { cout << day << "/" << month << "/" << year; }
