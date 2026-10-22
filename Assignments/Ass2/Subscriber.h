#ifndef SUBSCRIBER_H
#define SUBSCRIBER_H

#include "MsgArray.h"
#include <string>

using namespace std;

/**
 * Class: Subscriber
 * Purpose: Represents a telephone subscriber in the telco system, storing their
 *          phone number and collections for incoming and outgoing messages.
 * Members:
 *   - phoneNum: string representing the subscriber's phone number
 *   - incomingMsgs: MsgArray holding all messages received by the subscriber
 *   - outgoingMsgs: MsgArray holding all messages sent by the subscriber
 */

class Subscriber {
public:
  Subscriber(string phoneNum = "");

  void addIncoming(Msg *msg);
  void addOutgoing(Msg *msg);

  string getPhoneNum() const;
  MsgArray &getIncomingMsgs();
  MsgArray &getOutgoingMsgs();

  void print() const;

private:
  string phoneNum;
  MsgArray incomingMsgs;
  MsgArray outgoingMsgs;
};
#endif
