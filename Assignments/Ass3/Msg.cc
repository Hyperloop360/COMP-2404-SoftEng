#include "Msg.h"

Msg::Msg(int day, int month, int year, int hours, int mins)
{
  date = new Date(day, month, year);
  time = new Time(hours, mins);
}

Msg::~Msg()
{
  delete date;
  delete time;
}

bool Msg::greaterThan(Msg* msg)
{
  if (date->greaterThan(msg->date))
    return true;
  return date->equals(msg->date) && time->greaterThan(msg->time);
}

string Msg::getSrc()  { return ""; }
string Msg::getDest() { return ""; }

void Msg::print()
{
  date->print();
  cout<<"  ";
  time->print();
  cout<<" ";
}
