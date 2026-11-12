#ifndef INTERNMSG_H
#define INTERNMSG_H

#include "Msg.h"
#include "Subscriber.h"

/*
  Class:   InternMsg
  Purpose: Entity class derived from Msg, representing a text message
           between two telco subscribers.

  Members:
    src, dest    pointers to the source and destination subscribers, which are
                 owned by the telco's subscriber collection
    getSrc()     returns the source subscriber's phone number
    getDest()    returns the destination subscriber's phone number
    print()      prints the full message
*/

class InternMsg : public Msg
{
  public:
    InternMsg(int, int, int, int, int, Subscriber*, Subscriber*);
    virtual string getSrc();
    virtual string getDest();
    virtual void print();

  private:
    Subscriber* src;
    Subscriber* dest;
};

#endif
