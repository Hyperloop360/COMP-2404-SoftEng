#include "InternMsg.h"

InternMsg::InternMsg(int day, int month, int year, int hours, int mins,
                     Subscriber* s, Subscriber* d)
  : Msg(day, month, year, hours, mins), src(s), dest(d) { }

string InternMsg::getSrc()  { return src->getPhoneNum(); }
string InternMsg::getDest() { return dest->getPhoneNum(); }

void InternMsg::print()
{
  Msg::print();
  cout<<"I-Msg From: "<<getSrc()<<"  To: "<<getDest()<<endl;
}
