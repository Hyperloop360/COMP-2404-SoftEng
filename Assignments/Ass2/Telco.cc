#include "Telco.h"
#include "defs.h"
#include <iostream>

using namespace std;

Telco::Telco(string name) {
  this->name = name;
  this->numSubscribers = 0;
}

Telco::~Telco() {
  for (int i = 0; i < numSubscribers; ++i) {
    delete subscribers[i];
  }
  allMsgs.cleanup();
}

void Telco::addSub(string phoneNumber) {
  if (numSubscribers >= MAX_SUBS) {
    return;
  }
  subscribers[numSubscribers] = new Subscriber(phoneNumber);
  numSubscribers++;
}

bool Telco::findSub(string phoneNum, Subscriber *&sub) const {
  for (int i = 0; i < numSubscribers; ++i) {
    if (subscribers[i]->getPhoneNum() == phoneNum) {
      sub = subscribers[i];
      return true;
    }
  }
  sub = nullptr;
  return false;
}

void Telco::addMsg(string srcNum, string destNum, int year, int month, int day,
                   int hours, int mins) {
  Subscriber *sender = nullptr;
  Subscriber *receiver = nullptr;

  bool senderExists = findSub(srcNum, sender);
  bool receiverExists = findSub(destNum, receiver);

  if (!senderExists && !receiverExists) {
    return;
  }

  Msg *newMsg = new Msg(day, month, year, hours, mins, srcNum, destNum);
  allMsgs.add(newMsg);

  if (senderExists) {
    sender->addOutgoing(newMsg);
  }
  if (receiverExists) {
    receiver->addIncoming(newMsg);
  }
}

void Telco::printSubscribers() const {
  cout << "TELCO " << name << ":" << endl;
  for (int i = 0; i < numSubscribers; ++i) {
    subscribers[i]->print();
    cout << endl;
  }
}

void Telco::printFrequent(SubscriberType subType) const {
  if (subType == C_SENDER) {
    cout << "==> MOST FREQUENT SENDING SUBSCRIBERS:" << endl;
  } else {
    cout << "==> MOST FREQUENT RECEIVING SUBSCRIBERS:" << endl;
  }

  if (numSubscribers == 0) {
    cout << "No subscribers" << endl;
    return;
  }

  int totals[MAX_SUBS];
  int indices[MAX_SUBS];

  for (int i = 0; i < numSubscribers; ++i) {
    indices[i] = i;
    if (subType == C_SENDER) {
      totals[i] = subscribers[i]->getOutgoingMsgs().getSize();
    } else {
      totals[i] = subscribers[i]->getIncomingMsgs().getSize();
    }
  }

  selectionSort(numSubscribers, totals, indices);

  for (int i = 0; i < numSubscribers; ++i) {
    int idx = indices[i];
    cout << "FROM: " << subscribers[idx]->getPhoneNum() << ":";

    MsgArray &targetMsgs = (subType == C_SENDER)
                               ? subscribers[idx]->getOutgoingMsgs()
                               : subscribers[idx]->getIncomingMsgs();

    if (targetMsgs.getSize() == 0) {
      cout << " No messages" << endl;
    } else {
      cout << endl;
      targetMsgs.print();
    }
    cout << endl;
  }
}
