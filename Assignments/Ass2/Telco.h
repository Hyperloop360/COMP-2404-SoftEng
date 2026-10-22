#ifndef TELCO_H
#define TELCO_H

#include "MsgArray.h"
#include "Subscriber.h"
#include "defs.h"
#include <string>

using namespace std;

#define MAX_SUBS 64

/**
 * Class: Telco
 * Purpose: Represents a telephone company that manges a collection of
 * subscribers and a primary collection o fall text messages Members:
 * - name: String representing the telco name
 * - numSubscribers: count of current subscribers
 * - subscribers: primitive array of Subscriber object pointers
 * - allMsgs: primary MsgArray containing all telco messages
 */
class Telco {
public:
  Telco(string name = "");
  ~Telco();

  void addSub(string phoneNumber);
  void addMsg(string srcNum, string destNum, int year, int month, int day,
              int hours, int mins);
  void printSubscribers() const;
  void printFrequent(SubscriberType subType) const;

private:
  string name;
  int numSubscribers;
  Subscriber *subscribers[MAX_SUBS];
  MsgArray allMsgs;

  bool findSub(string phoneNum, Subscriber *&sub) const;
};

#endif
