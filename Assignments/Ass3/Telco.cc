#include "Telco.h"

Telco::Telco(string n) : name(n) { }

Telco::~Telco()
{
  messages.cleanup();
  subscribers.cleanup();
}

void Telco::addSub(string phoneNum)
{
  subscribers.add(new Subscriber(phoneNum));
}

bool Telco::findSub(string phoneNum, Subscriber** sub)
{
  *sub = NULL;

  for (int i = 0; i < subscribers.getSize(); ++i) {
    Subscriber* curr = subscribers.get(i);
    if (curr != NULL && curr->getPhoneNum() == phoneNum) {
      *sub = curr;
      return true;
    }
  }
  return false;
}

void Telco::addMsg(string srcNum, string destNum, int year, int month,
                   int day, int hours, int mins)
{
  Subscriber* src  = NULL;
  Subscriber* dest = NULL;
  Msg* msg = NULL;

  findSub(srcNum, &src);
  findSub(destNum, &dest);

  if (src != NULL && dest != NULL)
    msg = new InternMsg(day, month, year, hours, mins, src, dest);
  else
    msg = new ExternMsg(day, month, year, hours, mins, srcNum, destNum);

  messages.add(msg);
}

void Telco::printMessages()
{
  cout<<endl;
  messages.print();
}

void Telco::printSubscribers()
{
  cout<<endl<<endl<<"TELCO "<<name<<" SUBSCRIBERS:"<<endl<<endl;

  for (int i = 0; i < subscribers.getSize(); ++i) {
    MsgList temp;
    Subscriber* sub = subscribers.get(i);

    temp.copySubset(sub->getPhoneNum(), messages);
    sub->print();
    temp.print();
    cout<<endl;
  }
}

void Telco::printByActivity()
{
  int n = subscribers.getSize();
  int totals[MAX_ARR_SIZE];
  int indexes[MAX_ARR_SIZE];

  for (int i = 0; i < n; ++i) {
    MsgList temp;
    temp.copySubset(subscribers.get(i)->getPhoneNum(), messages);
    totals[i]  = temp.getSize();
    indexes[i] = i;
  }

  selectionSort(n, totals, indexes);

  cout<<endl<<"==> MOST ACTIVE SUBSCRIBERS:"<<endl<<endl;

  for (int i = 0; i < n; ++i) {
    MsgList temp;
    Subscriber* sub = subscribers.get(indexes[i]);

    temp.copySubset(sub->getPhoneNum(), messages);
    cout<<"Subscriber "<<sub->getPhoneNum()<<":"<<endl;
    temp.print();
    cout<<endl;
  }
}

void Telco::printFrequent(SubscriberType type)
{
  int n = subscribers.getSize();
  int totals[MAX_ARR_SIZE];
  int indexes[MAX_ARR_SIZE];

  cout<<endl;
  if (type == C_SENDER)
    cout<<"==> MOST FREQUENT SENDING SUBSCRIBERS:"<<endl;
  else
    cout<<"==> MOST FREQUENT RECEIVING SUBSCRIBERS:"<<endl;
  cout<<endl;

  if (n == 0) {
    cout<<"No subscribers."<<endl;
    return;
  }

  for (int i = 0; i < n; ++i) {
    MsgList temp;
    temp.copySubset(subscribers.get(i)->getPhoneNum(), messages, type);
    totals[i]  = temp.getSize();
    indexes[i] = i;
  }

  selectionSort(n, totals, indexes);

  for (int i = 0; i < n; ++i) {
    MsgList temp;
    Subscriber* sub = subscribers.get(indexes[i]);

    temp.copySubset(sub->getPhoneNum(), messages, type);
    cout<<"Subscriber "<<sub->getPhoneNum()<<":"<<endl;
    temp.print();
    cout<<endl;
  }
}
