#include "Subscriber.h"

int Subscriber::nextId = SUBSCRIBER_ID;

Subscriber::Subscriber(string num) : id(nextId++), phoneNum(num) { }

string Subscriber::getPhoneNum() { return phoneNum; }

void Subscriber::print()
{
  cout<<"Subscriber :: "<<id<<" :: "<<phoneNum<<endl;
}
