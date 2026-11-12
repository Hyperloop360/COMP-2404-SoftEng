#ifndef EXTERNMSG_H
#define EXTERNMSG_H

#include "Msg.h"

/*
  Class:   ExternMsg
  Purpose: Entity class derived from Msg, representing a text message
           between a telco subscriber and a non-subscriber.

  Members:
    src, dest    the source and destination phone numbers
    getSrc()     returns the source phone number
    getDest()    returns the destination phone number
    print()      prints the full message
*/

class ExternMsg : public Msg
{
  public:
    ExternMsg(int, int, int, int, int, string, string);
    virtual string getSrc();
    virtual string getDest();
    virtual void print();

  private:
    string src;
    string dest;
};

#endif
