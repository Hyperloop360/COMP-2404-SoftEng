#include "Subscriber.h"
#include <iostream>

using namespace std;

Subscriber::Subscriber(string phoneNum) { this->phoneNum = phoneNum; }

void Subscriber::addIncoming(Msg *msg) { incomingMsgs.add(msg); }

void Subscriber::addOutgoing(Msg *msg) { outgoingMsgs.add(msg); }

string Subscriber::getPhoneNum() const { return phoneNum; }

MsgArray &Subscriber::getIncomingMsgs() { return incomingMsgs; }

MsgArray &Subscriber::getOutgoingMsgs() { return outgoingMsgs; }

void Subscriber::print() const {
  cout << "Subscriber " << phoneNum << ":";

  MsgArray mergedMsgs(incomingMsgs);
  mergedMsgs.add(const_cast<MsgArray &>(outgoingMsgs));

  if (mergedMsgs.getSize() == 0) {
    cout << " No messages" << endl;
  } else {
    cout << endl;
    mergedMsgs.print();
  }
}
