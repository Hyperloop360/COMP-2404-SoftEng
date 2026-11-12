#ifndef SUBSCRIBER_H
#define SUBSCRIBER_H

#include "defs.h"

/*
  Class:   Subscriber
  Purpose: Entity class representing one customer of the telco.
           A subscriber does not store any messages.

  Members:
    nextId      static counter used to assign each subscriber a unique id
    id          the unique identifier of this subscriber
    phoneNum    the subscriber's phone number
    getPhoneNum()  getter for the phone number
    print()        prints the subscriber's data
*/

class Subscriber
{
  public:
    Subscriber(string);
    string getPhoneNum();
    void print();

  private:
    static int nextId;

    int id;
    string phoneNum;
};

#endif
