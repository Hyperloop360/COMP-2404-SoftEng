#include "ExternMsg.h"

ExternMsg::ExternMsg(int day, int month, int year, int hours, int mins,
                     string s, string d)
  : Msg(day, month, year, hours, mins), src(s), dest(d) { }

string ExternMsg::getSrc()  { return src; }
string ExternMsg::getDest() { return dest; }

void ExternMsg::print()
{
  Msg::print();
  cout<<"E-Msg From: "<<getSrc()<<"  To: "<<getDest()<<endl;
}
