#include <iostream>
using namespace std;

#include "Msg.h"

Msg::Msg(int day, int month, int year, int hours, int mins, string src,
         string dest) {
  this->src = src;
  this->dest = dest;
  this->date = new Date(day, month, year);
  this->time = new Time(hours, mins);
}

Msg::~Msg() {
  delete date;
  delete time;
}

bool Msg::greaterThan(Msg *msg) {
  if (date->greaterThan(msg->date)) {
    return true;
  }
  if (date->equals(msg->date)) {
    return time->greaterThan(msg->time);
  }
  return false;
}

void Msg::print() {
  date->print();
  cout << " @ ";
  time->print();
  cout << ": From: " << src << " To: " << dest;
}
