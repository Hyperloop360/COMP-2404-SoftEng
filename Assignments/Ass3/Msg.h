#ifndef MSG_H
#define MSG_H

#include "defs.h"
#include "Date.h"
#include "Time.h"

/*
  Class:   Msg
  Purpose: Base entity class representing a text message in the telco.
           Derived classes represent internal and external messages.

  Members:
    date, time     dynamically allocated date and time the message was sent
    greaterThan()  returns whether this message was sent later than the given one
    getSrc()       returns the source phone number (empty here, overridden)
    getDest()      returns the destination phone number (empty here, overridden)
    print()        prints the date and time of the message
*/

class Msg
{
  public:
    Msg(int, int, int, int, int);
    virtual ~Msg();
    bool greaterThan(Msg*);
    virtual string getSrc();
    virtual string getDest();
    virtual void print();

  private:
    Date* date;
    Time* time;
};

#endif
