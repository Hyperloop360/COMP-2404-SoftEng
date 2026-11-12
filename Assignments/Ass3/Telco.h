#ifndef TELCO_H
#define TELCO_H

#include "defs.h"
#include "SubArray.h"
#include "MsgList.h"
#include "Msg.h"
#include "InternMsg.h"
#include "ExternMsg.h"

/*
  Class:   Telco
  Purpose: Entity class representing the telephone company being managed.
           It owns the subscribers and all the text messages.

  Members:
    name          the name of the telco
    subscribers   the collection of subscribers
    messages      the collection of messages, in descending order by date/time
    addSub()      creates a subscriber with the given phone number
    addMsg()      creates an internal or external message and adds it
    printMessages()     prints all messages
    printSubscribers()  prints every subscriber with their messages
    printByActivity()   prints subscribers, most active first
    printFrequent()     prints subscribers ordered by messages sent (C_SENDER)
                        or received (C_RECEIVER), most first
    findSub()     finds a subscriber by phone number (output param is NULL if absent)
  Destructor:     cleans up all subscribers and messages
*/

class Telco
{
  public:
    Telco(string);
    ~Telco();
    void addSub(string);
    void addMsg(string, string, int, int, int, int, int);
    void printMessages();
    void printSubscribers();
    void printByActivity();
    void printFrequent(SubscriberType);

  private:
    string name;
    SubArray subscribers;
    MsgList messages;

    bool findSub(string, Subscriber**);
};

#endif
